#include "stdio.h"

void bin(unsigned short x){
  short size = sizeof(unsigned short)*8;
  char o[sizeof(x)*8] = {'0'};
  o[size+1]='\0';
  int i;
  for(i=0;i<=size;i++)o[size-i] = (x>>i&1)+48;
  printf("binary : %s, dec : %u\n",o+1,x);
}

unsigned short circular_shift(unsigned short x, int n){
  // x                    = 0001 0100 0011 0011
  // x << n(3)            = 1010 0001 1001 1000
  // x >> 16 - n(13)      = 0000 0000 0000 0001
  // x << n | x >> 16 - n = 1010 0001 1001 1001
  // unsigned size = sizeof(x) * 8;
  return x << n | x >> (16-n);
}









int main() {
  unsigned short a = 21555;
  bin(circular_shift(a,3));
  return 0;
}
