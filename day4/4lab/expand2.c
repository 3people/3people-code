#include <stdio.h>

void expand(char s[], char t[]) {
    int start = s[0] - 48;
    int i = 0, j = 0;

    if (s[0] == '-' && s[1] != '\0') {
      for(i = 0; i <= (s[1] - 48); ++i){
        t[j++] = i + 48;
      }
    }
    else if(s[0] == '-' && s[1] == '\0'){
      for(i = 0; i < 10; ++i){
        t[j++] = i + 48;
      }
    }
    else if(s[1] == '-'){
      for(i = start; i < 10; ++i){
        t[j++] = i + 48;
      }
    }
    else if(s[0] != '-' && s[1] == '\0'){
      t[j++] = s[0];
    }
    t[j] = '\0';
}

int main() {
    char u0[12] = "-";
    char u1[12] = "-3";
    char u2[12] = "4-";
    char u3[12] = "5";
    char v[12];
    printf("Before: %s\n", u0);
    expand(u0, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u1);
    expand(u1, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u2);
    expand(u2, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u3);
    expand(u3, v);
    printf("After: %s\n", v);
}
