#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  /* max #lines to be sorted */

char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines(char *lineptr[], int nlines);

// 역순으로 출력만 하면 되기때문에, 출력함수에 순서를 알려준다.
void writelines(char *lineptr[], int nlines, int order);


/*
	컴파일 오류를 고치기 위해 const를 붙입니다.
	const는 넘겨준 값이 변할 수 없다는 뜻입니다. 포인터에서는 포인터가 가르키고 있는 값을 변경시킬 수 없습니다.
*/

void qsort(char *lineptr[], int left, int right,
	       int (*comp)(const char *, const char *));

/*
	복잡한 포인터 읽는법 :
	(4) (2  1 )(            3             )
	int (*comp)(const char *, const char *)	
	=> comp는 포인터인데, (const char *, const char *)를 받는 함수인데 리턴값으로 int를 내어준다.
*/

// 주어진 두 문자열을 숫자로 바꾸어 비교하는 함수입니다.
int numcmp(const char *, const char *);

// 대소문자를 구분하지 않는 비교함수입니다.  (qsort.c에 구현합니다.)
int charcmp(const char *, const char *);

/* sort input lines */
int main(int argc, char *argv[]) {
	int nlines;       /* number of input lines read */
	int numeric = 0;  /* 1 if numeric sort */
	int decr = 0;  	  /* 1 if decr sort */
	int fold = 0;  	  /* 왜 대소문자 구분을 f이고, fold라고 하는지 잘 모르겠네요. */
	int c = 0;



	// 간단하게 옵션을 하나씩만 받을 수 있는 코드입니다.
	// argv[0] 은 자기자신이므로 ++ 해줍니다. -f -n 과 같이 첫번째 문자가 '-'일때 옵션을 찾습니다. (argv[1][0])
	if (**++argv == '-') 
	// 현재가리키고 있는 argv에서 ++ 만큼하고, 해당 문자를 가져옵니다. (argv[1][1])
	switch (*++*argv) {
		case 'f':
			fold = 1;
			break;
		case 'n':
			numeric = 1;
			break;
		case 'r':
			decr = 1;
			break;
		default:
			printf("sort: illegal option %c\n",c);
			printf("Usage: -[f|n|r] %c\n",c);
			return 0;
			break;
	}

	// 좀 더 그럴싸하게 옵션을 받는 방법입니다.
	// 하지만 각 옵션별로 하나의 비교함수만 사용할 수 있으니, 큰 이득은 없습니다.
	/*
	while(--argc > 0 && (*++argv)[0] == '-') {
		while((c = *++argv[0])){
			switch(c) {
				case 'f':
						fold = 1;
						break;
				case 'n':
						numeric = 1;
						break;
				case 'r':
						decr = 1;
						break;
				default:
						printf("sort: illegal option %c\n",c);
						printf("Usage: -[f|n|r] %c\n",c);
				break;
				}
			}
		}
	*/

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		// -n 옵션으로 numeric이 1이 되면, qsort의 comp자리에 numcmp가 들어가게 되고,
		// 다른 옵션이 없다면 strcmp를 사용하게 됩니다.
		// (numeric ? (numcmp) : (fold ? (charcmp) : (strcmp))) 삼항연사자는 겹쳐사용해도 됩니다.
		qsort(lineptr, 0, nlines-1, numeric ? numcmp : fold ? charcmp : strcmp);
		writelines(lineptr, nlines, decr);
		return 0;
	}
	else {
		printf("input too big to sort\n");
		return 1;
	}
}