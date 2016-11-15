#include "stdio.h"
#include "string.h"


int mystrncmp(char *s, char *t, int n){
  for ( ; n > 0; s++, t++, --n){
	  if (*s != *t){
      if(*s < *t){
        return -1;
      }
      else{
        return +1;
      }
    }
  }
  return 0;
}



int main(void){
  char a[100] = "appleapple";
  char b[100] = "banana";
  printf("%d\n", mystrncmp(a,b,3));
}
