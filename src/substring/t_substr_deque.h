/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr_deque.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:16:14 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 20:12:00 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SUBSTR_DEQUE_H
# define T_SUBSTR_DEQUE_H

# include "substring/t_substr.h"

typedef struct s_substr_list
{
	const t_substr			substr;
	struct s_substr_list	*next;
}							t_substr_list;

t_substr_list				*substr_list_new(const char *start,
								const char *end);

typedef struct s_substr_deque
{
	t_substr_list			*head;
	t_substr_list			*tail;
}							t_substr_deque;

t_substr_deque				substr_deque_new(void);
void						substr_deque_push(t_substr_deque *l,
								const char *start, const char *end);
void						substr_deque_clear(t_substr_deque *l);

#endif
