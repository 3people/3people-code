#include <stdio.h>

void time(int t, int *h, int *m, int *s){
  *h = t / 3600;
  *m = t % 3600 / 60;
  *s = t % 60;
}

int main(){
  int t = 3723;
  int m,h,s;
  time(t, &h, &m, &s);
  printf("%d시간 %d분 %d초 \n", h,m,s);
}
