#include <stdio.h>

int main() {
    char *p = "xyz";
    char r[] = "xyz";
    char *q = "xyz";

    printf("p = %p, %s\n",p, p);
    printf("q = %p, %s\n",q, q);
    printf("r = %p, %s\n",r, r);
    if (p == q)
        printf("p and q have the same address!\n");
    else
        printf("p and q have different addresses!\n");
    if (p == r)
        printf("p and r have the same address!\n");
    else
        printf("p and r have different addresses!\n");
}