/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:35:32 by poss              #+#    #+#             */
/*   Updated: 2024/03/20 18:50:45 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static size_t	print_integer(va_list args);
static size_t	print_literal(t_substr literal);
static size_t	print_percent(void);
static char		get_specifier(t_substr token);

size_t	print_token(t_substr token, va_list args)
{
	char	conversion_specifier;

	if (token.start[0] != '%')
		return (print_literal(token));
	conversion_specifier = get_specifier(token);
	if (strchr("id", conversion_specifier))
		return (print_integer(args));
	if (conversion_specifier == '%')
		return (print_percent());
	return (0);
}

const char		*null_repr = "(null)";

size_t	print_integer(va_list args)
{
	int	to_print;

	to_print = va_arg(args, int);
	return (printf("%d", to_print));
}

size_t	print_literal(t_substr literal)
{
	for (size_t i = 0; i < literal.len; i++)
		printf("%c", literal.start[i]);
	return (literal.len);
}

static size_t	print_percent(void)
{
	write(1, "%", 1);
	return 1;
}

char	get_specifier(t_substr token)
{
	return (token.start[token.len - 1]);
}
