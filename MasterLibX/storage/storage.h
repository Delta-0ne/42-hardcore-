/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:00:32 by delta_0ne         #+#    #+#             */
/*   Updated: 2025/01/23 12:39:57 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_H
# define STORAGE_H

/* ------ MODULES ------- */
// Globals :
# include "storage_types.h"

/* ------ INLINES ------- */
// comment ...
static inline t_storage	*create_storage(void)
{
	t_storage	*storage;
	t_buffer	allocation;

	if (__builtin_expect(_int_alloc((t_ptr *)(&storage),
			sizeof(t_storage)
			+ sizeof(t_track)
			+ sizeof(t_composer) + COMPOSER_SIZE
			+ sizeof(t_manager) + MANAGER_SIZE
			+ sizeof(t_buffer)) != true, unexpected))
		return (NULL);
	allocation = (t_buffer)storage;
	*storage = __int__storage_wrapper(
			track_wrapper(NULL, NULL),
			__int__composer_wrapper(COMPOSER_SIZE,
				(t_buffer)(allocation + sizeof(t_storage) + sizeof(t_track)
					+ sizeof(t_composer))),
			__int__manager_wrapper(MANAGER_SIZE,
				(t_buffer)(allocation + sizeof(t_storage) + sizeof(t_track)
					+ sizeof(t_composer) + COMPOSER_SIZE + sizeof(t_manager)))
			);
	return (_int_set0(storage->manager.buffer, storage->manager.size), storage);
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