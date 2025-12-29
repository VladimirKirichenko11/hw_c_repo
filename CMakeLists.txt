cmake_minimum_required(VERSION 3.10)

project(HW1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(array_replace src/array_replace.c)

add_executable(fast_polynomial src/fast_polynomial.c)

add_executable(lucky_tickets src/lucky_tickets.c)

add_executable(partial_quottient src/partial_quotient.c)
