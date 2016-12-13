#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *, char *key[]);
int getword(char *, int);
char *blacklist[] = {"a", "the", "is", "was", "are", "were", "have", "had", "they", "you", "your", "it", "don’t", "of", "in", "with", "that", "which"};
/* word frequency count */

int main() {
	struct tnode *root;
	char word[MAXWORD];
	int flag = 0;
	int i;
	char *key[1000];

	root = NULL;

	while (getword(word, MAXWORD) != EOF){
		flag = 0;
		for(i=0; i < 18; i++){
			if(strcmp(blacklist[i], word) == 0){
				flag= 1;
				break;
			}
		}
		if (isalpha(word[0]) && flag ==0){
			root = addtree(root, word);
		}
	}
	treeprint(root, key);

	for(int j = 0; key[j] != NULL ; j++){
		printf("%s\n", key[j]);
	}
	return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond <0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}
int i = 0;
/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p, char *key[]) {
	if (p != NULL) {
		treeprint(p->left, key);
		key[i++] = p->word;
		treeprint(p->right, key);
	}
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */
char *mystrdup(char *s) {
	char *p;

	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}

#define BUFSIZE  100

static char buf[BUFSIZE];   /* buffer for ungetch */
static int bufp = 0;        /* bext free position in buf */

int getch(void) {    /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {   /* push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getword(char *word, int lim) {
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		if ('A' < c || c < 'Z') {
			c += 32;
		}
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
