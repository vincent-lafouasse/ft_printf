/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_raw_tokens.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:14:06 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 20:13:35 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include "substring/t_substr_deque.h"

t_substr_deque split_raw_tokens(const char* format);

#endif
