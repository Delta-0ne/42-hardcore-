/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/22 14:59:34 by rcreuzea         ###   ########.fr       */
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
		// TODO : shall obtain the rgb encoding.
	}
	return (root);
}

#endif