#include <stdio.h>

int main() {
  char *pc = NULL;
  int *pi = NULL;
  double *pd = NULL;
  short *ps = NULL;
  long *pl = NULL;
  float *pf = NULL;
  long double *pld = NULL;

  printf("char = %lu byte\n", (unsigned long) (pc + 1));
  printf("int = %lu byte\n", (unsigned long) (pi + 1));
  printf("double = %lu byte\n", (unsigned long) (pd + 1));
  printf("short = %lu byte\n", (unsigned long) (ps + 1));
  printf("long = %lu byte\n", (unsigned long) (pl + 1));
  printf("float = %lu byte\n", (unsigned long) (pf + 1));
  printf("long double = %lu byte\n", (unsigned long) (pld + 1));
}