#ifndef HASHMAP_H
# define HASHMAP_H
# include "libft.h"

typedef struct			s_hashmap
{
	int					hash;
	void				*key;
	size_t				key_size;
	t_list				*contents;
	struct s_hashmap	*next;
}						t_hashmap;

int						ft_hash(void *data, size_t data_size);
t_hashmap				*ft_hashmapnew(void *key, size_t key_size, void *content, size_t content_size);
void					ft_hashmapadd(t_hashmap **root, t_hashmap *add);
void					*ft_hashmapget(t_hashmap *root, void *key, size_t key_size, int (*compare)(const void*, const void*));
void					ft_hashmapdel(t_hashmap *root, void (*del)(void*));

#endif
