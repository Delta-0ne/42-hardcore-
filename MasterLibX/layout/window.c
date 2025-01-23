/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 11:32:29 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_C
# define VIEWPORT_C

/* ------ MODULES ------- */
// Locals :
# include "layout_types.h"
# include "window.h"
// Globals :
# include "memory.h"

/* ----- FUNCTIONS ------ */
// TODO :  shall introduce a killing option to kill the manager while we return
// the error value.

// comment ...
__attribute__((hot)) t_parent_window	*get_root_window(void)
{
	static t_parent_window	*root = NULL;

	if (__builtin_expect(root == NULL, unexpected))
	{
		// TODO : shall allocate here by manager
		root->server = XOpenDisplay(NULL);
		if (__builtin_expect(root->server == NULL
			|| init_context(root->server, &root->context) != no_error,
			unexpected))
			return (NULL);
		if (init_screen(root->server, &root->screen) != error)
		{
			root->screen.map = XCreateColormap(root->server,
				root->context.window, root->screen.visual, AllocNone);
			if (__builtin_expect(root->screen.map == NULL, unexpected))
				root->screen.map = DefaultColormap(root->server,
					root->screen.id);
		}
		get_color_encoding(&root->screen);
	}
	return (root);
}

__attribute__((hot)) t_child_window	*create_new_window(t_parent_window *root,
													const t_axis dimensions,
													t_cstr title)
{
	t_child_window			*window;
	XSetWindowAttributes	config;
	XGCValues				infos;

	config = (XSetWindowAttributes){.background_pixel = 0, .border_pixel = none,
			.colormap = root->screen.map, .event_mask = 0xFFFFFF};
	// TODO : allocate via manager the window.
	window->context.window = XCreateWindow(root->server, root->context.window,
		0, 0, dimensions.x, dimensions.y, 0,
		CopyFromParent, InputOutput, root->screen.visual,
		CWEventMask | CWBackPixel | CWBorderPixel | CWColormap,
		&config);
	XStoreName(root->server, window->context.window, title);
	infos = (XGCValues){.foreground = none, .function = GXcopy,
		.plane_mask = AllPlanes};
	window->context.graphical = XCreateGC(root->server, window->context.window,
		GCFunction | GCPlaneMask | GCForeground, &infos);
	XMapRaised(root->server, root->context.window);
	return (window);
}

#endif