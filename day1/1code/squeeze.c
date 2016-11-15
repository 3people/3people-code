#include "stdio.h"

#define SPACE 1
#define WORDS 0

int main(){
  int c, state;
  state = SPACE;
  while((c = getchar()) != EOF ){
    if(state == WORDS || c != ' '){
      putchar(c);
    }
    if(c == ' '){
      state = SPACE;
    }
    else{
      state = WORDS;
    }
  }
}
