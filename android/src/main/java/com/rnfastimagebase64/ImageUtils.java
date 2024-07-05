package com.rnfastimagebase64;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class ImageUtils {
  public static byte[] readImage(String imagePath) throws IOException {
    File file = new File(imagePath);
    FileInputStream fileInputStream = new FileInputStream(file);
    byte[] bytes = new byte[(int)file.length()];
    fileInputStream.read(bytes);
    fileInputStream.close();
    return bytes;
  }
}
