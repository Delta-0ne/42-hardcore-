/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcreuzea <rcreuzea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:10:47 by rcreuzea          #+#    #+#             */
/*   Updated: 2025/01/22 11:23:17 by rcreuzea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/* ------ MODULES ------- */
// Locals :
# include "standard_types.h"

/* ------ INLINES ------- */

// TODO : shall modify (universalize) the following functions.

// comment ...
static inline t_int8b	alloc(void **buffer, const t_l_size size)
{
	*buffer = (void *)malloc(size);
	if (__builtin_expect(!*buffer, unexpected))
		return (error);
	return (no_error);
}

// comment ...
static inline void	set0(t_buffer buffer, t_l_size size)
{
	while (size--)
		buffer[size] = 0;
}

// comment ...
static inline t_l_size	transfer(t_buffer area, const t_str data, t_l_size len)
{
	register t_l_size	i;

	i = 0;
	while (data[i] != '\0' && len--)
	{
		area[i] = data[i];
		++i;
	}
	return (i);
}

#endif