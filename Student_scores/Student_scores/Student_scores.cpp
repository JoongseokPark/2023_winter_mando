#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	int Sscores[20];
	int scores_check[10] = { 0 };
	int length = sizeof(Sscores) / sizeof(int);
	int k = 0;

	for (int i = 0;i < length;i++) Sscores[i] = rand() % 100;
	for (int i = 0;i < length;i++) ++scores_check[Sscores[i] % 10];

	for (int i = 1;i < 11;i++) {
		printf("[%d ~ %d] : ",10*(i-1),(i*10)-1);
		k = scores_check[i-1];
		for (;k > 0;k--) printf("*");
		printf("\n");
	}

	return 0;
}
