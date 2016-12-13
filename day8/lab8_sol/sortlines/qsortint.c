#include <stdio.h>
#include <string.h>

/*
  qsort는 문자열( char[] ) 하나를 문자(char) 기준으로 정렬했다면
  이 프로그램에서는 strcmp함수를 이용해서 문자열( char[] )끼리 정렬합니다.
*/


/* swap: interchange v[i] and v[j] */

/*
  int v[] 를 int *v[]로 바꿉니다.
  문자열 배열이니까 char *v[]로 바꿉니다.
  강의노트에 있는 배열을 가리키는 포인터입니다.

  char v[]에서 v[i]는 'char'이지만,
  char *v[]에서 v[i]는 'char*'를 의미하게 됩니다.
*/


// void swap(int v[], int i, int j) {
void swap(char *v[], int i, int j) {
	// int temp;
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
/*
  int v[]를 char *v[]로 바꿔줍니다.
  pivot변수를 선언하지 않고 사용해서 error가 납니다.
  int pivot을 선언해줍니다.
*/

// void qsort(int v[], int left, int right) {
void qsort(char *v[], int left, int right) {
	// int i, last;
	int i, last, pivot;

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	pivot = left;
	for (i = left+1; i <= right; i++)
/*
  입력받은 문자열인 int v[]이었을땐, v[i]와 v[left]를 비교하며
  quick sort를 실행합니다.

  ex)
  v[] = "acb" 일때
  v[0] < v[1] 는
  'a' < 'b' 와 같은 비교를 하게됩니다.

  이제 입력받은 문자열의 포인터 *v[]를 받습니다.
  v[i]는 이제 문자가 아닌 문자열입니다. 이때 비교는 strcmp를 이용합니다.

  strcmp는
  - 두 문자열이 같으면 0을 내줍니다.
  - "abc"와 "  abc"를 비교하면 양수를 내어줍니다.
  공백이 있는 문자열이 더 길지만, 문자 'a'는 공백문자 ' '보다 ascii값이 더 작기때문에 그렇습니다.
  - "abc"와 "acb"를 비교하면, 음수를 내어줍니다.
  앞의 'a'는 같지만, 두번째 글자인 'b'가'c'보다 값이 작기때문입니다.


  ex)
  *v[] = "abc"
         "cba"
         "acb"
  strcmp( v[0], v[1] ) 을 하게되면,
  strcmp( "abc", "cba" ) 를 하게 됩니다.

  이제 v[i] < v[left] 에서
  strcmp(v[i], v[left]) 로 바꾸어주면 됩니다.
*/
		// if (v[i] < v[left])
		if (strcmp(v[i],v[left]) < 0)
			swap(v, ++pivot, i);
	swap(v, left, pivot);
	qsort(v, left, pivot-1);
	qsort(v, pivot+1, right);
}


/*
  컴파일시 main이 두개이면 컴파일이 되지 않습니다.
  이 메인은 주석처리 해주도록 합니다.
*/

/*
int main() {
	int a[10] = {5,2,4,3,6,8,7,1,9,10};
	int i;

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	qsort(a, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}
*/