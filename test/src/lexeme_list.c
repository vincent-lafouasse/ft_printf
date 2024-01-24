/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeme_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:39:17 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 07:46:30 by poss             ###   ########.fr       */
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

TEST_GROUP_RUNNER(LexemeList)
{
    printf("\e[34m----- LexemeList -----\e[0m\n");
    RUN_TEST_CASE(LexemeList, NewNode);
}
