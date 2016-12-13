#include <stdio.h>

int main() {
  char a[] = "xyz";
  char *p;
  int i;
  p = a;


  for (i = 0; i < 3; ++i){
    printf("%c\n", *p++);
  }
  /*
    x
    y
    z
  */
  printf("a = %s\n", a);
  // a = xyz

  p = a;

  for (i = 0; i < 3; ++i){
    printf("%c\n", (*p)++);
  }
  /*
    x y z
  */
  // printf("a = %lu   // p = %lu\n", (unsigned long)a, (unsigned long)p);
  printf("a = %s\n", a);
}