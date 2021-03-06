#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct		s_list 
{
	int		data;
	struct s_list	*next;
}			t_list;


int	sum(int *arr, size_t size)
{
	if (size == 1)
		return (arr[0]);
	return (arr[0] + sum(arr + 1, size - 1));
}

int	getsize(t_list *head)
{
	int	i;

	i = 0;
	if (head == NULL)
		return (i);
	i += 1;
	return (i + getsize(head->next));
}

int	getmax(t_list *head, int first_node)
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

int     hcf(int side1, int side2)
{
    int     a;
    int     b;
    
    a  = (side1 > side2) ? side1 : side2;
    b  = (side1 < side2) ? side1 : side2;

    if (a % b == 0)
        return (b);
    while (a > b)
        a -= b;
    return (hcf(b, a));
}

int	factorial(int n)
{
	if (n == 1)
		return (n);
	return (n * factorial(n - 1));
}

int	main(void)
{
	int	arr[] = {2, 5, 6};
	size_t	arr_size = sizeof(arr) / sizeof(arr[0]);
	int	i = 0;
	t_list	*head = NULL;
	int	side1 = 1680;
	int	side2 = 640;

	srand(time(NULL));
	while (i < 10)
	{
		head = newnode(head, rand() % (20 - 0) + 1);
		i += 1;
	}
	printf("sum of array - %d\n", sum(arr, arr_size));
	printf("size of list - %d\n", getsize(head));
	printf("max of list - %d\n", getmax(head, head->data));
	printf("the highest common factor of %d and %d is %d\n", side1, side2, hcf(side1, side2));
	printf("factorial of %d is %d\n", 5, factorial(5));
	return (0);
}
