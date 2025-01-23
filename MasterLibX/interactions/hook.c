/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:55 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 12:49:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactions.h"

void	mousse_click_hook(int indice, void (*callback)(int, int, int),
						void *usr_data)
{
	
}

// rajouter le truc de romain pour gerer la femture de la fenetre
void	main_hook(XEvent *event, Display *server, void (*callback)(),
					void *usr_data)
{
	XNextEvent(server, event);
	if (event->type == KeyPress || event->type == KeyRelease)
		callback(event->xkey.keycode, event->xkey.state, usr_data);
	else if (event->type == ButtonPress || event->type == ButtonRelease)
		callback(event->xbutton.button, event->xbutton.x, event->xbutton.y,
			usr_data);
	else if (event->type == MotionNotify)
		callback(event->xmotion.x, event->xmotion.y, usr_data);
	else if (event->type == ConfigureNotify)
		callback(event->xconfigure.width, event->xconfigure.height, usr_data);
	else if (event->type == Expose)
		callback(usr_data);
	else if (ClientMessage)
		if (event->xclient.data.l[0] == (long)XInternAtom(server,
				"WM_DELETE_WINDOW", False))
			return ;
}
