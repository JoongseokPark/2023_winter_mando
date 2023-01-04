#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

static int balance = 100000;
static int onway = 2;
void save(int amount);
void random_deposit();
void deposit();
void withdraw();
int mainmenu();
int login();

int main()
{
	srand((unsigned)time(NULL));
	int select = 0;
	//printf("자동으로 입금과 출력이 반복됩니다\n");
	//printf("남은 잔고가 0이 되면 종료됩니다\n");
	printf("===========================\n");
	//printf("입금\t출금\t잔고\n");
	
	onway = login();

	while (onway == 1) {
		printf("남은 잔고 = %d\n", balance);
		select = mainmenu();

		switch (select) {
		case 1:
			deposit();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			onway = false;
		}

	}
	
	printf("은행 프로그램이 종료되었습니다\n");
	printf("최종 잔고 : %d\n", balance);
	Sleep(2500);
	
	/*
	while (balance > 0) {
		random_save();
		Sleep(1000);
	}
	*/
	printf("===========================\n");
	return 0;
}

void save(int amount) {
	balance += amount;
	
	(amount > 0) ? printf("%d \t\t%d\n", amount, balance) : printf("\t%d\t%d\n", amount, balance);
}

void random_deposit() {
	int random = 1 + rand() % 50;
	int rand_amount = 0;

	if (random > 35) {
		rand_amount = 1000 * (1+rand() % 10);
		printf("%d \t\t%d\n", rand_amount, balance);
	}
	else if(random < 35) {
		rand_amount = -1000 * (1 + rand() % 10);
		printf("\t%d\t%d\n", rand_amount, balance);
	}
	balance += rand_amount;
}

int mainmenu() {
	int select;
	printf("\n\n원하는 은행 메뉴의 번호를 선택해주세요.\n");
	printf("1.입금\t2.출금\t3.종료\n");

	scanf_s("%d",&select);
	return select;
}

void deposit() {
	int amount;
	printf("입금 금액을 선택해주세요 :");
	scanf_s("%d", &amount);
	printf("입금금액 : %d$\n", amount);
	balance += amount;
}

void withdraw() {
	int amount;
	printf("출금 금액을 선택해주세요 :");
	scanf_s("%d", &amount);
	if (balance < amount) {
		printf("출금 금액이 잔고보다 많습니다.\n");
		return;
	}

	printf("출금금액 : %d$\n", amount);
	balance -= amount;
}

int login(){
	int Id = 123;
	int Id_insert = 0;
	int password = 567;
	int password_insert;
	int chance = 5;

	while (onway != 1) {
		printf("아이디를 입력 :");
		scanf_s("%d", &Id_insert);
		if (Id == Id_insert) {
			while (chance > 0) {
				printf("패스워드 입력 :");
				scanf_s("%d", &password_insert);
				if (password == password_insert) {
					printf("로그인 성공\n");
					return 1;
					break;
				}
				else {
					printf("비밀번호 불일치\n");
					chance--;
				}
			}
		}
		else {
			chance--;
			printf("아이디가 맞지 않습니다\n");
		}
		if (chance <= 0) break;
	}

	if (chance <= 0) {
		printf("로그인 실패 5번 틀렸습니다.\n");
		return 2;
	}
}