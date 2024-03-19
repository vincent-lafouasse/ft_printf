/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:24:35 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 17:36:57 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens/t_tokens.h"

static t_format_token parse_format_token(t_substr raw_token)
{
	t_format_token format_token;
	char conversion_specifier = raw_token.start[raw_token.len - 1];

	if (conversion_specifier == 'c')
		format_token.type = CHAR;
	else if (conversion_specifier == 's')
		format_token.type = STRING;
	else if (conversion_specifier == 'p')
		format_token.type = POINTER;
	else if (conversion_specifier == 'd' || conversion_specifier == 'i')
		format_token.type = SIGNED;
	else if (conversion_specifier == 'u')
		format_token.type = UNSIGNED;
	else if (conversion_specifier == 'x')
		format_token.type = LOWERCASE_HEX;
	else if (conversion_specifier == 'X')
		format_token.type = UPPERCASE_HEX;
	else if (conversion_specifier == '%')
		format_token.type = PERCENT;
	else
		format_token.type = INVALID;
	return format_token;
}

t_token parse_raw_token(t_substr raw_token)
{
	t_token token;

	if (raw_token.len == 0 || raw_token.start[0] != '%')
	{
		token.type = LITERAL;
		token.data.literal = raw_token;
		return token;
	}
	token.type = FORMAT;
	token.data.format = parse_format_token(raw_token);
	return token;
}
