#ifndef HASHTABLE_H
# define HASHTABLE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct			s_pairlist
{
	char			*key;
	char			*val;
	struct s_pairlist	*next;
}				t_list;

typedef struct			s_hashtable
{
	size_t			size;
	t_list			**item;
}				t_hash;

t_hash				*htable(size_t size);
void				free_htable(t_hash *ht);
char				*ht_getdata(t_hash *ht, const char *key);
int				ht_setdata(t_hash *ht, const char *key, const char *val);

#endif
