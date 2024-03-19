/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 18:24:29 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char* conversion_specifiers = "cspdiuxX%";

typedef struct
{
	const char* start;
	size_t len;
} t_substr;
 
// ---------------------------------------

bool is_specifier(char c)
{
	return strchr(conversion_specifiers, c);
}

char get_specifier(t_substr token)
{
	return token.start[token.len - 1];
}

void log_token(t_substr token)
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

	while (token.len != 0)
	{
		log_token(token);
		format += token.len;
		token = get_next_token(format);
	}

	return (0);
}
