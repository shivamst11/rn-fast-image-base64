#import "RnFastImageBase64.h"
#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#include "base64.hpp"
#import <jsi/jsi.h>
#import <sys/utsname.h>
#import "YeetJSIUtils.h"
#import <React/RCTBridge+Private.h>
#include "base64.hpp"

using namespace facebook::jsi;
using namespace std;

@implementation RnFastImageBase64

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

RCT_EXPORT_MODULE()

 + (BOOL)requiresMainQueueSetup {

     return YES;
 }

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install)
{
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge* cxxBridge = (RCTCxxBridge*)bridge;
    if (cxxBridge == nil) {
        return @false;
    }


    auto jsiRuntime = (jsi::Runtime*) cxxBridge.runtime;
    if (jsiRuntime == nil) {
        return @false;
    }

    install(*(facebook::jsi::Runtime *)jsiRuntime, self);
    return @true;
}

static void install(jsi::Runtime &jsiRuntime, RnFastImageBase64 *base64Image) {

    auto imageToBase64 = Function::createFromHostFunction(
        jsiRuntime,
        PropNameID::forAscii(jsiRuntime, "imageToBase64"),
        1,
        [](Runtime &runtime, const Value &thisValue, const Value *arguments, size_t count) -> Value {
            if (count < 1 || !arguments[0].isString()) {
                return Value::undefined();
            }

            auto imagePath = arguments[0].getString(runtime);
            NSString *inputNSString = convertJSIStringToNSString(runtime, imagePath);
            NSURL *url = [NSURL URLWithString:inputNSString];
            NSData* data = [NSData dataWithContentsOfURL:url];
            std::string base64String = base64_encode(reinterpret_cast<const unsigned char*>(data.bytes), data.length, false);
            auto outputString = convertNSStringToJSIString(runtime, [NSString stringWithUTF8String:base64String.c_str()]);

            return Value(runtime, outputString);
        });

    jsiRuntime.global().setProperty(jsiRuntime, "imageToBase64", std::move(imageToBase64));
}
@end
