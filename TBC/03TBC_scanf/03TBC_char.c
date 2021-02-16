#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>

int main()
{
	// ASCII Chart - 어떤 문자가 어떤 숫자에 대응되는지
	
	// char에는 문자가 하나씩 들어갈 수 있다.
	// single quote
	char c = 'A';
	char d = 65; // char d = 'A';

	// 문자로 출력, 숫자로 출력
	printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);

	d = '*';
	printf("%c %hhd\n", d, d); // * 42
	printf("%c", c + 1); // B

	char a = '\a'; 
	printf("%c", a);
	printf('\07'); // 8진수 7
	printf('\x7'); // 16진수 7
	printf('\x23'); // #

	float salary;
	printf("$______\b\b\b\b\b\b"); // \b: backspace
	scanf("%f", &salary);

	// tab은 줄을 맞춰준다.
	printf("AB\tCDEF\n");
	printf("ABC\tDEF\n");

	printf("\\ \'HA+\' \"Hello\" \?\n");

	return 0;
}