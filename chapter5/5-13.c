#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000

int getline(char *, int);
char *alloc(int);

int nlines = 10;
char *lineptr[MAXLINES];

main(int argc, char *argv[])
{
	int i, c, current, len, total, start;
	char *p, line[MAXLEN];
	while (--argc > 0 && (*++argv)[0] == '-')
		if (isdigit(*++argv[0])) 
			nlines = atoi(argv[0]);
		else
			printf("illegal option %s\n", argv[0]);
	if (argc != 0) {
		printf("Usage: tail -NUMBER (default tail -10)\n");
		return 1;
	}

	if (nlines >= MAXLINES) {
		printf("error: too many lines to keep in memory");
		return 1;
	}

	total = current = 0;
	while ((len = getline(line, MAXLEN)) > 0) {
		total++;
		if ((p = alloc(len)) == NULL) {
			printf("error: out of memory");
			return -1;
		} else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[current++] = p;
			current %= nlines;
		}
	}

	start = total < nlines ? 0 : current;
	nlines = total < nlines ? total : nlines;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[(start + i) % nlines]);

	/* printf("nlines = %d\n", nlines); */
	return 0;
}


#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >=n ) {
		allocp += n;
		return allocp - n;
	} else
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

