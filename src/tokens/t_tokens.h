#include <stdbool.h>
#include <stddef.h>

#include "substring/t_substr.h"

typedef enum
{
	SIGNED,
	UNSIGNED,
	STRING,
	CHAR,
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
