cmake_minimum_required(VERSION 3.10)

add_executable(
    converter-test
    test-validator.cpp
)

target_link_libraries(
    converter-test
    PRIVATE
    gmock
    gmock_main
    gtest
    converter-lib
)
