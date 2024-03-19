/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr_deque.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:25:23 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 17:20:12 by poss             ###   ########.fr       */
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

	out = malloc(sizeof(*out));
	out->substr = substr_make(start, len);
	out->next = NULL;
	return (out);
}

void	substr_deque_push_back(t_substr_deque *l, const char *start,
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

bool substr_deque_isempty(t_substr_deque deque)
{
	return deque.head == NULL;
}

t_substr					substr_deque_pop_front(t_substr_deque *p_deque)
{
	if (p_deque == NULL || substr_deque_isempty(*p_deque))
		return substr_make_none();

	t_substr out = p_deque->head->substr;
	t_substr_list* new_head = p_deque->head->next;
	free(p_deque->head);
	p_deque->head = new_head;

	return out;
}

void substr_deque_clear(t_substr_deque *p_deque);
