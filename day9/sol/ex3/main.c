#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include "calc.h"

#define MAXOP   100    /* max size of operand or operator */

/* reverse Polish calculator */
int main(int argc, char *argv[]) {
	int type;
	double op2;
	char s[MAXOP];


	/*	#0
		기존의 함수는 getop(s)를 이용하여 s에 입력한 값을 넣고, 리턴값으로 s의 타입을 정합니다.
		getop(s)함수는 getch.c에 있는 getch() 함수를 이용합니다. getch.c#1에 계속
	*/


	// while ((type = getop(s)) != EOF) {


	/*	#4
		원래 코드는 getop()를 이용해 EOF까지 입력을 계속 받습니다.
		대신 #3에서 만든 ungets에 argv를 직접 넣어줍니다.
	*/
	while (--argc > 0) {

		/* 
			"\n"을 처음에 넣어주는 이유는 case에서 '\n'일때 결과를 출력해주기 때문입니다. (First In Last Out)
		*/
		ungets("\n");
		/*
			이후 argv에 담겨있는 것들을 하나씩 넣습니다.
			argv의 구성은 자기 자신의 이름도 포함합니다.
			ex) $ ./a.out 12 34 56 + +
				일때 argv는 {"./a.out","12","34","56","+","+"} 입니다.
			때문에 첫번째 자기 자신을 무시하기 위해 argv++가 아닌 ++argv를 합니다.
			*++argv로 각각의 문자열을 ungets에 넣어주면서, buf 에 넣습니다.
		*/
		ungets(*++argv);

		/*
			이제 getop(s)를 사용하더라도, getch가 getchar을 불러오지 않고,
			ungets에서 넣어준 문자열을 읽어오게 되면서, type을 리턴하고, s를 정해줍니다.
			-끝-
		*/
		type = getop(s);
	
		switch (type) {
			case NUMBER: 
			    push(atof(s)); 
			    break;
			case '+': 
			    push(pop() + pop()); 
			    break;
			case '*': 
			    push(pop() * pop()); 
			    break;
			case '-':
			    op2 = pop();
			    push(pop() - op2);
			    break;
			case '/':
			    op2 = pop();
			    if (op2 != 0.0)
			    	push(pop() / op2);
			    else
			    	printf("error: zero divisor\n");
			    break;
			case '\n':
			    printf("\t%.8g\n", pop());
			    break;
			default:
			    printf("error: unknown command %s\n", s);
			    break;
		}
	}
	return 0;
}
