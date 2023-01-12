#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting(int* A, int totalsize);
void combining(int* A, int* B, int* C, int TotalSize);
void Ary_prt(int* A,int totalsize);

#define size 5

int main()
{
	srand((unsigned)time(NULL));
	int A[size],B[size],C[2*size];

	for (int i = 0; i < size; i++) A[i] = rand() % 20;
	for (int i = 0; i < size; i++) B[i] = rand() % 20;
	Ary_prt(A, size);
	Ary_prt(B, size);
	combining(A, B, C, 2 * size);
	sorting(C, 2 * size);
	Ary_prt(C,2*size);
}

void combining(int* A, int* B, int* C,int TotalSize) {
	for (int i = 0; i < TotalSize; i++) {
		if (i < TotalSize / 2) C[i] = A[i];
		else C[i] = B[i - TotalSize / 2];
	}
}
void sorting(int* A,int totalsize) {
	for (int i = 0; i < totalsize; i++) {
		int temp = A[i];
		int max = A[i];
		int max_loca = i;
		for (int j = i; j < totalsize; j++) {
			if (max > A[j]) {
				max = A[j];
				max_loca = j;
			}
		}
		A[max_loca] = temp;
		A[i] = max; 
	}
}
void Ary_prt(int* A,int totalsize) {
	for (int i = 0; i < totalsize; i++) {
		printf("%3d", A[i]);
	}
	printf("\n");
}