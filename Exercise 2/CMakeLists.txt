cmake_minimum_required(VERSION 3.13)
project(ASD_L1 C)

set(CMAKE_C_STANDARD 11)

add_executable(ASD_L1 main.c quickSort.c quickSort.h heapSort.c heapSort.h unifiedFunctions.c unifiedFunctions.h selectInsertSort.c selectInsertSort.h rngGood.c rngGood.h)