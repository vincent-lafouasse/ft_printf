/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr_deque.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:16:14 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 17:05:11 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SUBSTR_DEQUE_H
# define T_SUBSTR_DEQUE_H

# include "substring/t_substr.h"

typedef struct s_substr_list
{
	t_substr				substr;
	struct s_substr_list	*next;
}							t_substr_list;

t_substr_list				*substr_list_new(const char *start, size_t len);

typedef struct s_substr_deque
{
	t_substr_list			*head;
	t_substr_list			*tail;
}							t_substr_deque;

t_substr_deque				substr_deque_new(void);
void						substr_deque_push_back(t_substr_deque *l,
								const char *start, size_t len);
void						substr_deque_clear(t_substr_deque *l);

#endif
