#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 1000

int getline(char line[], int maxline);
void detab(char to[], char from[]);

main()
{
	int len;
	char line[MAXLINE];
	char detabbed[TABSIZE * MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		detab(detabbed, line);
		printf("%s", detabbed);
	}

	return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void detab(char buff[], char s[])
{
	int i, j, nextstop;

	for (i=0,j=0; (buff[j]=s[i])!='\0'; ++i,++j)
		if (buff[j] == '\t') {
			nextstop = j + (TABSIZE - j%TABSIZE);
			for ( ;j < nextstop - 1; ++j)
				buff[j] = ' ';
			/* last incremenet is taken care of by the outer loop */
			buff[j] = ' ';
		}
}
