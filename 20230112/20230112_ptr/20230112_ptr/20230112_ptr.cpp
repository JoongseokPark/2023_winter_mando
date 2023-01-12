#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void convert(float* grade, int* scores, int size);

int main()
{
	srand((unsigned)time(NULL));
	float grade[10] = { 0.0 };
	int scores[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		int random = rand() % 44;
		grade[i] = float(random) / 10;
	}
	convert(grade, scores, 10);
	printf("학점 출력\n");
	for (int i = 0; i < 10; i++) printf("%.2f\t", grade[i]);
	printf("\n점수로 변환\n");
	for (int i = 0; i < 10; i++) printf("%d\t", scores[i]);
}

void convert(float* grade, int * scores, int size) {
	for (int i = 0; i < size; i++) scores[i] = 100 * float(grade[i]) / 4.3;
}
