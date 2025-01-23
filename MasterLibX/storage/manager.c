/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:51 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/23 12:38:06 by rcreuzea         ###   ########.fr       */
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
	if (__builtin_expect(!storage, unexpected))
		storage = create_storage(); 
	else if (__builtin_expect(destroy, unexpected))
		return (drop_storage(storage));
	return (storage);
}

#endif