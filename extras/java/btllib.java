/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package btllib;

public class btllib {
  public static SWIGTYPE_p_uint8_t getCp_off() {
    return new SWIGTYPE_p_uint8_t(btllibJNI.cp_off_get(), true);
  }

  public static int getMultishift() {
    return btllibJNI.multishift_get();
  }

  public static SWIGTYPE_p_uint64_t getMultiseed() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.multiseed_get(), true);
  }

  public static SWIGTYPE_p_uint64_t getSeedA() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.seedA_get(), true);
  }

  public static SWIGTYPE_p_uint64_t getSeedC() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.seedC_get(), true);
  }

  public static SWIGTYPE_p_uint64_t getSeedG() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.seedG_get(), true);
  }

  public static SWIGTYPE_p_uint64_t getSeedT() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.seedT_get(), true);
  }

  public static SWIGTYPE_p_uint64_t getSeedN() {
    return new SWIGTYPE_p_uint64_t(btllibJNI.seedN_get(), true);
  }

  public static int getASCII_SIZE() {
    return btllibJNI.ASCII_SIZE_get();
  }

  public static SWIGTYPE_p_uint64_t getSeed_tab() {
    long cPtr = btllibJNI.seed_tab_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getA33r() {
    long cPtr = btllibJNI.A33r_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getA31l() {
    long cPtr = btllibJNI.A31l_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getC33r() {
    long cPtr = btllibJNI.C33r_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getC31l() {
    long cPtr = btllibJNI.C31l_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getG33r() {
    long cPtr = btllibJNI.G33r_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getG31l() {
    long cPtr = btllibJNI.G31l_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getT33r() {
    long cPtr = btllibJNI.T33r_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getT31l() {
    long cPtr = btllibJNI.T31l_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getN33r() {
    long cPtr = btllibJNI.N33r_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t getN31l() {
    long cPtr = btllibJNI.N31l_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_uint64_t(cPtr, false);
  }

  public static void setMs_tab_33r(SWIGTYPE_p_p_uint64_t value) {
    btllibJNI.ms_tab_33r_set(SWIGTYPE_p_p_uint64_t.getCPtr(value));
  }

  public static SWIGTYPE_p_p_uint64_t getMs_tab_33r() {
    long cPtr = btllibJNI.ms_tab_33r_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_uint64_t(cPtr, false);
  }

  public static void setMs_tab_31l(SWIGTYPE_p_p_uint64_t value) {
    btllibJNI.ms_tab_31l_set(SWIGTYPE_p_p_uint64_t.getCPtr(value));
  }

  public static SWIGTYPE_p_p_uint64_t getMs_tab_31l() {
    long cPtr = btllibJNI.ms_tab_31l_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_p_uint64_t(cPtr, false);
  }

  public static SWIGTYPE_p_uint64_t rol1(SWIGTYPE_p_uint64_t v) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.rol1(SWIGTYPE_p_uint64_t.getCPtr(v)), true);
  }

  public static SWIGTYPE_p_uint64_t ror1(SWIGTYPE_p_uint64_t v) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.ror1(SWIGTYPE_p_uint64_t.getCPtr(v)), true);
  }

  public static SWIGTYPE_p_uint64_t rol31(SWIGTYPE_p_uint64_t v, long s) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.rol31(SWIGTYPE_p_uint64_t.getCPtr(v), s), true);
  }

  public static SWIGTYPE_p_uint64_t rol33(SWIGTYPE_p_uint64_t v, long s) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.rol33(SWIGTYPE_p_uint64_t.getCPtr(v), s), true);
  }

  public static SWIGTYPE_p_uint64_t swapbits033(SWIGTYPE_p_uint64_t v) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.swapbits033(SWIGTYPE_p_uint64_t.getCPtr(v)), true);
  }

  public static SWIGTYPE_p_uint64_t swapbits3263(SWIGTYPE_p_uint64_t v) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.swapbits3263(SWIGTYPE_p_uint64_t.getCPtr(v)), true);
  }

  public static SWIGTYPE_p_uint64_t NTF64(String kmer_seq, long k) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTF64__SWIG_0(kmer_seq, k), true);
  }

  public static SWIGTYPE_p_uint64_t NTR64(String kmer_seq, long k) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTR64__SWIG_0(kmer_seq, k), true);
  }

  public static SWIGTYPE_p_uint64_t NTF64(SWIGTYPE_p_uint64_t fh_val, long k, short char_out, short char_in) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTF64__SWIG_1(SWIGTYPE_p_uint64_t.getCPtr(fh_val), k, char_out, char_in), true);
  }

  public static SWIGTYPE_p_uint64_t NTR64(SWIGTYPE_p_uint64_t rh_val, long k, short char_out, short char_in) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTR64__SWIG_1(SWIGTYPE_p_uint64_t.getCPtr(rh_val), k, char_out, char_in), true);
  }

  public static SWIGTYPE_p_uint64_t NTC64(String kmer_seq, long k) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTC64__SWIG_0(kmer_seq, k), true);
  }

  public static SWIGTYPE_p_uint64_t NTC64(String kmer_seq, long k, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTC64__SWIG_1(kmer_seq, k, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val)), true);
  }

  public static SWIGTYPE_p_uint64_t NTC64(short char_out, short char_in, long k, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTC64__SWIG_2(char_out, char_in, k, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val)), true);
  }

  public static SWIGTYPE_p_uint64_t NTF64L(SWIGTYPE_p_uint64_t rh_val, long k, short char_out, short char_in) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTF64L(SWIGTYPE_p_uint64_t.getCPtr(rh_val), k, char_out, char_in), true);
  }

  public static SWIGTYPE_p_uint64_t NTR64L(SWIGTYPE_p_uint64_t fh_val, long k, short char_out, short char_in) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTR64L(SWIGTYPE_p_uint64_t.getCPtr(fh_val), k, char_out, char_in), true);
  }

  public static SWIGTYPE_p_uint64_t NTC64L(short char_out, short char_in, long k, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTC64L(char_out, char_in, k, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val)), true);
  }

  public static SWIGTYPE_p_uint64_t NTF64(String kmer_seq, long k, long seed) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTF64__SWIG_2(kmer_seq, k, seed), true);
  }

  public static SWIGTYPE_p_uint64_t NTC64(String kmer_seq, long k, long seed) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTC64__SWIG_3(kmer_seq, k, seed), true);
  }

  public static void NTM64(String kmer_seq, long k, long m, SWIGTYPE_p_uint64_t h_val) {
    btllibJNI.NTM64__SWIG_0(kmer_seq, k, m, SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static SWIGTYPE_p_uint64_t NTE64(SWIGTYPE_p_uint64_t h_val, long k, long i) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTE64(SWIGTYPE_p_uint64_t.getCPtr(h_val), k, i), true);
  }

  public static void NTM64(short char_out, short char_in, long k, long m, SWIGTYPE_p_uint64_t h_val) {
    btllibJNI.NTM64__SWIG_1(char_out, char_in, k, m, SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static void NTMC64(String kmer_seq, long k, long m, SWIGTYPE_p_uint64_t h_val) {
    btllibJNI.NTMC64__SWIG_0(kmer_seq, k, m, SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static void NTMC64(String kmer_seq, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_uint64_t h_val) {
    btllibJNI.NTMC64__SWIG_1(kmer_seq, k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static void NTMC64(short char_out, short char_in, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_uint64_t h_val) {
    btllibJNI.NTMC64__SWIG_2(char_out, char_in, k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static boolean NTC64(String kmer_seq, long k, SWIGTYPE_p_uint64_t h_val, SWIGTYPE_p_unsigned_int locN) {
    return btllibJNI.NTC64__SWIG_4(kmer_seq, k, SWIGTYPE_p_uint64_t.getCPtr(h_val), SWIGTYPE_p_unsigned_int.getCPtr(locN));
  }

  public static boolean NTMC64(String kmer_seq, long k, long m, SWIGTYPE_p_unsigned_int locN, SWIGTYPE_p_uint64_t h_val) {
    return btllibJNI.NTMC64__SWIG_3(kmer_seq, k, m, SWIGTYPE_p_unsigned_int.getCPtr(locN), SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static boolean NTC64(String kmer_seq, long k, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_uint64_t h_val, SWIGTYPE_p_unsigned_int locN) {
    return btllibJNI.NTC64__SWIG_5(kmer_seq, k, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_uint64_t.getCPtr(h_val), SWIGTYPE_p_unsigned_int.getCPtr(locN));
  }

  public static boolean NTMC64(String kmer_seq, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_unsigned_int locN, SWIGTYPE_p_uint64_t h_val) {
    return btllibJNI.NTMC64__SWIG_4(kmer_seq, k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_unsigned_int.getCPtr(locN), SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static boolean NTMC64(String kmer_seq, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_unsigned_int locN, SWIGTYPE_p_uint64_t h_val, SWIGTYPE_p_bool hStn) {
    return btllibJNI.NTMC64__SWIG_5(kmer_seq, k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_unsigned_int.getCPtr(locN), SWIGTYPE_p_uint64_t.getCPtr(h_val), SWIGTYPE_p_bool.getCPtr(hStn));
  }

  public static void NTMC64(short char_out, short char_in, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_uint64_t h_val, SWIGTYPE_p_bool hStn) {
    btllibJNI.NTMC64__SWIG_6(char_out, char_in, k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_uint64_t.getCPtr(h_val), SWIGTYPE_p_bool.getCPtr(hStn));
  }

  public static SWIGTYPE_p_uint64_t maskHash(SWIGTYPE_p_uint64_t fk_val, SWIGTYPE_p_uint64_t rk_val, String seed_seq, String kmer_seq, long k) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.maskHash(SWIGTYPE_p_uint64_t.getCPtr(fk_val), SWIGTYPE_p_uint64_t.getCPtr(rk_val), seed_seq, kmer_seq, k), true);
  }

  public static SWIGTYPE_p_uint64_t NTS64(String kmer_seq, SWIGTYPE_p_std__vectorT_bool_t seed, long k, SWIGTYPE_p_uint64_t h_val) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTS64__SWIG_0(kmer_seq, SWIGTYPE_p_std__vectorT_bool_t.getCPtr(seed), k, SWIGTYPE_p_uint64_t.getCPtr(h_val)), true);
  }

  public static SWIGTYPE_p_uint64_t NTS64(String kmer_seq, SWIGTYPE_p_std__vectorT_bool_t seed, short char_out, short char_in, long k, SWIGTYPE_p_uint64_t h_val) {
    return new SWIGTYPE_p_uint64_t(btllibJNI.NTS64__SWIG_1(kmer_seq, SWIGTYPE_p_std__vectorT_bool_t.getCPtr(seed), char_out, char_in, k, SWIGTYPE_p_uint64_t.getCPtr(h_val)), true);
  }

  public static boolean NTMS64(String kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t seed_seq, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_unsigned_int locN, SWIGTYPE_p_uint64_t h_val, SWIGTYPE_p_bool hStn) {
    return btllibJNI.NTMS64__SWIG_0(kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t.getCPtr(seed_seq), k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_unsigned_int.getCPtr(locN), SWIGTYPE_p_uint64_t.getCPtr(h_val), SWIGTYPE_p_bool.getCPtr(hStn));
  }

  public static void NTMS64(String kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t seed_seq, short char_out, short char_in, long k, long m, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_uint64_t h_val, SWIGTYPE_p_bool hStn) {
    btllibJNI.NTMS64__SWIG_1(kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t.getCPtr(seed_seq), char_out, char_in, k, m, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_uint64_t.getCPtr(h_val), SWIGTYPE_p_bool.getCPtr(hStn));
  }

  public static boolean NTMSM64(String kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t seed_seq, long k, long m, long m2, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_unsigned_int locN, SWIGTYPE_p_uint64_t h_val) {
    return btllibJNI.NTMSM64__SWIG_0(kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t.getCPtr(seed_seq), k, m, m2, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_unsigned_int.getCPtr(locN), SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static void NTMSM64(String kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t seed_seq, short char_out, short char_in, long k, long m, long m2, SWIGTYPE_p_uint64_t fh_val, SWIGTYPE_p_uint64_t rh_val, SWIGTYPE_p_uint64_t h_val) {
    btllibJNI.NTMSM64__SWIG_1(kmer_seq, SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t.getCPtr(seed_seq), char_out, char_in, k, m, m2, SWIGTYPE_p_uint64_t.getCPtr(fh_val), SWIGTYPE_p_uint64_t.getCPtr(rh_val), SWIGTYPE_p_uint64_t.getCPtr(h_val));
  }

  public static SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t parse_seeds(SWIGTYPE_p_std__vectorT_std__string_t seed_strings) {
    return new SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_int_t_t(btllibJNI.parse_seeds(SWIGTYPE_p_std__vectorT_std__string_t.getCPtr(seed_strings)), true);
  }

  public static SWIGTYPE_p_std__vectorT_std__string_t split(String s, String delim) {
    return new SWIGTYPE_p_std__vectorT_std__string_t(btllibJNI.split(s, delim), true);
  }

  public static void ltrim(SWIGTYPE_p_std__string s) {
    btllibJNI.ltrim(SWIGTYPE_p_std__string.getCPtr(s));
  }

  public static void rtrim(SWIGTYPE_p_std__string s) {
    btllibJNI.rtrim(SWIGTYPE_p_std__string.getCPtr(s));
  }

  public static void trim(SWIGTYPE_p_std__string s) {
    btllibJNI.trim(SWIGTYPE_p_std__string.getCPtr(s));
  }

  public static boolean starts_with(String s, String prefix) {
    return btllibJNI.starts_with(s, prefix);
  }

  public static boolean ends_with(String s, String suffix) {
    return btllibJNI.ends_with(s, suffix);
  }

  public static String get_saveload_cmd(String path, SaveloadOp op) {
    return btllibJNI.get_saveload_cmd(path, op.swigValue());
  }

  public static _Pipeline run_saveload_cmd(String cmd, SaveloadOp op) {
    return new _Pipeline(btllibJNI.run_saveload_cmd(cmd, op.swigValue()), true);
  }

  public static void sigchld_handler(int sig) {
    btllibJNI.sigchld_handler(sig);
  }

  public static boolean data_saveload_init() {
    return btllibJNI.data_saveload_init();
  }

  public static boolean getData_saveload_initialized() {
    return btllibJNI.data_saveload_initialized_get();
  }

  public static String get_time() {
    return btllibJNI.get_time();
  }

  public static void log_info(String msg) {
    btllibJNI.log_info(msg);
  }

  public static void log_warning(String msg) {
    btllibJNI.log_warning(msg);
  }

  public static void log_error(String msg) {
    btllibJNI.log_error(msg);
  }

  public static void check_error(boolean condition, String msg) {
    btllibJNI.check_error(condition, msg);
  }

  public static void check_warning(boolean condition, String msg) {
    btllibJNI.check_warning(condition, msg);
  }

  public static void check_stream(SWIGTYPE_p_std__ios stream, String name) {
    btllibJNI.check_stream(SWIGTYPE_p_std__ios.getCPtr(stream), name);
  }

  public static String getCOMPLEMENTS() {
    return btllibJNI.COMPLEMENTS_get();
  }

  public static String getCAPITALS() {
    return btllibJNI.CAPITALS_get();
  }

  public static long getBITS_IN_BYTE() {
    return btllibJNI.BITS_IN_BYTE_get();
  }

  public static SWIGTYPE_p_unsigned_char getBIT_MASKS() {
    long cPtr = btllibJNI.BIT_MASKS_get();
    return (cPtr == 0) ? null : new SWIGTYPE_p_unsigned_char(cPtr, false);
  }

  public static long pop_cnt_byte(short x) {
    return btllibJNI.pop_cnt_byte(x);
  }

}
