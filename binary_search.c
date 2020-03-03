#include <stdio.h>

int		binary_search(int list[], size_t list_len, int item)
{
	int		low;
	int		high;
	int		mid;
	int		guess;
	int		steps;

	steps = 0;
	low = 0;
	high = list_len - 1;
	mid = 0;
	guess = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = list[mid];
		if (guess == item)
		{
			printf("steps - %d\n", steps);
			return (mid);
		}
		else if (guess > item)
			high = mid - 1;
		else
			low = mid + 1;
		steps += 1;
	}
	return (-1);
}

int		recur_bin_search(int *list, size_t size, int x)
{
	int		low;
	int		high;

	low = 0;
	high = size - 1;
	if (list[high] == x)
		return (high);
	return (recur_bin_search(list, (low + high) / 2, x));
}

int		main(void)
{
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int res;

	res = binary_search(list, sizeof(list) / sizeof(list[0]), 9);
	printf("index of %d is %d\n", list[res], res);
	res = recur_bin_search(list, sizeof(list) / sizeof(list[0]), 9);
	printf("index of %d is %d\n", list[res], res);
	return (0);
}