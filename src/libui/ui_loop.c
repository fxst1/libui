#include "libui.h"

void	ui_loop()
{
	t_ui		*data;
	t_list		*components;
	t_component	*c;
	SDL_Event	event;

	data = ui_data();
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_Quit();
				return ;
			}
		}
		components = data->components;
		if (data->ready)
			while (components)
			{
				c = components->content;
				if (c && !c->hidden)
				{

				}
				components = components->next;
			}
		else
			break ;
	}
	SDL_Quit();
}
