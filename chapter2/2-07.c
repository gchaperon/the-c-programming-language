#include <stdio.h>
#include <limits.h>

unsigned invert(unsigned x, int p, int n);
char *itobin(unsigned n, char buff[]);

main()
{
	int x, p, n;
	char binstr[1000];

	x = 0x23b4f6dc;
	p = 17;
	n = 10;
	printf("%s\n", itobin(x, binstr));
	printf("%s\n", itobin(invert(x, p, n), binstr));
	
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned mask;

	mask = ~(~0 << n) << p-n+1;
	return ~x & mask | x & ~mask;
}

char *itobin(unsigned n, char buff[])
{
	int i, j;

	for (i=sizeof(n)*CHAR_BIT-1, j=0; i>=0; --i) {
		buff[j++] = '0' + (n >> i & 1);
		if (i % CHAR_BIT == 0 && i > 0)
			buff[j++] = ' ';
	}
	buff[j] = '\0';
	return buff;
}
