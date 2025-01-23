/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:00:32 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/01/23 13:37:59 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_H
# define STORAGE_H

/* ------ MODULES ------- */
// Locals :
# include "storage_wrappers.h"

// Globals :
# include "memory.h"

/* ------ INLINES ------- */
// comment ...
static inline t_storage	*create_storage(void)
{
	t_storage	*storage;
	t_buffer	allocation;

	if (__builtin_expect(alloc((t_ptr *)(&storage),
			sizeof(t_storage)
			+ sizeof(t_table)
			+ DEFAULT_MAX_WINDOW * sizeof(t_ptr))
			!= no_error, unexpected))
		return (NULL);
	// TODO : i think this segmentation isn't good thus it shall be verified.
	allocation = (t_buffer)storage + sizeof(t_storage);
	storage->table.list = (t_ptr)(allocation);
	// TODO : everything should be set to the associated default values.
	return (storage);
}

// comment ...
static inline t_storage	*drop_storage(t_storage *storage)
{
	t_storage	*temp;

	temp = storage;
	storage = NULL;
	return (temp);
}

#endif