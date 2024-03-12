/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:25:23 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 20:06:14 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substring/t_substr_list.h"
#include <stdlib.h>
#include <string.h>

t_substr_list	substr_list_new(void)
{
	t_substr_list	out;

	out.head = NULL;
	out.tail = NULL;
	return (out);
}

t_substr_node	*substr_node_new(const char *start, const char *end)
{
	t_substr_node	*out;
	t_substr		substr;

	out = malloc(sizeof(*out));
	substr.start = start;
	substr.end = end;
	memcpy((void *)&(out->substr), &substr, sizeof(substr));
	out->next = NULL;
	return (out);
}

void	substr_list_push(t_substr_list *l, const char *start, const char *end)
{
	if (l->head == NULL)
	{
		l->head = substr_node_new(start, end);
		l->tail = l->head;
		return ;
	}
	l->tail->next = substr_node_new(start, end);
	l->tail = l->tail->next;
}

void			substr_list_clear(t_substr_list *l);
