#include <stdio.h>


static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// 함수의 프로토타입 입니다.
int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);

int main(void)
{
    int day,mon,dat;

    day=day_of_year(1992,12,31);
    printf("1.\t%d\n",day);

    day=day_of_year(1993,12,31);
    printf("2.\t%d\n",day);

    day=day_of_year(1992,6,6);
    printf("3.\t%d\n",day);

    day=day_of_year(1992,12,32);
    printf("4.\t%d\n",day);




    month_day(1992,81,&mon,&dat);
    printf("5.\t%d,%d\n",mon,dat);

    month_day(1992,366,&mon,&dat);
    printf("6.\t%d,%d\n",mon,dat);

    month_day(2002,366,&mon,&dat);
    printf("7.\t%d,%d\n",mon,dat);

    month_day(2002,100,&mon,&dat);
    printf("8.\t%d,%d\n",mon,dat);
    
    return 0;
}

/* day_of_year: set day of year from manth & day */
int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	// month & day 체크 루틴
	if(month < 1
		|| month > 12
		|| day < 1
		|| day > daytab[leap][month]) // day는 해당 month의 마지막 날짜보다 클 수 없습니다.
        return -1;

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	// year 체크
	if (year < 1) {
		*pmonth = -1;
		*pday = -1;
		return ;
	}

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	// i <= 12, 12월 넘지 않게 체크
	for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	// 해당 년도의 월이 몇일인지 체크하는 루틴
	if(i > 12 || yearday > daytab[leap][12]) {
		*pmonth=-1;
		*pday=-1;
	} else {
		*pmonth=i;
		*pday=yearday;
	}
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