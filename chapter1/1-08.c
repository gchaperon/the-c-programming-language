#include <stdio.h>

main()
{
	int c;
	long count;

	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++count;
		if (c == '\t')
			++count;
		if (c == '\n')
			++count;
	}
	printf("%ld\n", count);
}

