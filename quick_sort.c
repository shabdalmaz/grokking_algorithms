#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void	print(int *arr)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		(i < SIZE - 1) ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
		i += 1;
	}
}

void	swapper(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *arr, int first, int last)
{
	int	left;
	int	right;
	int	pivot;

	left = first;
	right = last;
	pivot = arr[(first + last) / 2];
	
	while (left <= right)
	{
		while (arr[left] < pivot)
			left += 1;
		while (arr[right] > pivot)
			right -= 1;
		if (left <= right)
		{
			swapper(&arr[left], &arr[right]);
			left += 1;
			right -= 1;
		}
	}
	if (first < last)
	{
		quick_sort(arr, first, right);
		quick_sort(arr, left, last);
	}
}

int	main(void)
{
	int	i = 0;
	int	arr[SIZE];

	srand(time(NULL));
	while (i < SIZE)
	{
		arr[i] = rand() % (SIZE - 1) + 1;
		i += 1;
	}

	printf("unsorted array:\narr[] = {");
	print(arr);
	printf("\n");
	printf("};\n");

	quick_sort(arr, 0, SIZE - 1);

	printf("sorted array:\narr[] = {");
	print(arr);
	printf("\n");
	printf("};\n");
	return (0);
}
