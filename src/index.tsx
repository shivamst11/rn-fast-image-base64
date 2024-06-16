import { NativeModules } from 'react-native';

interface IModule {
  imageToBase64(url: string): string;
}
//@ts-ignore

NativeModules.RnFastImageBase64?.install();

export const { imageToBase64 } = global as unknown as IModule;
