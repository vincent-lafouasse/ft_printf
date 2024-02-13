cmake_minimum_required(VERSION 3.5)

project(ft_printf LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

add_library(printf
	src/ft_printf.c
	src/parse.c
	src/t_lexeme_list/t_lexeme_list.c
)
target_compile_options(printf PUBLIC -Wall -Wextra -Wpedantic -g3)
target_include_directories(printf PUBLIC include)

add_subdirectory(test)
