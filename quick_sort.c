#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 35

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		get_wall(int *arr, int pivot, int last)
{
	int		leftmark;
	int		rightmark;
	int		done;

	leftmark = pivot + 1;
	rightmark = last;
	done = 0;
	while (!done)
	{
		while (arr[leftmark] <= arr[pivot] && leftmark <= rightmark)
			leftmark += 1;
		while (arr[rightmark] >= arr[pivot] && rightmark >= leftmark)
			rightmark -= 1;
		if (rightmark < leftmark)
			done = 1;
		else
			ft_swap(&arr[leftmark], &arr[rightmark]);
	}
    ft_swap(&arr[rightmark], &arr[pivot]);
    return (rightmark);
}

void	quick_sort(int arr[], int low, int high)
{
	int		wall;

	wall = 0;
	if (low < high)
	{
		wall = get_wall(arr, low, high);
		quick_sort(arr, low, wall - 1);
		quick_sort(arr, wall + 1, high);
	}
}

int		main(void)
{
	int		i = 0;
	int		arr[SIZE];

	srand(time(NULL));
	while (i < SIZE)
	{
		arr[i] = rand() % (SIZE - 1) + 1;
		i += 1;
	}
	i = 0;
	printf("unsorted array:\narr[] = {");
	while (i < SIZE)
	{
		(i < SIZE - 1) ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
		i += 1;
	}
	printf("};\n");
	quick_sort(arr, 0, SIZE - 1);
	i = 0;
	printf("sorted array:\narr[] = {");
	while (i < SIZE)
	{
		(i < SIZE - 1) ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
		i += 1;
	}
	printf("};\n");
	return (0);
}
