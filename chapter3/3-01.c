#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define N 1000000
#define NTESTS 1000

int binsearch2(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

main()
{
	clock_t search1_t, search2_t, start_t;
	int x, v[N], i, rint, res1, res2;

	for (i = 0; i < N; ++i)
		v[i] = i * i;
	search1_t = search2_t = 0;

	for (i = 0; i < NTESTS; ++i) {
		rint = random();

		start_t = clock();
		res1 = binsearch1(rint, v, N);
		search1_t += clock() - start_t;

		start_t = clock();
		res2 = binsearch2(rint, v, N);
		search2_t += clock() - start_t;

		assert(binsearch1(rint, v, N) == binsearch2(rint, v, N));
	}
	
	printf(
		"Single test inside loop: %.2f ns\n",
		(double)search1_t / CLOCKS_PER_SEC / NTESTS * 1e9
	);
	printf(
		"Two tests inside loop: %.2f ns\n",
		(double)search2_t / CLOCKS_PER_SEC / NTESTS * 1e9
	);

	return 0;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch1(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low + high) / 2;
		if (v[mid] >= x)
			high = mid;
		else
			low = mid + 1;
	}
	return v[high] == x ? high : -1;
}
