#include <jni.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <jni.h>
#include <android/log.h>

#include <stdarg.h>
#include "../../../../xhook/src/main/cpp/src/xhook.h"



extern "C" JNIEXPORT jstring JNICALL
Java_com_linshujie_xhookdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



extern "C"
JNIEXPORT void JNICALL
Java_com_linshujie_xhookdemo_MainActivity_hook(JNIEnv *env, jobject thiz) {
    xhook_register("^/system/.*\\.so$",  "__android_log_print", (void *)my_system_log_print,  NULL);
}