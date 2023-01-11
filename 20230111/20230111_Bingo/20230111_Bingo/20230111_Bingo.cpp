#include <stdio.h>
#include <stdlib.h> //랜덤 함수 포함
#include <time.h> //랜덤 시드를 위한 변수 포함
#include <windows.h> //프롬포트를 비우고 딜레이를 주는 함수 포함

#define player 6 //전체 보드의 수
#define length 5 //정사각형 보드의 변 길이 
int overlap[25] = { 0 }; //중복 숫자 확인을 위해 게임 중 나온 숫자를 저장하는 배열 
int BingoCount[6] = { 0 }; //각 보드의 빙고 숫자를 저장하는 변수
int winner; //승자의 정보를 넣는 변수

void init_BingoBoard(int a[][length][length]); //보드 초기화하는 함수
void Board_gene(int a[][length][length]); //보드 안에 1~25의 숫자를 랜덤한 위치에 생성하는 함수
void Board_prt(int a[][length][length]); //보드를 출력하는 함수
int overlap_check(int a); //중복되는지 확인하는 함수
void Bingo_check(int a[][length][length]); //빙고의 개수를 확인하는 함수 
int Bingo(int a[][length][length]); //게임을 진행하는 주요 함수, 랜덤 숫자를 생성하고 보드와 비교한다 
int GameOverCheck(int num[]); //게임이 종료되었는지 확인하는 변수

int main()
{
	int game = 0; //1이 되면 게임이 종료되는 변수
	srand((unsigned)time(NULL));
	int Board[6][5][5]; //5X5보드 6개 생성
	int on; //게임 중 숫자를 생성했을 때 중복이 아니라면 1

	init_BingoBoard(Board); //보드 0으로 초기화
	Board_gene(Board); //보드 숫자 채우기
	Board_prt(Board); //보드 출력

	while (game == 0) {
		system("cls"); //프롬포트 비우기
		on = Bingo(Board); //랜덤 숫자 생성하고 각 보드와 비교
		if (on == 1) { //생성된 숫자가 중복이 아닌 경우
			Bingo_check(Board); //각 보드에 빙고가 몇개인지 확인
			game = GameOverCheck(BingoCount); //모두의 빙고가 3개 이하면 0, 이상이면 1을 반환해 루프 종료
			Board_prt(Board); //보드 출력
			Sleep(1500); //1.5초 대기
		}
	}
	system("cls"); //프롬포트 비우기
	for (int i = 0;i < 6;i++) printf("%d ", BingoCount[i]);
	printf("\n"); 
	Board_prt(Board); //보드 출력
	printf("\n승자는 %d번째 보드입니다!!", winner); //이긴 보드의 순서가 출력
}

void init_BingoBoard(int a[][length][length]) { //게임 시작 시 0으로 채워진 판을 생성
	for (int k = 0;k < 6;k++) for (int i = 0;i < length;i++) for (int j = 0;j < length;j++) a[k][i][j] = 0;
}
void Board_gene(int a[][length][length]) { //보드 안의 숫자를 겹치지 않는 1~25의 숫자로 채움
	int count = 0;
	for (int k = 0;k < 6;k++) {
		while (count < 25) {
			int x = rand() % 5;
			int y = rand() % 5;
			if (a[k][x][y] == 0) {
				a[k][x][y] = count + 1;
				count++;
			}
		}
		count = 0;
	}
}
void Board_prt(int a[][length][length]) { //채워진 보드를 출력
	int k = 0;
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < length;j++) printf("%3d", a[k][i][j]); //첫번째 보드
		printf("\t\t");
		k++;
		for (int j = 0;j < length;j++) printf("%3d", a[k][i][j]); //두번째 보드
		printf("\t\t");
		k++;
		for (int j = 0;j < length;j++) printf("%3d", a[k][i][j]); //세번째 보드
		printf("\n");
		k = 0;
	}
	printf("\n");
	k = 3;
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < length;j++) printf("%3d", a[k][i][j]); //네번째 보드
		printf("\t\t");
		k++;
		for (int j = 0;j < length;j++) printf("%3d", a[k][i][j]); //다섯번째 보드
		printf("\t\t");
		k++;
		for (int j = 0;j < length;j++) printf("%3d", a[k][i][j]); //여섯째 보드
		printf("\n");
		k = 3;
	}
	printf("\n");
	
}
int overlap_check(int a) {
	static int repeat; //횟수 저장하는 정적 변수
	for (int i = 0;i < 25;i++) if (a == overlap[i]) return 0; //중복이 확인되면 0 반환
	overlap[repeat] = a; //중복이 아닐 경우 배열 마지막 위치에 현재 숫자 대입 
	repeat++; //횟수 더하기
	return 1; //중복이 아닐 때 1 반환
}
void Bingo_check(int a[][length][length]) { //각 판에 빙고가 있으면 체크
	int sum = 0;
	for (int k = 0;k < player;k++) { //플레이어
		int bingo = 0;
		for (int i = 0;i < length;i++) { //가로 빙고 확인
			for (int j = 0;j < length;j++) {
				if (a[k][i][j] == 0) sum++;
			}
			if (sum == 5) bingo++;
			sum = 0; 
		}
		for (int i = 0;i < length;i++) { //세로 빙고 확인
			for (int j = 0;j < length;j++) {
				if (a[k][j][i] == 0) sum++;
			}
			if (sum == 5) bingo++;
			sum = 0;
		}
		for (int i = 0;i < length;i++) { //왼오 대각선 빙고 확인
			if (a[k][i][i] == 0) sum++;
		}
		if (sum == 5) bingo++;
		sum = 0;
		for (int i = 0;i < length;i++) { //오왼 대각선 빙고 확인
			if (a[k][i][4-i] == 0) sum++;
		}
		if (sum == 5) bingo++;
		sum = 0;

		BingoCount[k] = bingo;
	}
	for (int i = 0;i < 6;i++) printf("%d ", BingoCount[i]);
	printf("\n");
}
int Bingo(int a[][length][length]) {
	int ongoing = 0;
	int number = 1 + rand() % 25; //랜덤한 숫자를 생성하고
	int check = overlap_check(number); //숫자가 중복되는지 확인한다

	if (check == 1) { //중복이 아니라면
		printf("이번 숫자는 %d \n", number);
		for (int k = 0;k < player;k++) { //플레이어의 수 만큼
			for (int i = 0;i < length;i++) { //세로열의 길이만큼
				for (int j = 0;j < length;j++) { //가로열의 길이만큼
					if (number == a[k][i][j]) { //선언된 숫자와 같은 숫자를 찾으면
						a[k][i][j] = 0; //선언된 숫자가 있는 위치의 값이 0이 된다
					}
				}
			}
		}
		ongoing = 1;
	}
	return ongoing;
}
int GameOverCheck(int num[]) {
	for (int i = 0;i < player;i++) { //각 보드에 대해 확인
		if (num[i] >= 3) { //빙고의 숫자가 3 이상이면
			winner = i+1; //지금 확인하고 있는 순서의 보드는 승자이다
			return 1; 
		}
	}
	return 0;
}