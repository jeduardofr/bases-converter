cmake_minimum_required(VERSION 3.10)

add_executable(
  json-parser
  main.cpp
)

target_link_libraries(json-parser PRIVATE json-parser-lib)


add_library(
  json-parser-lib
  lex.cpp
)

target_include_directories(json-parser-lib PUBLIC .)

