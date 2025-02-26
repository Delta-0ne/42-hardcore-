/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 12:40:53 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_TYPES_H
# define LAYOUT_TYPES_H

/* ------ MODULES ------- */
// Globals :
# include "standard_types.h"

/* ------- TYPES -------- */
// Space :
typedef struct s_dimensions	t_position;

/* ------ STRUCTS ------- */
// TODO : perhaps we shall change the name of t_dimensions.
// comment ...
typedef struct s_dimensions
{
	t_axis				actual;
	t_axis				initial;
}	t_dimensions;

// comment ...
typedef struct s_context
{
	Window				window;
	GC					graphical;
}	t_context;

// comment ...
typedef struct s_screen
{
	t_int8b				id;
	t_uint32b			depth;
	Colormap			map;
	Visual				*visual;
	t_color_encoding	encoding;
}	t_screen;

// comment ...
typedef struct s_config
{
	t_color				color;
	t_dimensions		dimension;
	t_position			position;
}	t_config;

// TODO : Shall rename those as the parent isn't a parent bu simply a host on which
// we add windows, thus child is just a window.

// comment ...
typedef struct s_parent_window
{
	Display				*server;
	t_context			context;
	t_screen			screen;
	t_config			config;
}	t_parent_window;

typedef struct s_viewport
{
	t_context			context;
	t_config			config;
}	t_child_window;

#endif