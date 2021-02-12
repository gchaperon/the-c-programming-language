#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void reverse(char s[], int i, int j);

main()
{
	char s[MAXLEN];

	strcpy(s, "hola que tal \t");
	reverse(s, 0, strlen(s) - 1);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[], int i, int j)
{
	char c;

	if (i > j)
		return ;

	c = s[i];
	s[i] = s[j];
	s[j] = c;
	reverse(s, ++i, --j);
}
	


