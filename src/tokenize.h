/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:33:59 by poss              #+#    #+#             */
/*   Updated: 2024/03/22 13:00:17 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <stddef.h>

typedef struct
{
	const char	*start;
	size_t		len;
}				t_substr;

t_substr		get_next_token(const char *format);

#endif
