#include "stdio.h"

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from manth & day */
int day_of_year(int year, int month, int day) {
	int i, leap;

	if (year < 0 || (month <= 12 && 1 <= month)) {
		return -1;
	}
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	if (year < 0) {
		*pmonth = -1;
		*pday = -1;
		return ;

	}
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < 12 && yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	if (yearday > daytab[leap][i]) {
		*pmonth = -1;
		*pday = -1;
		return;
	}
	*pmonth = i;
	*pday = yearday;
}

/* month_name: return name of n-th month */
char *month_name(int n) {
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(int argc, char const *argv[]) {
	int year;
	int yearday;
	int pmonth;
	int pday;

	year = 2000;
	yearday = 366;
	month_day(year, yearday, &pmonth, &pday);
	printf("year : %d, yearday : %d, month : %d, day : %d\n", year, yearday, pmonth, pday);
	year = 2002;
	yearday = 366;
	month_day(year, yearday, &pmonth, &pday);
	printf("year : %d, yearday : %d, month : %d, day : %d\n", year, yearday, pmonth, pday);
	year = 1997;
	month = 7;
	day = 31;
	printf("year : %d, month : %d, day : %d = %d\n", year, month, day, day_of_year(year, month, day));
}
