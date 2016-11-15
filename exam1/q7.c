#include <stdio.h>

/* packdate: packs date into 16-bit integer */
unsigned short packdate(unsigned short year, unsigned short month, unsigned short day) {
	unsigned short zero = ~0;
	unsigned short allone = ~(zero << 5);
	// allone 0000 0000 0001 1111
	// day    0000 0000 0001 1011
	// month  0000 0000 0000 1010
	// 5_m    0000 0001 0100 0000
	allone = allone & day;
	allone = allone | (month << 5);
	year = year - 2000;
	allone = allone | (year << 9);


  return allone;
}

int main() {
	unsigned short year = 2016;
	unsigned short month = 10;
	unsigned short day = 27;
	printf("%d/%d/%d = %d\n", year, month, day, packdate(year, month, day));
}

/*
2016/10/27 = 8539
*/
