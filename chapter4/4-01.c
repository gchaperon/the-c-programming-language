#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strrindex(char s[], char t[]);

char pattern[] = "caca";

main()
{
	char line[MAXLINE];

	while (getline(line, MAXLINE) > 0)
		printf("%d\n", strrindex(line, pattern));

	return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) !=EOF && c!='\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s) - 1; i >= 0; --i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
