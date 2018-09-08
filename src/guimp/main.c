#include "libui.h"

int			main(int ac, char **av)
{
	t_component	*win = ui_init_window("Hello World", 600, 600);
	t_document	*doc = NULL;

	if (win)
	{
		if (ac == 2)
			doc = document_open(av[1], "XML");
		if (doc)
			ui_component_put_xml(win, doc);
		ui_show(win);
	}
	ui_loop();
	return (0);
}
