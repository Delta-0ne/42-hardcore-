/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:36:08 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 12:44:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <stdio.h>

#include "interactions.h"

void	key_hook_proc(int keycode, int status, void *usr_data)
{
	printf("Mouse hook, %d, %d\n", keycode, status);
	if (keycode == 9)
	{
		printf("Exiting\n");
		exit(0);
	}
}

void	mouse_hook_proc(int button, int x, int y, void *usr_data)
{
	printf("Mouse hook, %d, %d, %d\n", button, x, y);
}

int main(void)
{
	Display *display;
	Window window;
	unsigned long event_mask;

	display = XOpenDisplay(NULL);
	window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, 800, 600, 1, 0, 0);

	// Définir un masque pour les événements que l'on souhaite recevoir
	event_mask = ExposureMask | KeyPressMask | ButtonPressMask;

	// Appliquer le masque à la fenêtre
	XSelectInput(display, window, event_mask);

	// Afficher la fenêtre
	XMapWindow(display, window);

	XEvent event;

	while (1)
	{
		main_hook(&event, display, callback, NULL);
	}
}