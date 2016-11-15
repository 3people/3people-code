#include <stdio.h>

#define SPACE 1
#define WORDS 0
/* copy input to output; 2nd version */
int main() {
    int c, state;
    state = SPACE;
	while ((c = getchar()) != EOF){
    if (state == WORDS || c != ' ') {
      putchar(c);
    }
    state = c == ' ' ? SPACE : WORDS;
  }
}
