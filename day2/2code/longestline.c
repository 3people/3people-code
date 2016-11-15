#include <stdio.h>
#define MAXLINE 10

int readline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int len);
/* print each input line in reverse */
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

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

void reverse(char line[], int len){
  int i;
  for(i=len-1; i >= 0; --i){
    printf("%c", line[i]);
  }
  printf("\n");
}
