cmake_minimum_required(VERSION 3.5)

project(ft_printf LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

add_library(printf
	src/ft_printf.c
	src/raw_tokens/split_raw_tokens.c
	src/substring/t_substr_deque.c
)
target_compile_options(printf PUBLIC -Wall -Wextra -Wpedantic -g3)
target_include_directories(printf PUBLIC include)
target_include_directories(printf PUBLIC src)

# add_subdirectory(test)
