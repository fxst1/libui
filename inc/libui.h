#ifndef LIBUI_H
# define LIBUI_H
# include <SDL2/SDL.h>
# include "libft.h"
# include "component.h"
# include "document.h"

typedef struct		s_ui
{
	int				ready:1;
	t_list			*components;
}					t_ui;

t_component			*ui_init_window(const char *title, int width, int height);
void				ui_show(t_component *c);
void				ui_loop(void);
t_ui				*ui_data(void);

#endif
