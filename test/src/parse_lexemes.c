#include "t_lexeme_list.h"
#include "unity_fixture.h"

#include <stdio.h>
#include <string.h>

TEST_GROUP(ParseLexemes);
TEST_SETUP(ParseLexemes) {}
TEST_TEAR_DOWN(ParseLexemes) {}

TEST(ParseLexemes, Dummy)
{
    t_lexeme_list list = lexeme_list_new();
    TEST_ASSERT_EQUAL(list.head, NULL);
    TEST_ASSERT_EQUAL(list.tail, NULL);
}

TEST_GROUP_RUNNER(ParseLexemes)
{
    printf("\e[34m----- ParseLexemes -----\e[0m\n");
    RUN_TEST_CASE(ParseLexemes, Dummy);
}
