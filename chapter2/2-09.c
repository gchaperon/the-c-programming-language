#include <stdio.h>

int bitcount(unsigned x);

main()
{
	unsigned x;

	x = ~0xd;
	printf("%d\n", bitcount(x));
	return 0;
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= x-1)
		++b;
	return b;
}
