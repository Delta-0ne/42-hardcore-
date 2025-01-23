/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 10:54:59 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

/* ------ MODULES ------- */
// Locals :
# include "layout_types.h"

/* ------ INLINES ------- */
// comment ...
static inline t_int8b	init_context(Display *const server,
									t_context *const context)
{
	context->window = DefaultRootWindow(server);
	return (no_error);
}

// comment ...
static inline t_int8b	init_screen(Display *const server,
									t_screen *const screen)
{
	XVisualInfo	*infos;

	__attribute__((unused)) XVisualInfo config;
	__attribute__((unused)) int			no_warn;
	screen->id = DefaultScreen(server);
	screen->depth = DefaultDepth(server, screen->id);
	screen->visual = DefaultVisual(server, screen->id);
	if (screen->visual->class == TrueColor)
		return (no_error);
	config = (XVisualInfo){.class = TrueColor, .depth = screen->depth};
	infos = XGetVisualInfo(server, VisualDepthMask | VisualClassMask, &config,
			&no_warn);
	if (__builtin_expect(infos != NULL, unexpected))
	{
		screen->visual = infos->visual;
		return (no_error);
	}
	return (error);
}

# if defined(__GNUC__)

// comment ...
static inline void	get_color_encoding(t_screen *const screen)
{
	const t_uint32b	red_mask = screen->visual->red_mask;
	const t_uint32b	green_mask = screen->visual->green_mask;
	const t_uint32b	blue_mask = screen->visual->blue_mask;

	screen->encoding = (t_color_encoding){0};
	if (__builtin_expect(red_mask != 0, unexpected))
	{
		screen->encoding.r.shift = __builtin_ctz(red_mask);
		screen->encoding.r.len = __builtin_ctz(~(rm >> screen->encoding.r.shift));
	}
	if (__builtin_expect(green_mask != 0, unexpected))
	{
		screen->encoding.g.shift = __builtin_ctz(green_mask);
		screen->encoding.g.len = __builtin_ctz(~(rm >> screen->encoding.g.shift));
	}
	if (__builtin_expect(blue_mask != 0, unexpected))
	{
		screen->encoding.b.shift = __builtin_ctz(blue_mask);
		screen->encoding.b.len = __builtin_ctz(~(rm >> screen->encoding.b.shift));
	}
}

# else

// comment ...
static inline void	get_color_encoding(t_screen *const screen)
{
	const t_uint32b	red_mask = screen->visual->red_mask;
	const t_uint32b	green_mask = screen->visual->green_mask;
	const t_uint32b	blue_mask = screen->visual->blue_mask;

	screen->encoding = (t_color_encoding){0};
	while (!(red_mask & 1) && ++screen->encoding.r.shift)
		red_mask >>= 1;
	while (red_mask & 1 && ++screen->encoding.r.len)
		red_mask >>= 1;
	while (!(green_mask & 1) && ++screen->encoding.g.shift)
		green_mask >>= 1;
	while (green_mask & 1 && ++screen->encoding.g.len)
		green_mask >>= 1;
	while (!(blue_mask & 1) && ++screen->encoding.b.shift)
		blue_mask >>= 1;
	while (blue_mask & 1 && ++screen->encoding.b.len)
		blue_mask >>= 1;
}

# endif

#endif