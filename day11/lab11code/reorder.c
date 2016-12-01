#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENT 100
#define BUF 100

struct student {
	char *name;
	char *id;
	char grade;
};

struct student *read_student();
void add_student(struct student array[], struct student *std);
void print_student(struct student students[]);
float class_average(struct student students[]);

char *get_word();

int meetEOF = 0;

int main(void) {
	struct student students[MAX_STUDENT] = {{0}};
	struct student *std;

	while ((std = read_student()) != NULL) {
		add_student(students,std);
	}
	print_student(students);
	printf("\nClass AVG.:\t%f\n", class_average(students));
}

struct student *read_student() {
	struct student *std;
	char *name = get_word();
	char *id = get_word();
	char *grade = get_word();

	if(name == NULL || id == NULL || grade == NULL) return NULL;
	std = (struct student *)(malloc(sizeof(struct student)));
	std->name = name;
	std->id = id;
	std->grade = *grade;
	return std;
}

void add_student(struct student students[], struct student *std) {
	int inserted = 0;
	struct student tmp, swap;
	int index;

	for(index = 0; students[index].id != 0 && index < MAX_STUDENT; index++){
		//students[index].grade vs (*std).grade
		//1. students[index] 보다 (*std).grade가 작은가?
		if(students[index].grade > (*std).grade
			|| (students[index].grade == (*std).grade
				&& strcmp(students[index].name, (*std).name) > 0)){
		//1.T students[index]에 (*std)를 넣고.
		//    원래 students[index]에 있는 struct를 std에 넣는다.
			tmp = students[index];
			students[index] = *std;
			*std = tmp;
		//1.F 다음으로 넘어간다.
		}
	}
	//2. for가 끝날때까지 들어갈 자리가 없었다면(insertion이 없다면)
	//   마지막자리(index)에 *std를 넣는다.
	students[index] = *std;
}

void print_student(struct student students[]) {
	printf("%10s\t%10s\tGrade\n","Name","Student ID");
	for (int index=0;
		 students[index].id != 0 && index < MAX_STUDENT;
		 ++index) {
		printf("%10s\t%10s\t%c\n",
			   students[index].name,
			   students[index].id,
			   students[index].grade);
	}
}

float class_average(struct student students[]) {
	float avg,sum=0.0;
	int count = 0;

	for (count=0;
		 students[count].id != 0 && count < MAX_STUDENT;
		 ++count) {
			 if(students[count].grade != 'F'){
				 sum += (69 -students[count].grade);
			 }
			
	}

	return (count == 0) ? 0.0 : sum/count;;
}

char *get_word() {
	char *word = (char *) malloc(sizeof(char)*BUF);
	char c;
	int index;

	if (meetEOF) return NULL;

	while (isspace(c = getchar())) ;

	for (index=0; index < BUF; ++index) {
		if (c == EOF) {
			meetEOF = 1;
			break;
      // free(word);
      // return NULL;
		}
		if (isalnum(c))
			word[index] = c;
		else
			break;
		c = getchar();
	}
	word[index] = '\0';
	return word;
}
