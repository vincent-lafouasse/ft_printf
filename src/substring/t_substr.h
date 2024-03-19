/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_substr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:11:18 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 17:02:06 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SUBSTR_H
# define T_SUBSTR_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_substr
{
	const char		*start;
	size_t	len;
}					t_substr;

t_substr substr_make(const char* start, size_t len);
t_substr substr_make_none(void);
bool substr_is_none(t_substr substr);

#endif
