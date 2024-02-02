/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lexeme.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:11:18 by poss              #+#    #+#             */
/*   Updated: 2024/01/24 07:13:50 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LEXEME_H
# define T_LEXEME_H

# include <stdbool.h>

typedef struct s_lexeme
{
	const char	*start;
	const char	*end;
}				t_lexeme;

#endif
