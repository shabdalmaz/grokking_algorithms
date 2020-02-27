#include <stdio.h>

int		factorial(int n)
{
	if (n == 1)
		return (n);
	return (n * factorial(n - 1));
}

int		main(void)
{
	int		n;

	n = 3;
	printf("%d\n", factorial(n));
	return (0);
}