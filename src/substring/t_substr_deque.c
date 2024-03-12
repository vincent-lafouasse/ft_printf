/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr_deque.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:25:23 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 21:13:08 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substring/t_substr_deque.h"
#include <stdlib.h>
#include <string.h>

t_substr_deque	substr_deque_new(void)
{
	t_substr_deque	out;

	out.head = NULL;
	out.tail = NULL;
	return (out);
}

t_substr_list	*substr_list_new(const char *start, size_t len)
{
	t_substr_list	*out;
	t_substr		substr;

	out = malloc(sizeof(*out));
	substr.start = start;
	memcpy((void *)&(substr.len), &len, sizeof(len));
	memcpy((void *)&(out->substr), &substr, sizeof(substr));
	out->next = NULL;
	return (out);
}

void	substr_deque_push(t_substr_deque *l, const char *start,
		const size_t len)
{
	if (l->head == NULL)
	{
		l->head = substr_list_new(start, len);
		l->tail = l->head;
		return ;
	}
	l->tail->next = substr_list_new(start, len);
	l->tail = l->tail->next;
}

void			substr_deque_clear(t_substr_deque *l);
