/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeme_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:39:17 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 07:42:38 by poss             ###   ########.fr       */
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
    int expected = 0;
    int actual = 0;

    char error[100];
    sprintf(error, "Error found, expected %d was %d", expected, actual);
    TEST_ASSERT_MESSAGE(expected == actual, error);
}

TEST_GROUP_RUNNER(LexemeList)
{
    printf("\e[34m----- LexemeList -----\e[0m\n");
    RUN_TEST_CASE(LexemeList, NewNode);
}
