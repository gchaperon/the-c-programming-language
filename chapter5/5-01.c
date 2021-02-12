#include <stdio.h>

int getint(int *pn);

main()
{
	int i, c;

	while ((c = getint(&i)) && c != EOF)
		printf("%d\n", i);
	return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if (!isdigit(c = getch())) {
			ungetch(c);
			return 0;
		}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("ungetch: too many characters\n");
}
