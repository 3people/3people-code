#include <stdio.h>


int main() {
  // TEST

  char a[] = "64";
  char b[] = "3E8";
  char c[] = "270f";
  char d[] = "3039";

  printf("%s -> %d\n", a , htoi(a));
  printf("%s -> %d\n", b , htoi(b));
  printf("%s -> %d\n", c , htoi(c));
  printf("%s -> %d\n", d , htoi(d));

  return 0;
}


/* atoi: convert s to integer */
int htoi(char s[]) {
  int i, n;
  
  n = 0; // 정답으로 내어줄 변수.

  // atoi에서 'a'~'f' 까지 허용하도록 |(or) 연사자로 붙여준다.
  for (i = 0; (s[i] >= '0' && s[i] <= '9') | (s[i]>='a' && s[i]<='f'); ++i) {
    // 해당 문자가 숫자에 해당하는 경우
    if( s[i] >= '0' && s[i] <= '9')
      /* '2'은 숫자 50, '0'은 숫자 48
         '2' - '0'은 숫자 2 이다.
         16 * n은 한자리가 올라가면 16이 올라가기 때문에
         자리올림으로 16을 곱해준다.
      */
      n = 16 * n + (s[i] - '0');
    // 해당 문자가 숫자에 해당하는 경우
    if( s[i] >= 'a' && s[i] <= 'f')
      /* 'a'는 숫자 97, 'f'는 숫자 102
         'f' - 'a'은 숫자 5 이다.
         실제 'f'는 15를 의미하기 때문에 +10 을 해준다.
         'a'의 경우 'a' - 'a' +10 = 0 + 10
      */
      n = 16 * n + (s[i] - 'a' + 10);
  }
  return n;
}
