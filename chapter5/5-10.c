#include <stdio.h>
#include <stdlib.h>

void push(double);
double pop(void);

/* reverse polish calculator, assumes the input is well formed */
main(int argc, char *argv[])
{
	double op2;
	while (*++argv) {
		switch(*argv[0]) {
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			push(pop() / op2);
			break;
		default:
			push(atof(*argv));
		}
	}
	printf("%.8g\n", pop());
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

