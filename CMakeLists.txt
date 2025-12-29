cmake_minimum_required(VERSION 3.10)

project(HW6 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(rhyme src/rhyme.c)

add_executable(sorted_list src/sorted_list.c)