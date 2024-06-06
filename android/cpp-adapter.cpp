#include <jni.h>
#include "rn-fast-image-base64.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_rnfastimagebase64_RnFastImageBase64Module_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return rnfastimagebase64::multiply(a, b);
}
