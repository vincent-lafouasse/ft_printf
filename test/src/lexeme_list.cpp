#include <cstdlib>
#include "gtest/gtest.h"

extern "C"
{
#include "t_lexeme_list.h"
}

static void assert_lexeme_equality(t_lexeme lexeme, const char* expected)
{
    if (lexeme.end < lexeme.start)
    {
        FAIL() << "invalid lexeme, end is before start";
        return;
    }

    size_t size = lexeme.end - lexeme.start;
    const std::string lexeme__(lexeme.start, size);
    const std::string expected__(expected);

    ASSERT_EQ(lexeme__, expected__);
}

TEST(LexemeList, NewNode)
{
    const char* src = "abcdefgh";

    t_lexeme_node* node1 = lexeme_node_new(src, src + 3);
    t_lexeme_node* node2 = lexeme_node_new(src + 4, src + 5);

    assert_lexeme_equality(node1->lexeme, "abc");
    ASSERT_EQ(node1->next, nullptr);

    assert_lexeme_equality(node2->lexeme, "e");
    ASSERT_EQ(node2->next, nullptr);
}

TEST(LexemeList, NewList)
{
    t_lexeme_list l = lexeme_list_new();
    ASSERT_EQ(l.head, nullptr);
    ASSERT_EQ(l.tail, nullptr);
}

TEST(LexemeList, ListPush)
{
    const char* src = "abcdefgh";

    t_lexeme_list list = lexeme_list_new();

    lexeme_list_push(&list, src, src + 4);
    ASSERT_NE(list.head, nullptr);
    ASSERT_EQ(list.head, list.tail);
    assert_lexeme_equality(list.head->lexeme, "abcd");

    lexeme_list_push(&list, src + 3, src + 7);
    ASSERT_NE(list.head, nullptr);
    ASSERT_NE(list.head, list.tail);
    assert_lexeme_equality(list.head->lexeme, "abcd");
    assert_lexeme_equality(list.tail->lexeme, "defg");
}
