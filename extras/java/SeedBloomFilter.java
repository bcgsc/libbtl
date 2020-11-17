/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package btllib;

public class SeedBloomFilter {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected SeedBloomFilter(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SeedBloomFilter obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        btllibJNI.delete_SeedBloomFilter(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public SeedBloomFilter() {
    this(btllibJNI.new_SeedBloomFilter__SWIG_0(), true);
  }

  public SeedBloomFilter(long bytes, long k, SWIGTYPE_p_std__vectorT_std__string_t seeds, long hash_num_per_seed) {
    this(btllibJNI.new_SeedBloomFilter__SWIG_1(bytes, k, SWIGTYPE_p_std__vectorT_std__string_t.getCPtr(seeds), hash_num_per_seed), true);
  }

  public SeedBloomFilter(String path) {
    this(btllibJNI.new_SeedBloomFilter__SWIG_2(path), true);
  }

  public void insert(String seq, long seq_len) {
    btllibJNI.SeedBloomFilter_insert__SWIG_0(swigCPtr, this, seq, seq_len);
  }

  public void insert(String seq) {
    btllibJNI.SeedBloomFilter_insert__SWIG_1(swigCPtr, this, seq);
  }

  public SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t contains(String seq, long seq_len) {
    return new SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t(btllibJNI.SeedBloomFilter_contains__SWIG_0(swigCPtr, this, seq, seq_len), true);
  }

  public SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t contains(String seq) {
    return new SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t(btllibJNI.SeedBloomFilter_contains__SWIG_1(swigCPtr, this, seq), true);
  }

  public boolean contains(SWIGTYPE_p_uint64_t hashes) {
    return btllibJNI.SeedBloomFilter_contains__SWIG_2(swigCPtr, this, SWIGTYPE_p_uint64_t.getCPtr(hashes));
  }

  public boolean contains(SWIGTYPE_p_std__vectorT_uint64_t_t hashes) {
    return btllibJNI.SeedBloomFilter_contains__SWIG_3(swigCPtr, this, SWIGTYPE_p_std__vectorT_uint64_t_t.getCPtr(hashes));
  }

  public long get_bytes() {
    return btllibJNI.SeedBloomFilter_get_bytes(swigCPtr, this);
  }

  public SWIGTYPE_p_uint64_t get_pop_cnt() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.SeedBloomFilter_get_pop_cnt(swigCPtr, this), true);
  }

  public double get_occupancy() {
    return btllibJNI.SeedBloomFilter_get_occupancy(swigCPtr, this);
  }

  public long get_hash_num() {
    return btllibJNI.SeedBloomFilter_get_hash_num(swigCPtr, this);
  }

  public double get_fpr() {
    return btllibJNI.SeedBloomFilter_get_fpr(swigCPtr, this);
  }

  public long get_k() {
    return btllibJNI.SeedBloomFilter_get_k(swigCPtr, this);
  }

  public SWIGTYPE_p_std__vectorT_std__string_t get_seeds() {
    return new SWIGTYPE_p_std__vectorT_std__string_t(btllibJNI.SeedBloomFilter_get_seeds(swigCPtr, this), false);
  }

  public SWIGTYPE_p_std__vectorT_SpacedSeed_t get_parsed_seeds() {
    return new SWIGTYPE_p_std__vectorT_SpacedSeed_t(btllibJNI.SeedBloomFilter_get_parsed_seeds(swigCPtr, this), false);
  }

  public long get_hash_num_per_seed() {
    return btllibJNI.SeedBloomFilter_get_hash_num_per_seed(swigCPtr, this);
  }

  public KmerBloomFilter get_kmer_bloom_filter() {
    return new KmerBloomFilter(btllibJNI.SeedBloomFilter_get_kmer_bloom_filter(swigCPtr, this), false);
  }

  public void write(String path) {
    btllibJNI.SeedBloomFilter_write(swigCPtr, this, path);
  }

}
