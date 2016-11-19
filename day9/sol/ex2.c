#include <stdio.h>


static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

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
    

    /*
    1.	366
	2.	365
	3.	158
	4.	-1
	5.	3,21
	6.	12,31
	7.	-1,-1
	8.	4,10
	*/
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
	int leap;
	char *p;

	// year 체크
	if (year < 1) {
		*pmonth = -1;
		*pday = -1;
		return ;
	}

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	// i <= 12, 12월 넘지 않게 체크

	/*
		ex1. 코드
		for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*/


	// char *p는 윤년/평년의 월별 날짜정보를 가지고 있는 12개짜리 배열을 가리키고 있습니다.
	p = daytab[leap];

	/*
		*p는 해당하는 월의 날짜를 가지고 있으며, daytab[leap][i]와 같은 역할을 합니다.
		따라서 종료조건은 yearday보다 작아야하며, 매번 yearday -= *p를 해줍니다.
	*/
	while (yearday > *++p)
		yearday -= *p;

	/*
		포인터 p만 가지고는 현재 가리키고 있는 위치가 어느곳인지 알 수 없으므로, 포인터 연산을 이용합니다.
		ex)	int *a = *b = {1,2,3}; 일때,
			(++b) - a = 1; 과 같이 나옵니다.
		기존 위치에서 몇칸을 움직였는지 포인터 연산으로 알아냅니다.
		p는 yearday를 계산하느라 어느정도 움직인 상태입니다.
		p의 원래 위치는 daytab[leap]이므로, p - daytab[leap] 으로 현재 월을 알아냅니다.
	*/
	if (p - daytab[leap] > 12){
		*pmonth = -1;
		*pday = -1;
		return ;
	}
	*pmonth = (p - (daytab[leap]));
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