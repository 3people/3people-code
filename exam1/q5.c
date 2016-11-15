#include <stdio.h>

/* vowels_out : extracts vowels and remembers where they were */
int vowels_out(char s[], char t[]) {
	int count, i, j;
	count = 0;
	for (i = j = 0; t[i] != '\0'; i++)
			switch (t[i]) {
					case 'a':
							s[j++] = ' ';
							count++;
							break;
					case 'e':
							s[j++] = ' ';
							count++;
							break;
					case 'i':
							s[j++] = ' ';
							count++;
							break;
					case 'o':
							s[j++] = ' ';
							count++;
							break;
					case 'u':
							s[j++] = ' ';
							count++;
							break;
					default:
							s[j++] = t[i];
							break;
			}
	return count;
}

int main() {
	char u1[100] = "While my guitar gently weeps";
  char u2[100] = "Still crazy after all these years";
  char u3[100] = "She came in through the bathroom window";
	char v[100];
	printf("%s = ", u1);
	printf("%d\nC : %s\nV : %s\n", vowels_out(u1, v), u1, v);
	printf("%s = ", u2);
	printf("%d\nC : %s\nV : %s\n", vowels_out(u2, v), u2, v);
	printf("%s = ", u3);
	printf("%d\nC : %s\nV : %s\n", vowels_out(u3, v), u3, v);
}

/*
While my guitar gently weeps = 8
C : Wh l  my g  t r g ntly w  ps
V :   i e     ui a   e      ee
Still crazy after all these years = 9
C : St ll cr zy  ft r  ll th s  y  rs
V :   i     a   a  e  a     e e  ea
She came in through the bathroom window = 12
C : Sh  c m   n thr  gh th  b thr  m w nd w
V :   e  a e i     ou     e  a   oo   i  o
*/
