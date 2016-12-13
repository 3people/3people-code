#include <stdio.h>

int main() {
  int i = 3, j = 7;
  int *p = &i, *q = &j;
  printf("*p + 7 = %d\n", *p + 7);
  printf("3 * **&p + 1 = %d\n", 3 * **&p + 1);
  printf("p = %lu\n", (unsigned long)p); /* 1 */
  printf("q = %lu\n", (unsigned long)q); /* 1 */
  printf("p - q = %lu\n", p - q); /* 2 */
  printf("p - 2 = %lu\n", (unsigned long)(p - 2) ); /* 3 */
  printf("p - (p - 2) = %ld\n", p - (p - 2)); /* 4 */
}