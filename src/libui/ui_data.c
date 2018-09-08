#include "libui.h"

t_ui		*ui_data(void)
{
	static t_ui		ui = {0, 0};

	return (&ui);
}
