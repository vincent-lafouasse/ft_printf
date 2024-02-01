#include "parse.h"
#include "unity_fixture.h"

#include <stdio.h>
#include <string.h>

TEST_GROUP(ParseLexemes);
TEST_SETUP(ParseLexemes) {}
TEST_TEAR_DOWN(ParseLexemes) {}

static void log_lexeme(t_lexeme lexeme)
{
    while (lexeme.start != lexeme.end)
    {
        printf("%c", *(lexeme.start));
        lexeme.start++;
    }
}

static void assert_lexeme(t_lexeme lexeme, const char* expected)
{
    uint64_t size = lexeme.end - lexeme.start;

    if (size < 0)
    {
        FAIL("invalid lexeme, end is before start");
        return;
    }

    if (size > strlen(expected))
    {
        FAIL("lexeme is longer than expected");
        return;
    }

    for (char* it = (char*)lexeme.start; it != lexeme.end; it++, expected++)
    {
        TEST_ASSERT_EQUAL(*it, *expected);
    }
}

static void assert_lexeme_list(t_lexeme_list* l,
                               const char* expected[],
                               size_t sz)
{
    t_lexeme_node* current = l->head;

    printf("\n");
    while (current && sz)
    {
        printf("matching ");
        log_lexeme(current->lexeme);
        printf(" and %s\n", *expected);
        assert_lexeme(current->lexeme, *expected);
        current = current->next;
        expected++;
    }
    TEST_ASSERT_EQUAL(current, NULL);
    TEST_ASSERT_EQUAL(sz, 0);
}

TEST(ParseLexemes, Dummy)
{
    t_lexeme_list l = split_lexemes("abc%c");
    const char* expected[] = {"abc", "%c"};
    size_t size = sizeof(expected) / sizeof(*expected);

    assert_lexeme_list(&l, expected, size);
}

TEST_GROUP_RUNNER(ParseLexemes)
{
    printf("\e[34m----- ParseLexemes -----\e[0m\n");
    RUN_TEST_CASE(ParseLexemes, Dummy);
}
