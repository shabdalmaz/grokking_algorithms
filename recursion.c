#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct	s_list 
{
	int				data;
	struct s_list	*next;
}				t_list;


int		sum(int *arr, size_t size)
{
	if (size == 1)
		return (arr[0]);
	return (arr[0] + sum(arr + 1, size - 1));
}

int		getsize(t_list *head, int i)
{
	if (head == NULL)
		return (i);
	i += 1;
	return (getsize(head->next, i));
}

int		getmax(t_list *head, int first_node)
{
	if (head == NULL)
		return (first_node);
	if (head->data > first_node)
		first_node = head->data;
	return (getmax(head->next, first_node));
}

t_list	*newnode(t_list *head, int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = head;
	return (node);
}

int		main(void)
{
	int		arr[] = {2, 5, 6};
	size_t	arr_size = sizeof(arr) / sizeof(arr[0]);
	int		i = 0;
	t_list	*head;

	srand(time(NULL));
	while (i < 10)
	{
		head = newnode(head, rand() % (20 - 0) + 1);
		i += 1;
	}
	printf("sum of array - %d\n", sum(arr, arr_size));
	printf("size of list - %d\n", getsize(head, 0));
	printf("max of list - %d\n", getmax(head, head->data));
	return (0);
}
