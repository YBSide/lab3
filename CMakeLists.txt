cmake_minimum_required(VERSION 3.15)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp )
target_include_directories(lab3 PUBLIC .)