#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
	char s[100];
	int n;

	n = INT_MIN;
	itoa(n, s);
	printf("%s\n", s);
	printf("%d\n", n);

	return 0;
}

void itoa(int n, char s[])
{
	int i;
	unsigned aux;

	aux = n < 0 ? -n : n;
	i = 0;
	do {
		s[i++] = aux % 10 + '0';
	} while ((aux /= 10) > 0);
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j, c;
	
	for (i=0,j=strlen(s)-1; i<j; ++i,--j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
