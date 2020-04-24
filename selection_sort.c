#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

typedef struct	s_list 
{
	int		num;
	struct s_list	*next;
}		t_list;

void		print_list(t_list *list)
{
	while (list != NULL)
	{
		if (list->next != NULL)
			printf("%d => ", list->num);
		else
			printf("%d\n", list->num);
		list = list->next;
	}
}

t_list		*addnode(t_list *node, int num)
{
	t_list	*newnode;

	newnode = NULL;
	if ((newnode = (t_list *)malloc(sizeof(t_list))))
	{
		newnode->next = node;
		newnode->num = num;
	}
	return (newnode);
}

t_list		*find_smallest(t_list *list)
{
	t_list	*smallest;

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

	begin = list;
	if (begin == node)
	{
		list = list->next;
		free(begin);
		return (list);
	}
	while (begin != node && begin != NULL)
	{
		prev = begin;
		begin = begin->next;
	}
	if (begin != NULL)
	{
		prev->next = begin->next;
		free(begin);
	}
	return (list);
}

t_list		*selection_sort(t_list *list)
{
	t_list	*newlist;
	t_list	*smallest;

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
	t_list	*head;
	int	i;

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
	head = selection_sort(head);
	printf("sorted list:\n");
	print_list(head);
	return (0);
}
