#include <stdio.h>
#define NMONTHS 12

static char daytab[2][NMONTHS + 1] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += *(*(daytab + leap) + i);
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > *(*(daytab + leap) + i); i++)
		yearday -= *(*(daytab + leap) + i);
	*pmonth = i;
	*pday = yearday;
}

main()
{
	int year, month, day, yearday, rmonth, rday;

	year = 2020;
	month = 11;
	day = 7;
	yearday = day_of_year(year, month, day);

	printf("%d-%d-%d is the %d%s day of that year \n",
		year, month, day, yearday,
		yearday == 1 ? "st" : yearday == 2 ? "nd" : yearday == 3 ? "rd" : "th");

	month_day(year, yearday, &rmonth, &rday);
	printf("the %d day of %d is %d-%d-%d\n", yearday, year, year, rmonth, rday);	

	return 0;
}
