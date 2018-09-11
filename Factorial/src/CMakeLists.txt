cmake_minimum_required(VERSION 3.3)

project(factorial)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Factorial.cpp )

add_executable(factorial ${SOURCE_FILES})


