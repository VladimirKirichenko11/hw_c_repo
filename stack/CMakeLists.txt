add_library(static_lib STATIC stack.c)

add_executable(bracket_balance bracket_balance.c)
add_executable(infix_to_postfix infix_to_postfix.c)


target_link_libraries(bracket_balance stack_lib)
target_link_libraries(infix_to_postfix stack_lib)
