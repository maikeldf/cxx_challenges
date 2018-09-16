CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

set(CMAKE_BUILD_TYPE Debug)

project(attr_parser)

add_executable(
  ${PROJECT_NAME}
  main.cpp
  AttrParser.cpp
)
