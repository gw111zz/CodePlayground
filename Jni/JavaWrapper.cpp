#include <jni.h>
#include "JavaWrapper.h"

JNIEXPORT jint JNICALL Java_JavaWrapper_getInt(JNIEnv *, jclass) {
    return 5;
}

JNIEXPORT jstring JNICALL Java_JavaWrapper_getString(JNIEnv *, jclass) {
    return 0;
}
