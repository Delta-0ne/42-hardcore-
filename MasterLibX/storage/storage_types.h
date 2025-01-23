/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 13:24:57 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_TYPES_H
# define STORAGE_TYPES_H

/* ------ MODULES ------- */
// Locals :
// TODO : In this exact case we should introduce the module API to access obscure definitions.
# include "layout_types.h"

// Globals :
# include "standard_types.h"

/* ------- MACROS ------- */

# define DEFAULT_MAX_WINDOW	10

/* ------- TYPES -------- */
// ...

/* ------ STRUCTS ------- */
// comment ...
typedef struct s_storage
{
	t_parent_window	root;
	// TODO :  shall rename properly that .
	t_table			table;
	// TODO : shall add what's needed to create an image and all the other stuff
	// that needs to be allocated.
}	t_storage;

#endif