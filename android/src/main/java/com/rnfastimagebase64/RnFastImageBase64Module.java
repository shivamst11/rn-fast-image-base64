package com.rnfastimagebase64;

import android.content.SharedPreferences;
import android.os.Build;
import android.preference.PreferenceManager;
import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = RnFastImageBase64Module.NAME)
public class RnFastImageBase64Module extends ReactContextBaseJavaModule {
  public static final String NAME = "RnFastImageBase64";


  private native void nativeInstall(long jsiPtr, String docDir);

  public RnFastImageBase64Module(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  @ReactMethod(isBlockingSynchronousMethod = true)
  public boolean install() {
    try {
      System.loadLibrary("rn-fast-image-base64");
      ReactApplicationContext context = getReactApplicationContext();
      nativeInstall(
        context.getJavaScriptContextHolder().get(),
        context.getFilesDir().getAbsolutePath()
      );
      return true;
    } catch (Exception exception) {
      return false;
    }
  }



}
