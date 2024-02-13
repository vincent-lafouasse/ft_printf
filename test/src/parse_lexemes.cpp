#include "gtest/gtest.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

extern "C"
{
#include "parse.h"
#include "t_lexeme_list.h"
}

/*
static void log_lexeme(t_lexeme lexeme)
{
    while (lexeme.start != lexeme.end)
    {
        printf("%c", *(lexeme.start));
        lexeme.start++;
    }
}
*/

static void assert_lexeme_equality(t_lexeme lexeme, const char* expected)
{
    int64_t size = lexeme.end - lexeme.start;

    if (size < 0)
    {
        FAIL() << "invalid lexeme, end is before start";
        return;
    }

    const std::string lexeme__(lexeme.start, size);
    const std::string expected__(expected);

    ASSERT_EQ(lexeme__, expected__);
}

static void assert_lexeme_list_equality(
    const t_lexeme_list* l,
    const std::vector<const char*>& expected)
{
    size_t size = expected.size();
    t_lexeme_node* current = l->head;

    size_t i = 0;

    while (current && i < size)
    {
        assert_lexeme_equality(current->lexeme, expected[i]);
        current = current->next;
        i++;
    }

    ASSERT_EQ(i, size) << "Not enough lexemes";
    ASSERT_EQ(current, nullptr) << "Too many lexemes";
}

TEST(ParseLexemes, Simple)
{
    t_lexeme_list l = split_lexemes("abc");
    const std::vector<const char*> expected = {"abc"};

    assert_lexeme_list_equality(&l, expected);
}

TEST(ParseLexemes, OneSpecifier)
{
    t_lexeme_list l = split_lexemes("abc%c");
    const std::vector<const char*> expected = {"abc", "%c"};

    assert_lexeme_list_equality(&l, expected);
}

TEST(ParseLexemes, TwoSpecifier)
{
    t_lexeme_list l = split_lexemes("abc  %c  %abc");
    const std::vector<const char*> expected = {"abc  ", "%c", "  ", "%abc"};

    assert_lexeme_list_equality(&l, expected);
}
