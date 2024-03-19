/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tokens.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:27 by poss              #+#    #+#             */
/*   Updated: 2024/03/19 14:53:42 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "substring/t_substr.h"

typedef enum
{
	SIGNED,
	UNSIGNED,
	STRING,
	CHAR,
	UPPERCASE_HEX,
	LOWERCASE_HEX,
	POINTER,
	PERCENT,
}							t_type_specifier;

typedef enum
{
	NONE,
	LONG,
}							t_type_modifier;

typedef struct
{
	const t_type_specifier	type;
	const t_type_modifier	type_modifier;
	const size_t			minimum_field_width;
	const size_t			precision;
	const bool				pad_left;
	const char				pad_with;
	const bool				show_sign;
}							t_format_token;

// ----------------------------------------------------------------------------

typedef enum
{
	LITERAL,
	FORMAT,
}							t_token_type;

typedef union
{
	t_substr				literal;
	t_format_token			format;
}							t_any_token;

typedef struct
{
	t_token_type			type;
	t_any_token				data;
}							t_token;
