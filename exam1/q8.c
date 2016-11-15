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

/* showpackeddate: unpacks and prints a packed date */
unsigned short showpackeddate(unsigned short date) {
	unsigned short zero = ~0;
	unsigned short allone = ~(zero << 5);
	//date            0010 0001 0101 1011
	// allone         0000 0000 0001 1111
	unsigned short mask1 = date & allone;
	unsigned short mask2 = date & (allone << 5);
	unsigned short mask2_1 = mask2 >> 5;
	unsigned short mask3 = date & (allone << 9);
	unsigned short mask3_1 = mask3 >> 9;
	mask3_1 = mask3_1 +2000;
	printf("%d/%d/%d\n", mask3_1, mask2_1, mask1);

}

int main() {
	unsigned short year = 2016;
	unsigned short month = 10;
	unsigned short day = 27;
	showpackeddate(packdate(year, month, day));
}
