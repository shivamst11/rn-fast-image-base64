package com.rnfastimagebase64;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.Promise;

abstract class RnFastImageBase64Spec extends ReactContextBaseJavaModule {
  RnFastImageBase64Spec(ReactApplicationContext context) {
    super(context);
  }

  public abstract void multiply(double a, double b, Promise promise);
}
