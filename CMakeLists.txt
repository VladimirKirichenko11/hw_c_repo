cmake_minimum_required(VERSION 3.10)

project(HW2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bracket_balance src/bracket_balance.c)

add_executable(substring_counting src/substring_counting.c)

add_executable(zero_elements src/zero_elements.c)