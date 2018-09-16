cmake_minimum_required(VERSION 3.7)

include_directories(
  ${CATCH_INCLUDE_DIR}
)

set ( 
  ATTR_TEST attr_test.cpp 
)

set( 
  SRC

  ${CMAKE_CURRENT_SOURCE_DIR}/../src/AttrParser.cpp
)

add_executable(
  attr_test
  main.cpp
  ${SRC}
  ${ATTR_TEST}
)

add_dependencies(attr_test catch)
enable_testing()