#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int myGetline(char line[], int maxline);

main()
{
	char s[MAXLINE];

	/*while (getline(s, MAXLINE) > 0)*/
	while (myGetline(s, MAXLINE) > 0)
		printf("%s", s);
	return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int myGetline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim-1; ++i)
		if ((c=getchar()) != EOF)
			if (c != '\n')
				s[i] = c;
			else
				break;
		else
			break;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
