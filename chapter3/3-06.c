#include <stdio.h>
#include <limits.h>
#include <string.h>

int itoa(int n, char s[], int w);
void reverse(char s[]);

main()
{
	char s[100];
	int n, w;

	n = INT_MIN;
	w = 20;
	itoa(n, s, w);
	printf("|\t|\t|\t|\n");
	printf("%s\n", s);
	printf("%*d\n", w, n);

	return 0;
}

int itoa(int n, char s[], int w)
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
	for ( ; i < w; ++i)
		s[i] = ' ';
	s[i] = '\0';
	reverse(s);
	return i;
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

