#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int filter(char c);

main()
{
	int len, i;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		if (len == 1 && line[0] == '\n')
			continue;
		for (i = len-1; i>=0 && (line[i]==' ' || line[i]=='\t' || line[i]=='\n'); --i)
			;
		printf("%.*s", i+1, line);
		if (line[len-1] == '\n')
			putchar('\n');
	}
	return 0;
}

int filter(char c)
{
	return c==' ' || c=='\t';
}


int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}


