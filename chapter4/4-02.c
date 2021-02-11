#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

double atof(char s[]);
double mypow(double b, int e);
int getline(char line[], int max);

main()
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));

	return 0;
}

double atof(char s[])
{
	double val, power;
	int i, sign, exp_sign, exp;
	
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] -'0');

	return sign * val / power * mypow(10.0, exp_sign * exp);
}

double mypow(double base, int exp)
{
	double ret;
	int abs;

	for (ret = 1.0, abs = (exp < 0) ? -exp : exp; abs > 0; abs--)
		ret *= base;
	return (exp < 0) ? 1.0/ret : ret;
}

int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) !=EOF && c!='\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
