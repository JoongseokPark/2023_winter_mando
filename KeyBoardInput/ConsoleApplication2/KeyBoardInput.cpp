#include <stdio.h>
#include <Windows.h>//system("cls") 포함
#include <conio.h> //_getch 포함 

int table[10][10]; // 10X10 Array(정수형 변수 묶음) 
int position[2] = { 4,5 }; // 정수형 변수 2개 묶음(초기 마커 위치)
//자료형 묶음 부르기 => 
//position은 0번째(셀 때는 0부터)와 1번째 공간 보유
//선언했을 때 position[0] = 4, position[1] = 5  

int main()
{
	while (true) { //무한 반복
		printf("%d , %d \n", position[0], position[1]); //현재 위치 출력
		prt_table(); //테이블 출력
		Moving_position(); //키보드 입력 감지(입력이 있을 때까지 대기)
		system("cls"); //터미널 출력 지우기
	}
}

void Moving_position() { //키보드에서 값 읽고 위치를 바꾸어주는 함수
	char input;
	input = _getch(); //scanf와 다르게 엔터를 누르지 않아도 입력
	if (input == 'a' && position[1] > 0) position[1]--;
	// a 입력시 position[1]의 값 하나 줄이기(왼쪽으로)
	else if (input == 'w' && position[0] > 0) position[0]--;
	// w 입력시 position[0]의 값 하나 줄이기(위로)
	else if (input == 's' && position[0] < 9) position[0]++;
	// s 입력시 position[0]의 값 하나 늘리기(아래로)
	else if (input == 'd' && position[1] < 9) position[1]++;
	// d 입력시 position[1]의 값 하나 늘리기(오른쪽으로)
	else return;
	return;
}

void prt_table() { //테이블을 출력해주는 함수
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(i == position[0] && j == position[1]) table[i][j] = 7;
			//마커가 있는 위치는 7을 대입
			else table[i][j] = 0; //나머지는 0을 대입
			printf("%d ", table[i][j]); //만들어진 판을 출력
		}
		printf("\n");
	}
	return;
}


