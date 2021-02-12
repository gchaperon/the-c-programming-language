#include <stdio.h>

char *strncpy(char *s, const char *ct, int n);
char *strncat(char *s, const char *ct, int n);
int strncmp(const char *cs, const char *ct, int n);

main()
{
	char s[100];

	printf("%s\n", strncpy(s, "hola que tal", 7));
	printf("%s\n", strncat(s, "parece que no se copio todo", 13));
	printf("%d\n", strncmp(s, "hola quparece que si", 18));
	printf("%d\n", strncmp(s, "hola quparece que si", 100));

	return 0;
}

char *strncpy(char *s, const char *ct, int n)
{
	/* I dont want to pad with '\0' :P */
	char *os = s;

	for ( ; (*s = *ct) && n; s++, ct++, n--)
		;
	*s = '\0';
	return os;
}

char *strncat(char *s, const char *ct, int n)
{
	char *os = s;
	
	for ( ; *s; ++s)
		;
	for ( ; (*s = *ct) && n; ++s, ++ct, --n)
		;
	*s = '\0';
	return os;
}

int strncmp(const char *cs, const char *ct, int n)
{
	for ( ; --n && *cs == *ct; cs++, ct++)
		if (*cs == '\0')
			return 0;
	return *cs - *ct;
}
		
