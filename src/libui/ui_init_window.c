/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:33:26 by fjacquem          #+#    #+#             */
/*   Updated: 2018/09/08 17:15:40 by fjacquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_component		*ui_init_window(const char *title, int width, int height)
{
	t_window	*w;
	t_ui		*data;

	data = ui_data();
	if (data->ready == 0)
	{
		SDL_Init(SDL_INIT_VIDEO);
		data->ready = 1;
	}
	w = (t_window*)malloc(sizeof(t_window));
	if (!w)
		return (NULL);
	w->title = (char*)title;
	w->width = width;
	w->height = height;
	w->win = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, 0
    );
    return (ui_init_component(COMPONENT_WINDOW, w));
}
