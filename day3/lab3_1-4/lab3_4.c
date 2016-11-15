#include <stdio.h>

void bin(unsigned x){
  short size = sizeof(x)*8;
  char o[sizeof(x)*8] = {'0'};
  o[size+1]='\0';
  int i;
  for(i=0;i<=size;i++)o[size-i] = (x>>i&1)+48;
  printf("binary : %s, dec : %u\n",o+1,x);
}

unsigned invert(unsigned x, int p, int n){

  /*
  p = 3, n = 5
  mask            = 00000000000000000000000000011111

  x               = 00000000111110101111101010101010
  ~x              = 11111111000001010000010101010101
  mask<<p         = 00000000000000000000000011111000
  ~x&mask<<p      = 00000000000000000000000001010000

  x               = 00000000111110101111101010101010
  ~(mask<<p)      = 11111111111111111111111100000111
  x&~(mask<<p)    = 00000000111110101111101000000010

  ~x&mask<<p | x&~(mask<<p)
                  = 00000000111110101111101000000010
                   +00000000000000000000000001010000
                    ---------------------------------
                  = 00000000111110101111101010101010
  */

  unsigned mask = ~(~0 << n);
  bin(x);
  bin(~x);
  bin(~(mask<<p));
  bin(~x&mask<<p);
  bin(x&~(mask<<p));
  bin( ~x&mask<<p | x&~(mask<<p) );
  return x;
}

int main() {
  invert(0xFAFAAA,3,5);
  return 0;
}