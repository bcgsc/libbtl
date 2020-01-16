#ifndef BTLLIB_SEQ_READER_HPP
#define BTLLIB_SEQ_READER_HPP

#include "data_saveload.hpp"
#include "index_queue.hpp"
#include "seq.hpp"
#include "status.hpp"

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cctype>
#include <condition_variable>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>

namespace btllib {

/** Read a FASTA, FASTQ, SAM, or GFA2 file. */
class SeqReader
{
public:
  enum Flag
  {
    /** Fold lower-case characters to upper-case. */
    FOLD_CASE = 0,
    NO_FOLD_CASE = 1,
    /** Trim masked (lower case) characters from the ends of
     * sequences. */
    NO_TRIM_MASKED = 0,
    TRIM_MASKED = 2
  };

  SeqReader(const std::string& source_path, int flags = 0);
  ~SeqReader();

  void close();

  bool flagFoldCase() const { return bool(~flags & NO_FOLD_CASE); }
  bool flagTrimMasked() const { return bool(flags & TRIM_MASKED); }

  enum Format
  {
    UNDETERMINED,
    FASTA,
    FASTQ,
    SAM,
    GFA2,
    INVALID
  };

  Format get_format() const { return format; }

  struct Record
  {
    std::string name;
    std::string comment;
    std::string seq;
    std::string qual;

    operator bool() { return !seq.empty(); }
  };

  /** Read operator. */
  Record read();

private:
  const std::string& source_path;
  DataSource source;
  unsigned flags = 0;
  Format format = UNDETERMINED; // Format of the source file
  bool closed = false;

  static const size_t DETERMINE_FORMAT_CHARS = 2048;
  static const size_t BUFFER_SIZE = DETERMINE_FORMAT_CHARS;

  char* buffer = nullptr;
  size_t buffer_start = 0;
  size_t buffer_end = 0;
  bool eof_newline_inserted = false;

  static const size_t RECORD_QUEUE_SIZE = 128;
  static const size_t RECORD_BLOCK_SIZE = 64;

  static const size_t NAME_DEFAULT_CAPACITY = 4096;
  static const size_t COMMENT_DEFAULT_CAPACITY = NAME_DEFAULT_CAPACITY;
  static const size_t SEQ_DEFAULT_CAPACITY = NAME_DEFAULT_CAPACITY;
  static const size_t QUAL_DEFAULT_CAPACITY = SEQ_DEFAULT_CAPACITY;

  struct RecordCString
  {

    RecordCString()
      : name((char*)std::malloc(NAME_DEFAULT_CAPACITY))
      , name_cap(NAME_DEFAULT_CAPACITY)
      , comment((char*)std::malloc(COMMENT_DEFAULT_CAPACITY))
      , comment_cap(COMMENT_DEFAULT_CAPACITY)
      , seq((char*)std::malloc(SEQ_DEFAULT_CAPACITY))
      , seq_cap(SEQ_DEFAULT_CAPACITY)
      , qual((char*)std::malloc(QUAL_DEFAULT_CAPACITY))
      , qual_cap(QUAL_DEFAULT_CAPACITY)
    {
      name[0] = '\0';
      comment[0] = '\0';
      seq[0] = '\0';
      qual[0] = '\0';
    }

    RecordCString(const RecordCString&) = delete;

    RecordCString(RecordCString&& record)
    {
      std::swap(name, record.name);
      std::swap(name_cap, record.name_cap);
      std::swap(comment, record.comment);
      std::swap(comment_cap, record.comment_cap);
      std::swap(seq, record.seq);
      std::swap(seq_cap, record.seq_cap);
      std::swap(qual, record.qual);
      std::swap(qual_cap, record.qual_cap);
    }

    RecordCString& operator=(const RecordCString&) = delete;

    RecordCString& operator=(RecordCString&& record)
    {
      std::swap(name, record.name);
      std::swap(name_cap, record.name_cap);
      std::swap(comment, record.comment);
      std::swap(comment_cap, record.comment_cap);
      std::swap(seq, record.seq);
      std::swap(seq_cap, record.seq_cap);
      std::swap(qual, record.qual);
      std::swap(qual_cap, record.qual_cap);
      return *this;
    }

    ~RecordCString()
    {
      free(name);
      free(comment);
      free(seq);
      free(qual);
    }

    char* name = nullptr;
    size_t name_cap = 0;
    char* comment = nullptr;
    size_t comment_cap = 0;
    char* seq = nullptr;
    size_t seq_cap = 0;
    char* qual = nullptr;
    size_t qual_cap = 0;
  };

  char* tmp = nullptr;
  size_t tmp_cap = 0;

  std::thread* reader_thread = nullptr;
  std::thread* postprocessor_thread = nullptr;
  std::mutex format_mutex;
  std::condition_variable format_cv;
  std::atomic<bool> reader_end;
  InputIndexQueue<Record, RECORD_QUEUE_SIZE, RECORD_BLOCK_SIZE>::Block
    ready_records;
  RecordCString* reader_record = nullptr;
  Record* ready_record = nullptr;
  InputIndexQueue<RecordCString, RECORD_QUEUE_SIZE, RECORD_BLOCK_SIZE>
    reader_queue;
  InputIndexQueue<Record, RECORD_QUEUE_SIZE, RECORD_BLOCK_SIZE>
    postprocessor_queue;

  void determine_format();
  void start_reader();
  void start_postprocessor();

  bool load_buffer();

  bool is_fasta_buffer();
  bool is_fastq_buffer();
  bool is_sam_buffer();
  bool is_gfa2_buffer();

  bool readline_buffer_append(char*& ptr, size_t& cap);
  void readline_file(char*& ptr, size_t& cap);
  void readline_file_append(char*& ptr, size_t& cap);

  int read_stage = 0;

  bool read_fasta_buffer();
  bool read_fastq_buffer();
  bool read_sam_buffer();
  bool read_gfa2_buffer();

  void read_fasta_transition();
  void read_fastq_transition();
  void read_sam_transition();
  void read_gfa2_transition();

  void read_fasta_file();
  void read_fastq_file();
  void read_sam_file();
  void read_gfa2_file();

  bool (SeqReader::*read_format_buffer_impl)() = nullptr;
  void (SeqReader::*read_format_transition_impl)() = nullptr;
  void (SeqReader::*read_format_file_impl)() = nullptr;

  void postprocess();
};

inline SeqReader::SeqReader(const std::string& source_path, int flags)
  : source_path(source_path)
  , source(source_path)
  , flags(flags)
  , reader_end(false)
{
  buffer = new char[BUFFER_SIZE];
  tmp = (char*)std::malloc(SEQ_DEFAULT_CAPACITY); // NOLINT
  tmp_cap = SEQ_DEFAULT_CAPACITY;
  tmp[0] = '\0';
  start_postprocessor();
  std::unique_lock<std::mutex> lock(format_mutex);
  start_reader();
  format_cv.wait(lock);
}

inline SeqReader::~SeqReader()
{
  close();
  delete[] buffer;
  free(tmp);
}

inline void
SeqReader::close()
{
  if (!closed) {
    reader_end = true;
    reader_queue.close();
    postprocessor_queue.close();
    reader_thread->join();
    postprocessor_thread->join();
    source.close();
    closed = true;
  }
}

inline bool
SeqReader::load_buffer()
{
  buffer_start = 0;
  char last = buffer_end > 0 ? buffer[buffer_end - 1] : char(0);
  buffer_end = 0;
  do {
    buffer_end +=
      fread(buffer + buffer_end, 1, BUFFER_SIZE - buffer_end, source);
  } while (buffer_end < BUFFER_SIZE && !bool(std::feof(source)));

  if (bool(std::feof(source)) && !eof_newline_inserted) {
    if (buffer_end < BUFFER_SIZE) {
      if ((buffer_end == 0 && last != '\n') ||
          (buffer_end > 0 && buffer[buffer_end - 1] != '\n')) {
        buffer[buffer_end++] = '\n';
      }
      eof_newline_inserted = true;
    } else if (buffer[BUFFER_SIZE - 1] == '\n') {
      eof_newline_inserted = true;
    }
    return true;
  }
  return bool(buffer_end);
}

inline bool
SeqReader::is_fasta_buffer()
{
  size_t current = buffer_start;
  unsigned char c;
  enum State
  {
    IN_HEADER_1,
    IN_HEADER_2,
    IN_SEQ
  };
  State state = IN_HEADER_1;
  while (current < buffer_start + DETERMINE_FORMAT_CHARS &&
         current < buffer_end) {
    c = buffer[current];
    switch (state) {
      case IN_HEADER_1:
        if (c == '>') {
          state = IN_HEADER_2;
        } else {
          return false;
        }
        break;
      case IN_HEADER_2:
        if (c == '\n') {
          state = IN_SEQ;
        }
        break;
      case IN_SEQ:
        if (c == '\n') {
          state = IN_HEADER_1;
        } else if (!bool(COMPLEMENTS[c])) {
          return false;
        }
        break;
    }
    current++;
  }
  return true;
}

inline bool
SeqReader::is_fastq_buffer()
{
  size_t current = buffer_start;
  unsigned char c;
  enum State
  {
    IN_HEADER_1,
    IN_HEADER_2,
    IN_SEQ,
    IN_PLUS_1,
    IN_PLUS_2,
    IN_QUAL
  };
  State state = IN_HEADER_1;
  while (current < buffer_start + DETERMINE_FORMAT_CHARS &&
         current < buffer_end) {
    c = buffer[current];
    switch (state) {
      case IN_HEADER_1:
        if (c == '@') {
          state = IN_HEADER_2;
        } else {
          return false;
        }
        break;
      case IN_HEADER_2:
        if (c == '\n') {
          state = IN_SEQ;
        }
        break;
      case IN_SEQ:
        if (c == '\n') {
          state = IN_PLUS_1;
        } else if (!bool(COMPLEMENTS[c])) {
          return false;
        }
        break;
      case IN_PLUS_1:
        if (c == '+') {
          state = IN_PLUS_2;
        } else {
          return false;
        }
        break;
      case IN_PLUS_2:
        if (c == '\n') {
          state = IN_QUAL;
        }
        break;
      case IN_QUAL:
        if (c == '\n') {
          state = IN_HEADER_1;
        } else if (c < '!' || c > '~') {
          return false;
        }
        break;
    }
    current++;
  }
  return true;
}

inline bool
SeqReader::is_sam_buffer()
{
  enum Column
  {
    QNAME = 1,
    FLAG,
    RNAME,
    POS,
    MAPQ,
    CIGAR,
    RNEXT,
    PNEXT,
    TLEN,
    SEQ,
    QUAL
  };

  size_t current = buffer_start;

  while (current < buffer_start + DETERMINE_FORMAT_CHARS &&
         current < buffer_end && buffer[current] == '@') {
    while (current < buffer_start + DETERMINE_FORMAT_CHARS &&
           current < buffer_end && buffer[current] != '\n') {
      current++;
    }
    current++;
  }

  int column = 1;
  unsigned char c;
  while (current < buffer_start + DETERMINE_FORMAT_CHARS &&
         current < buffer_end) {
    c = buffer[current];
    if (c == '\n') {
      break;
    }
    if (c == '\t') {
      if (current > 0 && !bool(std::isspace(buffer[current - 1]))) {
        column++;
      } else {
        return false;
      }
    } else {
      switch (Column(column)) {
        case QNAME:
          if (bool(std::isspace(c))) {
            return false;
          }
          break;
        case FLAG:
          if (!bool(std::isdigit(c))) {
            return false;
          }
          break;
        case RNAME:
          if (bool(std::isspace(c))) {
            return false;
          }
          break;
        case POS:
          if (!bool(std::isdigit(c))) {
            return false;
          }
          break;
        case MAPQ:
          if (!bool(std::isdigit(c))) {
            return false;
          }
          break;
        case CIGAR:
          if (bool(std::isspace(c))) {
            return false;
          }
          break;
        case RNEXT:
          if (bool(std::isspace(c))) {
            return false;
          }
          break;
        case PNEXT:
          if (!bool(std::isdigit(c))) {
            return false;
          }
          break;
        case TLEN:
          if (!bool(std::isdigit(c))) {
            return false;
          }
          break;
        case SEQ:
          if (!bool(COMPLEMENTS[c])) {
            return false;
          }
          break;
        case QUAL:
          if (bool(std::isspace(c))) {
            return false;
          }
          break;
        default:
          break;
      }
    }
    current++;
  }

  return current >= buffer_end || column >= QUAL;
}

inline bool
SeqReader::is_gfa2_buffer()
{
  const unsigned char specs[] = { 'H', 'S', 'F', 'E', 'G', 'O', 'U' };

  enum State
  {
    IN_ID,
    IN_ID_TAB,
    IN_REST,
    IN_IGNORED
  };

  auto is_a_spec = [&](unsigned char c) {
    bool found = false;
    for (unsigned char spec : specs) {
      if (c == spec) {
        found = true;
        break;
      }
    }
    return found;
  };

  State state = is_a_spec(buffer[0]) ? IN_ID : IN_IGNORED;
  bool has_id = false;
  size_t current = buffer_start;
  unsigned char c;
  while (current < buffer_start + DETERMINE_FORMAT_CHARS &&
         current < buffer_end) {
    c = buffer[current];
    switch (state) {
      case IN_ID:
        if (!is_a_spec(c)) {
          return false;
        }
        has_id = true;
        state = IN_ID_TAB;
        break;
      case IN_ID_TAB:
        if (c != '\t') {
          return false;
        }
        state = IN_REST;
        break;
      case IN_REST:
        if (c == '\n') {
          if (current + 1 < buffer_end) {
            state = is_a_spec(buffer[current + 1]) ? IN_ID : IN_IGNORED;
          }
        }
        break;
      case IN_IGNORED:
        if (c == '\n') {
          if (current + 1 < buffer_end) {
            state = is_a_spec(buffer[current + 1]) ? IN_ID : IN_IGNORED;
          }
        }
        break;
      default:
        break;
    }
    current++;
  }

  return has_id;
}

inline void
SeqReader::determine_format()
{
  load_buffer();
  bool empty = buffer_end - buffer_start == 1;
  check_warning(empty, std::string(source_path) + " is empty.");

  if (empty) {
    return;
  }

  if (is_fasta_buffer()) {
    format = Format::FASTA;
    read_format_buffer_impl = &SeqReader::read_fasta_buffer;
    read_format_transition_impl = &SeqReader::read_fasta_transition;
    read_format_file_impl = &SeqReader::read_fasta_file;
  } else if (is_fastq_buffer()) {
    format = Format::FASTQ;
    read_format_buffer_impl = &SeqReader::read_fastq_buffer;
    read_format_transition_impl = &SeqReader::read_fastq_transition;
    read_format_file_impl = &SeqReader::read_fastq_file;
  } else if (is_sam_buffer()) {
    format = Format::SAM;
    read_format_buffer_impl = &SeqReader::read_sam_buffer;
    read_format_transition_impl = &SeqReader::read_sam_transition;
    read_format_file_impl = &SeqReader::read_sam_file;
  } else if (is_gfa2_buffer()) {
    format = Format::GFA2;
    read_format_buffer_impl = &SeqReader::read_gfa2_buffer;
    read_format_transition_impl = &SeqReader::read_gfa2_transition;
    read_format_file_impl = &SeqReader::read_gfa2_file;
  } else {
    format = Format::INVALID;
    log_error(std::string(source_path) + " source file is in invalid format!");
    std::exit(EXIT_FAILURE);
  }
}

inline bool
SeqReader::readline_buffer_append(char*& ptr, size_t& cap)
{
  char c = char(0);
  size_t size = std::strlen(ptr);
  for (; buffer_start < buffer_end && (c = buffer[buffer_start]) != '\n';
       ++buffer_start) {
    if (size >= cap) {
      cap *= 2;
      ptr = (char*)std::realloc((char*)ptr, cap);
    }
    ptr[size++] = c;
  }
  if (size >= cap) {
    cap *= 2;
    ptr = (char*)std::realloc((char*)ptr, cap);
  }
  ptr[size++] = '\0';
  if (c == '\n') {
    ++buffer_start;
    return true;
  }
  return false;
}

inline void
SeqReader::readline_file(char*& ptr, size_t& cap)
{
  getline(&ptr, &cap, source);
}

inline void
SeqReader::readline_file_append(char*& ptr, size_t& cap)
{
  readline_file(tmp, tmp_cap);
  size_t tmp_size = std::strlen(tmp);
  size_t ptr_size = std::strlen(ptr);
  while (tmp_size + ptr_size > cap) {
    cap *= 2;
    ptr = (char*)std::realloc((char*)ptr, cap);
  }
  strcat(ptr, tmp);
}

#define READ_FASTA_NAME_COMMENT(READLINE_SECTION, END_SECTION)                 \
  READLINE_SECTION                                                             \
  size_t tmp_size = strlen(tmp);                                               \
  while (tmp_size > reader_record->name_cap) {                                 \
    reader_record->name_cap *= 2;                                              \
    reader_record->name = (char*)std::realloc((char*)reader_record->name,      \
                                              reader_record->name_cap);        \
  }                                                                            \
  while (tmp_size > reader_record->comment_cap) {                              \
    reader_record->comment_cap *= 2;                                           \
    reader_record->comment = (char*)std::realloc(                              \
      (char*)reader_record->comment, reader_record->comment_cap);              \
  }                                                                            \
  bool in_name = true;                                                         \
  char c;                                                                      \
  int i, j;                                                                    \
  for (i = 0, j = 0, c = tmp[1]; c != '\0'; c = tmp[++i + 1]) {                \
    if (in_name) {                                                             \
      if (c == ' ') {                                                          \
        reader_record->name[i] = '\0';                                         \
        in_name = false;                                                       \
      } else {                                                                 \
        reader_record->name[i] = c;                                            \
      }                                                                        \
    } else {                                                                   \
      reader_record->comment[j++] = c;                                         \
    }                                                                          \
  }                                                                            \
  if (in_name) {                                                               \
    reader_record->name[++i] = '\0';                                           \
  }                                                                            \
  reader_record->comment[j] = '\0';                                            \
  END_SECTION

#define READ_SAM(READLINE_SECTION, MIDEND_SECTION, END_SECTION)                \
  enum Column                                                                  \
  {                                                                            \
    QNAME = 1,                                                                 \
    FLAG,                                                                      \
    RNAME,                                                                     \
    POS,                                                                       \
    MAPQ,                                                                      \
    CIGAR,                                                                     \
    RNEXT,                                                                     \
    PNEXT,                                                                     \
    TLEN,                                                                      \
    SEQ,                                                                       \
    QUAL                                                                       \
  };                                                                           \
  for (;;) {                                                                   \
    READLINE_SECTION                                                           \
    std::string tmp_string = tmp;                                              \
    if (tmp_string.length() > 0 && tmp_string[0] != '@') {                     \
      size_t pos = 0, pos2 = 0, pos3 = 0;                                      \
      pos2 = tmp_string.find('\t');                                            \
      while (tmp_cap > reader_record->name_cap) {                              \
        reader_record->name_cap *= 2;                                          \
        reader_record->name = (char*)std::realloc((char*)reader_record->name,  \
                                                  reader_record->name_cap);    \
      }                                                                        \
      strcpy(reader_record->name, tmp_string.substr(0, pos2).c_str());         \
      for (int i = 0; i < int(SEQ) - 1; i++) {                                 \
        pos = tmp_string.find('\t', pos + 1);                                  \
      }                                                                        \
      pos2 = tmp_string.find('\t', pos + 1);                                   \
      pos3 = tmp_string.find('\t', pos2 + 1);                                  \
      if (pos3 == std::string::npos) {                                         \
        pos3 = tmp_string.length();                                            \
      }                                                                        \
      while (tmp_cap > reader_record->seq_cap) {                               \
        reader_record->seq_cap *= 2;                                           \
        reader_record->seq = (char*)std::realloc((char*)reader_record->seq,    \
                                                 reader_record->seq_cap);      \
      }                                                                        \
      while (tmp_cap > reader_record->qual_cap) {                              \
        reader_record->qual_cap *= 2;                                          \
        reader_record->qual = (char*)std::realloc((char*)reader_record->qual,  \
                                                  reader_record->qual_cap);    \
      }                                                                        \
      strcpy(reader_record->seq,                                               \
             tmp_string.substr(pos + 1, pos2 - pos - 1).c_str());              \
      strcpy(reader_record->qual,                                              \
             tmp_string.substr(pos2 + 1, pos3 - pos2 - 1).c_str());            \
      MIDEND_SECTION                                                           \
    }                                                                          \
    tmp[0] = '\0';                                                             \
    END_SECTION                                                                \
  }

#define READ_GFA2(READLINE_SECTION, MIDEND_SECTION, END_SECTION)               \
  enum Column                                                                  \
  {                                                                            \
    S = 1,                                                                     \
    ID,                                                                        \
    LEN,                                                                       \
    SEQ                                                                        \
  };                                                                           \
  for (;;) {                                                                   \
    READLINE_SECTION                                                           \
    std::string tmp_string = tmp;                                              \
    if (tmp_string.length() > 0 && tmp_string[0] == 'S') {                     \
      size_t pos = 0, pos2 = 0;                                                \
      pos2 = tmp_string.find('\t', 1);                                         \
      while (tmp_cap > reader_record->name_cap) {                              \
        reader_record->name_cap *= 2;                                          \
        reader_record->name = (char*)std::realloc((char*)reader_record->name,  \
                                                  reader_record->name_cap);    \
      }                                                                        \
      strcpy(reader_record->name, tmp_string.substr(1, pos2 - 1).c_str());     \
      for (int i = 0; i < int(SEQ) - 1; i++) {                                 \
        pos = tmp_string.find('\t', pos + 1);                                  \
      }                                                                        \
      pos2 = tmp_string.find('\t', pos + 1);                                   \
      if (pos2 == std::string::npos) {                                         \
        pos2 = tmp_string.length();                                            \
      }                                                                        \
      while (tmp_cap > reader_record->seq_cap) {                               \
        reader_record->seq_cap *= 2;                                           \
        reader_record->seq = (char*)std::realloc((char*)reader_record->seq,    \
                                                 reader_record->seq_cap);      \
      }                                                                        \
      strcpy(reader_record->seq,                                               \
             tmp_string.substr(pos + 1, pos2 - pos - 1).c_str());              \
      MIDEND_SECTION                                                           \
    }                                                                          \
    tmp[0] = '\0';                                                             \
    END_SECTION                                                                \
  }

inline bool
SeqReader::read_fasta_buffer()
{
  switch (read_stage) {
    case 0: {
      READ_FASTA_NAME_COMMENT(
        if (!readline_buffer_append(tmp, tmp_cap)) { return false; },
        ++read_stage;
        tmp[0] = '\0';)
    }
    case 1: {
      if (!readline_buffer_append(reader_record->seq, reader_record->seq_cap)) {
        return false;
      }
      read_stage = 0;
      return true;
    }
  }
  return false;
}

inline bool
SeqReader::read_fastq_buffer()
{
  switch (read_stage) {
    case 0: {
      READ_FASTA_NAME_COMMENT(
        if (!readline_buffer_append(tmp, tmp_cap)) { return false; },
        ++read_stage;
        tmp[0] = '\0';)
    }
    case 1: {
      if (!readline_buffer_append(reader_record->seq, reader_record->seq_cap)) {
        return false;
      }
      ++read_stage;
    }
    case 2: {
      if (!readline_buffer_append(tmp, tmp_cap)) {
        return false;
      }
      ++read_stage;
      tmp[0] = '\0';
    }
    case 3: {
      if (!readline_buffer_append(reader_record->qual,
                                  reader_record->qual_cap)) {
        return false;
      }
      read_stage = 0;
      return true;
    }
  }
  return false;
}

inline bool
SeqReader::read_sam_buffer()
{
  READ_SAM(
    if (!readline_buffer_append(tmp, tmp_cap)) { return false; }, tmp[0] = '\0';
    return true;
    , if (buffer_start >= buffer_end) { return false; })
}

inline bool
SeqReader::read_gfa2_buffer()
{
  READ_GFA2(
    if (!readline_buffer_append(tmp, tmp_cap)) { return false; }, tmp[0] = '\0';
    return true;
    , if (buffer_start >= buffer_end) { return false; })
}

inline void
SeqReader::read_fasta_transition()
{
  switch (read_stage) {
    case 0: {
      READ_FASTA_NAME_COMMENT(readline_file_append(tmp, tmp_cap);, ++read_stage;
                              tmp[0] = '\0';)
    }
    case 1: {
      readline_file_append(reader_record->name, reader_record->name_cap);
      read_stage = 0;
    }
  }
}

inline void
SeqReader::read_fastq_transition()
{
  switch (read_stage) {
    case 0: {
      READ_FASTA_NAME_COMMENT(readline_file_append(tmp, tmp_cap);, ++read_stage;
                              tmp[0] = '\0';)
    }
    case 1: {
      readline_file_append(reader_record->seq, reader_record->seq_cap);
      ++read_stage;
    }
    case 2: {
      readline_file_append(tmp, tmp_cap);
      ++read_stage;
      tmp[0] = '\0';
    }
    case 3: {
      readline_file_append(reader_record->qual, reader_record->qual_cap);
      read_stage = 0;
    }
  }
}

inline void
SeqReader::read_sam_transition()
{
  READ_SAM(
    readline_file_append(tmp, tmp_cap);, , if (bool(feof(source))) { break; })
}

inline void
SeqReader::read_gfa2_transition()
{
  READ_GFA2(
    readline_file_append(tmp, tmp_cap);, , if (bool(feof(source))) { break; })
}

inline void
SeqReader::read_fasta_file()
{
  READ_FASTA_NAME_COMMENT(readline_file(tmp, tmp_cap);, )
  readline_file(reader_record->seq, reader_record->seq_cap);
}

inline void
SeqReader::read_fastq_file()
{
  READ_FASTA_NAME_COMMENT(readline_file(tmp, tmp_cap);, )
  readline_file(reader_record->seq, reader_record->seq_cap);
  readline_file(tmp, tmp_cap);
  readline_file(reader_record->qual, reader_record->qual_cap);
}

inline void
SeqReader::read_sam_file()
{
  READ_SAM(
    readline_file(tmp, tmp_cap);, , if (bool(feof(source))) { break; })
}

inline void
SeqReader::read_gfa2_file()
{
  READ_GFA2(
    readline_file(tmp, tmp_cap);, , if (bool(feof(source))) { break; })
}

inline void
SeqReader::start_reader()
{
  reader_thread = new std::thread([this]() {
    {
      std::unique_lock<std::mutex> lock(format_mutex);
      determine_format();
      format_cv.notify_all();
    }
    size_t counter = 0;

    decltype(reader_queue)::Block records;
    if (format != UNDETERMINED) {
      // Read from buffer
      for (; buffer_start < buffer_end && !reader_end;) {
        reader_record = &(records.data[records.current]);
        if (!(this->*read_format_buffer_impl)() ||
            reader_record->seq[0] == '\0') {
          break;
        }
        records.current++;
        records.count++;
        if (records.current == RECORD_BLOCK_SIZE) {
          records.current = 0;
          records.index = counter++;
          reader_queue.write(records);
          records = decltype(reader_queue)::Block();
        }
      }

      // Transition from buffer to file
      if (std::ferror(source) == 0 && std::feof(source) == 0 && !reader_end) {
        int p = std::fgetc(source);
        if (p != EOF) {
          std::ungetc(p, source);
          reader_record = &(records.data[records.current]);
          (this->*read_format_transition_impl)();
          if (reader_record->seq[0] != '\0') {
            records.current++;
            records.count++;
            if (records.current == RECORD_BLOCK_SIZE) {
              records.current = 0;
              records.index = counter++;
              reader_queue.write(records);
              records = decltype(reader_queue)::Block();
            }
          }
        }
      }

      // Read from file
      for (;
           std::ferror(source) == 0 && std::feof(source) == 0 && !reader_end;) {
        int p = std::fgetc(source);
        if (p == EOF) {
          break;
        }
        std::ungetc(p, source);
        reader_record = &(records.data[records.current]);
        (this->*read_format_file_impl)();
        if (reader_record->seq[0] == '\0') {
          break;
        }
        records.current++;
        records.count++;
        if (records.current == RECORD_BLOCK_SIZE) {
          records.current = 0;
          records.index = counter++;
          reader_queue.write(records);
          records = decltype(reader_queue)::Block();
        }
      }
    }

    reader_end = true;
    records.current = 0;
    records.index = counter++;
    size_t last_count = records.count;
    reader_queue.write(records);
    if (last_count > 0) {
      decltype(reader_queue)::Block dummy;
      dummy.index = counter++;
      dummy.current = 0;
      dummy.count = 0;
      reader_queue.write(dummy);
    }
  });
}

inline void
SeqReader::start_postprocessor()
{
  postprocessor_thread = new std::thread([this]() {
    decltype(reader_queue)::Block records_reader;
    decltype(postprocessor_queue)::Block records_postprocessor;
    for (;;) {
      reader_queue.read(records_reader);
      for (size_t i = 0; i < records_reader.count; i++) {
        records_postprocessor.data[i].name = records_reader.data[i].name;
        records_postprocessor.data[i].comment = records_reader.data[i].comment;
        records_postprocessor.data[i].seq = records_reader.data[i].seq;
        records_postprocessor.data[i].qual = records_reader.data[i].qual;
        auto& name = records_postprocessor.data[i].name;
        auto& comment = records_postprocessor.data[i].comment;
        auto& seq = records_postprocessor.data[i].seq;
        auto& qual = records_postprocessor.data[i].qual;
        if (!name.empty() && name.back() == '\n') {
          name.pop_back();
        }
        if (!comment.empty() && comment.back() == '\n') {
          comment.pop_back();
        }
        if (!seq.empty() && seq.back() == '\n') {
          seq.pop_back();
        }
        if (!qual.empty() && qual.back() == '\n') {
          qual.pop_back();
        }
        if (flagTrimMasked()) {
          const auto len = seq.length();
          size_t trim_start = 0, trim_end = seq.length();
          while (trim_start <= len && bool(islower(seq[trim_start]))) {
            trim_start++;
          }
          while (trim_end > 0 && bool(islower(seq[trim_end - 1]))) {
            trim_end--;
          }
          seq.erase(trim_end);
          seq.erase(0, trim_start);
          if (!qual.empty()) {
            qual.erase(trim_end);
            qual.erase(0, trim_start);
          }
        }
        if (flagFoldCase()) {
          for (auto& c : seq) {
            char old = c;
            c = CAPITALS[unsigned(c)];
            if (!bool(c)) {
              log_error(
                std::string("A sequence contains invalid IUPAC character: ") +
                old);
              std::exit(EXIT_FAILURE);
            }
          }
        }
        records_reader.data[i].name[0] = '\0';
        records_reader.data[i].comment[0] = '\0';
        records_reader.data[i].seq[0] = '\0';
        records_reader.data[i].qual[0] = '\0';
      }
      records_postprocessor.count = records_reader.count;
      records_postprocessor.current = records_reader.current;
      records_postprocessor.index = records_reader.index;
      if (records_postprocessor.count == 0) {
        postprocessor_queue.write(records_postprocessor);
        break;
      } else {
        postprocessor_queue.write(records_postprocessor);
      }
    }
  });
}

inline SeqReader::Record
SeqReader::read()
{
  if (ready_records.count <= ready_records.current) {
    postprocessor_queue.read(ready_records);
  }
  ready_record = &(ready_records.data[ready_records.current++]);
  if (ready_records.count == 0) {
    close();
  }
  return std::move(*ready_record);
}

} // namespace btllib

#endif