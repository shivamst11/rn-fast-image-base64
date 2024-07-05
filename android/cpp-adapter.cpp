#include <jni.h>
#include <android/log.h>
#include <jsi/jsi.h>
#include <fbjni/fbjni.h>
#include "base64.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace facebook::jsi;
using namespace std;

#define APPNAME "module_name_jni"
#define LOGD(TAG) __android_log_print(ANDROID_LOG_DEBUG, APPNAME, "%s", TAG)

// Function to remove leading and trailing whitespace
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

string removeFilePrefix(const string& filePath) {
    const string prefix = "file://";
    if (filePath.substr(0, prefix.size()) == prefix) {
        return trim(filePath.substr(prefix.size()));
    }
    return filePath;
}

vector<unsigned char> readFile(const string& filePath) {
    string cleanedFilePath = removeFilePrefix(filePath);
    LOGD(("Reading file: " + cleanedFilePath).c_str());
    ifstream file(cleanedFilePath, ios::binary);
    if (!file.is_open()) {
        LOGD("Failed to open file");
        return {};
    }
    vector<unsigned char> buffer(istreambuf_iterator<char>(file), {});
    return buffer;
}



void install(JNIEnv* env, Runtime &jsiRuntime) {
    auto imageToBase64 = Function::createFromHostFunction(
            jsiRuntime,
            PropNameID::forAscii(jsiRuntime, "imageToBase64"),
            1,
            [env](Runtime &runtime, const Value &thisValue, const Value *arguments, size_t count) -> Value {
                if (count < 1 || !arguments[0].isString()) {
                    LOGD("Invalid argument count or argument type");
                    return Value::undefined();
                }

                auto imagePath = arguments[0].getString(runtime).utf8(runtime);

                // Read the image file
                 vector<unsigned char> imageBytes = readFile(imagePath);
                if (imageBytes.empty()) {
                    LOGD("Failed to read image file");
                    return Value::undefined();
                }

                 string base64String = base64_encode(imageBytes.data(), imageBytes.size());

                return Value(runtime, String::createFromUtf8(runtime, base64String));
            }
    );

    jsiRuntime.global().setProperty(jsiRuntime, "imageToBase64",  move(imageToBase64));
}





extern "C"
JNIEXPORT void JNICALL
Java_com_rnfastimagebase64_RnFastImageBase64Module_nativeInstall(JNIEnv *env, jobject thiz, jlong jsi, jstring doc_dir) {
    auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi);
    if (runtime) {
        LOGD("Native Install function called" );
        install(env, *runtime);
    } else {
    }
}
