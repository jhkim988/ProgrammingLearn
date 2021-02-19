#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>	//struct
// #include <stdalign.h> // _Alignas, _Alignof -> alignas, alignof, ������� �ٿ�޾ƾ� �ϴµ�?

//{
//	bool has_sword : 1;
//	bool has_shield : 1;
//	bool has_magic_potion : 1;
//	bool has_choes : 1;
//	bool has_gun : 1;
//	bool has_pet : 1;
//	bool has_guntlet : 1;
//	bool has_arrow : 1;
//} items_flag;

// shift�� �̿��ص� �ǰ�, Hex, Octet�� �̿��ؼ� ������ ���� �ִ�.
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
	// 	if ((num & mask) == mask) // ������ �켱����..
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

	// for���� ū ���ڿ��� ���� ���ڷ� ������(i�� �����ϵ���) �ϸ�
	// size_t�� unsigned int�̱� ������ for���� ������ �ʴ´�.
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
		const int mask = 1 << (bits - 1 - i); // pow() �Լ��� ������� ����..
		if ((num  & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
*/

// 15.7
/*
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
		const int mask = 1 << (bits - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
*/

// 15.10
void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; --i)
		printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes) // extended for any sizes
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]);
	printf("\n");
}

int main()
{
	// 15.1 ��Ʈ���� �� ������
	//// bitwise not : ~ (tilde)
	//// bitwise and : & (ampersane)
	//// bitwise or : | (vertical bar)
	//// bitwise exclusive or : ^ (caret)

	//// example
	//// ���ӿ���...
	//// 8���� ������ �����ϱ� ���ؼ��� 8����Ʈ(64��Ʈ)�� �ʿ��ϴ�.
	//unsigned char has_sword = 1;
	//unsigned char has_shield = 0;
	//unsigned char has_magic_potion = 0;
	//unsigned char has_choes = 1;
	//unsigned char has_gun = 0;
	//unsigned char has_pet = 1;
	//unsigned char has_guntlet = 0;
	//unsigned char has_arrow = 0;

	//// bitwise... 1����Ʈ�� ����ص� ǥ���� �� �ִ�.
	//unsigned char items = 148; // 10010100b = 148

	//// & : bitwise and
	//// 6 = 0000 0110
	//// 5 = 0000 0101
	//// 5 & 6 = 0000 0100 = 4

	//// | : bitwise or
	//// 6 | 5 = 0000 0111 = 7

	//// ^ : bitwise xor (or������ �� �� 1 1 �̸� 0�� ���´�.)
	//// 6^5 =  0000 0011 = 3

	//// ~ : bitwise not
	//// ~6 = 1111 1001 = 249

	// 15.2 �������� �������� �ٲٱ� ��������
	// printf("Binary (string) to decimal conversion\n");

	// printf("%d\n", to_decimal("00000110")); // 6
	// printf("%d\n", to_decimal("00010110")); // 22
	// printf("%d\n", to_decimal("10010100")); // 148

	// 15.3 &�� �̿��ؼ� �������� �������� �ٲٱ�
	// unsigned char i = to_decimal("01000110");
	// unsigned char mask = to_decimal("00000101");

	// print_binary(i);
	// print_binary(mask);
	// print_binary(i & mask);

	// 15.4 ��Ʈ���� �� ������ Ȯ���غ���
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

	// 15.5 2�� ���� ǥ���� Ȯ���ϱ�
	// -5�� ǥ�� �ϴ� ��� = ~5 + 1
	// print_binary(127);
	// print_binary(-127);
	// print_binary(~127 + 1);

	// print_binary(12);
	// print_binary(-12);
	// print_binary(~12 + 1);

	// print_binary(7);
	// print_binary(-7);
	// print_binary(~-7 + 1);
	
	// 15.6 ��Ʈ���� ����Ʈ ������
	// // << : left shift, number << n : multiply number by 2^n
	// // >> : right shift, number >> n : divide number by 2^n

	// // 8bit integer
	// printf("%hhd\n", 1 << 3);
	// printf("%hhd\n", 8 >> 1);

	// printf("%hhd\n", -119 >> 3); // signed�� ��쿡, ���� ���� ��Ʈ�� 1�̶�� �ű�� �� �� ��ĭ�� 1�� ä���.
	// printf("%hhu\n", 137 >> 3); // unsigned�� ��쿡�� �ű�� �� �� ��ĭ�� 0���� ä���.

	// printf("%hhd\n", (char)(-119 << 4)); // 1�� �̵��ϸ鼭 ������� ������ warning
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

	// 15.7 ��Ʈ���� �������� �پ��� ����
	//// ��Ʈ����ŷ = ����ũ�� ���� ���� ���� �κи� ���̴� ��ó��, ��Ʈ���� 1�� �κи� �̾Ƴ� �� �ִ�.
	//char flags = 0; // mask flags
	//char_binary(flags);

	//flags |= MASK_SWORD; // bitwise OR �����ڷ� Ư�� ��Ʈ�� 1�� �ٲ��� �� �ִ�.
	//char_binary(flags);

	//flags |= MASK_AMULET;
	//char_binary(flags);

	//printf("\nTurning Bits off (Clearning Bits)\n");
	//flags |= MASK_POTION;
	//char_binary(flags);

	//flags &= ~MASK_POTION; // bitwise AND�� NOT���� Ư�� ��Ʈ�� 0���� �ٲ��� �� �ִ�.

	//printf("\nToggling Bits\n");
	//// 0�� 1�� 1�� 0���� �ٲ��ֱ� ������ Toggling���� ����� �� �ִ�.
	//flags = flags ^ MASK_HAMMER;
	//char_binary(flags);

	//flags = flags ^ MASK_HAMMER;
	//char_binary(flags);

	//flags = flags ^ MASK_HAMMER;
	//char_binary(flags);
	//
	//printf("\nChecking the Value of a Bit\n");
	//if ((flags & MASK_KEY) == MASK_KEY)
	//{
	//	printf(">> You can enter.\n");
	//}
	//else
	//{
	//	printf(">> You can't enter.\n");
	//}

	//flags |= MASK_KEY;

	//if ((flags & MASK_KEY) == MASK_KEY)
	//{
	//	printf(">> You can enter.\n");
	//}
	//else
	//{
	//	printf(">> You can't enter.\n");
	//}

	//printf("\nTrimming\n");
	//int int_flag = 0xffffffff; // ��ü�� 4����Ʈ�� �÷���
	//int_binary(int_flag);
	//int_binary((int)0xff);
	//int_flag  &= 0xff; // 1����Ʈ�κи� ���� ���� ��
	//int_binary(int_flag);

	// 15.8 RGBA ���� ��Ʈ ����ũ ��������
	//unsigned int rgba_color = 0x66cdaaff; // medium aqua marine (102, 205, 170, 225)
	//unsigned char red, green, blue, alpha; // ���ε��� ������ �ٴ� �ʿ䰡 ����.

	//alpha = (rgba_color & 0xff);
	//blue = (rgba_color >> 8) & 0xff;
	//green = (rgba_color >> 16) & 0xff;
	//red = (rgba_color >> 24) & 0xff;

	//printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n", red, green, blue, alpha);

	// 15.9 ����ü ���� ��Ʈ�ʵ�
	//// ��Ʈ�ʵ�: ��Ʈ�� ���������� ������ �ִ� ����

	//// ����� ��Ʈ ������ �ݷ�(:) ������ ���ش�.
	//struct
	//{
	//	bool has_sword : 1;
	//	bool has_shield : 1;
	//	bool has_magic_potion : 1;
	//	bool has_choes : 1;
	//	bool has_gun : 1;
	//	bool has_pet : 1;
	//	bool has_guntlet : 1;
	//	bool has_arrow : 1;
	//} items_flag;

	//items_flag.has_sword = 1; // flags = flags | MASK_SWORD;

	// 15.10 ��Ʈ�ʵ��� �����
	//struct items
	//{
	//	bool has_sword : 1;
	//	bool has_shield : 1;
	//	bool has_magic_potion : 1;
	//	bool has_choes : 1;
	//	bool has_gun : 1;
	//	bool has_pet : 1;
	//	bool has_guntlet : 1;
	//	bool has_arrow : 1;
	//} items_flag;

	//printf("Size = %zd\n", sizeof(items_flag)); // 1 ����Ʈ(8 ��Ʈ)

	//items_flag.has_sword = 1;
	//items_flag.has_shield = 0;
	//items_flag.has_magic_potion = 0;
	//items_flag.has_choes = 1;
	//items_flag.has_gun = 0;
	//items_flag.has_pet = 1;
	//items_flag.has_guntlet = 0;
	//items_flag.has_arrow = 0;

	//printf("Size = %zd\n", sizeof(items_flag));
	//print_binary((char*)&items_flag, sizeof(items_flag));

	//// ��Ʈ �ʵ带 �̿��ϸ� �Ʒ��� ���� �ڵ� ��Ÿ�Ϸ� �ڵ��� �� �ִ�.
	//if (items_flag.has_arrow == 1)
	//	printf(">> You have arrow.");

	//// union�� �̿��Ͽ� �� ���� ������� ������ ���� �ִ�.
	//union
	//{
	//	struct items bf;
	//	unsigned char uc;
	//} uni_flag;

	//uni_flag.uc = 0;
	//uni_flag.bf.has_arrow = true;
	//uni_flag.uc |= (1 << 4);

	//print_binary((char*)&uni_flag, sizeof(uni_flag));

	//// KNK DOS example
	//// ��� ���Ͽ� ���������� ����Ǵ� ������ �������� ����.
	//struct file_time {
	//	unsigned int seconds : 5; // 2^5 = 32, 0 ~ 31, 2�� ������ ����Ѵ�.
	//	unsigned int minutes : 6; // 2^6 = 64, 0 ~ 59��
	//	unsigned hours : 5; // 2^5 = 32, 0 ~ 23 �ð�
	//};
	//struct file_date {
	//	unsigned int day : 5; //  2^5, 0 ~ 31��
	//	unsigned int month : 4; // 2^4 1 ~ 12��
	//	unsigned year : 7; // 2^7 = 128, 1980�� ~ 
	//} fd; 
	//fd.day = 28; // ������ ����� overflow
	//fd.month = 12;
	//fd.year = 8;
	//
	//printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);
	////scanf("%d", &fd.day); // ������ ����.

	// 15.11 ��Ʈ�ʵ��� �е�
	// struct {
	// 	bool option1 : 1;
	// 	bool : 0; // ������ �޸𸮸� �� �Ҵ�
	// 	bool option2 : 1;
	// 	unsigned long long option3 : 1; // �߰��ϸ� sizeof(bbf)�� 16����Ʈ�� �ٲ��. �е��� �ż� option1, option2�� 8����Ʈ�� �����ϰ�, option3�� 8����Ʈ�� ������ ���̴�.
	// } bbf;

	// memset((char*)&bbf, 0xff, sizeof(bbf));
	// bbf.option1 = 0;
	// bbf.option2 = 0;
	// bbf.option3 = 0;

	// printf("%zu bytes\n", sizeof(bbf)); // 1����Ʈ

	// struct {
	// 	unsigned short option1 : 8;
	// 	unsigned short option2 : 7;
	// 	unsigned short option3 : 1;
	// } usbf;

	// printf("%zu bytes\n", sizeof(usbf)); // 2����Ʈ, 1��Ʈ���� ����ϴ� ������ �ٲ㵵 2����Ʈ�̴�.

	// struct {
	// 	unsigned int option1 : 1;
	// 	unsigned int option2 : 1;
	// } uibf;

	// printf("%zu bytes\n", sizeof(uibf)); // 4����Ʈ, �ڷ���(unsigned int)�� ���� �ٸ���.

	// 15.12 �޸� �ٸ��� alignof, alignas
	// ms�����Ϸ������� ���� �ʴ´�. gcc �����Ϸ����� ����
	printf("Alignment of char = %zu\n", _Alignof(char)); // 1����Ʈ
	printf("alignof(float[10]) = %zu\n", _Alignof(float[10])); // ������ ���ҿ� ���� align�� �� ����Ʈ �������� ����� �ϴ���
	printf("alignof(struct{char c; int n;}) = %zu\n", _Alignof(struct{char c; int n;})); // ũ�Ⱑ ū (int)4����Ʈ�� �Ѵ�.

	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	// char _Alignas(double) cz;
	// char _Alignas(16) cz;
	char cz;

	printf("char alignment %zd\n", _Alignof(char));
	printf("double alignment: %zu\n", _Alignof(double));
	
	// �޸� �ٸ���..
	printf("&dx: %p %ld\n", &dx, (long)&dx % 8); // �������� 0
	printf("&ca: %p %ld\n", &ca, (long)&ca % 8);
	printf("&cx: %p %ld\n", &cx, (long)&cx % 8);
	printf("&dz: %p %ld\n", &dz, (long)&dz % 8); // �������� 0
	printf("&cb: %p %ld\n", &cb, (long)&cb % 8);
	printf("&cz: %p %ld\n", &cz, (long)&cz % 8); // _Alignas(double), _Alignas(16)�� �ϸ� �������� 0���� �ȴ�.
	
	unsigned char _Alignas(long double) c_arr[sizeof(long double)]; // �迭�� ���� ���� Align�� ����� �� �ִ�.
	return 0;
}