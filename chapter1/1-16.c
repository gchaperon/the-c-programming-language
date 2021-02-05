#include <stdio.h>
#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) != 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		if (max > MAXLINE)
			fprintf(stderr, "overflow!\n");
		printf("%d\t%s", max, longest);
	return 0;
}

int getline(char s[], int lim)
{
	int c, i, count;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	count = i;
	while (i==lim-1 && c!='\n' && (c  = getchar())!=EOF)
		++count;
	s[i] = '\0';
	return count;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
