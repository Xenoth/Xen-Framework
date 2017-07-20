cmake_minimum_required(VERSION 2.6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(SKV)

set(EXECUTABLE_NAME "skv-tests")
file (GLOB_RECURSE sourceFiles ./*)
add_executable(${EXECUTABLE_NAME} test.cpp SKVManager.cpp SKVManager.h)
