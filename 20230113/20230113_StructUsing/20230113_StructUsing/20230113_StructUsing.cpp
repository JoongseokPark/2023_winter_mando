#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct student {
	int num;
	char name[20];
	int kor;
	int eng;
	int math;
	int sum;
	double avg;
};
void score_prt(struct student* p);
void score_gene(struct student* p);
double round(double a);
char randName[20][20] = { "김성윤","최강민","김경수","박현수","박길태","백두산","신성하","허준","이태식","구대문","김수광","이광수"};

int main()
{
	srand((unsigned)time(NULL));
	struct student s_list[10];

	score_gene(s_list);
	score_prt(s_list);
}

double round(double a) {
	double left = a/10 - int(a/10);
	if (left > 0.5) a += double((10 - int(left*10))) * 10;
	a -= left * 10;
	a = double(a)/1000;
	return a;
}

void score_gene(struct student *p) {
	for (int i = 0;i < 10;i++) {
		strcpy_s((p + i)->name, randName[rand() % 12]);
		(p + i)->kor = (rand() % 101);
		(p + i)->eng = (rand() % 101);
		(p + i)->math = (rand() % 101);
		(p + i)->sum = (p + i)->kor + (p + i)->eng + (p + i)->math;
		(p + i)->avg = double(((p + i)->kor + (p + i)->eng + (p + i)->math)) / 3;
		(p + i)->avg = round((p + i)->avg*1000); //평균을 소수점 둘째자리에서 반올림하는 기능
	}
}

void score_prt(struct student* p) {
	printf("\n번호\t이름\t국어\t영어\t수학\t총점\t평균\n");
	for (int i = 0;i < 10;i++) {
		printf("%d\t", i+1);
		printf("%s\t", (p + i)->name);
		printf("%d\t", (p + i)->kor);
		printf("%d\t", (p + i)->eng);
		printf("%d\t", (p + i)->math);
		printf("%d\t", (p + i)->sum);
		printf("%f\n", (p + i)->avg);
	}
}

