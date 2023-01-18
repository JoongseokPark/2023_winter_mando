#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int main()
{
	int studentNum;
	head = NULL;
	srand((unsigned)time(NULL));

	printf("총 학생 수 입력 :");
	scanf_s("%d", &studentNum);

	for (int i = 0;i <= studentNum;i++) insert(i);
	ranking();
	score_prt();
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
	int formal_num = 100;
	int max = 0;
	int max_loca = 0;
	int rank = 1;
	student* ptr;
	student* ptr2;
	student* ptr3;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
		max_loca = ptr->num;
		max = 0;
		for (ptr2 = head; ptr2->next != NULL; ptr2 = ptr2->next) {
			if (formal_num != ptr2->num && formal_max > ptr2->avg && max <= ptr2->avg) {
				max = ptr2->avg;
				max_loca = ptr2->num;
			}
		}
		for (ptr3 = head; ptr3->next != NULL; ptr3 = ptr3->next) if(ptr3->num == max_loca) ptr3->rank = rank;
		printf("%d등은 %d번 학생 기존 = %d 신규 = %d\n", rank, max_loca, formal_max, max);
		formal_max = max;
		formal_num = max_loca;
		rank++;
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
	newStudent->avg = newStudent->sum/3;
	newStudent->next = head;

	head = newStudent;   
}