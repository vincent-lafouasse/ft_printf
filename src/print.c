/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:35:32 by poss              #+#    #+#             */
/*   Updated: 2024/03/22 12:58:14 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

#define STDOUT 1
#define NULL_STRING_REPR "(null)"
#define NULL_POINTER_REPR "(nil)"
#define DECIMAL "0123456789"
#define LOWERCASE_HEX DECIMAL "abcdef"
#define UPPERCASE_HEX DECIMAL "ABCDEF"
#define POINTER_PREFIX "0x"

static size_t		print_unsigned(va_list args, const char* charset);
static size_t		print_integer(va_list args);
static size_t		print_pointer(va_list args);
static size_t		print_literal(t_substr literal);
static size_t		print_percent(void);
static char			get_specifier(t_substr token);
static size_t		get_n_digits(uint64_t n, size_t base);
static unsigned int	ft_abs(int n);

static void	ft_put_unsigned(uint64_t n, const char* charset)
{
	size_t base = ft_strlen(charset);
	if (n < base)
		ft_putchar_fd(charset[n], STDOUT);
	else
	{
		ft_put_unsigned(n / base, charset);
		ft_put_unsigned(n % base, charset);
	}
}

static size_t	print_char(va_list args)
{
	ft_putchar_fd(va_arg(args, int), STDOUT);
	return (1);
}

static size_t	print_string(va_list args)
{
	const char	*to_print = va_arg(args, const char *);

	if (!to_print)
		to_print = NULL_STRING_REPR;
	ft_putstr_fd(to_print, STDOUT);
	return (ft_strlen(to_print));
}

size_t	print_token(t_substr token, va_list args)
{
	char	conversion_specifier;

	if (token.start[0] != '%')
		return (print_literal(token));
	conversion_specifier = get_specifier(token);
	if (ft_strchr("id", conversion_specifier))
		return (print_integer(args));
	if (conversion_specifier == '%')
		return (print_percent());
	if (conversion_specifier == 'c')
		return (print_char(args));
	if (conversion_specifier == 'u')
		return (print_unsigned(args, DECIMAL));
	if (conversion_specifier == 'x')
		return (print_unsigned(args, LOWERCASE_HEX));
	if (conversion_specifier == 'X')
		return (print_unsigned(args, UPPERCASE_HEX));
	if (conversion_specifier == 's')
		return (print_string(args));
	if (conversion_specifier == 'p')
		return (print_pointer(args));
	return (0);
}

size_t	print_integer(va_list args)
{
	int	to_print;

	to_print = va_arg(args, int);
	ft_putnbr_fd(to_print, STDOUT);
	if (to_print == 0)
		return (1);
	return (to_print < 0) + get_n_digits(ft_abs(to_print), 10);
}

static size_t	print_unsigned(va_list args, const char* charset)
{
	uint64_t	to_print;

	to_print = va_arg(args, unsigned int);
	ft_put_unsigned(to_print, charset);
	if (to_print == 0)
		return (1);
	return (get_n_digits(to_print, ft_strlen(charset)));
}

static size_t		print_pointer(va_list args)
{
	const void* to_print = va_arg(args, void*);

	if (to_print == NULL)
	{
		ft_putstr_fd(NULL_POINTER_REPR, STDOUT);
		return (ft_strlen(NULL_POINTER_REPR));
	}
	ft_putstr_fd(POINTER_PREFIX, STDOUT);
	ft_put_unsigned((uint64_t)to_print, LOWERCASE_HEX);
	return ft_strlen(POINTER_PREFIX) + get_n_digits((uint64_t)to_print, ft_strlen(LOWERCASE_HEX));
}

size_t	print_literal(t_substr literal)
{
	size_t	i;

	i = 0;
	while (i < literal.len)
		ft_putchar_fd(literal.start[i++], STDOUT);
	return (literal.len);
}

static size_t	print_percent(void)
{
	ft_putchar_fd('%', STDOUT);
	return (1);
}

char	get_specifier(t_substr token)
{
	return (token.start[token.len - 1]);
}

static size_t	get_n_digits(uint64_t n, size_t base)
{
	size_t	n_digits;

	n_digits = 0;
	while (n)
	{
		n_digits++;
		n /= base;
	}
	return (n_digits);
}

static unsigned int	ft_abs(int n)
{
	return (((n >= 0) - (n < 0)) * n);
}
