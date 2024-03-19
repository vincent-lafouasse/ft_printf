/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 22:22:48 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

const char* conversion_specifiers = "cspdiuxX%";

typedef struct
{
    const char* start;
    size_t len;
} t_substr;

// ---------------------------------------

size_t print_char(unsigned char c)
{
    return printf("%c", c);
}
size_t print_string(const char* s)
{
    return printf("%s", s);
}
size_t print_pointer(void* p)
{
    return printf("%p", p);
}
size_t print_integer(int i)
{
    return printf("%i", i);
}
size_t print_unsigned(unsigned int);
size_t print_lowercase_hex(unsigned int);
size_t print_uppercase_hex(unsigned int);
size_t print_literal(t_substr);

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

size_t print_token(const t_substr* token, va_list args);

int ft_printf(const char* format, ...)
{
    t_substr token;
    size_t total_len = 0;
    va_list args;

    va_start(args, format);

    token = get_next_token(format);

    while (token.len != 0)
    {
        total_len += print_token(&token, args);
        format += token.len;
        token = get_next_token(format);
    }

    va_end(args);

    return (total_len);
}
