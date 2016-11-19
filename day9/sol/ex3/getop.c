#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[], int argc, char *argv[]) {
	int i, c;


	int j = 0
	while ((s[0] = c = argv[j++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;      /* not a number */
	i = 0;
	if (isdigit(c))    /* collect integer part */
		while (isdigit(s[++i] = argv[j++] = getch()))
			;
	if (c == '.')      /* collect fraction part */
		while (isdigit(s[++i] = argv[j++] = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}