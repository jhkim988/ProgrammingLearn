#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()

// 15.2
unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi); // x86, x64...
	unsigned char result = 0;
	for (size_t i = bits - 1; i >= 0; --i)
		if (bi[i] == '1')
			result += (unsigned char)pow((double)2, (double) (strlen(bi) - i - 1)); // warnings...
		else if (bi[i] != '0')
		{
			printf("Wrong character : %c\n", bi[i]);
			exit(1);
		}
	return result;
}

int main()
{
	// 15.1 비트단위 논리 연산자
	//// bitwise not : ~ (tilde)
	//// bitwise and : & (ampersane)
	//// bitwise or : | (vertical bar)
	//// bitwise exclusive or : ^ (caret)

	//// example
	//// 게임에서...
	//// 8가지 정보를 저장하기 위해서는 8바이트(64비트)가 필요하다.
	//unsigned char has_sword = 1;
	//unsigned char has_shield = 0;
	//unsigned char has_magic_potion = 0;
	//unsigned char has_choes = 1;
	//unsigned char has_gun = 0;
	//unsigned char has_pet = 1;
	//unsigned char has_guntlet = 0;
	//unsigned char has_arrow = 0;

	//// bitwise... 1바이트만 사용해도 표현할 수 있다.
	//unsigned char items = 148; // 10010100b = 148

	//// & : bitwise and
	//// 6 = 0000 0110
	//// 5 = 0000 0101
	//// 5 & 6 = 0000 0100 = 4

	//// | : bitwise or
	//// 6 | 5 = 0000 0111 = 7

	//// ^ : bitwise xor (or이지만 둘 다 1 1 이면 0이 나온다.)
	//// 6^5 =  0000 0011 = 3

	//// ~ : bitwise not
	//// ~6 = 1111 1001 = 249

	// 15.2 이진수를 십진수로 바꾸기 연습문제
	printf("Binary (string) to decimal conversion\n");

	printf("%d\n", to_decimal("00000110")); // 6
	printf("%d\n", to_decimal("00010110")); // 22
	printf("%d\n", to_decimal("10010100")); // 148
	return 0;
}