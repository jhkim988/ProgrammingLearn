#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 50
#define NAME "Jin-Han Kim"
#define ADDRESS "Seoul, South Korea"

// 9.1
void print_bar(int);
void print_multiple_chars(char c, int num, bool print_newline);
void print_centered_str(char str[]);

// 9.3
int int_min(int, int);

// 9.4
int int_max(int i, int j);

// 9.6
void my_func(int);

// 9.8
long loop_factorial(int n);
long recursive_factorial(int n);

// 9.9
void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
	// 9.1 �Լ��� �ʿ��� ��
	//printf("********************\n");
	//printf("     Jin-Han Kim    \n");
	//printf(" South Korea, Seoul \n");
	//printf("********************\n");

	//print_multiple_chars('*', WIDTH, true);

	//print_centered_str(NAME);
	//print_centered_str(ADDRESS);
	//print_centered_str("I Love You.");

	//print_multiple_chars('*', WIDTH, false);


	// 9.2
	// ���ڽ��ν��� �Լ� (������� ������ ���� ������ �� �ʿ�� ����.)
	// ������� ���� �����ϰ� ���α����� �׿� �°� �����Ѵ�.
	// �Լ��� ������ �̸��� �� ����� �Ѵ�.

	// �����Ϸ��� �������� �� ���� ���ڽ��ν��� �Լ�(�Է��� �����̰�, ����� ��������)�� �˾Ƶ� �������� �ȴ�.
	// �� �Լ��� ������Ÿ�Ը� �־ �ȴ�.
	// ������Ÿ�� -> �Լ��� �̸�, ������ Ÿ��, ��ȯ���� Ÿ��
	// ������Ÿ�Ը� ������ ������ ������ ���� �ʴ´�.(�������� �ȴ�.) ��ŷ����(���������� ����� ����)���� ������ ����.
	// �ڵ����� �и�: �Լ� -> ��Ŭ�� -> quick actions and refactoring -> create declaration/definition

	// �Լ��� ������ �� input�� parameter��� �Ѵ�.
	// �Լ��� �ִ� ���� arguments��� �Ѵ�.

	// ���� ǥ�ؿ��� ������Ÿ�Կ� parameter�� ���� �ʾƵ� �ƾ���. (���� ���� ��� �� ��)
	// parameter�� void�� �ƹ��͵� ���� �ʴ´ٴ� �ǹ��̴�.
	// parameter�� �̸��� ���� �ʰ� Ÿ�Ը� �ᵵ �ȴ�. (���� ǥ��)
	// ��� ������Ÿ�Կ��� parameter �̸��� ���� �ʿ䰡 ����..


	// 9.3 �Լ��� �ڷ����� ��ȯ��
	// int int_min(int, int); ��ġ int_min�� ����Ÿ���� ��ó�� ���δ�. ��ȯ���� Ÿ���� �Լ��� �ڷ����̶�� �Ѵ�.
	// int_min(int i1, int i2){ ... } ���� �ڷ���(int)�� �����ص� ������ ������ ����.
	// local ���� (�Լ� ������ ����� ����)
	// return min; // ��ȯ��
	// return (float) min; // int�� ��ȯ�ϱ�� �ߴµ� float�� �ٲ㼭 ��ȯ �õ� -> float�� �ٽ� int�� �ٲ㼭 ��ȯ�Ѵ�. (������ �ٲ۴�.)
	//int i1, i2;
	//
	//while (1)
	//{
	//	printf("Input tow integers: ");
	//	if (scanf("%d %d", &i1, &i2) != 2) break;

	//	int lesser = int_min(i1, i2);
	//	
	//	printf("Thd lesser of %d and %d is %d\n", i1, i2, lesser);
	//	//printf("Thd lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2);
	//}
	//printf("End.\n");


	// 9.4 ������ ������ �������� (scope, local variable)
	//int a; // ������ ����� �� �ִ� ������ �ִ�.

	//a = int_max(1, 2);

	////m = 123;
	//// m�� ��ȿ�� ������ { ... } �� �����̴�. (�ش� ������ ����� ����)
	//// stack frame
	//// file ���� ���� (��� �Լ� �ٱ� ��) ���� ��ü���� ������ �� �ִ�.
	//// ���ʿ� ���� �̸��� ������ ������ ���ʿ� �ִ� ������ ��ü�ȴ�.

	//printf("%d\n", a);
	//printf("%p\n", &a);

	//// �޸��� �ּ� ��ü�� ���� �̿��Ͽ� �ڵ��ϴ� ���� ��ƴ�. ���� ������ �̿��Ѵ�.
	//// ���� a�� �ּҸ� ���� ���� ���ؼ��� &a�� �Է��ϸ� �ȴ�.

	//{
	//	// int a; // ���� ������ �����ϸ� �ٸ� ������ �ȴ�. (�ּ� ���� �ٸ�)
	//	a = int_max(4, 5);
	//	printf("%d\n", a);
	//	printf("%p\n", &a);

	//	int b = 123;
	//}

	//printf("%d\n", a);
	//printf("%p\n", &a);


	// 9.5 ���������� ����
	//int a; // ���ÿ� a ������ ����� �޸𸮰� ���δ�.

	//a = int_max(1, 2); // int_max �Լ� ���η� ���� int m;�� �ִ�. m�� ���ÿ� ���δ�.
	//// int_max �Լ��� �����ϴ� ���߿� ���ÿ� �׿��ִ� a�� ���� �� �ִ�. (���� ������ �� �� ����.)
	//// int_max �Լ��� ������ ���ÿ� ���� m�� �������.
	//{
	//	int b; // ���ÿ� b�� ���δ�. ���������� a�� ������ �� �ִ� ���´�.
	//	b = int_max(4, 5); // int_max�� �����ϸ鼭 m�� ���ÿ� �׿��ٰ� �ٽ� �������.
	//	{
	//		int b = 123; // ���ÿ� b�� ���δ�. ���� b�ʹ� �ٸ� �ּҸ� ���� �����̴�. (a, b, b ��� �޸𸮿� �ְ�, ����� �� �ִ�.) �̸��� ���ļ� ����
	//	} // ������ �����鼭 b�� ���ÿ��� �������.
	//	{
	//		int c = 456;  // ���ÿ� c�� ���δ�.
	//	} // ������ �����鼭 c�� ���ÿ��� �������.
	//} // ������ �����鼭 b�� ���ÿ��� �������.
	

	// 9.6 ��� ȣ�� (Recursion)
	// ���ѷ����� ������ �� ��͸� ��������� �ʴ´�. (while�̳� for�� �̿��ϴ� ���� ����.)
	// ȣ�� Ƚ���� ���ų�, ���α׷��� ����ȭ�ϰ� ���� ������ ��͸� ������� �ʴ� ���� ����.
	//my_func(1);


	// 9.7 ��� ȣ��� ����
	// n=1 �� ���ÿ� ���� -> n=2�� ���ÿ� ���� -> ...
	// n�� �̸��� ����, �޸� �ּҴ� �ٸ���.
	// int�� 4����Ʈ����, ���� �޸� �ּ��� ���̴� 4���� ũ��. ȣ���� �Լ� ��ü�� �޸𸮿� �ö󰡱� ������...
	//my_func(1);


	// 9.8 ���丮�� ����
	//int num = 5;

	//printf("%d\n", loop_factorial(num));
	//printf("%d\n", recursive_factorial(num));

	// 9.9 ������ ��ȯ ����
	unsigned long num = 10;

	print_binary_loop(num);
	//print_binary(num);



	return 0;
}

// 9.1
void print_bar(int n_stars)
{
	for (int i = 0; i < n_stars; i++)
		printf("*");
	printf("\n");
}
void print_multiple_chars(char c, int num, bool print_newline)
{
	for (int i = 0; i <num; i++)
		printf("%c", c);
	if (print_newline) printf("\n");
}
void print_centered_str(char str[])
{
	print_multiple_chars(' ', (WIDTH - strlen(str)) / 2, false);
	printf("%s\n", str);
}

// 9.3
int int_min(int i1, int i2)
{
	return (i1 > i2) ? i2 : i1;
}

// 9.4
int int_max(int i, int j)
{
	int m;
	m = (i > j) ? i : j;
	return m;
}

// 9.6
void my_func(int n)
{
	printf("Level %d, adress of variable n = %d\n", n, (int)&n); // ȣ���� ������ n�� �ּҰ� �ٸ���.
	if (n < 4)
		my_func(n + 1); // �ڱ� �ڽ��� ȣ���ϴ� ����, ���� �޸𸮰� �� ���� ����ȴ�. ���� �����÷ο�

	printf("Level %d, adress of variable n = %d\n", n, (int)&n); // ���ƿ��� ��θ� ���� ����...
	// TODO: stop condition
	// TODO: tail recursion
}

// 9.8
long loop_factorial(int n)
{
	int result = 1;

	//// My Try.
	//for (int i = 2; i <= n; i++)
	//	result *= i;
	
	for (result = 1; n > 1; n--)
		result *= n;

	return result;
}
long recursive_factorial(int n)
{
	if (n == 0) return 1;
	return n * recursive_factorial(n - 1); // ���� ��� (tail recursion, end recursion): ���Ͽ��� ���ȣ���� �ϴ� ��
}

// 9.9
void print_binary(unsigned long n)
{ 
	unsigned long quotient = n / 2, remainder = n % 2;
	if (quotient == 0) return printf("%u", remainder);
	return print_binary(quotient);
}
void print_binary_loop(unsigned long n)
{
	unsigned long quotient = n, remainder = 0;
	unsigned long sum = 0, exp = 1;

	while (quotient != 0)
	{
		remainder = quotient % 2;
		quotient /= 2;
		
		sum += remainder * exp;
		exp *= 10;
	}
	printf("%u\n", sum);
}