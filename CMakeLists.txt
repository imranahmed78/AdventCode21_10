# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


#set(CMAKE_C_COMPILER "/c/MinGW/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "/c/MinGW/bin/g++.exe")
#set(CMAKE_MAKE_PROGRAM "c/cmake/bin/cmake.exe")

project ("SubmarineSyntaxScoring")

add_executable (SubmarineSyntaxScoring "main.cpp" "SyntaxScoring.cpp" "SyntaxScoring.h")
