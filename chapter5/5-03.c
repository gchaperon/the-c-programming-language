#include <stdio.h>

void strcat(char *s, char *t);

main()
{
	char s[1000] = "esto es un string";
	
	strcat(s, ", seguido de otro string");
	printf("%s\n", s);

	return 0;
}

void strcat(char *s, char *t)
{
	for ( ; *s; s++)
		;
	while (*s++ = *t++)
		;
}	
