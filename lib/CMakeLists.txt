cmake_minimum_required(VERSION 3.0.0)

add_library(Color color.hpp)

target_include_directories(Color PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})