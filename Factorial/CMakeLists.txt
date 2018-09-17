cmake_minimum_required(VERSION 3.7)

# Include src
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src bin)
add_subdirectory(test)
