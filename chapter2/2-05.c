#include <stdio.h>

int any(char s1[], char s2[]);
int in(char c, char s[]);

main()
{
	printf("%d\n", any("hola", "aeiou"));
	printf("%d\n", any("qwrtpdfg", "aeiou"));
	printf("%d\n", any("qqqqqqqqqqqqqqqqqqqqe", "aeiou"));
}

int any(char text[], char filter[])
{
	int i;

	for (i = 0; text[i] != '\0'; ++i)
		if (in(text[i], filter))
			return i;

	return -1;
}

int in(char c, char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		if (c == s[i])
			return 1;
	return 0;
}
