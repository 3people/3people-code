#include <stdio.h>
#include <string.h>

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
	int i, last, pivot;

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	pivot = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++pivot, i);
	swap(v, left, pivot);
	qsort(v, left, pivot-1);
	qsort(v, pivot+1, right);
}

// int main() {
// 	int a[10] = {5,2,4,3,6,8,7,1,9,10};
// 	int i;
//
// 	for (i = 0; i < 10; i++)
// 		printf("%d ", a[i]);
// 	printf("\n");
// 	qsort(a, 0, 9);
// 	for (i = 0; i < 10; i++)
// 		printf("%d ", a[i]);
// 	printf("\n");
// }
