#include <stdio.h>

/* copy input to output */
int main() {
    int c;

	while ((c = getchar()) != EOF)
    if(c>= 'A' && c<='Z'){
      putchar(c);
    }
    else if(c >= 'a' && c <= 'z'){
      c = c - 32;
      putchar(c);
    }
    else{
      putchar(c);
    }
}
