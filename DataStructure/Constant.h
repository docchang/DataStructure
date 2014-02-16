//
//  Constant.h
//  Evolution
//
//  Created by Dominic Chang on 8/8/13.
//
//

#ifndef Evolution_Constant_h
#define Evolution_Constant_h


#define STRING(s) #s

#define VECTOR_INDEX_CHECK(vector , index) (index >= 0 && index < vector.size())



//  Random
#define ARC4RANDOM_MAX 0x100000000
#define ARC4RANDOM_0_1 ((double)arc4random() / ARC4RANDOM_MAX)
#define ARC4RANDOM(max) (arc4random() % (int)(max))
#define fARC4RANDOM_signed_int(ivalue) (float)(ARC4RANDOM_0_1 + (float)ARC4RANDOM(2 * (int)(ivalue)) - (float)(ivalue))



#define ccRANDOM_COLOR ccc3(ARC4RANDOM_0_1 * 255.0f, ARC4RANDOM_0_1 * 255.0f, ARC4RANDOM_0_1 * 255.0f)




#include <sstream>
#include <thread>
static std::string const getThisThreadID() {
    std::thread::id  thread_id = std::this_thread::get_id();
    std::stringstream ss;
    ss << thread_id;
    return ss.str();
}






#include <math.h>
#include <sys/time.h>
#define MICRO pow(10.0, -6.0)
static double timeintervalSinceEvolution() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    double ms = tp.tv_sec + tp.tv_usec * MICRO;
    return ms;
}



//DebugLog
#define DebugLog getThisThreadID() << ":" << __PRETTY_FUNCTION__ << "[Line " << __LINE__ << "] "

#define DebugFloat(f) DebugLog("%s:%f", #f, f)
#define DebugInt(i) DebugLog("%s:%d", #i, i)

//http://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
static std::string string_format(const char *fmt, ...)
{
    char *ret;
    va_list ap;
    
    va_start(ap, fmt);
    vasprintf(&ret, fmt, ap);
    va_end(ap);
    
    std::string str(ret);
    free(ret);
    
    return str;
}
static void append_format(std::string& str, const char *fmt, ...)
{
    va_list ap;
    char *ret;
    
    va_start(ap, fmt);
    vasprintf(&ret, fmt, ap);
    va_end(ap);
    
    str.append(ret);
    free(ret);
}









// Macro Loops
#define __VA_NARG__(...) \
(__VA_NARG_(_0, ## __VA_ARGS__, __RSEQ_N()) - 1)

#define __VA_NARG_(...) \
__VA_ARG_N(__VA_ARGS__)

#define __VA_ARG_N( \
_1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
_61,_62,_63,N,...) N

#define __RSEQ_N() \
63, 62, 61, 60,                         \
59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#define FOR_EACH_1(what, x, ...)\
what(x)

#define FOR_EACH_2(what, x, ...)\
what(x);\
FOR_EACH_1(what, __VA_ARGS__);

#define FOR_EACH_3(what, x, ...)\
what(x);\
FOR_EACH_2(what, __VA_ARGS__);

#define FOR_EACH_4(what, x, ...)\
what(x);\
FOR_EACH_3(what, __VA_ARGS__);

#define FOR_EACH_5(what, x, ...)\
what(x);\
FOR_EACH_4(what, __VA_ARGS__);

#define FOR_EACH_6(what, x, ...)\
what(x);\
FOR_EACH_5(what, __VA_ARGS__);

#define FOR_EACH_7(what, x, ...)\
what(x);\
FOR_EACH_6(what, __VA_ARGS__);

#define FOR_EACH_8(what, x, ...)\
what(x);\
FOR_EACH_7(what, __VA_ARGS__);

#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME

#define FOR_EACH(action,...) GET_MACRO(__VA_ARGS__,FOR_EACH_8,FOR_EACH_7,FOR_EACH_6,FOR_EACH_5,FOR_EACH_4,FOR_EACH_3,FOR_EACH_2,FOR_EACH_1)(action,__VA_ARGS__)


#endif  //endif Evolution_Constant_h
