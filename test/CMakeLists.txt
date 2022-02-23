cmake_minimum_required(VERSION 3.10)

add_executable(
    json-parser-test
    test-lex.cpp
)

target_link_libraries(
    json-parser-test
    PRIVATE
    gmock
    gmock_main
    gtest
    json-parser-lib
)