#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/*
  main은 int를 리턴하는것이 기본입니다.
  컴파일러가 고쳐주긴 하지만, 확실하게 하기 위해 리턴타입을 명시해줍니다.
*/

/*********************************
   여러 파일을 한꺼번에 컴파일 하려면
   gcc a.c b.c c.c .. 와 같이 gcc의 인자로 모두 써주면 됩니다.
   이 실습문제에서는 새로 추가한 salloc.c 까지 포함하여 다음과 같이 씁니다.

   > gcc main.c qsortint.c rwlines.c salloc.c
   > a.out

   아래와 같은 입력을 하였을때ㅡ
   bbb11
   bbb33
   bbb22
   ab
   aa

   결과는 다음과 같습니다.
   aa
   ab
   bbb11
   bbb22
   bbb33

	EOF를 입력하는 방법은 ctrl+D를 누르면 됩니다.
*/


int main() {
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}