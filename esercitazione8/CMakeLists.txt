cmake_minimum_required(VERSION 3.10)
project(esercitazione8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(esercitazione8 main.cpp)
target_include_directories(esercitazione8 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
