#include <stdio.h>

/* otoi: converts an octal string to decimal integer */
int otoi(char s[]) {
  int i,n;
  n=0;
  for(i=0;(s[i] >= '0' && s[i] <= '7'); ++i){
    n = 8 * n + (s[i] - '0');
  }
    return n;
}

int main() {
	printf("%d\n", otoi("00")); /* prints 0 */
	printf("%d\n", otoi("01")); /* prints 1 */
	printf("%d\n", otoi("02")); /* prints 2 */
	printf("%d\n", otoi("07")); /* prints 7 */
	printf("%d\n", otoi("010")); /* prints 8 */
    printf("%d\n", otoi("011")); /* prints 9 */
    printf("%d\n", otoi("017")); /* prints 15 */
    printf("%d\n", otoi("020")); /* prints 16 */
    printf("%d\n", otoi("077")); /* prints 63 */
    printf("%d\n", otoi("0100")); /* prints 64 */
}
