/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeme_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:39:17 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 07:54:00 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lexeme_list.h"
#include "unity_fixture.h"

#include <stdio.h>

TEST_GROUP(LexemeList);
TEST_SETUP(LexemeList) {}
TEST_TEAR_DOWN(LexemeList) {}

TEST(LexemeList, NewNode)
{
	const char* src = "abcdefgh";

	t_lexeme_node* node = lexeme_node_new(src, src + 3);
	t_lexeme lexeme = node->lexeme;

    TEST_ASSERT_EQUAL(lexeme.start, src);
    TEST_ASSERT_EQUAL(lexeme.end, src + 3);
    TEST_ASSERT_EQUAL(node->next, NULL);
}

TEST(LexemeList, NewList)
{
	t_lexeme_list list = lexeme_list_new();
	TEST_ASSERT_EQUAL(list.head, list.tail);
	TEST_ASSERT_EQUAL(list.head, NULL);
}

TEST(LexemeList, ListPush)
{
	const char* src = "abcdefgh";

	t_lexeme_list list = lexeme_list_new();

	lexeme_list_push(&list, src, src + 4);
	TEST_ASSERT_NOT_EQUAL(list.head, NULL);
	TEST_ASSERT_EQUAL(list.head, list.tail);
	TEST_ASSERT_EQUAL(list.head->lexeme.start, src);
	TEST_ASSERT_EQUAL(list.head->lexeme.end, src + 4);


	lexeme_list_push(&list, src + 3, src + 7);
	TEST_ASSERT_NOT_EQUAL(list.head, NULL);
	TEST_ASSERT_NOT_EQUAL(list.head, list.tail);
	TEST_ASSERT_EQUAL(list.head->lexeme.start, src);
	TEST_ASSERT_EQUAL(list.head->lexeme.end, src + 4);
	TEST_ASSERT_EQUAL(list.tail->lexeme.start, src + 3);
	TEST_ASSERT_EQUAL(list.tail->lexeme.end, src + 7);
}

TEST_GROUP_RUNNER(LexemeList)
{
    printf("\e[34m----- LexemeList -----\e[0m\n");
    RUN_TEST_CASE(LexemeList, NewNode);
    RUN_TEST_CASE(LexemeList, NewList);
    RUN_TEST_CASE(LexemeList, ListPush);
}
