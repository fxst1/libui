#include "hashmap.h"

void					ft_hashmapadd(t_hashmap **root, t_hashmap *add)
{
	t_hashmap			*hmap;

	if (!root)
		return ;
	if ((hmap = *root))
	{
		while (hmap->next)
		{
			if (hmap->hash == add->hash)
			{
				ft_lstadd(&hmap->contents, add->contents);
				free(add);
				return ;
			}
			hmap = hmap->next;
		}
		hmap->next = add;
	}
	else
		*root = add;
}
