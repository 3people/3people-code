#include <stdio.h>

#define ARRAY_SIZE 4

void merge(int *x, int *y, int *z);


int main() {
  int x[ARRAY_SIZE] = {3,7,11,13};
  int y[ARRAY_SIZE] = {2,5,6,9};
  int z[ARRAY_SIZE*2];
  merge(x,y,z);
  for(int i = 0; i < ARRAY_SIZE*2; printf("%2d\n", *(z+i++)));
  return 0;
}



void merge(int *x, int *y, int *z) {
  int i = 0,j = 0,k,a;
  for(k=0; k<=ARRAY_SIZE*2; *(z+k++) = a) {
    if( j >= ARRAY_SIZE ) a = *(x+i++);
    else if( i >= ARRAY_SIZE ) a = *(y+j++);
    else {
      if(*(x+i) < *(y+j) ) a = *(x+i++);
      else a = *(y+j++);
    }
  }
}