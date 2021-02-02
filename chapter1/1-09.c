#include <stdio.h>

main()
{
	int c, in;
	
	in = 0;
	while ((c = getchar()) != EOF) {
		if (in)
			if (c == ' ') continue;
			else in = 0;
		else
			if (c == ' ') in = 1;

		putchar(c);
	}
}



		
