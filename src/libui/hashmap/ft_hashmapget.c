#include "hashmap.h"

void					*ft_hashmapget(t_hashmap *root, void *key, size_t key_size, int (*compare)(const void*, const void*))
{
	int		h;
	t_list	*lst;

	h = ft_hash(key, key_size);
	while (root)
	{
		if (root->hash == h)
		{
			lst = root->contents;
			if (!compare)
				return (NULL);
			while (lst)
			{
				if ((*compare)(key, lst->content) == 0)
					return (lst->content);
				lst = lst->next;
			}
		}
		root = root->next;
	}
	return (NULL);
}
