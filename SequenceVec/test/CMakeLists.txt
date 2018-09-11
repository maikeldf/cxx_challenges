cmake_minimum_required(VERSION 3.7)

include_directories(
  ${CATCH_INCLUDE_DIR}
)

set ( 
  SEQ_TEST seq_test.cpp 
)

set( 
  SRC

  ${CMAKE_CURRENT_SOURCE_DIR}/../src/SequenceVec.cpp
)

add_executable(
  seq_test
  main.cpp
  ${SRC}
  ${SEQ_TEST}
)

add_dependencies(seq_test catch)

enable_testing()
