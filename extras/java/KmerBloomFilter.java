/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package btllib;

public class KmerBloomFilter extends BloomFilter {
  private transient long swigCPtr;

  protected KmerBloomFilter(long cPtr, boolean cMemoryOwn) {
    super(btllibJNI.KmerBloomFilter_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(KmerBloomFilter obj) {
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
        btllibJNI.delete_KmerBloomFilter(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public KmerBloomFilter() {
    this(btllibJNI.new_KmerBloomFilter__SWIG_0(), true);
  }

  public KmerBloomFilter(long bytes, long hash_num, long k) {
    this(btllibJNI.new_KmerBloomFilter__SWIG_1(bytes, hash_num, k), true);
  }

  public KmerBloomFilter(String path) {
    this(btllibJNI.new_KmerBloomFilter__SWIG_2(path), true);
  }

  public void insert(String seq, long seq_len) {
    btllibJNI.KmerBloomFilter_insert__SWIG_0(swigCPtr, this, seq, seq_len);
  }

  public void insert(String seq) {
    btllibJNI.KmerBloomFilter_insert__SWIG_1(swigCPtr, this, seq);
  }

  public long contains(String seq, long seq_len) {
    return btllibJNI.KmerBloomFilter_contains__SWIG_0(swigCPtr, this, seq, seq_len);
  }

  public long contains(String seq) {
    return btllibJNI.KmerBloomFilter_contains__SWIG_1(swigCPtr, this, seq);
  }

  public long get_k() {
    return btllibJNI.KmerBloomFilter_get_k(swigCPtr, this);
  }

  public void write(String path) {
    btllibJNI.KmerBloomFilter_write(swigCPtr, this, path);
  }

}
