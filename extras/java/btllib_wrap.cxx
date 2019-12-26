/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */


#ifndef SWIGJAVA
#define SWIGJAVA
#endif



#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1,
  SWIG_JavaIOException,
  SWIG_JavaRuntimeException,
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError,
  SWIG_JavaIllegalStateException,
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { SWIG_JavaIllegalStateException, "java/lang/IllegalStateException" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "btllib/seq_reader.hpp"
#include "btllib/graph.hpp"
#include "btllib/util.hpp"
#include "btllib/data_saveload.hpp"
#include "btllib/status.hpp"
#include "btllib/seq.hpp"


#include <string>


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jint JNICALL Java_btllibJNI_SeqReader_1FOLD_1CASE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  btllib::SeqReader::Flag result;
  
  (void)jenv;
  (void)jcls;
  result = (btllib::SeqReader::Flag)btllib::SeqReader::FOLD_CASE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_btllibJNI_SeqReader_1NO_1FOLD_1CASE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  btllib::SeqReader::Flag result;
  
  (void)jenv;
  (void)jcls;
  result = (btllib::SeqReader::Flag)btllib::SeqReader::NO_FOLD_CASE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_btllibJNI_SeqReader_1NO_1TRIM_1MASKED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  btllib::SeqReader::Flag result;
  
  (void)jenv;
  (void)jcls;
  result = (btllib::SeqReader::Flag)btllib::SeqReader::NO_TRIM_MASKED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_btllibJNI_SeqReader_1TRIM_1MASKED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  btllib::SeqReader::Flag result;
  
  (void)jenv;
  (void)jcls;
  result = (btllib::SeqReader::Flag)btllib::SeqReader::TRIM_MASKED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_new_1SeqReader_1_1SWIG_10(JNIEnv *jenv, jclass jcls, jstring jarg1, jint jarg2) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  int arg2 ;
  btllib::SeqReader *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  arg2 = (int)jarg2; 
  result = (btllib::SeqReader *)new btllib::SeqReader((char const *)arg1,arg2);
  *(btllib::SeqReader **)&jresult = result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_new_1SeqReader_1_1SWIG_11(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  btllib::SeqReader *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  result = (btllib::SeqReader *)new btllib::SeqReader((char const *)arg1);
  *(btllib::SeqReader **)&jresult = result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_SeqReader_1flagFoldCase(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (bool)((btllib::SeqReader const *)arg1)->flagFoldCase();
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_SeqReader_1flagTrimMasked(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (bool)((btllib::SeqReader const *)arg1)->flagTrimMasked();
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_btllibJNI_SeqReader_1get_1format(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  btllib::SeqReader::Format result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (btllib::SeqReader::Format)((btllib::SeqReader const *)arg1)->get_format();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_btllibJNI_SeqReader_1peek(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (int)(arg1)->peek();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_SeqReader_1read(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (bool)(arg1)->read();
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_SeqReader_1name(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (arg1)->name();
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_SeqReader_1comment(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (arg1)->comment();
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_SeqReader_1seq(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (arg1)->seq();
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_SeqReader_1qual(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  result = (arg1)->qual();
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_delete_1SeqReader(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  btllib::SeqReader *arg1 = (btllib::SeqReader *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(btllib::SeqReader **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_btllibJNI_delete_1Vertex(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  btllib::Vertex *arg1 = (btllib::Vertex *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(btllib::Vertex **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_btllibJNI_delete_1Edge(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  btllib::Edge *arg1 = (btllib::Edge *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(btllib::Edge **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_new_1Graph(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  btllib::Graph *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (btllib::Graph *)new btllib::Graph();
  *(btllib::Graph **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_Graph_1add_1vertex(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  btllib::Graph *arg1 = (btllib::Graph *) 0 ;
  SwigValueWrapper< btllib::Vertex > result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::Graph **)&jarg1; 
  result = (arg1)->add_vertex();
  *(btllib::Vertex **)&jresult = new btllib::Vertex((const btllib::Vertex &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_Graph_1remove_1vertex(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  btllib::Graph *arg1 = (btllib::Graph *) 0 ;
  SwigValueWrapper< btllib::Vertex > arg2 ;
  btllib::Vertex *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(btllib::Graph **)&jarg1; 
  argp2 = *(btllib::Vertex **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null btllib::Vertex");
    return ;
  }
  arg2 = *argp2; 
  (arg1)->remove_vertex(arg2);
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_Graph_1add_1edge(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_) {
  jlong jresult = 0 ;
  btllib::Graph *arg1 = (btllib::Graph *) 0 ;
  SwigValueWrapper< btllib::Vertex > arg2 ;
  SwigValueWrapper< btllib::Vertex > arg3 ;
  btllib::Vertex *argp2 ;
  btllib::Vertex *argp3 ;
  SwigValueWrapper< btllib::Edge > result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = *(btllib::Graph **)&jarg1; 
  argp2 = *(btllib::Vertex **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null btllib::Vertex");
    return 0;
  }
  arg2 = *argp2; 
  argp3 = *(btllib::Vertex **)&jarg3; 
  if (!argp3) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null btllib::Vertex");
    return 0;
  }
  arg3 = *argp3; 
  result = (arg1)->add_edge(arg2,arg3);
  *(btllib::Edge **)&jresult = new btllib::Edge((const btllib::Edge &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_Graph_1remove_1edge(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  btllib::Graph *arg1 = (btllib::Graph *) 0 ;
  SwigValueWrapper< btllib::Edge > arg2 ;
  btllib::Edge *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(btllib::Graph **)&jarg1; 
  argp2 = *(btllib::Edge **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null btllib::Edge");
    return ;
  }
  arg2 = *argp2; 
  (arg1)->remove_edge(arg2);
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_Graph_1to_1string(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  btllib::Graph *arg1 = (btllib::Graph *) 0 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(btllib::Graph **)&jarg1; 
  result = (arg1)->to_string();
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_delete_1Graph(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  btllib::Graph *arg1 = (btllib::Graph *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(btllib::Graph **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_split(JNIEnv *jenv, jclass jcls, jstring jarg1, jstring jarg2) {
  jlong jresult = 0 ;
  std::string *arg1 = 0 ;
  std::string *arg2 = 0 ;
  SwigValueWrapper< std::vector< std::string > > result;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  if(!jarg2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  }
  const char *arg2_pstr = (const char *)jenv->GetStringUTFChars(jarg2, 0); 
  if (!arg2_pstr) return 0;
  std::string arg2_str(arg2_pstr);
  arg2 = &arg2_str;
  jenv->ReleaseStringUTFChars(jarg2, arg2_pstr); 
  result = btllib::split((std::string const &)*arg1,(std::string const &)*arg2);
  *(std::vector< std::string > **)&jresult = new std::vector< std::string >((const std::vector< std::string > &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_ltrim(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  std::string *arg1 = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(std::string **)&jarg1;
  if (!arg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "std::string & reference is null");
    return ;
  } 
  btllib::ltrim(*arg1);
}


SWIGEXPORT void JNICALL Java_btllibJNI_rtrim(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  std::string *arg1 = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(std::string **)&jarg1;
  if (!arg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "std::string & reference is null");
    return ;
  } 
  btllib::rtrim(*arg1);
}


SWIGEXPORT void JNICALL Java_btllibJNI_trim(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  std::string *arg1 = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(std::string **)&jarg1;
  if (!arg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "std::string & reference is null");
    return ;
  } 
  btllib::trim(*arg1);
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_starts_1with(JNIEnv *jenv, jclass jcls, jstring jarg1, jstring jarg2) {
  jboolean jresult = 0 ;
  std::string arg1 ;
  std::string arg2 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  } 
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  (&arg1)->assign(arg1_pstr);
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  if(!jarg2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  } 
  const char *arg2_pstr = (const char *)jenv->GetStringUTFChars(jarg2, 0); 
  if (!arg2_pstr) return 0;
  (&arg2)->assign(arg2_pstr);
  jenv->ReleaseStringUTFChars(jarg2, arg2_pstr); 
  result = (bool)btllib::starts_with(arg1,arg2);
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_ends_1with(JNIEnv *jenv, jclass jcls, jstring jarg1, jstring jarg2) {
  jboolean jresult = 0 ;
  std::string arg1 ;
  std::string arg2 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  } 
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  (&arg1)->assign(arg1_pstr);
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  if(!jarg2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  } 
  const char *arg2_pstr = (const char *)jenv->GetStringUTFChars(jarg2, 0); 
  if (!arg2_pstr) return 0;
  (&arg2)->assign(arg2_pstr);
  jenv->ReleaseStringUTFChars(jarg2, arg2_pstr); 
  result = (bool)btllib::ends_with(arg1,arg2);
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_data_1load(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jlong jresult = 0 ;
  std::string *arg1 = 0 ;
  FILE *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  result = (FILE *)btllib::data_load((std::string const &)*arg1);
  *(FILE **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_data_1save(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jlong jresult = 0 ;
  std::string *arg1 = 0 ;
  FILE *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  result = (FILE *)btllib::data_save((std::string const &)*arg1);
  *(FILE **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_sigchld_1handler(JNIEnv *jenv, jclass jcls, jint jarg1) {
  int arg1 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  btllib::sigchld_handler(arg1);
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_data_1saveload_1init(JNIEnv *jenv, jclass jcls) {
  jboolean jresult = 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  result = (bool)btllib::data_saveload_init();
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_btllibJNI_data_1saveload_1initialized_1get(JNIEnv *jenv, jclass jcls) {
  jboolean jresult = 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  result = (bool)(bool)btllib::data_saveload_initialized;
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_get_1saveload_1cmd(JNIEnv *jenv, jclass jcls, jstring jarg1, jboolean jarg2) {
  jstring jresult = 0 ;
  std::string *arg1 = 0 ;
  bool arg2 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  arg2 = jarg2 ? true : false; 
  result = btllib::get_saveload_cmd((std::string const &)*arg1,arg2);
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_btllibJNI_run_1saveload_1cmd(JNIEnv *jenv, jclass jcls, jstring jarg1, jboolean jarg2) {
  jlong jresult = 0 ;
  std::string *arg1 = 0 ;
  bool arg2 ;
  FILE *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return 0;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return 0;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  arg2 = jarg2 ? true : false; 
  result = (FILE *)btllib::run_saveload_cmd((std::string const &)*arg1,arg2);
  *(FILE **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_get_1time(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  std::string result;
  
  (void)jenv;
  (void)jcls;
  result = btllib::get_time();
  jresult = jenv->NewStringUTF((&result)->c_str()); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_btllibJNI_log_1info(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  std::string *arg1 = 0 ;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return ;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return ;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  btllib::log_info((std::string const &)*arg1);
}


SWIGEXPORT void JNICALL Java_btllibJNI_log_1warning(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  std::string *arg1 = 0 ;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return ;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return ;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  btllib::log_warning((std::string const &)*arg1);
}


SWIGEXPORT void JNICALL Java_btllibJNI_log_1error(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  std::string *arg1 = 0 ;
  
  (void)jenv;
  (void)jcls;
  if(!jarg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return ;
  }
  const char *arg1_pstr = (const char *)jenv->GetStringUTFChars(jarg1, 0); 
  if (!arg1_pstr) return ;
  std::string arg1_str(arg1_pstr);
  arg1 = &arg1_str;
  jenv->ReleaseStringUTFChars(jarg1, arg1_pstr); 
  btllib::log_error((std::string const &)*arg1);
}


SWIGEXPORT void JNICALL Java_btllibJNI_check_1error(JNIEnv *jenv, jclass jcls, jboolean jarg1, jstring jarg2) {
  bool arg1 ;
  std::string *arg2 = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = jarg1 ? true : false; 
  if(!jarg2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return ;
  }
  const char *arg2_pstr = (const char *)jenv->GetStringUTFChars(jarg2, 0); 
  if (!arg2_pstr) return ;
  std::string arg2_str(arg2_pstr);
  arg2 = &arg2_str;
  jenv->ReleaseStringUTFChars(jarg2, arg2_pstr); 
  btllib::check_error(arg1,(std::string const &)*arg2);
}


SWIGEXPORT void JNICALL Java_btllibJNI_check_1warning(JNIEnv *jenv, jclass jcls, jboolean jarg1, jstring jarg2) {
  bool arg1 ;
  std::string *arg2 = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = jarg1 ? true : false; 
  if(!jarg2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return ;
  }
  const char *arg2_pstr = (const char *)jenv->GetStringUTFChars(jarg2, 0); 
  if (!arg2_pstr) return ;
  std::string arg2_str(arg2_pstr);
  arg2 = &arg2_str;
  jenv->ReleaseStringUTFChars(jarg2, arg2_pstr); 
  btllib::check_warning(arg1,(std::string const &)*arg2);
}


SWIGEXPORT void JNICALL Java_btllibJNI_check_1stream(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
  std::ios *arg1 = 0 ;
  std::string *arg2 = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(std::ios **)&jarg1;
  if (!arg1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "std::ios const & reference is null");
    return ;
  } 
  if(!jarg2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null string");
    return ;
  }
  const char *arg2_pstr = (const char *)jenv->GetStringUTFChars(jarg2, 0); 
  if (!arg2_pstr) return ;
  std::string arg2_str(arg2_pstr);
  arg2 = &arg2_str;
  jenv->ReleaseStringUTFChars(jarg2, arg2_pstr); 
  btllib::check_stream((std::ios const &)*arg1,(std::string const &)*arg2);
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_COMPLEMENTS_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)(char *)btllib::COMPLEMENTS;
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_btllibJNI_CAPITALS_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)(char *)btllib::CAPITALS;
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


#ifdef __cplusplus
}
#endif

