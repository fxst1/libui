#include "hashmap.h"

t_hashmap		*ft_hashmapnew(void *key, size_t key_size, void *content, size_t content_size)
{
	t_hashmap	*hmap;
	int			h;

	h = ft_hash(key, key_size);
	hmap = (t_hashmap*)malloc(sizeof(t_hashmap));
	if (!hmap)
		return (NULL);
	hmap->hash = h;
	hmap->key = key;
	hmap->key_size = key_size;
	hmap->contents = ft_lstnew(content, content_size);
	hmap->next = NULL;
	return (hmap);
}
