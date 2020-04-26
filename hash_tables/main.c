#include "hashtable.h"

int	main(void)
{
	t_hash	*ht;

	ht = htable(3);
	ht_setdata(ht, "variable", "is a storage place which has some memory allocated to it");
	ht_setdata(ht, "array", "is a collection of items stored at contiguous memory locations and elements can be accessed randomly using indices of an array");
	ht_setdata(ht, "structure", "is a user defined data type in C/C++");
	printf("A variable %s\n", ht_getdata(ht, "variable"));
	printf("An array %s\n", ht_getdata(ht, "array"));
	printf("A structure %s\n", ht_getdata(ht, "structure"));
	return (0);
}
