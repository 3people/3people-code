#include "stdio.h"

int palindrome(char *s, int l){
  int ans = 1;
  for(int i = 0; i*2 <= l; i++){
    if(*(s+i) != *(s+l-i-1))
      ans = 0;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  int ans;
  ans = palindrome("step on no pets", 15);
  printf("%d\n", ans);
  return 0;
}
