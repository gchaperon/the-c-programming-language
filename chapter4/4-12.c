#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void itoa(int n, char s[]);

main()
{
	char s[MAXLEN];
	int n = 1234123;

	itoa(n, s);
	printf("%s\n", s);
	int i;
	for (i = 0; i <=strlen(s); ++i)
		printf("%d\n", s[i]);
	return 0;
}

void itoa(int n, char s[])
{
	static i = 0;

	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
}
