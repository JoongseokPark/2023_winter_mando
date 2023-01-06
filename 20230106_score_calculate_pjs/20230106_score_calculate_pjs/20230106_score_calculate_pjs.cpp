#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Std_score[10][6];
void score_generate();
void mean_calculate();
void rank_giving();
void score_prt();

int main()
{
	srand((unsigned)time(NULL));

	score_generate();
	mean_calculate();
	rank_giving();
	score_prt();
}

void score_generate() {
	for (int i = 0;i < 10;i++) {
		Std_score[i][0] = rand() % 101;
		Std_score[i][1] = rand() % 101;
		Std_score[i][2] = rand() % 101;
	}
}

void mean_calculate() {
	for (int i = 0;i < 10;i++) {
		Std_score[i][3] = Std_score[i][0] + Std_score[i][1] + Std_score[i][2];
		Std_score[i][4] = Std_score[i][3] / 3;
	}
}

void rank_giving() {
	int temp[10];
	int max = -1, max_location = 0;
	int tmp;

	for (int i = 0;i < 10;i++) {
		temp[i] = Std_score[i][4];
	}

	for (int i = 0;i < 10;i++) {
		max = temp[i];
		max_location = temp[i];
		for (int j = i+1;j < 10;j++) {
			if (max < temp[j]) {
				max = temp[j];
				max_location = j;
			}
		}
		tmp = temp[i];
		temp[i] = max;
		temp[max_location] = tmp;
	}

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if (temp[i] == Std_score[j][4]) Std_score[j][5] = i + 1;
		}
	}
}

void score_prt() {
	printf("번호\t국어\t영어\t수학\t총합\t평균\t등수\n");
	for (int i = 0;i < 10;i++) {
		printf("%d\t", i+1);
		for (int j = 0;j < 6;j++) printf("%d\t", Std_score[i][j]);
		printf("\n");
	}
}