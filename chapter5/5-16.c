#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void*), int reverse);
int numcmp(const char *, const char *);
int mystrcasecmp(const char *, const char *);

int mystrdircmp(const char *, const char *);
int mystrdircasecmp(const char *, const char *);

main_() {
	printf("hola!\n");
	printf("%d\n", mystrdircmp("_hola", "hola"));
	printf("%d\n", mystrdircmp("hola", "hola"));
	printf("%d\n", mystrdircmp("_hola", "ola"));
	return 0;
}

main(int argc, char *argv[])
{
	int (*compfn)(const char *, const char *);
	int nlines, c, numeric = 0, reverse = 0, fold = 0, directory = 0, outcode = 1;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				fold = 1;
				break;
			case 'd':
				directory = 1;
				break;
			default:
				printf("sort: illegal option %c\n", c);
				argc = -1;
				break;
			}

	printf("fold = %d\n", fold);
	if (argc != 0)
		printf("Usage: sort -n -r\n");

	if (numeric) 
		compfn = numcmp;
	else if (fold && directory)
		compfn = mystrdircasecmp;
	else if (fold)
		compfn = mystrcasecmp;
	else if (directory)
		compfn = mystrdircmp;
	else
		compfn = strcmp;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort(
			(void **) lineptr,
			0,
			nlines-1, 
			(int (*)(void *, void *))compfn,
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

int mystrdircmp(const char *s1, const char *s2)
{
	int i = 0, j = 0;

	/* find first valid char */
	while (!(isalpha(s1[i]) || isdigit(s1[i]) || isblank(s1[i]))){
		i++;
	}
	while (!(isalpha(s2[j]) || isdigit(s2[j]) || isblank(s2[j]))) {
		j++;
	}
	
	while (s1[i] == s2[j]) {
		if (s1[i] == '\0')
			return 0;
		while (!(isalpha(s1[i]) || isdigit(s1[i]) || isblank(s1[i])))
			i++;
		while (!(isalpha(s2[j]) || isdigit(s2[j]) || isblank(s2[j])))
			j++;
		i++;
		j++;
	}
	
	return s1[i] - s2[j];
}

char lower(char c);

int mystrcasecmp(const char *s1, const char *s2)
{
	int i;
	
	for (i = 0; lower(s1[i]) == lower(s2[i]); i++)
		if (s1[i] == '\0')
			return 0;
	return lower(s1[i]) - lower(s2[i]);
}

int mystrdircasecmp(const char *s1, const char *s2)
{
	int i = 0, j = 0;

	/* find first valid char */
	while (!(isalpha(s1[i]) || isdigit(s1[i]) || isblank(s1[i]))){
		i++;
	}
	while (!(isalpha(s2[j]) || isdigit(s2[j]) || isblank(s2[j]))) {
		j++;
	}
	
	while (lower(s1[i]) == lower(s2[j])) {
		if (s1[i] == '\0')
			return 0;
		while (!(isalpha(s1[i]) || isdigit(s1[i]) || isblank(s1[i])))
			i++;
		while (!(isalpha(s2[j]) || isdigit(s2[j]) || isblank(s2[j])))
			j++;
		i++;
		j++;
	}
	
	return lower(s1[i]) - lower(s2[j]);
}


char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return 'a' + (c - 'A');
	else
		return c;
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

