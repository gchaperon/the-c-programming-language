#include <stdio.h>
#define NMONTHS 12

static char daytab[2][NMONTHS + 1] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int in_range(int val, int lower, int upper)
{
	return val >= lower && val <= upper;
}

int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (!in_range(month, 1, NMONTHS))
		return -1;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (!in_range(day, 1, daytab[leap][month]))
		return -1;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* return 0 if error, 1 if no error */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
	if ((leap && !in_range(yearday, 1, 366)) || (!leap && !in_range(yearday, 1, 365)))
		return 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 1;
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

	if (day_of_year(1239, 14, 1) == -1)
		printf("ups, bad arguments for day_of_year\n");
	if (day_of_year(1239, 2, 4123) == -1)
		printf("ups, bad arguments for day_of_year\n");
	return 0;
}
