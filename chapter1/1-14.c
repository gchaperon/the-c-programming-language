#include <stdio.h>

#define NCHARS 128
main()
{
	int c, i, j, k, maxcount, nnonzero;
	int char_counts[NCHARS + 1];
	for (i = 0; i < NCHARS + 1; ++i)
		char_counts[i] = 0;

	while ((c = getchar()) != EOF)
		if (c > NCHARS)
			++char_counts[NCHARS];
		else
			++char_counts[c];

	maxcount = 0;
	nnonzero = 0;
	for (i = 0; i < NCHARS + 1; ++i) {
		if (char_counts[i] > 0)
			++nnonzero;
		if (char_counts[i] > maxcount)
			maxcount = char_counts[i];
	}

	int hist_matrix[maxcount][nnonzero];
	for (i = 0; i < maxcount; ++i)
		for (j = 0; j < nnonzero; ++j)
			hist_matrix[i][j] = 0;

	k = 0;
	for (i = 0; i < NCHARS + 1; ++i) {
		if (char_counts[i]) {
			for (j = 0; j < char_counts[i]; ++j)
				hist_matrix[maxcount - 1 - j][k] = 1;
			++k;
		}
	}

	for (i = 0; i < maxcount; ++i) {
		for (j = 0; j < nnonzero; ++j)
			if (hist_matrix[i][j])
				printf("%3c", '#');
			else
				printf("%3c", ' ');
		putchar('\n');
	}

	putchar('\n');
	for (i = 0; i < NCHARS; ++i)
		if (char_counts[i])
			if (i == '\n')
				printf(" \\n");
			else if (i == '\t')
				printf(" \\t");
			else
				printf("%3c", i);
	if (char_counts[NCHARS])
		printf(" na");
	putchar('\n');
}



