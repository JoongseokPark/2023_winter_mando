#include <iostream>
#include <stdio.h>
#include <windows.h>

int A_top, B_top, C_top;
int score;
int complete = 0;
int start = 1;
int route = 1;
int Ascore, Bscore, Cscore;
int repeatation = 0;

void checking(int num[]);
void where_is_top(int num1[], int num2[], int num3[]);
void exchange(int* num1, int* num2);
void move(int num1[], int num2[], int num3[]);
void tower_drawing(int num1[], int num2[], int num3[]);

int A_tower[11] = { 1,2,3,4,5,6,7,8,9,10,999 };
//맨 왼쪽 탑에 모든 원판을 가지고 시작한다, [0] = 1,[9] = 10
int B_tower[11] = { 0,0,0,0,0,0,0,0,0,0,999 }; //중간 탑
int C_tower[11] = { 0,0,0,0,0,0,0,0,0,0,999 }; //오른쪽 탑
//바닥은 999

int main()
{
	
	while (complete == 0) {
		move(A_tower, B_tower, C_tower);

		tower_drawing(A_tower, B_tower, C_tower);

		checking(C_tower);
		Sleep(1500);
	}

}

void where_is_top(int num1[], int num2[], int num3[]) {
	int A_on = 1, B_on = 1, C_on = 1;

	for (int i = 0; i < 11;i++) {
		if (A_on == 1) {
			if (num1[i] > 0) {
				A_top = i;
				A_on = 0;
			}
		}
		if (B_on == 1) {
			if (num2[i] > 0) {
				B_top = i;
				B_on = 0;
			}
		}
		if (C_on == 1) {
			if (num3[i] > 0) {
				C_top = i;
				C_on = 0;
			}
		}
	}
}

void checking(int num[]) { //정렬되었으면 1 반환 -> 반복 종료
	int checker = 0;
	for (int i = 0; i < 10;i++) if (num[i] == i + 1) checker++;
	if (checker == 10) complete = 1;
	else complete = 0;
}

void exchange(int* num1, int* num2) {

	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void tower_drawing(int num1[], int num2[], int num3[]) {
	//printf("\n\n\n\n\n\n\n");
	for (int i = 0; i < 11;i++) {
		printf("%d\t\t%d\t\t%d\n", num1[i], num2[i], num3[i]);
		
	}
	printf("\n");
	//printf("\n\n\n\n\n\n");
}

void move(int num1[], int num2[], int num3[]) {

	where_is_top(A_tower, B_tower, C_tower);

	int* ptr_Atop = &num1[A_top];		
	int* ptr_Btop = &num2[B_top];
	int* ptr_Ctop = &num3[C_top];

	Ascore = 0;
	Bscore = 0;
	Cscore = 0;

	printf("A_top = %d\n", A_top);
	printf("B_top = %d\n", B_top);
	printf("C_top = %d\n", C_top);

	for (int i = 0;i < 10;i++) { 
		Ascore += A_tower[i];
		Bscore += B_tower[i];
		Bscore += C_tower[i];
	}
	
	if (route == 1) {
		printf("route 1\n");
		if (*ptr_Atop > B_tower[B_top]) {
			if (*ptr_Atop > *ptr_Ctop) {
				repeatation++;
				route = 2;
				move(A_tower, B_tower, C_tower);
			}
			else exchange(ptr_Atop, ptr_Ctop-1);
		}
		else exchange(ptr_Atop, ptr_Btop-1);
	}

	else if (route == 2) {

		printf("route 2\n");
		if (*ptr_Btop > *ptr_Ctop) {
			if (*ptr_Btop > A_tower[A_top]) {
				repeatation++;
				route = 3;
				move(A_tower, B_tower, C_tower);
			}
			else exchange(ptr_Btop, ptr_Atop-1);
		}
		else { 
			exchange(ptr_Btop, &C_tower[C_top-1]);
			route = 1;
		}
	}

	else if (route == 3) {

		printf("route 3\n");
		if (*ptr_Ctop > *ptr_Atop) {
			if (*ptr_Ctop > *ptr_Btop) {
				repeatation++;
				route = 1;
				move(A_tower, B_tower, C_tower);
			}
			else exchange(ptr_Ctop, ptr_Btop-1);
		}
		else {
			exchange(ptr_Ctop, ptr_Atop-1);
			route = 1;
		}
	}

}


/*
printf("A_top = %d\n", A_top);
printf("B_top = %d\n", B_top);
printf("C_top = %d\n", C_top);
*/