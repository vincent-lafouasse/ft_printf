/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:16:14 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 20:06:24 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SUBSTR_LIST_H
# define T_SUBSTR_LIST_H

# include "substring/t_substr.h"

typedef struct s_substr_node
{
	const t_substr			substr;
	struct s_substr_node	*next;
}							t_substr_node;

t_substr_node				*substr_node_new(const char *start,
								const char *end);

typedef struct s_substr_list
{
	t_substr_node			*head;
	t_substr_node			*tail;
}							t_substr_list;

t_substr_list				substr_list_new(void);
void						substr_list_push(t_substr_list *l,
								const char *start, const char *end);
void						substr_list_clear(t_substr_list *l);

#endif
