cmake_minimum_required(VERSION 3.4.1)
project(RnFastImageBase64)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

add_library(rn-fast-image-base64            SHARED
            ../cpp/rn-fast-image-base64.cpp
            cpp-adapter.cpp
)

# Specifies a path to native header files.
include_directories(
            ../cpp
)
