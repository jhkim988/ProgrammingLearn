#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>

int main()
{
	// ASCII Chart - � ���ڰ� � ���ڿ� �����Ǵ���
	
	// char���� ���ڰ� �ϳ��� �� �� �ִ�.
	// single quote
	char c = 'A';
	char d = 65; // char d = 'A';

	// ���ڷ� ���, ���ڷ� ���
	printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);

	d = '*';
	printf("%c %hhd\n", d, d); // * 42
	printf("%c", c + 1); // B

	char a = '\a'; 
	printf("%c", a);
	printf('\07'); // 8���� 7
	printf('\x7'); // 16���� 7
	printf('\x23'); // #

	float salary;
	printf("$______\b\b\b\b\b\b"); // \b: backspace
	scanf("%f", &salary);

	// tab�� ���� �����ش�.
	printf("AB\tCDEF\n");
	printf("ABC\tDEF\n");

	printf("\\ \'HA+\' \"Hello\" \?\n");

	return 0;
}