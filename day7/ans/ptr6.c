#include <stdio.h>

void time(int t, int *h, int *m, int *s);

int main() {
  int t = 3723, h, m, s;
  time(t, &h, &m , &s);
  printf("%8d =\n%2d : %2d : %2d\n", t, h ,m ,s);
  return 0;
}

void time(int t, int *h, int *m, int *s) {
  *h = t/3600;
  *m = t%3600/60;
  *s = t%60;
}