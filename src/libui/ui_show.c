#include "libui.h"

void		ui_show(t_component *c)
{
	t_list		*childs;

	if (c)
	{
		childs = c->childs;
		c->hidden = 0;
		while (childs)
		{
			ui_show(childs->content);
			childs = childs->next;
		}
	}
}
