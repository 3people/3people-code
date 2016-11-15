#include <stdio.h>

void expand(char s[], char t[]) {
    int start = s[0] - 48;
    int end = s[2] - 48;
    int i, j = 0;
    for(i = start; i <= end; ++i){
      t[j++] = i + 48;
    }
    t[j] = '\0';
}

int main() {
    char u0[10] = "2-7";
    char u1[10] = "3-3";
    char u2[10] = "4-2";
    char v[10];
    printf("Before: %s\n", u0);
    expand(u0, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u1);
    expand(u1, v);
    printf("After: %s\n", v);
    printf("Before: %s\n", u2);
    expand(u2, v);
    printf("After: %s\n", v);
}
