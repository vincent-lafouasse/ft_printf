/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/20 14:31:59 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

const char* conversion_specifiers = "cspdiuxX%";

const char* null_repr = "(null)";

typedef struct
{
    const char* start;
    size_t len;
} t_substr;

// ---------------------------------------

size_t print_integer(va_list args)
{
    int to_print = va_arg(args, int); 
    return printf("%d", to_print);
}

size_t print_literal(t_substr literal)
{
    for (size_t i = 0; i < literal.len; i++)
        printf("%c", literal.start[i]);
    return literal.len;
}

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

size_t print_token(t_substr token, va_list args)
{
    if (token.start[0] != '%')
        return print_literal(token);
    
    char conversion_specifier = get_specifier(token);
    if (strchr("id", conversion_specifier))
        return print_integer(args);
    return 0;
}

int ft_printf(const char* format, ...)
{
    t_substr token;
    size_t total_len = 0;
    va_list args;

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
