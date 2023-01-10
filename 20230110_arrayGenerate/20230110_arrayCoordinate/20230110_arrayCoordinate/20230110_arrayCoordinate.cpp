
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_array(int a[][10]);
void rand_check(int location[]);
void rand_gene(int a[][10]);
void arr_prt(int a[][10]);

int checking[10][10];

int main()
{
	srand((unsigned)time(NULL));
	int array[10][10];
	init_array(array);
	init_array(checking);
	for(int i=0;i<100;i++) rand_gene(array);
	arr_prt(array);
	printf("\n");
	arr_prt(checking);

}

void init_array(int a[][10]) {
	for (int i = 0;i < 10;i++) for (int j = 0;j < 10;j++) a[i][j] = 0;
}

void rand_check(int location[]) {
	checking[location[0]][location[1]]++;
}

void rand_gene(int a[][10]) {
	int x = rand() % 10;
	int y = rand() % 10;
	int random = rand() % 100;
	a[x][y] = random;
	int location[2] = { x,y };
	rand_check(location);
}

void arr_prt(int a[][10]) {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}