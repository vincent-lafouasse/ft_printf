/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/20 14:40:34 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

#include <stdio.h>

// ---------------------------------------

void log_token(t_substr token)
{
    printf("token:\n\t");
    for (size_t i = 0; i < token.len; i++)
        printf("%c", token.start[i]);
    printf("\n");
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
