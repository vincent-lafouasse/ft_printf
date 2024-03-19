/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:01:06 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 17:02:45 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substring/t_substr.h"

t_substr substr_make(const char* start, size_t len)
{
	t_substr out;

	out.start = start;
	out.len = len;
	return out;
}

t_substr substr_make_none(void)
{
	return substr_make(NULL, 0);
}

bool substr_is_none(t_substr substr)
{
	return substr.start = NULL;
}
