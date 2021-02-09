#include <stdio.h>
#include <limits.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
char *itobin(unsigned n, char buff[]);

main()
{
	/* i just play with different values of x, n, p and y to test */
	int x, y;
	char binstr[1000];

	x = 0xffffffff;
	printf("%s\n", itobin(x, binstr));
	y = 0x5a;
	printf("%s\n", itobin(y, binstr));
	printf("%s\n", itobin(setbits(x, 17, 8, y), binstr));

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask;
	
	mask = ~(~0 << n);

	return x & ~(mask << p-n+1) | (y & mask) << p-n+1;
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
