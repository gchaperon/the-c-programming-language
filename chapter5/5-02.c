#include <stdio.h>

int getfloat(double *pn);

main()
{
	int c;
	double f;

	while ((c = getfloat(&f)) && c != EOF)
		printf("%g\n", f);
	return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
	int c, sign;
	double power;

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
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}
	*pn *= sign / power;
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

