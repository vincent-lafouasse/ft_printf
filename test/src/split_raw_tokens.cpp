#include "gtest/gtest.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

extern "C"
{
#include "raw_tokens/split_raw_tokens.h"
}

static void log_substr(t_substr substr)
{
    while (substr.start != substr.end)
    {
        printf("%c", *(substr.start));
        substr.start++;
    }
}
/*
*/

static void assert_substr_equality(t_substr substr, const char* expected)
{
    if (substr.end < substr.start)
    {
        FAIL() << "invalid substr, end is before start";
        return;
    }

    size_t size = substr.end - substr.start;
    const std::string substr__(substr.start, size);
    const std::string expected__(expected);

    ASSERT_EQ(substr__, expected__);
}

static void assert_substr_list_equality(
    const t_substr_deque* l,
    const std::vector<const char*>& expected)
{
    size_t size = expected.size();
    t_substr_list* current = l->head;

    size_t i = 0;

    while (current && i < size)
    {
        assert_substr_equality(current->substr, expected[i]);
        current = current->next;
        i++;
    }

    ASSERT_EQ(i, size) << "Not enough raw tokens";
    ASSERT_EQ(current, nullptr) << "Too many raw tokens";
}

TEST(ParseRawTokens, Simple)
{
    t_substr_deque raw_tokens = split_raw_tokens("abc");
    const std::vector<const char*> expected = {"abc"};

    assert_substr_list_equality(&raw_tokens, expected);
}

TEST(ParseRawTokens, OneSpecifier)
{
    t_substr_deque raw_tokens = split_raw_tokens("abc%c");
    const std::vector<const char*> expected = {"abc", "%c"};

    assert_substr_list_equality(&raw_tokens, expected);
}

TEST(ParseRawTokens, TwoSpecifier)
{
    t_substr_deque raw_tokens = split_raw_tokens("abc  %c  %abc");
    const std::vector<const char*> expected = {"abc  ", "%c", "  ", "%abc"};

    assert_substr_list_equality(&raw_tokens, expected);
}
