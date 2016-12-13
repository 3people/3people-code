#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void myreverse(char *s){
  int c;
  char *start = s, *end = s;
  while(*end != '\0') end++;
  end--;

  for(;start<end;start++,end--){
    c = *start;
    *start = *end;
    *end = c;
  }
}

int main(void){
  char s[100] = "HANYANG";
  myreverse(s);
  printf("%s\n", s); // GNAYNAH
}