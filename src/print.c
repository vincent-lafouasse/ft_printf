/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:35:32 by poss              #+#    #+#             */
/*   Updated: 2024/03/25 15:47:31 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print.h"
#include <unistd.h>

#define STDOUT 1
#define NULL_POINTER_REPR "(nil)"
#define DECIMAL "0123456789"
#define LOWERCASE_HEX "0123456789abcdef"
#define UPPERCASE_HEX "0123456789ABCDEF"
#define POINTER_PREFIX "0x"

static char	get_specifier(t_substr token);

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

size_t	print_pointer(va_list args)
{
	const void	*to_print = va_arg(args, void *);

	if (to_print == NULL)
	{
		ft_putstr_fd(NULL_POINTER_REPR, STDOUT);
		return (ft_strlen(NULL_POINTER_REPR));
	}
	ft_putstr_fd(POINTER_PREFIX, STDOUT);
	ft_put_unsigned((uint64_t)to_print, LOWERCASE_HEX);
	return (ft_strlen(POINTER_PREFIX) + get_n_digits((uint64_t)to_print,
			ft_strlen(LOWERCASE_HEX)));
}

static char	get_specifier(t_substr token)
{
	return (token.start[token.len - 1]);
}
