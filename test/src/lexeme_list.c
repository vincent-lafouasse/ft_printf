/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeme_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:39:17 by poss              #+#    #+#             */
/*   Updated: 2024/02/01 19:39:09 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lexeme_list.h"
#include "unity_fixture.h"

#include <stdio.h>
#include <string.h>

TEST_GROUP(LexemeList);
TEST_SETUP(LexemeList) {}
TEST_TEAR_DOWN(LexemeList) {}

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

TEST(LexemeList, NewNode)
{
    const char* src = "abcdefgh";

    t_lexeme_node* node = lexeme_node_new(src, src + 3);

    assert_lexeme(node->lexeme, "abc");
    TEST_ASSERT_EQUAL(node->next, NULL);
}

TEST(LexemeList, NewList)
{
    t_lexeme_list list = lexeme_list_new();
    TEST_ASSERT_EQUAL(list.head, NULL);
    TEST_ASSERT_EQUAL(list.tail, NULL);
}

TEST(LexemeList, ListPush)
{
    const char* src = "abcdefgh";

    t_lexeme_list list = lexeme_list_new();

    lexeme_list_push(&list, src, src + 4);
    TEST_ASSERT_NOT_EQUAL(list.head, NULL);
    TEST_ASSERT_EQUAL(list.head, list.tail);
    assert_lexeme(list.head->lexeme, "abcd");

    lexeme_list_push(&list, src + 3, src + 7);
    TEST_ASSERT_NOT_EQUAL(list.head, NULL);
    TEST_ASSERT_NOT_EQUAL(list.head, list.tail);
    assert_lexeme(list.head->lexeme, "abcd");
    assert_lexeme(list.tail->lexeme, "defg");
}

TEST_GROUP_RUNNER(LexemeList)
{
    printf("\e[34m----- LexemeList -----\e[0m\n");
    RUN_TEST_CASE(LexemeList, NewNode);
    RUN_TEST_CASE(LexemeList, NewList);
    RUN_TEST_CASE(LexemeList, ListPush);
}
