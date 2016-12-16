/////////////////////////////////////////////////////////////////////////
//       C pointer example 2
//          Masaaki Mizuno (c) 1992,
//           modified for Learning Tree Course 223P, 2005
//
////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int a[3][4][3] = {{1,2,3,4,5,6,7,8,9,10,11,12},
              {13,14,15,16,17,18,19,20,21,22,23,24},
              {25,26,27,28,29,30,31,32,33,34,35,36}};
int (*b)[4][3] = a; //b가 가리키고 있는곳이 정수의 2차원 배열이다
int *(c[3][4]) = {a[0][0],a[0][1],a[0][2],a[0][3],
     a[1][0],a[1][1],a[1][2],a[1][3],
     a[2][0],a[2][1],a[2][2],a[2][3]}; //2차원 배열이 integer포인터로 정의되있다
int *(*d)[4] = c;
int *(*e[3]) = {c[0],c[1],c[2]};
int ***f = e;
int (*g[3])[3] = [a[0],a[1],a[2]];
int (**h)[3]; =g;
// Declare b, c, d, e, f, g, and  h correctly

int main() {
  int i, j, k;

  printf("a\tb\tc\td\te\tf\tg\th\n\n");
  for(i = 0; i < 3; i++)
    for(j = 0; j < 4; j++)
      for(k = 0; k < 3; k++) {
        printf("%d\t", a[i][j][k]);
        printf("%d\t", b[i][j][k]);
//        printf("%d\t", c[i][j][k]);
//        printf("%d\t", d[i][j][k]);
//        printf("%d\t", e[i][j][k]);
//        printf("%d\t", f[i][j][k]);
//        printf("%d\t", g[i][j][k]);
//        printf("%d\t", h[i][j][k]);
        printf("\n");
      }
  return 0;
}
