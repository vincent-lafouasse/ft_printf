/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexeme_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:16:14 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 07:23:30 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LEXEME_LIST_H
#define T_LEXEME_LIST_H

#include "t_lexeme.h"

typedef struct s_lexeme_node
{
	const t_lexeme lexeme;
	struct s_lexeme_node* next;
} t_lexeme_node;

typedef struct s_lexeme_list {
	t_lexeme_node* head;
	t_lexeme_node* tail;
} t_lexeme_list;

t_lexeme_list lexeme_list_new(void);
void lexeme_list_push(t_lexeme_list* l, const char* start, const char* end);
void lexeme_list_clear(t_lexeme_list* l);

#endif
