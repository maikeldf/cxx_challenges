cmake_minimum_required(VERSION 3.7)

project(sequence_vec)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SequenceVec.cpp)

add_executable(sequence_vec ${SOURCE_FILES})


