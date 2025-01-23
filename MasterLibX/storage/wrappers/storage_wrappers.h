/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_wrappers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:00:32 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/01/23 13:30:41 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_WRAPPERS_H
# define STORAGE_WRAPPERS_H

/* ------ MODULES ------- */
// Locals :
# include "storage_types.h"

/* ------ INLINES ------- */
// comment ...
static inline t_storage	storage_wrapper(const t_parent_window *root,
										const t_table *table)
{
	return ((t_storage){
		.root = *root,
		.table = *table
		}
	);
}

#endif