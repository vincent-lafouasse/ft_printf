#include <cstdlib>
#include "gtest/gtest.h"

extern "C"
{
#include "substring/t_substr_deque.h"
}

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

TEST(SubstringDeque, NewList)
{
    const char* src = "abcdefgh";

    t_substr_list* list1 = substr_list_new(src, src + 3);
    t_substr_list* list2 = substr_list_new(src + 4, src + 5);

    assert_substr_equality(list1->substr, "abc");
    ASSERT_EQ(list1->next, nullptr);

    assert_substr_equality(list2->substr, "e");
    ASSERT_EQ(list2->next, nullptr);
}

TEST(SubstringDeque, NewDeque)
{
    t_substr_deque deque = substr_deque_new();
    ASSERT_EQ(deque.head, nullptr);
    ASSERT_EQ(deque.tail, nullptr);
}

TEST(SubstringDeque, DequePush)
{
    const char* src = "abcdefgh";

    t_substr_deque deque = substr_deque_new();

    substr_deque_push(&deque, src, src + 4);
    ASSERT_NE(deque.head, nullptr);
    ASSERT_EQ(deque.head, deque.tail);
    assert_substr_equality(deque.head->substr, "abcd");

    substr_deque_push(&deque, src + 3, src + 7);
    ASSERT_NE(deque.head, nullptr);
    ASSERT_NE(deque.head, deque.tail);
    assert_substr_equality(deque.head->substr, "abcd");
    assert_substr_equality(deque.tail->substr, "defg");
}
