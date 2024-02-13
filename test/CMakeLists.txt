set(CMAKE_CXX_STANDARD 17)

# fetch gtest
# targets: `libgtest` `libgmock` (static libraries)
include(${CMAKE_SOURCE_DIR}/test/fetch_gtest.cmake)

add_executable(test_runner
	src/main.cpp
	src/test.cpp
	src/lexeme_list.cpp
	src/parse_lexemes.cpp
)
target_link_libraries(test_runner
    printf
    libgtest
)
