#include <stdio.h>

int strend(char *s, char *t);

main()
{
	char s[] = "hola que tal";

	printf("%d\n", strend(s, " tal"));
	printf("%d\n", strend(s, "ups"));

	return 0;
}

int strend(char *s, char *t)
{
	char *os, *ot;

	for (os = s ; *s; s++)
		;
	for (ot = t ; *t; t++)
		;
	while (*--s == *--t && s > os && t > ot)
		;
	return t == ot;
}



