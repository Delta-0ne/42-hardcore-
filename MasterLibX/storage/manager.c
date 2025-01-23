/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 13:40:53 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_C
# define MANAGER_C

/* ------ MODULES ------- */
// Locals :
# include "storage.h"

/* ----- FUNCTIONS ------ */
// comment ...
__attribute__((hot)) static t_storage	*get_storage(const t_int8b destroy)
{
	static t_storage	*storage = NULL;

	if (__builtin_expect(!storage, unexpected))
		storage = create_storage(); 
	else if (__builtin_expect(destroy, unexpected))
		return (drop_storage(storage));
	return (storage);
}

// TODO :
//	- We must create the accessing functions of the storage without exposing it,
//	It does concern window accessing, window creation and image storage.

#endif