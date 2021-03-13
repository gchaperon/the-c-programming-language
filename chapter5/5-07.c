#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char lineptr[][MAXLEN], int nlines, int maxlen);
void writelines(char lineptr[][MAXLEN], int nlines);

main()
{
	char lineptr[MAXLINES][MAXLEN];
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES, MAXLEN)) >=0) {
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big\n");
		return 1;
	}
}

int getline(char *, int);

int readlines(char lineptr[][MAXLEN], int maxlines, int maxlen)
{
	int len, nlines;

	nlines = 0;
	while ((len = getline(lineptr[nlines], MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else {
			/* replace newline char */
			lineptr[nlines++][len-1] = '\0'; 
		}
	return nlines;
}

void writelines(char lineptr[][MAXLEN], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
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

