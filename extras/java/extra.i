%ignore btllib::KmerSet::insert(const char*);
%ignore btllib::KmerSet::contains(const char*);

%ignore btllib::CountingKmerSet::insert(const char*);
%ignore btllib::CountingKmerSet::count(const char*);

%ignore btllib::DataSource::operator FILE*();
%ignore btllib::DataSink::operator FILE*();

%ignore btllib::SeqReader::Record::operator bool;

%ignore btllib::SeqReader::read_fasta_buffer::operator();
%ignore btllib::SeqReader::read_fasta_transition::operator();
%ignore btllib::SeqReader::read_fasta_file::operator();

%ignore btllib::SeqReader::read_fastq_buffer::operator();
%ignore btllib::SeqReader::read_fastq_transition::operator();
%ignore btllib::SeqReader::read_fastq_file::operator();

%ignore btllib::SeqReader::read_sam_buffer::operator();
%ignore btllib::SeqReader::read_sam_transition::operator();
%ignore btllib::SeqReader::read_sam_file::operator();

%ignore btllib::SeqReader::read_gfa2_buffer::operator();
%ignore btllib::SeqReader::read_gfa2_transition::operator();
%ignore btllib::SeqReader::read_gfa2_file::operator();

%ignore btllib::BLOOM_FILTER_MAGIC_HEADER;
%ignore btllib::COUNTING_BLOOM_FILTER_MAGIC_HEADER;