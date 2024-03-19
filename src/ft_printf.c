/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 18:21:16 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char* conversion_specifiers = "cspdiuxX%";

bool is_specifier(char c)
{
	return strchr(conversion_specifiers, c);
}

typedef struct
{
	const char* start;
	size_t len;
} t_substr;

void print_token(t_substr token)
{
	printf("token:\n\t");
	for (size_t i = 0; i < token.len; i++)
		printf("%c", token.start[i]);
	printf("\n");
}

t_substr get_next_token(const char* format)
{
	t_substr token;

	token.start = format;

	if (*format != '%')
	{
		while (*format && !is_specifier(*format))
			format++;
		token.len = format - token.start;
	}
	else
	{
		format++;
		while (!is_specifier(*format))
			format++;
		token.len = format + 1 - token.start;
	}

	return token;
}

int	ft_printf(const char *format, ...)
{
	t_substr token;

	token = get_next_token(format);
	print_token(token);
	format += token.len;

	token = get_next_token(format);
	print_token(token);
	format += token.len;

	return (0);
}
