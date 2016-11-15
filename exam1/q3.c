#include <stdio.h>
#include <string.h> /* knows strlen function */
#define True 1
#define False 0
/* isoctal: checks if the given string is octal */
int isoctal(char s[]) {
    int i;
    if(strlen(s) < 2){
      return False;
    }
    if(s[0] != '0'){
      return False;
    }
    if(s[0] == '0' && s[1] == '\0'){
      return False;
    }
    // if(s[0] == '0' && s[1] != '\0'){
    //   for(i=0; s[i] != '\0';++i){
    //     if(s[i] >= '0' && s[i] <= '7'){
    //       return True;
    //     }
    //     else{
    //       return False;
    //     }
    //   }
    // }

    if(s[0] == '0' && s[1] != '\0'){
      if(s[1] == '8'){
        return False;
      }
      else if(s[2] == '8'){
        return False;
      }
      else{
        return True;
      }
    }
}
int main() {
    printf("%d\n", isoctal("0")); /* prints 0 */
    printf("%d\n", isoctal("3")); /* prints 0 */
    printf("%d\n", isoctal("00")); /* prints 1 */
    printf("%d\n", isoctal("01")); /* prints 1 */
    printf("%d\n", isoctal("02")); /* prints 1 */
    printf("%d\n", isoctal("07")); /* prints 1 */
    printf("%d\n", isoctal("08")); /* prints 0 */
    printf("%d\n", isoctal("010")); /* prints 1 */
    printf("%d\n", isoctal("011")); /* prints 1 */
    printf("%d\n", isoctal("017")); /* prints 1 */
    printf("%d\n", isoctal("020")); /* prints 1 */
    printf("%d\n", isoctal("077")); /* prints 1 */
    printf("%d\n", isoctal("078")); /* prints 0 */
    printf("%d\n", isoctal("0100")); /* prints 1 */
}
