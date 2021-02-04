#include <stdio.h>

#define NBINS 11
#define IN 1
#define OUT 0

main()
{
	int i, j, c, curr_nchars, state;
	int lens[NBINS];
	for (i = 0; i < NBINS; ++i)
		lens[i] = 0;

	curr_nchars = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				state = OUT;
				if (curr_nchars > NBINS)
					curr_nchars = NBINS;
				++lens[curr_nchars - 1];
				curr_nchars = 0;
			}
		}
		else {
			if (state == OUT)
				state = IN;
			++curr_nchars;
		}
	}

	for (i = 0; i < NBINS -1; ++i) {
		printf("%3d ", i + 1);
		for (j = 0; j < lens[i]; ++j)
			putchar('|');
		putchar('\n');
	}

	printf("+%d ", NBINS-1);
	for (j = 0; j < lens[NBINS - 1]; ++j)
		putchar('|');
	putchar('\n');

}
