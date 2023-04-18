cmake_minimum_required(VERSION 3.26)
project(gdrive_zip_merger CXX)
add_executable(main main.cpp)

target_compile_features(main PUBLIC cxx_std_20)
target_compile_options(main PUBLIC -O3 -Wall)