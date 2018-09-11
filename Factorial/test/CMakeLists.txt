cmake_minimum_required(VERSION 3.7)

include_directories(
  ${CATCH_INCLUDE_DIR}
)

set ( 
  FAT_TEST fat_test.cpp 
)

set( 
  SRC

  ${CMAKE_CURRENT_SOURCE_DIR}/../src/Factorial.cpp
)

add_executable(
  fat_test
  main.cpp
  ${SRC}
  ${FAT_TEST}
)

add_dependencies(fat_test catch)

enable_testing()