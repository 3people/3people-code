#include "stdio.h"
#include "string.h"

char *strncopy(char *s, char *t, int n){
  char *k = s;
  while (n > 0 && *t != '\0') {
	   *k++ = *t++;
     --n;
  }
  while (n > 0) {
    *k++ = '\0';
	  --n;
  }
  return s;
}



int main(){
  char a[100] = "appleapple";
  char b[100] = "bbbbbbb";
  printf("%s\n", strncopy(a,b,3));
}
