#include "stdio.h"

void bin(unsigned x){
  short size = sizeof(x)*8;
  char o[sizeof(x)*8] = {'0'};
  o[size+1]='\0';
  int i;
  for(i=0;i<=size;i++)o[size-i] = (x>>i&1)+48;
  printf("binary : %s, dec : %u\n",o+1,x);
}


unsigned invert(unsigned x, int p, int n){
  // x         = 0001 0100 0011 0011
  // mask      = 0000 0000 0001 1111
  // mask2     = 0001 1111 0000 0000
  unsigned mask = ~(~0 << n);
  unsigned mask2 = mask << (p-n+1);
  return mask2 ^ x;
}











int main() {
  unsigned a = 0x1433;
  bin(invert(a,12,5));
  return 0;
}
