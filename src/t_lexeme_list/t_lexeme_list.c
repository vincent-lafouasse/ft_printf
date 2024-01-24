/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexeme_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:25:23 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 07:34:24 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lexeme_list.h"

#include <stdlib.h>

t_lexeme_list lexeme_list_new(void)
{
	t_lexeme_list out;

	out.head = NULL;
	out.tail = NULL;
	return out;
}

t_lexeme_node* lexeme_node_new(const char* start, const char* end)
{
	t_lexeme_node* out;
	t_lexeme lexeme;

	out = malloc(sizeof(*out));
	lexeme.start = start;
	lexeme.end = end;
	return out;
}

void lexeme_list_push(t_lexeme_list* l, const char* start, const char* end)
{
	t_lexeme lexeme;

	lexeme.start = start;
	lexeme.end = end;
	if (l->head == NULL)
	{
		l->head = 
	}
}

void lexeme_list_clear(t_lexeme_list* l);
