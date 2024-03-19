/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 17:47:27 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raw_tokens/split_raw_tokens.h"
#include "substring/t_substr_deque.h"
#include "tokens/t_tokens.h"

#include <stdio.h>

static void print_substring(t_substr substr)
{
	for (size_t i = 0; i < substr.len; i++)
	{
		printf("%c", substr.start[i]);
	}
}

int	ft_printf(const char *format, ...)
{
	t_substr_deque raw_tokens = split_raw_tokens(format);
	t_token current_token;

	while (!substr_deque_isempty(raw_tokens))
	{
		current_token = parse_raw_token(substr_deque_pop_front(&raw_tokens));
		if (current_token.type == LITERAL)
			print_substring(current_token.data.literal);
	}

	return (0);
}
