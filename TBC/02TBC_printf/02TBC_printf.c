#include <stdio.h>

void say_hello(void); // 함수 선언, prototyping, function declaration

int main()
{	
	// escape sequence
	// \n: 줄 바꿈
	// \": 따옴표
	// \a: 경고음

	int x, y, z; // 변수를 선언할 때 초기화까지 해주는 게 좋다.
	x = 1;
	y = 2;
	z = x + y;

	// printf: print formatted 사용법
	// %i: integer
	// %d: decimal number

	printf("%i + %i = %i", x, y, z);
	say_hello(); // 함수를 호출하기 전에 선언이 돼야 한다.
	return 0;
}

void say_hello(void) // 함수 정의
{
	// main함수 안에서 say_hello를 호출하기 전에 함수를 선언해줘야 한다.
	// 선언만 하고 정의를 뒤에서 할 수도 있다.
	// 그러면 컴파일이 끝난 후 링킹하는 과정에서 함수 정의를 찾아 연결된다.
	int x = 1;
	x = 10;
	printf("Hello, World!\n");
}