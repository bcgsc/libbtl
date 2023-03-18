#include "btllib/status.hpp"
#include "btllib/seq_reader.hpp"
#include "btllib/nthash.hpp" //parse_seeds
#include <omp.h>
#include "btllib/mi_bloom_filter.hpp"
#include <getopt.h>

#include <string>
#include <vector>

const static std::string PROGNAME = "mi_bloom_filter";
const static std::string VERSION = "1.0";
const static size_t MAX_THREADS = 32;
const static size_t DEFAULT_THREADS = 5;

typedef uint16_t ID_type;

using SpacedSeed = std::vector<unsigned>;

static void
print_error_msg(const std::string& msg)
{
  std::cerr << PROGNAME << ' ' << VERSION << ": " << msg << std::endl;
}

static void
print_usage()
{
  std::cerr << "Usage: " << PROGNAME
	<< "-p MIBF_ID [OPTION]... [FILE]"
		"  -p file_prefix     filter prefix and filter ID. Required option.\n"
		"  -k kmer_size       k-mer size.\n"
		"  -g hash_num        hash number.\n"
		"  -s spaced_seeds    expects list of seed 1s & 0s separated by spaces.\n"
		"		      required if '-k' and '-g' are not given.\n"
		"  -m mi_bf_size      output mi_bf bit vector size in bits. Default is 10^9.\n"
		"  -b occupancy       occupancy of Bloom filter. Used if '-m' not given. Default is 0.5.\n"
		"  -n number_of_elems the number of expected distinct k-mer frames. Used if '-m' not given. By default counts total k-mers in input files.\n"
		"		      by default determined from sequences within files.\n"
		"  -f by_file         assign IDs by file rather than by fasta header.\n"
		"  -t threads         number of threads (default 5, max 32)\n"
		"  -v verbose         show verbose output.\n"
		"  --help             display this help and exit.\n"
		"  --version          display version and exit.\n"
		"  FILE               space separated list of FASTA/Q files."    
	<< std::endl;
}

static std::vector<std::string>
split_string_by_space(const std::string &input_string)
{
	std::vector<std::string> current_string;
	std::string temp;
	std::stringstream converter(input_string);
	while (converter >> temp) {
		current_string.push_back(temp);
	}
	assert(current_string.size() > 0);
	return current_string;
}

static unsigned
assert_ID_size_and_count_kmers(const std::vector<std::string>& read_paths, const bool& by_file, const unsigned& kmer_size){
	unsigned total_id = 0;
	unsigned expected_elements = 0;

	for(auto& read_path : read_paths){
		std::cout << read_path << std::endl;
		btllib::SeqReader reader(read_path, btllib::SeqReader::Flag::SHORT_MODE);
		for (const auto record : reader) {
                        if(!by_file){
                                total_id++;
                        }
		}
		
	}

 
	for(auto& read_path : read_paths){
		btllib::SeqReader reader(read_path, btllib::SeqReader::Flag::SHORT_MODE, 6);
		if(by_file){
			total_id++;
		}
		for (const auto record : reader) {	
			if(!by_file){
                               	total_id++;
			}
			expected_elements += record.seq.size() > kmer_size ? record.seq.size() - kmer_size : 0;
		}
	}
	btllib::check_error(!(total_id < static_cast<unsigned>(std::numeric_limits<ID_type>::max())),
		"Total ID number overflows ID type.");
	return expected_elements;
}

template<typename T>
inline void insert_to_bv(btllib::MIBloomFilter<ID_type>& mi_bf, T& nthash, int& mi_bf_stage, ID_type& ID){
	while (nthash.roll()) {
		if(mi_bf_stage == 0){
			mi_bf.insert_bv(nthash.hashes());
		} else if(mi_bf_stage == 1){
			mi_bf.insert_id(nthash.hashes(), ID);
		} else if(mi_bf_stage == 2){
			mi_bf.insert_saturation(nthash.hashes(), ID);
        	}
	}
}

int
main(int argc, char* argv[])
{
  try {
    int c;
    bool failed = false;
    int optindex = 0;
    int help = 0, version = 0;
    bool verbose = false;
    int mi_bf_size = 1000000000;
    double occupancy = 0.5;
    unsigned kmer_size = 0, hash_num = 0, expected_elements = 0, thread_count = DEFAULT_THREADS;

    bool spaced_seed_set = false;
    bool output_path_set = false;
    bool by_file = false;

    std::string output_path;
    
    std::vector<std::string> spaced_seeds_string;
    std::vector<SpacedSeed> spaced_seeds;

    static const struct option longopts[] = {
      { "help", no_argument, &help, 1 },
      { "version", no_argument, &version, 1 },
      { nullptr, 0, nullptr, 0 }
    };

    std::cout << "here 1" << std::endl;

    while ((c = getopt_long(argc, // NOLINT(concurrency-mt-unsafe)
                            argv,
                            "p:k:g:s:m:n:b:ft:v",
                            longopts,
                            &optindex)) != -1) {
      switch (c) {
        case 0:
          break;
        case 'p':
          output_path = optarg;
          output_path_set = true;
          break;
	case 'k':
          kmer_size = std::stoul(optarg);
          break;
        case 'g':
          hash_num = std::stoul(optarg);
          break;
        case 's':
	  spaced_seed_set = true;
	  spaced_seeds_string = split_string_by_space(optarg);
	  spaced_seeds = btllib::parse_seeds(spaced_seeds_string);
          hash_num = spaced_seeds.size();
	  kmer_size = spaced_seeds_string[0].size();
	  break;
        case 'b':
	  occupancy = std::stod(optarg);
	  break;
	case 'f':
	  by_file = true;
	  break;
        case 'm':
          mi_bf_size = std::stoul(optarg);
          break;
	case 'n':
	  expected_elements = std::stoul(optarg);
	  break;
        case 't':
          thread_count = std::stoul(optarg);
          break;
        case 'v':
          verbose = true;
          break;
        default:
          std::exit(EXIT_FAILURE); // NOLINT(concurrency-mt-unsafe)
      }
    }
    if (kmer_size == 0) {
      print_error_msg("missing option -- 'k'");
      failed = true;
    }
    if (!failed && hash_num == 0) {
      print_error_msg("missing option -- 'h'");
      failed = true;
    }
    if (!failed && !output_path_set) {
      print_error_msg("missing option -- 'p'");
      failed = true;
    }
    if(verbose){std::cout << "verbose" << std::endl;}

    std::vector<std::string> read_paths(&argv[optind], &argv[argc]);
    if (argc < 2 || failed) {
      print_usage();
      std::exit(EXIT_FAILURE); // NOLINT(concurrency-mt-unsafe)
    }
    expected_elements = occupancy;
    occupancy = expected_elements;
    std::map<std::string, ID_type> read_IDs;
    unsigned kmer_count = assert_ID_size_and_count_kmers(read_paths, by_file, kmer_size);
    
    btllib::SeqReader reader_1(read_paths[0], btllib::SeqReader::Flag::LONG_MODE);

    if(expected_elements > 0){
	mi_bf_size = btllib::MIBloomFilter<ID_type>::calc_optimal_size(kmer_count, hash_num, occupancy);
   	btllib::log_info("Optimal size is calculated: " + std::to_string(mi_bf_size));
    }
  
    //set thread number configuration
#if defined(_OPENMP)
	if (thread_count > 0)
	omp_set_num_threads(thread_count);
#endif

    btllib::MIBloomFilter<ID_type>mi_bf(mi_bf_size, hash_num);
    const char* stages[3] = {"BV Insertion", "ID Insertion", "Saturation"};
    ID_type ID_counter = 0;
    for(int mi_bf_stage = 0; mi_bf_stage < 2; mi_bf_stage++){
		btllib::log_info(stages[mi_bf_stage] + std::string(" stage started"));
		
		for(auto& read_path : read_paths){
			btllib::SeqReader reader(read_path, btllib::SeqReader::Flag::SHORT_MODE, 6);

			for (const auto record : reader) {
				if(spaced_seed_set){
					btllib::SeedNtHash nthash(record.seq, spaced_seeds, 1, kmer_size);
        	       	                insert_to_bv<btllib::SeedNtHash>(mi_bf, nthash, mi_bf_stage, ID_counter);
				} else {
					btllib::NtHash nthash(record.seq, hash_num, kmer_size);
        	       	                insert_to_bv<btllib::NtHash>(mi_bf, nthash, mi_bf_stage, ID_counter);
				}
				if(!by_file){
					ID_counter++;
				}
			}
			if(by_file){
				ID_counter++;
			}
		}
		if(mi_bf_stage == 0){ mi_bf.complete_bv_insertion();}
   }
	mi_bf.save(output_path);
   }    
   catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    std::exit(EXIT_FAILURE); // NOLINT(concurrency-mt-unsafe)
   }

}
