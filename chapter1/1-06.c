#include <stdio.h>

main()
{
		int c;
		printf("gimme any char\n");
		c = getchar() != EOF;
		printf("the value of c is %d\n", c);
		while ((c = getchar()) != '\n') ;
		printf("now hit me with ctrl-d\n");
		c = getchar() != EOF;
		printf("the value of c is now %d\n", c);
}
