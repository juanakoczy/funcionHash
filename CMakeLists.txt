cmake_minimum_required(VERSION 3.24)
project(funcionHash C)

set(CMAKE_C_STANDARD 11)

add_executable(funcionHash main.c hash.h hash.c)
