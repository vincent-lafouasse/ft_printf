/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/25 15:59:18 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize/tokenize.h"
#include "print/print.h"

int	ft_printf(const char *format, ...)
{
	t_substr	token;
	size_t		total_len;
	va_list		args;

	total_len = 0;
	va_start(args, format);
	token = get_next_token(format);
	while (token.len != 0)
	{
		total_len += print_token(token, args);
		format += token.len;
		token = get_next_token(format);
	}
	va_end(args);
	return (total_len);
}
