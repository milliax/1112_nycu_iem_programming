set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

cmake_minimum_required(VERSION 3.0.0)
project(project VERSION 0.1.0)

#add_executable(${PROJECT_NAME} main.cpp)

include_directories(include)
add_subdirectory(src)
add_subdirectory(lib)