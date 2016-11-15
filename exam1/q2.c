#include <stdio.h>
#define MAXLINE 10  /* maximum input line size */

int readline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int len);

/* print longest input line */
int main() {
    int len;                 /* current line length */
	char line[MAXLINE];      /* current input line */

	while ((len = readline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}
	return 0;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;

	// i = 0;
	// while ((to[i] = from[i]) != '\0')
	// 	++i;
  for(i=0; from[i] != '\0'; ++i){
    to[i] = from[i];
  }
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void reverse(char line[], int len) {
	int i;
	char orig[MAXLINE];

	copy(orig, line);
	// i = 0;
	// while (orig[i] != '\n') {
	// 	line[len-i-2] = orig[i];
	// 	++i;
	// }

  for(i=0; orig[i] != '\n'; ++i){
    line[len-i-2] = orig[i];
  }
}
