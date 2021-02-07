#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int getline(char line[], int maxline);
void entab(char to[], char from[]);

main()
{
	int len;
	char line[MAXLINE];
	char entabbed[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0) {
		entab(entabbed, line);
		printf("%s", entabbed);
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

void entab(char buff[], char s[])
{
	int i, j, flag, onlywhite;
	
	flag = 0;
	for(i = 0, j = 0, onlywhite = s[i]==' ';
	    (buff[j] = s[i]) != '\0';
	    ++i, ++j, onlywhite = onlywhite && s[i]==' ')
	{
		if ((i + 1) % TABSIZE == 0 && onlywhite) {
			buff[flag] = '\t';
			j = flag;
			onlywhite = FALSE;
		}
		if (buff[j] == ' ' && !onlywhite) {
			flag = j;
			onlywhite = TRUE;
		}
	}
}
