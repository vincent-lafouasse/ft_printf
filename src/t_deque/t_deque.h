/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_deque.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:53:09 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 16:05:38 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void* data;
	struct s_list* next;
} t_list;

t_list* lst_new(void* data);

typedef struct s_deque
{
	t_list* head;
	t_list* tail;
} t_deque;

t_deque deque_new(void);
void	deque_push_back(t_deque* p_deque, void* data);
void	deque_clear(t_deque* p_deque);
