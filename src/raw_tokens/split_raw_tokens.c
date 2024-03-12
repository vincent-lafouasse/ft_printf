/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_raw_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:55:02 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 21:15:02 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raw_tokens/split_raw_tokens.h"
#include <stdbool.h>
#include <string.h>

#define CONVERSION_SPECIFIERS "cspdiuxX%"

static bool	is_conversion_specifier(char c)
{
	return (strchr(CONVERSION_SPECIFIERS, c));
}

t_substr_deque	split_raw_tokens(const char *format)
{
	t_substr_deque	raw_tokens;
	const char		*start;

	raw_tokens = substr_deque_new();
	while (*format)
	{
		start = format;
		if (*format != '%')
		{
			while (*format && *format != '%')
				format++;
			substr_deque_push(&raw_tokens, start, format - start);
		}
		else
		{
			format++;
			while (!is_conversion_specifier(*format))
				format++;
			substr_deque_push(&raw_tokens, start, format + 1 - start);
			format++;
		}
	}
	return (raw_tokens);
}
