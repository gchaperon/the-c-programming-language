#include <stdio.h>
#include <string.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
	char s[100];
	int n, b;

	n = INT_MIN;

	b = 16;
	itob(n, s, b);
	printf("%s\n", s);
	printf("%x\n", n); /* good enough */

	b = 10;
	itob(n, s, b);
	printf("%s\n", s);
	printf("%d\n", n);

	return 0;
}

void itob(int n, char s[], int b)
{
	int i, c, rem;
	unsigned aux;

	aux = n < 0 ? -n : n;
	i=0;
	do {
		c = (rem = aux % b) < 10 ? rem + '0' : rem - 10 + 'a';
		s[i++] = c;
	} while ((aux /= b) > 0);
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
