/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 13:04:53 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARD_TYPES_H
# define STANDARD_TYPES_H

/* ------ MODULES ------- */
// Globals :
# include "dependencies.h"

/* ------- TYPES -------- */
// comment ...
typedef enum e_expectancy
{
	unexpected		= +0,
	expected		= +1
}	t_expectancy;

// comment ...
typedef enum e_side
{
	down			= +1,
	up				= +2,
	left			= +4,
	right			= +8
}	t_side;

// comment ...
typedef enum e_standards
{
	error			= -1,
	none			= -1,
	no_error		= +0
}	t_standards;

// comment ...
typedef enum e_colors
{
	black			= +0,
	// ...
	white			= +1
}	t_colors;

// Numbers :
typedef int_fast8_t		t_int8b;			// fast int 8 bits.
typedef int_fast16_t	t_int16b;			// fast int 16 bits.
typedef int_fast32_t	t_int32b;			// fast int 32 bits.
typedef int_fast64_t	t_int64b;			// fast int 64 bits.
typedef uint_fast8_t	t_uint8b;			// fast unsigned int 8 bits.
typedef uint_fast16_t	t_uint16b;			// fast unsigned int 16 bits.
typedef uint_fast32_t	t_uint32b;			// fast unsigned int 32 bits.
typedef uint_fast64_t	t_uint64b;			// fast unsigned int 64 bits.
typedef t_int32b		t_int;				// fast int.
typedef t_uint32b		t_uint;				// fast unsigned int.
typedef t_int64b		t_llong;			// fast long long.
typedef t_uint64b		t_ullong;			// fast unsigned long long.
// Characters & Strings :
typedef char			*t_buffer;			// char buffer.
typedef char			*t_str;				// string.
typedef t_buffer		const t_c_buffer;	// constant buffer pointer.
typedef t_str			const t_c_str;		// constant string pointer.
typedef const char		*t_cbuffer;			// constant buffer content.
typedef const char		*t_cstr;			// constant string content.
// Control :
typedef t_int8b			t_anymode;			// any mode.
typedef t_int8b			t_s_size;			// small size.
typedef t_int32b		t_l_size;			// large size.
typedef t_uint8b		t_id;				// id of the windows (there shouldn't be much of them).
// Structs :
typedef struct s_axis	t_point;
// Address :
typedef void			*t_ptr;				// pointer.

/* ------ STRUCTS ------- */
// TODO : Could limit values of t_axis with some bitfields depending on the use we have.

// comment ...
typedef struct s_axis
{
	t_uint32b	x;
	t_uint32b	y;
	t_uint32b	z;
}	t_axis;

// comment ...
typedef struct s_line
{
	t_point		a;
	t_point		b;
}	t_line;

// TODO ; it should be renamed better.

// comment ...
typedef struct s_interaction
{
	t_axis		start;
	t_axis		end;

	// TODO : those are not really defined some make sure it's usefull and well defined.
	t_uint16b	button;
	t_uint16b	action;
}	t_interaction;

// comment ...
typedef struct s_color
{
	t_uint8b	r		: 8;
	t_uint8b	g		: 8;
	t_uint8b	b		: 8;
	t_uint8b	a		: 8;
}	t_color;

// comment ...
typedef struct s_encoding
{
	t_uint8b	shift	: 5;
	t_uint8b	len		: 5;
}	t_encoding;

// comment ...
typedef struct s_color_encoding
{
	t_encoding	r;
	t_encoding	g;
	t_encoding	b;
}	t_color_encoding;

// This table is limited to the window referencement inside the manager.
typedef struct s_table
{
	t_s_size	size;
	t_s_size	len;
	void		*list;
}	t_table;

#endif