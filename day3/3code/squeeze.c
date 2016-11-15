/* squeeze: delete all c from s */
void squeeze(char s[], char c[]) {
	int i, j, k;

	for(k=0; c[k]; ++k){
		for (i = j = 0; s[i] != '\0'; i++){
			if (s[i] != c[k]){
				s[j++] = s[i];
			}
		}
		s[j] = '\0';
	}
}

int main() {
	char s1[] = "abcdefg";
	char s2[] = "bf";
	squeeze(s1, s2);
	printf("result : %s\n",s1);

}
