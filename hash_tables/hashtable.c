#include "hashtable.h"

static unsigned int	hash(const char *key, size_t size)
{
	unsigned int hash;
	unsigned int i;

	hash = 0;
	i = 0;
	while (key && key[i])
	{
		hash += key[i];
		i += 1;
	}
	return (hash % size);
}

static void		data_handler(t_hash *ht, t_list *data)
{
	unsigned int	i;
	t_list		*cur;
	t_list		*prev;

	i = hash(data->key, ht->size);
	cur = ht->item[i];
	prev = NULL;
	if(ht->item[i])
	{
		while (cur)
		{
			if (strcmp(cur->key, data->key) == 0)
				break ;
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL)
			prev->next = data;
		else
		{
			free(cur->val);
			cur->val = strdup(data->val);
			free(data->val);
			free(data->key);
			free(data);
		}
	}
	else
		ht->item[i] = data;
}

int			ht_setdata(t_hash *ht, const char *key, const char *val)
{
	t_list	*data;

	if (!ht || !(data = (t_list *)malloc(sizeof(t_list))))
		return (1);
	data->key = strdup(key);
	data->val = strdup(val);
	data->next = NULL;
	data_handler(ht, data);
	return (0);
}

char			*ht_getdata(t_hash *ht, const char *key)
{
	unsigned int	i;
	t_list		*lst;

	if (!ht || !key)
		return (NULL);
	i = hash(key, ht->size);
	lst = ht->item[i];
	while (lst)
	{
		if (strcmp(lst->key, key) == 0)
			break ;
		lst = lst->next;
	}
	return (lst ? lst->val : NULL);
}

t_hash			*htable(size_t size)
{
	t_hash	*ht;

	if (!size || !(ht = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	if (!(ht->item = (t_list **)malloc(sizeof(t_list *) * size)))
	{
		free(ht);
		return (NULL);
	}
	ht->size = size;
	memset(ht->item, 0, sizeof(t_list *) * size);
	return (ht);
}

void			free_htable(t_hash *ht)
{
	unsigned int	i;
	t_list		*tmp;

	i = 0;
	tmp = NULL;
	if (ht)
	{
		while (i < ht->size)
		{
			while (ht->item[i])
			{
				tmp = ht->item[i]->next;
				free(ht->item[i]->key);
				free(ht->item[i]->val);
				free(ht->item[i]);
				ht->item[i] = tmp;
			}
			i += 1;
		}
		free(ht->item);
		free(ht);
	}
}
