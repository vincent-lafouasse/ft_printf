/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:55:02 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 08:06:51 by poss             ###   ########.fr       */
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

t_lexeme_list	split_lexemes(const char *format)
{
	t_lexeme_list	lexemes;
	const char		*start;

	lexemes = lexeme_list_new();
	while (*format)
	{
		start = format;
		if (*format != '%')
		{
			while (*format && *format != '%')
				format++;
			lexeme_list_push(&lexemes, start, format);
		}
		else
		{
			while (!is_conversion_specifier(*format))
				format++;
			lexeme_list_push(&lexemes, start, ++format);
		}
	}
	return (lexemes);
}
