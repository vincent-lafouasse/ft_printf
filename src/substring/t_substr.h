/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:11:18 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 21:09:45 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SUBSTR_H
#define T_SUBSTR_H

#include <stddef.h>

typedef struct s_substr
{
    const char* start;
    const size_t len;
} t_substr;

#endif
