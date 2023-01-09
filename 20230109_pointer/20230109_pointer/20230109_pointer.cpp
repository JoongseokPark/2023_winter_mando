#include <stdio.h>


int main()
{
	//십진수는 9의 다음 숫자로 넘어갈 때 10으로 바뀐다
	//팔진수는 7의 다음 숫자로 넘어갈 때 10으로 바뀌어 8이 10으로 표현된다
	//십육진수는 15의 다음 숫자로 넘어갈 때 10으로 바뀌어 16이 10으로 표현되고,
	//9이상의 숫자를 표현하기 위해 A~F의 알파벳을 아라비안 숫자 대신 사용한다.

	int i = 0x23;
	char a = 97,b = 65;
	double t = 145.768;

	//변수에 &입력시 주소값 출력, 변수 선언에 * 사용하여 포인터 생성
	//포인터의 앞에 *입력시 주소 안에 있는 값 출력

	int* ptr_int = &i;
	double* ptr_double = &t;
	char* ptr_char = &a;

	printf("i = %d\n", i);
	printf("ptr_int value = %d\n", *ptr_int);
	printf("i address = %u\n", &i);
	printf("ptr_int address = %u\n", ptr_int);
	printf("i address + 1 = %u\n\n", &i+1);
	//포인터의 형식이 정수형 -> 정수형 크기인 4바이트 다음의 주소를 출력

	/*
	printf("a = %c\n", a);
	printf("ptr_char address = %c\n", *ptr_char);
	printf("a address = %u\n", &a);
	printf("a address + 1 = %u\n\n", &a + 1);

	printf("b = %c\n", b);
	printf("b address = %u\n", &b);
	printf("b address + 1 = %u\n\n", &b + 1);

	printf("t = %lf\n", t);
	printf("ptr_double address = %lf\n", *ptr_double);
	printf("t address = %u\n", &t);
	printf("t address + 1 = %u\n\n", &t+1);

	*/
	return 0;
}
