#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef struct student {
	int num;
	int kor;
	int eng;
	int math;
	int sum;
	int avg;
	int rank;
	struct student* next;
}student;
student* head;

void score_prt();
double round(double a);
void ranking();
void insert(int a);
void del(int a);
void sorting(int a);
int studentNum;
int onway = 1;

int main()
{
	head = NULL;
	srand((unsigned)time(NULL));
	int num = 0;

	printf("총 학생 수 입력 :");
	scanf_s("%d", &studentNum);

	for (int i = 0;i <= studentNum;i++) insert(i);
	ranking();
	score_prt();

	while (onway == 1) {
		printf("삭제할 정보의 번호 입력 :");
		scanf_s("%d", &num);
		del(num);
		if (num == 999) onway = 0;
		//del(scanf_s("%d", &num));
		system("cls");
		score_prt();
	}
}

double round(double a) {
	double left = a / 10 - int(a / 10);
	if (left > 0.5) a += double((10 - int(left * 10))) * 10;
	a -= left * 10;
	a = double(a) / 1000;
	return a;
}
void ranking() {
	int formal_max = 100;
	int max = 0;
	int max_loca = 0;
	int rank = 1;
	int i = 0;
	student* ptr;
	student* ptr2;
	student* ptr3;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		max_loca = ptr->num;
		max = 0;
		for (ptr2 = head; ptr2->next != NULL; ptr2 = ptr2->next) {	
			if (formal_max > ptr2->avg && max <= ptr2->avg) {
				max = ptr2->avg;
				max_loca = ptr2->num;
			}
		}
		for (ptr3 = head; ptr3->next != NULL; ptr3 = ptr3->next) if (ptr3->num == max_loca) ptr3->rank = rank;
		formal_max = max;
		rank++;
	}
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		if (ptr->rank < 0 && ptr->rank > studentNum) {
			for (ptr2 = head; ptr2->next != NULL; ptr2 = ptr2->next) {
				if (ptr->avg == ptr2->avg) ptr->rank = ptr2->rank;
			}
		}
	}
}
void score_prt() {
	student* ptr;
	printf("\n번호\t국어\t영어\t수학\t총점\t평균\t등수\n");
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		printf("%d\t", ptr->num);
		printf("%d\t", ptr->kor);
		printf("%d\t", ptr->eng);
		printf("%d\t", ptr->math);
		printf("%d\t", ptr->sum);
		printf("%d\t", ptr->avg);
		printf("%d\n", ptr->rank);
	}
}
void insert(int a) {
	student* newStudent = (student*)malloc(sizeof(student));
	newStudent->num = a;
	newStudent->kor = rand() % 101;
	newStudent->math = rand() % 101;
	newStudent->eng = rand() % 101;
	newStudent->sum = newStudent->kor + newStudent->eng + newStudent->math;
	newStudent->avg = newStudent->sum / 3;
	newStudent->next = head;

	head = newStudent;
}
void del(int a) {
	student* ptr;
	student* PRE_ptr;
	PRE_ptr = NULL;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		if (ptr->num == a) {
			if (PRE_ptr == NULL) head = ptr->next;
			else PRE_ptr->next = ptr->next;
			free(ptr);
			break;
		}
		PRE_ptr = ptr;
	}
}
void sorting(int a) {
	student* ptr = (student*)malloc(sizeof(student));
	student* PRE_ptr = (student*)malloc(sizeof(student));
	student* ptr2;
	PRE_ptr = NULL;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		for (ptr2 = head; ptr2->next != NULL; ptr2 = ptr2->next) {

		}
	}
}