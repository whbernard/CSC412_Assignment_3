cmake_minimum_required(VERSION 3.9)
project(CSC412_Assignment_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(CSC412_Assignment_3 compareImages.c rotate.h rotate.c imageIO_TGA.h imageIO_TGA.c rasterImage.h rasterImage.c directorySearch.c compareImages.h compare.c)