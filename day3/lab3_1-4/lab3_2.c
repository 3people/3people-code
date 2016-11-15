#include <stdio.h>

// 원래 sqeeze 함수
void squeeze_origin(char s[], int c) {
	int i, j;

	/*
	 문자열의 구조가 다음과 같음을 기억해주세요.
	 "abc" => 'a' 'b' 'c' '\0'
	 문자열 끝에는 반드시 '\0'을 붙여줘야합니다.
	 그렇지 않으면 뒤에 쓰레기값까지 읽게 됩니다.
	*/

	// i와 j를 0으로 초기화하고; s[i]가 '\0'이면 종료
	for (i = j = 0; s[i] != '\0'; i++)
		// s[i]가 지울 문자가 아니라면
		if (s[i] != c)
			// s[j]에 s[i]를 넣은 뒤 j를 1 증가시킵니다.
			s[j++] = s[i];
		// for문이 끝난 뒤 마지막 자리에 '\0'을 넣습니다.
		s[j] = '\0';


/*
	C언어에서 중괄호가 없으면 반드시 다음 첫번째 명령어에만 작동합니다.

	예)
	for (...)
	if (...)
	a;
	b;
	c;
	
	는 중괄호를 써서 표현하면 다음과 같습니다.

	for (...){
		if (...){
			a;
		}
	}
	b;
	c;
*/
}


void squeeze(char s[], char c[]) {
	// 지울 문자 하나만 받던 c가 지금은 char[], 즉 문자열을 받습니다.
	int i, j, k;

	for (k = 0; c[k] != '\0'; k++){
		// c에서 지울 문자를 하나씩 가져오는 부분이 추가되었습니다.
		for (i = j = 0; s[i] != '\0'; i++){
			if (s[i] != c[k]){
				// 문자 하나인 c에서 문자열에서 k위치에 있는 문자인 c[k]로 바뀌었습니다.
				s[j++] = s[i];
			}
		}
		s[j] = '\0';
	}
}

void main() {
	char s1[] = "hanyang university";
	char s2[] = "san";

	// "hanyang university" 에서 's','a','n'을 지웁니다.

	squeeze(s1, s2);
	printf("result : %s\n",s1);

	// 예상 결과
	// result : hyg uiverity

}