/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 13:02:20 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_TYPES_H
# define STORAGE_TYPES_H

/* ------ MODULES ------- */
// Globals :
# include "standard_types.h"

/* ------- MACROS ------- */

# define MAX_WINDOW	10

/* ------- TYPES -------- */
// ...

/* ------ STRUCTS ------- */
// comment ...
typedef struct s_storage
{
	t_parent_window	root;
	t_child_window	*child;
	t_s_size		qty;
	t_s_size		size;
}	t_storage;

#endif