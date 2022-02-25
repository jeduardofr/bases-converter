cmake_minimum_required(VERSION 3.10)

add_executable(
  converter
  main.cpp
)

target_link_libraries(converter PRIVATE converter-lib)

add_library(
  converter-lib
  validator.cpp
  converter.cpp
)

target_include_directories(converter-lib PUBLIC .)

