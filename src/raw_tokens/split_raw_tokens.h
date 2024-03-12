/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_raw_tokens.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:14:06 by poss              #+#    #+#             */
/*   Updated: 2024/03/12 20:05:11 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "substring/t_substr_list.h"

t_substr_list	split_raw_tokens(const char *format);

#endif
