/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:38:17 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 16:26:52 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raw_tokens/split_raw_tokens.h"

int	ft_printf(const char *format, ...)
{
	t_substr_deque raw_tokens = split_raw_tokens(format);

	return (0);
}
