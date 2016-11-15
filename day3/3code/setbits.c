#include "stdio.h"

void bin(unsigned x){
  short size = sizeof(x)*8;
  char o[sizeof(x)*8] = {'0'};
  o[size+1]='\0';
  int i;
  for(i=0;i<=size;i++)o[size-i] = (x>>i&1)+48;
  printf("binary : %s, dec : %u\n",o+1,x);
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
  // x         = 0001 0100 0011 0011
  // y         = 0000 0000 0001 1011
  // mask      = 0000 0000 0001 1111
  // mask2     = 1110 0000 1111 1111
  // x         = 0000 0000 0011 0011
  // idontknow = 0000 0000 0001 1011
  // idontknoo = 0001 1011 0000 0000
  unsigned mask = ~(~0 << n);

  unsigned mask2 = ~(mask << (p+1-n));
  x = x & mask2;
  unsigned idontknow = y & mask;
  unsigned idontknoo = idontknow << (p-n+1);
  x = idontknoo | x;
  bin(x);
  return x;
}

int main() {
  unsigned a = 0x1433;
  unsigned b = 0x1b;
  // bin(setbits(a,12,5,b));
  unsigned k = setbits(a,12, 5,b);
  return 0;
}
