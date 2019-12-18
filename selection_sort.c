#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

typedef struct	n_list {
	int	num;
	struct n_list	*next;
}				t_list;

void		print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->num);
		list = list->next;
	}
}

t_list		*addnode(t_list *node, int num)
{
	t_list	*mem;
	
	mem = NULL;
	if ((mem = (t_list *)malloc(sizeof(t_list))))
	{
		mem->next = node;
		mem->num = num;
	}
	return (mem);
}

t_list		*find_smallest(t_list *list)
{
	t_list	*begin;
	t_list	*smallest;

	begin = list;
	smallest = list;
	while (list)
	{
		if (list->num < smallest->num)
			smallest = list;
		list = list->next;
	}
	return (smallest);
}

t_list		*delnode(t_list *list, t_list *node)
{
	t_list	*begin;
	t_list	*prev;
	t_list	*head;

	begin = list;
	if (begin == node)
	{
		head = begin->next;
		free(begin);
		return (head);
	}
	while (begin != node && begin != NULL)
	{
		prev = begin;
		begin = begin->next;
	}
	if (begin == NULL)
		return NULL;
	prev->next = begin->next;
	return (list);
}

t_list		*selection_sort(t_list *list)
{
	t_list	*newlist;
	t_list	*begin;
	t_list	*smallest;

	begin = list;
	newlist = NULL;

	while (list)
	{
		smallest = find_smallest(list);
		newlist = addnode(newlist, smallest->num);
		list = delnode(list, smallest);
	}
	return (newlist);
}

int			main(void)
{
	t_list *head;
	int		i;

	head = NULL;
	i = 0;

	srand(time(NULL));
	while (i < SIZE)
	{
		head = addnode(head, 1 + rand() % 100);
		i += 1;
	}
	printf("unsorted list:\n");
	print_list(head);
	printf("\n");
	head = selection_sort(head);
	printf("sorted list:\n");
	print_list(head);
	return (0);
}