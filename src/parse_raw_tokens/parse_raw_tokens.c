/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_raw_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:55:02 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 19:50:58 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdbool.h>
#include <string.h>

#define CONVERSION_SPECIFIERS "cspdiuxX%"

static bool	is_conversion_specifier(char c)
{
	return (strchr(CONVERSION_SPECIFIERS, c));
}

t_substr_list	split_raw_tokens(const char *format)
{
	t_substr_list	raw_tokens;
	const char		*start;

	raw_tokens = substr_list_new();
	while (*format)
	{
		start = format;
		if (*format != '%')
		{
			while (*format && *format != '%')
				format++;
			substr_list_push(&raw_tokens, start, format);
		}
		else
		{
			format++;
			while (!is_conversion_specifier(*format))
				format++;
			substr_list_push(&raw_tokens, start, ++format);
		}
	}
	return (raw_tokens);
}
