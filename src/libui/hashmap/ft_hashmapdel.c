#include "hashmap.h"

static void				clear_list(t_list *contents, void (*del)(void*))
{
	t_list		*next;

	while (contents)
	{
		next = contents->next;
		if (del)
			(*del)(contents->content);
		free(contents);
		contents = next;
	}
}

void					ft_hashmapdel(t_hashmap *root, void (*del)(void*))
{
	t_hashmap	*next;

	while (root)
	{
		next = root->next;
		clear_list(root->contents, del);
		free(root);
		root = next;
	}
}
