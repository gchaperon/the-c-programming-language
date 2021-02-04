#include <stdio.h>

#define NBINS 11
#define IN 1
#define OUT 0

main()
{
	int i, j, c, curr_nchars, state, max_count;
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

	/* Prepare a matrix to draw histogram */
	max_count = 0;
	for (i = 0; i < NBINS; ++i)
		if (lens[i] > max_count)
			max_count = lens[i];

	int hist_matrix[max_count][NBINS];
	for (i = 0; i < max_count; ++i)
		for (j = 0; j < NBINS; ++j)
			hist_matrix[i][j] = 0;
	
	for (i = 0; i < NBINS; ++i)
		for (j = 0; j < lens[i]; ++j)
			hist_matrix[max_count-1-j][i] = 1;

	/* Draw histogram */
	for (i = 0; i < max_count; ++i) {
		for (j = 0; j < NBINS; ++j)
			if (hist_matrix[i][j])
				printf("%4c", '#');
			else
				printf("%4c", ' ');
		putchar('\n');
	}
	putchar('\n');
	for (i = 0; i < NBINS - 1; ++i)
		printf("%4d", i + 1);
	printf(" +%2d\n", NBINS - 1);
	

}
