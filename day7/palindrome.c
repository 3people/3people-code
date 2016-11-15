#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string1[20];
    int i, length;
    int flag = 0;
    printf("Enter a string: ");
    scanf("%s", string1);
    length = strlen(string1);

    char *start=string1;
    char *end=&string1[length-1];

    //only check upto half


    for(i=0;i <= (length-1)/2 ;i++)
    {
        if(toupper(*(start+i)) != toupper(*(end-i)))
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("%s is not a palindrome \n\n", string1);
    else
        printf("%s is a palindrome \n", string1);

    return 0;
}
