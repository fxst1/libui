#include "hashmap.h"

int			ft_hash(void *data, size_t data_size)
{
	size_t	i;
	int		h;

	i = 0;
	h = 0;
	if (data)
		while (i < data_size)
		{
			h += ((unsigned char*)data)[i];
			i++;
		}
	return (h % 256);
}
