#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

main()
{
	unsigned int min_f_mask, max_f_mask;
	unsigned long min_d_mask, max_d_mask;
	assert(sizeof(int) == 4);
	assert(sizeof(long) == 8);

	
	printf("Ranges of variuous C types\n");

	printf("\nchar:\n");
	printf("\tsigned:\n");
	printf("\t\tstd header: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("\t\tcomputed: %hhd to %d\n",  1 << CHAR_BIT - 1, (unsigned char)~0 >> 1);
	printf("\tunsigned:\n");
	printf("\t\tstd header: 0 to %d\n", UCHAR_MAX);
	printf("\t\tcomputed:0 to %hhu\n", ~0);

	printf("short:\n");
	printf("\tsigned:\n");
	printf("\t\tstd header: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("\t\tcomputed: %d to %d\n", ~((unsigned short)~0 >> 1), (unsigned short)~0 >> 1);
	printf("\tunsigned:\n");
	printf("\t\tstd header: 0 to %hu\n", USHRT_MAX);
	printf("\t\tcomputed: 0 to %hu\n", ~0);

	printf("int:\n");
	printf("\tsigned:\n");
	printf("\t\tstd header: %d to %d\n", INT_MIN, INT_MAX);
	printf("\t\tcomputed: %d to %d\n", ~(~0u >> 1), ~0u >> 1);
	printf("\tunsigned:\n");
	printf("\t\tstd header: 0 to %u\n", UINT_MAX);
	printf("\t\tcomputed: 0 to %u\n", ~0);

	printf("long:\n");
	printf("\tsigned:\n");
	printf("\t\tstd header: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("\t\tcomputed: %ld to %ld\n", ~(~0ul >> 1), ~0ul >> 1);
	printf("\tunsigned:\n");
	printf("\t\tstd header: 0 to %lu\n", ULONG_MAX);
	printf("\t\tcomputed: 0 to %lu\n", ~0l);

	printf("float:\n");
	printf("\tstd header: %e to %e\n", FLT_MIN, FLT_MAX);
	min_f_mask = ~(~0u>>1)>>8;
	max_f_mask = ~(~(~0u>>1)>>7)>>1;
	printf("\tcomputed: %e to %e\n", *(float*)&min_f_mask, *(float*)&max_f_mask);

	printf("double:\n");
	printf("\tstd header: %e to %e\n", DBL_MIN, DBL_MAX);
	min_d_mask = ~(~0ul>>1)>>11;
	max_d_mask = ~(~(~0ul>>1)>>10)>>1;
	printf("\tcomputed: %e to %e\n", *(double*)&min_d_mask, *(double*)&max_d_mask);

	return 0;
}
