/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_deque.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:01:03 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 16:08:50 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_deque/t_deque.h"
#include <stdlib.h>

t_list* lst_new(void* data)
{
	t_list* lst;

	lst = malloc(sizeof(*lst));
	if (lst == NULL)
		return NULL;
	lst->data = data;
	lst->next = NULL;
	return lst;
}

t_deque deque_new(void)
{
	t_deque deque;

	deque.head = NULL;
	deque.tail = NULL;
	return deque;
}

void	deque_push_back(t_deque* p_deque, void* data)
{
	if (p_deque == NULL)
		return;

	t_list* new_node = lst_new(data);

	if (new_node == NULL)
		return;

	if (p_deque->head == NULL)
	{
		p_deque->head = new_node;
		p_deque->tail = new_node;
		return;
	}

	p_deque->tail->next = new_node;
	p_deque->tail = p_deque->tail->next;
}

void	deque_clear(t_deque* deque);
