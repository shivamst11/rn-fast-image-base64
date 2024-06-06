import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package 'rn-fast-image-base64' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

// @ts-expect-error
const isTurboModuleEnabled = global.__turboModuleProxy != null;

const RnFastImageBase64Module = isTurboModuleEnabled
  ? require('./NativeRnFastImageBase64').default
  : NativeModules.RnFastImageBase64;

const RnFastImageBase64 = RnFastImageBase64Module
  ? RnFastImageBase64Module
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

export function multiply(a: number, b: number): Promise<number> {
  return RnFastImageBase64.multiply(a, b);
}
