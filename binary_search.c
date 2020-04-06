#include <stdio.h>

int		binary_search(int list[], size_t list_len, int item)
{
	int		low;
	int		high;
	int		mid;
	int		guess;

	low = 0;
	high = list_len - 1;
	mid = 0;
	guess = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = list[mid];
		if (guess == item)
			return (mid);
		else if (guess > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}

int		recur_bin_search(int *list, int x, int low, int high)
{
	int	mid;

	mid = (low + high) / 2;
	if (list[mid] == x)
		return (mid);
	else if (low > high && list[mid] != x)
		return (-1);

	if (list[mid] > x)
		high = mid - 1;
	else if (list[mid] < x)
		low = mid + 1;
	return (recur_bin_search(list, x, low, high));
}

int		main(void)
{
	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int res;
	int x = 11;

	res = binary_search(list, sizeof(list) / sizeof(list[0]), x);
	printf("index of %d is %d\n", x, res);
	
	res = recur_bin_search(list, x, 0, sizeof(list) / sizeof(list[0]) - 1);
	printf("index of %d is %d\n", x, res);
	return (0);
}
