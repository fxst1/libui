#include "libui.h"

t_component		*ui_init_component(const int type, void *data)
{
	t_component	*c;

	c = (t_component*)malloc(sizeof(t_component));
	if (!c)
		return (NULL);
	ft_bzero(c, sizeof(t_component));
	c->hidden = 1;
	c->type = type;
	if (type == COMPONENT_WINDOW)
		c->data.win = (t_window*)data;
	else if (type == COMPONENT_BUTTON)
		c->data.button = (t_button*)data;
	else if (type == COMPONENT_TEXT)
		c->data.text = (t_text*)data;
	return (c);
}
