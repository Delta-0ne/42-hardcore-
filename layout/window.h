/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/22 14:59:03 by rcreuzea         ###   ########.fr       */
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

#endif