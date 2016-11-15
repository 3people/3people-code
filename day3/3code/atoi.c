/* atoi: convert s to integer */
#include "stdio.h"

int htoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f'); ++i){
      if (s[i] >= '0' && s[i] <= '9') {
        n = 16 * n + (s[i] - '0');
      }
      if (s[i] >= 'a' && s[i] <= 'f') {
        n = 16 * n + (s[i] - 'a' + 10);
      }
    }
    return n;
}

int main() {
  // TEST

  char a[] = "64";
  char b[] = "3e8";
  char c[] = "270f";
  char d[] = "3039";

  printf("%s -> %d\n", a , htoi(a));
  printf("%s -> %d\n", b , htoi(b));
  printf("%s -> %d\n", c , htoi(c));
  printf("%s -> %d\n", d , htoi(d));

  return 0;
}
