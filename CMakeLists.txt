cmake_minimum_required(VERSION 3.21)
project(bucketSort2 C)

set(CMAKE_C_STANDARD 99)

add_executable(bucketSort2 main.c bucketSort.c bucketSort.h)
