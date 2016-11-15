#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, …, 300; floating-point version */
int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = -30;    /* lower limit of temperature table */
    upper = 50;  /* upper limit */
    step = 10;    /* step size */

    celsius = lower;
    printf("  C    F\n");
    while (celsius <= upper) {
        fahr = celsius * 9 / 5 + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
