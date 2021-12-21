#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void*), int reverse);
int numcmp(const char *, const char *);

main(int argc, char *argv[])
{
	int nlines, c, numeric = 0, reverse = 0, outcode = 1;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			default:
				printf("sort: illegal option %c\n", c);
				argc = -1;
				break;
			}

	if (argc != 0)
		printf("Usage: sort -n -r\n");
	else if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort(
			(void **) lineptr,
			0,
			nlines-1, 
			(int (*)(void *, void *))(numeric ? numcmp : strcmp),
			reverse
		);
		writelines(lineptr, nlines);
		outcode = 0;
	} else 
		printf("input too big to sort\n");
	

	return outcode;
}

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
	int i, last, order;
	void swap(void *v[], int, int);

	if (left >= right)
		return ;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		order = (*comp)(v[i], v[left]);
		if (reverse ? order > 0 : order < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	myqsort(v, left, last-1, comp, reverse);
	myqsort(v, last+1, right, comp, reverse);
}

#include <stdlib.h>

int numcmp(const char *s1, const char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

int getline(char *s, int lim)
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
