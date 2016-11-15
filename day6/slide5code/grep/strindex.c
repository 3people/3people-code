/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k, last = 0;
	for(int l = 0; ;++l){
		if(s[l] == '\0'){
			last = l;
			break;
		}
	}

	for (i = last; i != 0; i--) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
