#include <stdio.h>
#define SIZE 4

void merge(int *x, int *y, int *z){
  int x_index, y_index = 0;
  for(int i = 0; i < SIZE * 2; i++){
    if (x_index >= SIZE) {
      *z = *y;
      y++;
      z++;
    }
    else if(y_index >= SIZE){
      *z = *x;
      x++;
      z++;
    }
    else{
      if(*x > *y){
        *z = *y;
        y++;
        z++;
      }
      else if(*y > *x){
        *z = *x;
        x++;
        z++;
      }
    }
  }
}

int main(){
  int x[SIZE] = {3,7,11,13};
  int y[SIZE] = {2,5,6,9};
  int z[SIZE*2];

  merge(x,y,z);
  for(int i = 0; i < SIZE*2; i++)
    printf("%d\n", *(z+i));
}
