CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src bin)
add_subdirectory(test)
