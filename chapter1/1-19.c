#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[], int maxlen);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		if (line[len-1] == '\n')
			--len;
		reverse(line, len);
		printf("%s", line);
	}
	return 0;
}

void reverse(char s[], int maxlen)
{
	int i, j, tmp;
	for (j = 0; s[j]!='\0' && j<maxlen; ++j)
		;
	for (i=0,--j; i<j; ++i,--j) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
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


