#include <jni.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const char *rev(const char *str) {
    string s = str;
    reverse(s.begin(), s.end());
    return s.c_str();
}

extern "C" {

JNIEXPORT jstring JNICALL
        Java_mintcode_com_jni_Ndk_convert(JNIEnv *env, jobject instance, jstring name_);

JNIEXPORT void JNICALL
        Java_mintcode_com_jni_Ndk_swapValue(JNIEnv *env, jobject instance, jstring first_,
                                            jstring second_);
JNIEXPORT void JNICALL
        Java_mintcode_com_jni_Ndk_sort(JNIEnv *env, jobject instance, jintArray array_);
}

JNIEXPORT jstring JNICALL
Java_mintcode_com_jni_Ndk_convert(JNIEnv *env, jobject instance, jstring name_) {
//    const char *name = env->GetStringUTFChars(env, name_, 0);

    jboolean iscopy = false;
    const char *name = env->GetStringUTFChars(name_, &iscopy);
    // TODO

//    env->ReleaseStringUTFChars(env,name_,name)
    env->ReleaseStringUTFChars(name_, name);
    return env->NewStringUTF(rev(name));
}


JNIEXPORT void JNICALL
Java_mintcode_com_jni_Ndk_swapValue(JNIEnv *env, jobject instance, jstring first_,
                                    jstring second_) {
    const char *first = env->GetStringUTFChars(first_, 0);
    const char *second = env->GetStringUTFChars(second_, 0);


    cout << "mintcode ndk" << endl;

    env->ReleaseStringUTFChars(first_, first);
    env->ReleaseStringUTFChars(second_, second);
}

JNIEXPORT void JNICALL
Java_mintcode_com_jni_Ndk_sort(JNIEnv *env, jobject instance, jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    int length = env->GetArrayLength(array_);

    env->ReleaseIntArrayElements(array_, array, 0);
}