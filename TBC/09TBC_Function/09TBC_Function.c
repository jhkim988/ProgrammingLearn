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
	// 9.1 함수가 필요할 때
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
	// 블랙박스로써의 함수 (입출력은 알지만 내부 구조를 알 필요는 없다.)
	// 입출력을 먼저 생각하고 내부구조를 그에 맞게 설계한다.
	// 함수와 인자의 이름을 잘 지어야 한다.

	// 컴파일러가 컴파일을 할 때는 블랙박스로써의 함수(입력이 무엇이고, 출력이 무엇인지)만 알아도 컴파일이 된다.
	// 즉 함수의 프로토타입만 있어도 된다.
	// 프로토타입 -> 함수의 이름, 인자의 타입, 반환값의 타입
	// 프로토타입만 있으면 컴파일 에러가 나지 않는다.(컴파일은 된다.) 링킹과정(실행파일을 만드는 과정)에서 에러가 난다.
	// 자동으로 분리: 함수 -> 우클릭 -> quick actions and refactoring -> create declaration/definition

	// 함수를 선언할 때 input을 parameter라고 한다.
	// 함수에 넣는 값을 arguments라고 한다.

	// 옛날 표준에는 프로토타입에 parameter를 넣지 않아도 됐었다. (빌드 실행 모두 잘 됨)
	// parameter에 void는 아무것도 넣지 않는다는 의미이다.
	// parameter에 이름을 쓰지 않고 타입만 써도 된다. (옛날 표준)
	// 사실 프로토타입에는 parameter 이름이 있을 필요가 없다..


	// 9.3 함수의 자료형과 반환값
	// int int_min(int, int); 마치 int_min이 정수타입인 것처럼 보인다. 반환값의 타입을 함수의 자료형이라고도 한다.
	// int_min(int i1, int i2){ ... } 에서 자료형(int)를 생략해도 문법상 문제가 없다.
	// local 변수 (함수 내에서 선언된 변수)
	// return min; // 반환값
	// return (float) min; // int를 반환하기로 했는데 float로 바꿔서 반환 시도 -> float를 다시 int로 바꿔서 반환한다. (강제로 바꾼다.)
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


	// 9.4 변수의 영역와 지역변수 (scope, local variable)
	//int a; // 변수를 사용할 수 있는 영역이 있다.

	//a = int_max(1, 2);

	////m = 123;
	//// m이 유효한 범위는 { ... } 블럭 내부이다. (해당 변수가 선언된 영역)
	//// stack frame
	//// file 영역 변수 (모든 함수 바깥 쪽) 파일 전체에서 접근할 수 있다.
	//// 안쪽에 같은 이름의 변수가 있으면 안쪽에 있는 것으로 교체된다.

	//printf("%d\n", a);
	//printf("%p\n", &a);

	//// 메모리의 주소 자체를 직접 이용하여 코딩하는 것은 어렵다. 따라서 변수를 이용한다.
	//// 변수 a의 주소를 직접 보기 위해서는 &a를 입력하면 된다.

	//{
	//	// int a; // 새로 변수를 선언하면 다른 변수가 된다. (주소 값이 다름)
	//	a = int_max(4, 5);
	//	printf("%d\n", a);
	//	printf("%p\n", &a);

	//	int b = 123;
	//}

	//printf("%d\n", a);
	//printf("%p\n", &a);


	// 9.5 지역변수와 스택
	//int a; // 스택에 a 변수가 사용할 메모리가 쌓인다.

	//a = int_max(1, 2); // int_max 함수 내부로 가면 int m;이 있다. m도 스택에 쌓인다.
	//// int_max 함수가 실행하는 도중에 스택에 쌓여있는 a를 꺼낼 수 있다. (직접 접근은 할 수 없다.)
	//// int_max 함수가 끝나면 스택에 쌓인 m이 사라진다.
	//{
	//	int b; // 스택에 b가 쌓인다. 마찬가지로 a에 접근할 수 있는 상태다.
	//	b = int_max(4, 5); // int_max를 실행하면서 m이 스택에 쌓였다가 다시 사라진다.
	//	{
	//		int b = 123; // 스택에 b가 쌓인다. 위의 b와는 다른 주소를 가진 변수이다. (a, b, b 모두 메모리에 있고, 사용할 수 있다.) 이름이 겹쳐서 문제
	//	} // 영역이 끝나면서 b가 스택에서 사라진다.
	//	{
	//		int c = 456;  // 스택에 c가 쌓인다.
	//	} // 영역을 나가면서 c가 스택에서 사라진다.
	//} // 영역을 나가면서 b가 스택에서 사라진다.
	

	// 9.6 재귀 호출 (Recursion)
	// 무한루프를 구현할 때 재귀를 사용하지는 않는다. (while이나 for를 이용하는 것이 좋다.)
	// 호출 횟수가 높거나, 프로그램을 최적화하고 싶을 때에는 재귀를 사용하지 않는 것이 좋다.
	//my_func(1);


	// 9.7 재귀 호출과 스택
	// n=1 이 스택에 쌓임 -> n=2이 스택에 쌓임 -> ...
	// n은 이름만 같고, 메모리 주소는 다르다.
	// int는 4바이트지만, 실제 메모리 주소의 차이는 4보다 크다. 호출한 함수 자체도 메모리에 올라가기 때문에...
	//my_func(1);


	// 9.8 팩토리얼 예제
	//int num = 5;

	//printf("%d\n", loop_factorial(num));
	//printf("%d\n", recursive_factorial(num));

	// 9.9 이진수 변환 예제
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
	printf("Level %d, adress of variable n = %d\n", n, (int)&n); // 호출할 때마다 n의 주소가 다르다.
	if (n < 4)
		my_func(n + 1); // 자기 자신을 호출하는 구조, 스택 메모리가 다 차면 종료된다. 스택 오버플로우

	printf("Level %d, adress of variable n = %d\n", n, (int)&n); // 돌아오는 경로를 보기 위해...
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
	return n * recursive_factorial(n - 1); // 꼬리 재귀 (tail recursion, end recursion): 리턴에서 재귀호출을 하는 것
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