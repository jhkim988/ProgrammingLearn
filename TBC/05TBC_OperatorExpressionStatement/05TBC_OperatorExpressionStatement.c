#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void draw(int n); // ANSI function prototype declaration

int main()
{
	// 5.1 반복 루프와의 첫 만남
	// 1부터 10까지 출력하는 프로그램\

	// 1. goto를 이용한 방식(옛날 방식)
	// 동선이 꼬이고 오류가 생길 가능성이 높다. 사용하지 않는 것이 좋다.
//	int n = 1;
//label:
//	printf("%d\n", n);
//	n = n + 1;
//	if (n == 10) goto out;
//	goto label;
//out:

	// 2. while문을 이용한 방법
	//int n = 1; // 초기조건 설정
	//while (n < 11) // 반복돼서 실행될 조건
	//{
	//	// 반복할 내용
	//	printf("%d\n", n);
	//	n = n + 1; // 변하는 조건을 넣어줘야한다.
	//};


	// 5.2 대입 연산자와 몇 가지 용어들
	// 기본 연산자들 =, +, -, *, /
	// operator, operand, 연산자, 피연산자
	// Data object, L-value(object locator value), R-value(value of an expression)


	// 5.3 더하기, 빼기, 부호 연산자들
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

	//1.0f + 2; // float가 된다.
	// binary operator, Unary operator


	// 5.4 곱하기 연산자
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
	//printf("%d년 후에 %.0f원이 %.0f원이 됩니다.", count, seed_money, fund);



	// 5.5 나누기 연산자
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


	//// 5.6 연산자 우선순위와 표현식 트리
	//double a = 4.0, b = 5.0;
	//double c;
	//c = 3.0 + 5.0 * b / a;
	//
	//// 컴파일러가 수식을 보고 표현식 트리를 만들어서 우선순위를 파악하고 계산한다.
	//// Expression Tree, (Node, Graph)
	////    +
	////   / \
	//// 3.0  "/"
	////     / \
	////    *   a
	////   / \
	//// 5.0  b
	

	//// 5.7 나머지 연산자
	////int hours, minutes, seconds, input = 0;
	////printf("Input seconds: ");
	////scanf("%d", &input);
	////hours = input / (60 * 60);
	////minutes = (input / 60) % 60;
	////seconds = input % 60;
	////printf("%d hours, %d minutes, %d seconds\nGood bye\n", hours, minutes, seconds);
	//
	//// 음수를 입력하면 종료하는 방식
	//int hours, minutes, seconds, input = 0;

	//// while 문을 사용하려면 입력 받는 부분을 밖으로 빼줘야 제대로 종료된다.
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


	// 5.8 증가, 감소 연산자
	//int a = 0;
	//a++;
	//printf("%d\n", a);

	//++a;
	//printf("%d\n", a);

	//// 실수형에서도 작동한다.
	//double b = 0;
	//b++;
	//printf("%f\n", b);
	//++b;
	//printf("%f\n", b);

	// while문과 같이 사용
	//int count;
	//count= 0;
	//while (++count < 10) // ++count와 count++의 출력 개수가 다르다.
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

	// Bad practices -> 너무 복잡하게 사용하는 것은 좋지 않다. (시스템마다 결과가 다르게 나올 수도 있다.)
	//int n = 1;
	//printf("%d %d", n, n * n++);
	//int x = n / 2 + 5 * (1 + n++);
	//int y = n++ + n++;


	// 5.9 표현식과 문장
	//// 표현식
	//// 표현식 -> 값 
	//// a = 2 + 3도 표현식이고, 값도 존재한다. (대입하는 것이 side effect) 
	//int a = 1;
	//printf("%d\n", 4 + (a = 2 + 3));
	//printf("%d\n", 2 > 1); // true -> 1, false -> 1

	//// 문장
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

	// 5.10 순서도(Flow chart)
	//// 마름모: 판단(분기)
	//// 사각형: 실제 기능 수행
	//int i = 0;
	//while (i < 10)
	//{	// an example of compound statements
	//	// (block)
	//	i++;
	//	printf("%d\n", i);
	//};

	// 5.11 자료형 변환
	//// promitions in assignments
	//short s = 64;
	//int i = s; // 작은 걸 큰 것에 대입할 떄는 문제가 안 생긴다.

	//float f = 3.14f;
	//double d = f;

	//// demotion in assignment
	//d = 1.25;
	//f = 1.25; // 1.25f가 아니다. double을 float에 대입 -> 컴파일러마다 다르지만, 1.25같은 숫자는 2진법으로 정밀하게 표현가능하다. (float, double 상관 없이)
	//f = 1.123; // truncation warning (float, double이 차이가 난다.)

	//// ranking of types in operations
	//// long double > double > float
	//// unsigned long long, long long
	//// unsigned long, long
	//// unsigned, int
	//// short int, unsigned short int
	//// signed char, char, unsigned char
	//// _Bool

	//// 실수와 정수를 더할 때 정수를 실수로 형변환 한 후에 실수끼리 더한다.
	//d = f + 1.234; // 둘 다 double로 변환하여 연산한다.
	//f = f + 1.234; // 둘 다 double로 변환하여 연산한 후에 float로 형변환 한다.

	//// automatic promotion of function arguments
	//// 1. Function without prototypes (C99에서 prototypes이 도입되면서 잘 사용하지 않는다.)
	//// 2. Variadic functions (받는 인자 개수가 변할 수 있는 함수, 가변인자 함수, ellipsis)

	//// casting operators
	//d = (double)3.14f; // expression의 값을 double로 형변환한다.
	//i = 1.6 + 1.7; // double + double -> 3.3 -> truncation i = 3
	//i = (int)1.6 + (int)1.7; // 1 + 1 = 2 -> i = 2

	//// more example
	//char c;
	//f = i = c = 'A'; // 65
	//printf("%c %d %f\n", c, i, f);
	//c = c + 2; // 'C', 67
	//i = f + 2 * c; // 65.0f + 2 * 67
	//printf("%c %d %f\n", c, i, f);
	//c = 1106; // demotion, 데이터 손실
	//printf("%c\n", c);
	//c = 83.99;
	//printf("%c\n", c);


	// 5.12 함수의 인수와 매개변수(Arguments, Parameters)
	int i = 5;
	char c = '#'; // 35
	float f = 7.1f;
	
	draw(i);
	draw((int)c);
	draw((int)f);
	// 자동으로 형변환 되지만, 명시적으로 표시해주는 것이 좋다.

	// C99에서 정리됐다.
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