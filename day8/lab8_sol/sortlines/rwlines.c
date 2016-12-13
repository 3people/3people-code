#include <stdio.h>
#include <string.h> // strcpy를 사용하기 위해 불러옵니다.

#define MAXLEN 1000

/*
  직접 구현하지 않고, 트렐로의 강의자료7번
  slide7code.zip에 있는 salloc.c를 사용합니다.
  함께 컴파일 하기 위해 sortlines폴더에 함께 넣습니다.
*/
char *alloc(int);

/* readline: read line into s, return length */
int readline(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = readline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			// strcpy() 함수를 쓰기 위해선 string.h를 불러와야 합니다.
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines) {
	int i;

	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
	/*
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
	*/
}
