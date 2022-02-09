#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void draw(int n); // ANSI function prototype declaration

int main()
{
	// 5.1 �ݺ� �������� ù ����
	// 1���� 10���� ����ϴ� ���α׷�\

	// 1. goto�� �̿��� ���(���� ���)
	// ������ ���̰� ������ ���� ���ɼ��� ����. ������� �ʴ� ���� ����.
//	int n = 1;
//label:
//	printf("%d\n", n);
//	n = n + 1;
//	if (n == 10) goto out;
//	goto label;
//out:

	// 2. while���� �̿��� ���
	//int n = 1; // �ʱ����� ����
	//while (n < 11) // �ݺ��ż� ����� ����
	//{
	//	// �ݺ��� ����
	//	printf("%d\n", n);
	//	n = n + 1; // ���ϴ� ������ �־�����Ѵ�.
	//};


	// 5.2 ���� �����ڿ� �� ���� ����
	// �⺻ �����ڵ� =, +, -, *, /
	// operator, operand, ������, �ǿ�����
	// Data object, L-value(object locator value), R-value(value of an expression)


	// 5.3 ���ϱ�, ����, ��ȣ �����ڵ�
	//printf("%d\n", 1 + 2);
	//int income, salary, bonus;
	//income = salary = bonus = 100; // triple assignment
	//salary = 100;
	//bonus = 30;
	//income = salary + bonus; // R-value

	//int takehome, tax;
	//tax = 20;
	//takehome = income - tax;

	//int a, b;
	//a = -7;
	//b = -a;
	//b = +a; // + does nothing

	//1.0f + 2; // float�� �ȴ�.
	// binary operator, Unary operator


	// 5.4 ���ϱ� ������
	//double seed_money = 1.0f;
	//double fund = 1.0f;
	//double target_money = 1.0f;
	//double annual_interest = 0.0f;
	//int count = 0;

	//printf("Input seed money: ");
	//scanf("%lf", &seed_money);
	//fund = seed_money;

	//printf("Input target money: ");
	//scanf("%lf", &target_money);

	//printf("Input annual interest(%%): ");
	//scanf("%lf", &annual_interest);

	//while (fund < target_money)
	//{
	//	fund *= (1 + annual_interest / 100);
	//	printf("Year %d fund %f\n", count, fund);
	//	count += 1;
	//};
	//printf("%d�� �Ŀ� %.0f���� %.0f���� �˴ϴ�.", count, seed_money, fund);



	// 5.5 ������ ������
	//printf("Integer divisions\n");
	//printf("%d\n", 14 / 7); // 2
	//printf("%d\n", 7 / 2); // 3.5 in floating division. -> 3
	//printf("%d\n", 7 / 3); // 2.333 in floating division. -> 2
	//printf("%d\n", 7 / 4); // 1.75 in floating division. -> 1
	//printf("%d\n", 8 / 4); // 2

	//printf("Truncating toward zero (C99)\n");
	//printf("%d\n", -7 / 2); // -3.5 -> -3
	//printf("%d\n", -7 / 3); // -2.333 -> -2
	//printf("%d\n", -7 / 4); // -1.75 -> -1
	//printf("%d\n", -8 / 4); // -2

	//printf("Floating divisions\n");
	//printf("%f\n", 9.0 / 4.0); // 2.25
	//printf("%f\n", 9.0 / 4); // 4 is integer. integer(4) -> double(4.0)


	//// 5.6 ������ �켱������ ǥ���� Ʈ��
	//double a = 4.0, b = 5.0;
	//double c;
	//c = 3.0 + 5.0 * b / a;
	//
	//// �����Ϸ��� ������ ���� ǥ���� Ʈ���� ���� �켱������ �ľ��ϰ� ����Ѵ�.
	//// Expression Tree, (Node, Graph)
	////    +
	////   / \
	//// 3.0  "/"
	////     / \
	////    *   a
	////   / \
	//// 5.0  b
	

	//// 5.7 ������ ������
	////int hours, minutes, seconds, input = 0;
	////printf("Input seconds: ");
	////scanf("%d", &input);
	////hours = input / (60 * 60);
	////minutes = (input / 60) % 60;
	////seconds = input % 60;
	////printf("%d hours, %d minutes, %d seconds\nGood bye\n", hours, minutes, seconds);
	//
	//// ������ �Է��ϸ� �����ϴ� ���
	//int hours, minutes, seconds, input = 0;

	//// while ���� ����Ϸ��� �Է� �޴� �κ��� ������ ����� ����� ����ȴ�.
	//printf("Input seconds: ");
	//scanf("%d", &input);
	//while (input >= 0)
	//{
	//	hours = input / (60 * 60);
	//	minutes = (input / 60) % 60;
	//	seconds = input % 60;
	//	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
	//	printf("Input seconds: ");
	//	scanf("%d", &input);
	//};


	//int div, mod;
	//div = 11 / 5;
	//mod = 11 % 5;
	//printf("div = %3d, mod = %3d\n", div, mod);

	//div = 11 / -5;
	//mod = 11 % -5;
	//printf("div = %3d, mod = %3d\n", div, mod);

	//div = -11 / -5;
	//mod = -11 % -5;
	//printf("div = %3d, mod = %3d\n", div, mod);

	//div = -11 / 5;
	//mod = -11 % 5;
	//printf("div = %3d, mod = %3d\n", div, mod);


	// 5.8 ����, ���� ������
	//int a = 0;
	//a++;
	//printf("%d\n", a);

	//++a;
	//printf("%d\n", a);

	//// �Ǽ��������� �۵��Ѵ�.
	//double b = 0;
	//b++;
	//printf("%f\n", b);
	//++b;
	//printf("%f\n", b);

	// while���� ���� ���
	//int count;
	//count= 0;
	//while (++count < 10) // ++count�� count++�� ��� ������ �ٸ���.
	//{
	//	printf("%d\n", count);
	//}

	//int i = 1, j = 1;
	//int i_post = i++;
	//int pre_j = ++j;
	//
	//printf("%d %d\n", i, j); // 2 2
	//printf("%d %d\n", i_post, pre_j); // 1 2

	//int i = 3;
	//int j = 2 * --i;
	//printf("%d %d\n", i, j); // 2 4

	//i = 1;
	//j = 2 * i--;
	//printf("%d %d\n", i, j); // 0 2

	/*int x, y, z;
	x = 3, y = 4;
	z = (x + y++) * 5;
	printf("%d %d %d", x, y, z);*/

	// ++ and -- affect modifiable L-values
	//int x = 1, y = 1, z;
	//z = x * y++;
	//// z = (x * y)++; // error;
	//// z = 3++; // error;

	// Bad practices -> �ʹ� �����ϰ� ����ϴ� ���� ���� �ʴ�. (�ý��۸��� ����� �ٸ��� ���� ���� �ִ�.)
	//int n = 1;
	//printf("%d %d", n, n * n++);
	//int x = n / 2 + 5 * (1 + n++);
	//int y = n++ + n++;


	// 5.9 ǥ���İ� ����
	//// ǥ����
	//// ǥ���� -> �� 
	//// a = 2 + 3�� ǥ�����̰�, ���� �����Ѵ�. (�����ϴ� ���� side effect) 
	//int a = 1;
	//printf("%d\n", 4 + (a = 2 + 3));
	//printf("%d\n", 2 > 1); // true -> 1, false -> 1

	//// ����
	//int x, y, apples; // declaration statement
	//apples = 3; // assignment statement
	//; // null statement
	//x = 1 + (y = 5); // y = 5 is subexpression
	//while (x++ < 10) y = x + y; // while statement
	//printf("%d\n", y); // function statement
	//// return 0; // return statement

	//// Side Effects and Sequence Points
	//x = 4; // main intent is evaluating expressions
	//y = 1 + x++;

	//while (x++ < 10) printf("%d\n", x); // (x++ < 10) is a full expression
	//y = (4 + x++) + (6 + x++); // Not (4 ++ x++) nor (6 + x++) is a full expression.

	// 5.10 ������(Flow chart)
	//// ������: �Ǵ�(�б�)
	//// �簢��: ���� ��� ����
	//int i = 0;
	//while (i < 10)
	//{	// an example of compound statements
	//	// (block)
	//	i++;
	//	printf("%d\n", i);
	//};

	// 5.11 �ڷ��� ��ȯ
	//// promitions in assignments
	//short s = 64;
	//int i = s; // ���� �� ū �Ϳ� ������ ���� ������ �� �����.

	//float f = 3.14f;
	//double d = f;

	//// demotion in assignment
	//d = 1.25;
	//f = 1.25; // 1.25f�� �ƴϴ�. double�� float�� ���� -> �����Ϸ����� �ٸ�����, 1.25���� ���ڴ� 2�������� �����ϰ� ǥ�������ϴ�. (float, double ��� ����)
	//f = 1.123; // truncation warning (float, double�� ���̰� ����.)

	//// ranking of types in operations
	//// long double > double > float
	//// unsigned long long, long long
	//// unsigned long, long
	//// unsigned, int
	//// short int, unsigned short int
	//// signed char, char, unsigned char
	//// _Bool

	//// �Ǽ��� ������ ���� �� ������ �Ǽ��� ����ȯ �� �Ŀ� �Ǽ����� ���Ѵ�.
	//d = f + 1.234; // �� �� double�� ��ȯ�Ͽ� �����Ѵ�.
	//f = f + 1.234; // �� �� double�� ��ȯ�Ͽ� ������ �Ŀ� float�� ����ȯ �Ѵ�.

	//// automatic promotion of function arguments
	//// 1. Function without prototypes (C99���� prototypes�� ���ԵǸ鼭 �� ������� �ʴ´�.)
	//// 2. Variadic functions (�޴� ���� ������ ���� �� �ִ� �Լ�, �������� �Լ�, ellipsis)

	//// casting operators
	//d = (double)3.14f; // expression�� ���� double�� ����ȯ�Ѵ�.
	//i = 1.6 + 1.7; // double + double -> 3.3 -> truncation i = 3
	//i = (int)1.6 + (int)1.7; // 1 + 1 = 2 -> i = 2

	//// more example
	//char c;
	//f = i = c = 'A'; // 65
	//printf("%c %d %f\n", c, i, f);
	//c = c + 2; // 'C', 67
	//i = f + 2 * c; // 65.0f + 2 * 67
	//printf("%c %d %f\n", c, i, f);
	//c = 1106; // demotion, ������ �ս�
	//printf("%c\n", c);
	//c = 83.99;
	//printf("%c\n", c);


	// 5.12 �Լ��� �μ��� �Ű�����(Arguments, Parameters)
	int i = 5;
	char c = '#'; // 35
	float f = 7.1f;
	
	draw(i);
	draw((int)c);
	draw((int)f);
	// �ڵ����� ����ȯ ������, ��������� ǥ�����ִ� ���� ����.

	// C99���� �����ƴ�.
	// Arguments: actual argument, actual parameter (values)
	// Parameters: formal argument, formal parameter (variables)

	return 0;
}

void draw(int n)
{
	while (n-- > 0)
	{
		printf("*");
	};
	printf("\n");
}