#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (state == OUT) 
			if (c == ' ' || c == '\t' || c == '\n') continue ;
			else state = IN;
		else
			if (c == ' ' || c == '\t' || c == '\n') {
				putchar('\n');
				state = OUT;
				continue;
			}

		putchar(c);
	}
}	
