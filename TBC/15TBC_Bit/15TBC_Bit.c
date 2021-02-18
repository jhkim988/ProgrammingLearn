#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()

// shift를 이용해도 되고, Hex, Octet을 이용해서 선언할 수도 있다.
#define MASK_SWORD 		(1 << 0)
#define MASK_SHIELD 	(1 << 1)
#define MASK_POTION 	(1 << 2)
#define MASK_GUNTLET 	(1 << 3)
#define MASK_HAMMER 	(1 << 4)
#define MASK_KEY 		(1 << 5)
#define MASK_RING 		(1 << 6)
#define MASK_AMULET 	(1 << 7)


// 15.2
/*
unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi); // x86, x64...
	
	unsigned char result = 0;
	for (size_t i = 0; i < bits; ++i)
	{	
		if (bi[i] == '1')
			result += (unsigned char)pow((double)2, (double) (strlen(bi) - i - 1)); // warnings...
		else if (bi[i] != '0')
		{
			printf("Wrong character : %c\n", bi[i]);
			exit(1);
		}
	}
	return result;
}
*/
// 15.3
/*
void print_binary(const char num)
{	
	// MyTry
	// printf("Decimal %3d \t== Binary ", num);
	// int mask = pow(2, 7);
	// while(mask != 0)
	// {
	// 	// printf("%d & %d = %d\n", num, mask, num & mask);
	// 	if ((num & mask) == mask) // 연산자 우선순위..
	// 	{	
	// 		printf("%d", 1);
	// 	}
	// 	else
	// 	{	
	// 		printf("%d", 0);
	// 	}
	// 	mask /= 2;
	// }
	// printf("\n");

	const size_t bits = sizeof(num) * 8;
	printf("Decimal %3d \t== Binary ", num);

	for(size_t i = 0; i < bits; ++i)
	{
		const unsigned char mask = (unsigned char)pow((double) 2, (double) (bits -  1 - i));
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");

	// for문을 큰 숫자에서 작은 숫자로 가도록(i가 감소하도록) 하면
	// size_t는 unsigned int이기 때문에 for문이 끝나지 않는다.
}
*/
// 15.6
/*
void int_binary(const int num)
{
	printf("Decimal %12d == Binary", num);

	const size_t bits = sizeof(num) * CHAR_BIT;
	for(size_t i = 0; i < bits; ++i)
	{
		const int mask = 1 << (bits - 1 - i); // pow() 함수를 사용하지 말고..
		if ((num  & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
*/

// 15.7
void char_binary(const char num)
{
	printf("Decimal %3d\t==Binary ", num);
	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const char mask = 1 << (bits - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}

void int_binary(const int num)
{
	printf("Decimal %3d\t==Binary ", num);
	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const char mask = 1 << (bits - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
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
	// printf("Binary (string) to decimal conversion\n");

	// printf("%d\n", to_decimal("00000110")); // 6
	// printf("%d\n", to_decimal("00010110")); // 22
	// printf("%d\n", to_decimal("10010100")); // 148

	// 15.3 &를 이용해서 십진수를 이진수로 바꾸기
	// unsigned char i = to_decimal("01000110");
	// unsigned char mask = to_decimal("00000101");

	// print_binary(i);
	// print_binary(mask);
	// print_binary(i & mask);

	// 15.4 비트단위 논리 연산자 확인해보기
	// unsigned char a = 6;
	// unsigned char b = 5;

	// printf("%hhu\n", a);
	// print_binary(a);

	// printf("%hhu\n", b);
	// print_binary(b);

	// printf("%hhu\n", a & b);
	// print_binary(a & b);

	// printf("%hhu\n", a | b);
	// print_binary(a | b);

	// printf("%hhu\n", a ^ b);
	// print_binary(a ^ b);

	// printf("%hhu\n", ~a);
	// print_binary(~a);

	// 15.5 2의 보수 표현법 확인하기
	// -5를 표기 하는 방법 = ~5 + 1
	// print_binary(127);
	// print_binary(-127);
	// print_binary(~127 + 1);

	// print_binary(12);
	// print_binary(-12);
	// print_binary(~12 + 1);

	// print_binary(7);
	// print_binary(-7);
	// print_binary(~-7 + 1);
	
	// 15.6 비트단위 쉬프트 연산자
	// // << : left shift, number << n : multiply number by 2^n
	// // >> : right shift, number >> n : divide number by 2^n

	// // 8bit integer
	// printf("%hhd\n", 1 << 3);
	// printf("%hhd\n", 8 >> 1);

	// printf("%hhd\n", -119 >> 3); // signed의 경우에, 가장 왼쪽 비트가 1이라면 옮기고 난 후 빈칸을 1로 채운다.
	// printf("%hhu\n", 137 >> 3); // unsigned의 경우에는 옮기고 난 후 빈칸을 0으로 채운다.

	// printf("%hhd\n", (char)(-119 << 4)); // 1이 이동하면서 사라지기 때문에 warning
	// printf("%hhu\n", (unsigned char)(137 << 4));

	// int a = 1;
	// a <<= 3; // a = (a << 3);
	// a >>= 2; // a = (a >> 2);

	// printf("Unsigned int %u\n", 0xffffffff);
	// printf("Signed int %d\n", 0xffffffff);
	// int_binary(0xffffffff);
	// printf("Right shift by 3\n");
	// int_binary((signed)0xffffffff >> 3);
	// int_binary((unsigned)0xffffffff >> 3);

	// printf("\nUnsigned int %u\n", 0x00ffffff);
	// printf("Signed int %d\n", 0x00ffffff);
	// int_binary(0x00ffffff);
	// printf("Right shift by 3\n");
	// int_binary((signed)0x00ffffff >> 3);
	// int_binary((unsigned)0x00ffffff >> 3);

	// 15.7 비트단위 연산자의 다양한 사용법
	// 비트마스킹 = 마스크를 쓰면 쓰지 않은 부분만 보이는 것처럼, 비트에서 1인 부분만 뽑아낼 수 있다.
	char flags = 0; // mask flags
	char_binary(flags);

	flags |= MASK_SWORD; // bitwise OR 연산자로 특정 비트를 1로 바꿔줄 수 있다.
	char_binary(flags);

	flags |= MASK_AMULET;
	char_binary(flags);

	printf("\nTurning Bits off (Clearning Bits)\n");
	flags |= MASK_POTION;
	char_binary(flags);

	flags &= ~MASK_POTION; // bitwise AND과 NOT으로 특정 비트를 0으로 바꿔줄 수 있다.

	printf("\nToggling Bits\n");
	// 0을 1로 1을 0으로 바꿔주기 때문에 Toggling으로 사용할 수 있다.
	flags = flags ^ MASK_HAMMER;
	char_binary(flags);

	flags = flags ^ MASK_HAMMER;
	char_binary(flags);

	flags = flags ^ MASK_HAMMER;
	char_binary(flags);
	
	printf("\nChecking the Value of a Bit\n");
	if ((flags & MASK_KEY) == MASK_KEY)
	{
		printf(">> You can enter.\n");
	}
	else
	{
		printf(">> You can't enter.\n");
	}

	flags |= MASK_KEY;

	if ((flags & MASK_KEY) == MASK_KEY)
	{
		printf(">> You can enter.\n");
	}
	else
	{
		printf(">> You can't enter.\n");
	}

	printf("\nTrimming\n");
	int int_flag = 0xffffffff; // 전체가 4바이트인 플래그
	int_binary(int_flag);
	int_flag  &= 0xff; // 1바이트부분만 보고 싶을 때
	int_binary(int_flag);

	return 0;
}