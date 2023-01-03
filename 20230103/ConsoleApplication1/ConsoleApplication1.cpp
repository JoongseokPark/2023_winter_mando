#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice_roll();
int betting(int left);
int main()
{
	int wallet[3] = { 1000,1000,1000 };
	int A_bet = 0, B_bet = 0, C_bet = 0;
	int A_dice = 0, B_dice = 0, C_dice = 0;
	int dice = 0;
	int i = 0;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {

		printf("\n%d회 째의 게임입니다\n", i+1);
		A_bet = betting(wallet[0]);
		B_bet = betting(wallet[1]);
		C_bet = betting(wallet[2]);

		wallet[0] -= A_bet;
		wallet[1] -= B_bet;
		wallet[2] -= C_bet;

		A_dice = dice_roll();
		B_dice = dice_roll();
		C_dice = dice_roll();

		printf("A : 주사위 눈 선택 = %d, 배팅 = %d\n", A_dice, A_bet);
		printf("B : 주사위 눈 선택 = %d, 배팅 = %d\n", B_dice, B_bet);
		printf("C : 주사위 눈 선택 = %d, 배팅 = %d\n\n", C_dice, C_bet);

		dice = dice_roll();
		printf("굴려진 주사위의 눈 = %d\n", dice);

		wallet[0] += (A_dice == dice) ? 2 * A_bet : 0;
		wallet[1] += (B_dice == dice) ? 2 * B_bet : 0;
		wallet[2] += (C_dice == dice) ? 2 * C_bet : 0;

		(A_dice == dice) ? printf("승리 ,") : printf("패배 ,");
		printf("A의 남은 판돈 = %d\n", wallet[0]);

		(B_dice == dice) ? printf("승리 ,") : printf("패배 ,");
		printf("B의 남은 판돈 = %d\n", wallet[1]);

		(C_dice == dice) ? printf("승리 ,") : printf("패배 ,");
		printf("C의 남은 판돈 = %d\n\n", wallet[2]);
	}

}

int dice_roll() {
	return 1 + rand() % 6;
}
int betting(int left) {
	if (left <= 0) return 0;
	else  return 100 * (1 + rand() % (left/2) / 100);
}
