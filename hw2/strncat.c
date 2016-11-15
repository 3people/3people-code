#include "stdio.h"
#include "string.h"

char *mystrncat(char *s, char *t, int n){
  char *k = s;
  int s_len = strlen(s);
  k = k + s_len;
  while (n > 0 && *t != '\0'){
    *k++ = *t++;
    --n;
  }
  *k= '\0';
  return s;
}

int main() {
  char a[100] = "appleapple";
  char b[100] = "bbbbbbb";
  printf("%s\n", mystrncat(a,b,3));
}
