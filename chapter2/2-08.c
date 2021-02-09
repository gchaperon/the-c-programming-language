#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);
char *itobin(unsigned n, char buff[]);

main()
{
	char s[1000];
	unsigned x, n;

	x = 0x8000009c;
	n = 5;
	printf("%s\n", itobin(x, s));
	printf("%s\n", itobin(rightrot(x, n), s));
	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	unsigned tail;
	char s[1000];

	tail = ~(~0 << n) & x;
	return tail << sizeof(x)*CHAR_BIT-n | x >> n;
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
