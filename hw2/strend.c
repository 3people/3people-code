#include <stdio.h>
#include "string.h"

int strend(char *s, char *t){
  int s_len = strlen(s);
  int t_len = strlen(t);
  s = s + s_len - t_len;
  for(; *s == *t ; s++,t++){
    if(*s!='\0'){
      return 1;
    }
  }
  return 0;
}

int main() {
    printf("%d\n", strend("HanyangERICA", "ERICA"));
    printf("%d\n", strend("HanyangERICAERICA", "ERICA"));
    printf("%d\n", strend("HanyangERICAnsan", "ERICA"));
    printf("%d\n", strend("Hanyang", "ERICA"));
}
