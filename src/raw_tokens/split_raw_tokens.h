/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_raw_tokens.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:14:06 by poss              #+#    #+#             */
/*   Updated: 2024/03/17 16:05:49 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_RAW_TOKENS_H
# define SPLIT_RAW_TOKENS_H

# include "substring/t_substr_deque.h"

t_substr_deque	split_raw_tokens(const char *format);

#endif
