#include <stdio.h>

int main()
{
	int x = 10, y = 20;
	int* ptr = NULL; //NULL로 포인터 초기화

	ptr = &x;
	printf("X value = %d\n", x);
	*ptr = 20; //포인터를 통해 원 변수의 값을 바꾼다.
	

	//ptr = &y;
	printf("X value = %d\n", x);

}