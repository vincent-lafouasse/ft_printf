/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:38:50 by poss              #+#    #+#             */
/*   Updated: 2024/03/20 14:39:44 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include <stdbool.h>
#include <string.h>

const char* conversion_specifiers = "cspdiuxX%";

bool is_specifier(char c)
{
    return strchr(conversion_specifiers, c);
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
