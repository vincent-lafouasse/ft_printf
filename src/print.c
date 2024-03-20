/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:35:32 by poss              #+#    #+#             */
/*   Updated: 2024/03/20 23:59:05 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define STDOUT 1
#define NULL_REPR "(null)"

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

size_t	print_integer(va_list args)
{
	int	to_print;

	to_print = va_arg(args, int);
	return (printf("%d", to_print));
}

size_t	print_literal(t_substr literal)
{
	size_t i = 0;

	while (i < literal.len)
		ft_putchar_fd(literal.start[i++], STDOUT);
		
	return (literal.len);
}

static size_t	print_percent(void)
{
	ft_putchar_fd('%', STDOUT);
	return 1;
}

char	get_specifier(t_substr token)
{
	return (token.start[token.len - 1]);
}
