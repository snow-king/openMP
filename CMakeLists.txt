cmake_minimum_required(VERSION 3.24)
project(openMP)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
add_executable(openMP main.cpp CommandLine.cpp CommandLine.h WorkTask.cpp WorkTask.h CalculateTask.cpp CalculateTask.h)
