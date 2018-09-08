#ifndef	COMPONENT_H
# define COMPONENT_H
# include "document.h"
# define COMPONENT_UNDEF 0
# define COMPONENT_WINDOW 1
# define COMPONENT_TEXT 2
# define COMPONENT_BUTTON 3

typedef struct			s_style
{
}						t_style;

typedef struct			s_button
{
}						t_button;

typedef struct			s_text
{
	SDL_Surface			*surface;
}						t_text;

typedef struct			s_window
{
	SDL_Window			*win;
	char				*title;
	int					width;
	int					height;
}						t_window;

typedef union			u_component_data
{
	t_window			*win;
	t_text				*text;
	t_button			*button;
}						t_component_data;

typedef struct			s_component
{
	SDL_Surface			*surface;
	t_style				*style;
	int					type;
	int					hidden;
	t_component_data	data;
	t_list				*childs;
	void				(*onclick)(struct s_component*, int);
	void				(*onmouseover)(struct s_component*, int, int);
	void				(*onmouseleave)(struct s_component*, int, int);
}						t_component;

t_component			*ui_init_component(const int type, void *data);
void				ui_component_put_xml(t_component *c, t_document *doc);

#endif
