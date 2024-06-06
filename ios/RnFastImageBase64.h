#ifdef __cplusplus
#import "rn-fast-image-base64.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNRnFastImageBase64Spec.h"

@interface RnFastImageBase64 : NSObject <NativeRnFastImageBase64Spec>
#else
#import <React/RCTBridgeModule.h>

@interface RnFastImageBase64 : NSObject <RCTBridgeModule>
#endif

@end
