#include <stdio.h>


int main()
{
	//�������� 9�� ���� ���ڷ� �Ѿ �� 10���� �ٲ��
	//�������� 7�� ���� ���ڷ� �Ѿ �� 10���� �ٲ�� 8�� 10���� ǥ���ȴ�
	//���������� 15�� ���� ���ڷ� �Ѿ �� 10���� �ٲ�� 16�� 10���� ǥ���ǰ�,
	//9�̻��� ���ڸ� ǥ���ϱ� ���� A~F�� ���ĺ��� �ƶ��� ���� ��� ����Ѵ�.

	int i = 0x23;
	char a = 97,b = 65;
	double t = 145.768;

	//������ &�Է½� �ּҰ� ���, ���� ���� * ����Ͽ� ������ ����
	//�������� �տ� *�Է½� �ּ� �ȿ� �ִ� �� ���

	int* ptr_int = &i;
	double* ptr_double = &t;
	char* ptr_char = &a;

	printf("i = %d\n", i);
	printf("ptr_int value = %d\n", *ptr_int);
	printf("i address = %u\n", &i);
	printf("ptr_int address = %u\n", ptr_int);
	printf("i address + 1 = %u\n\n", &i+1);
	//�������� ������ ������ -> ������ ũ���� 4����Ʈ ������ �ּҸ� ���

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
