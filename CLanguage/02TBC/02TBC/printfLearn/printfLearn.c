#include <stdio.h>

void say_hello(void); // 함수 선언, prototyping, function declaration

int main()
{
	// escape sequence: \n, \", \s, \t, \a(경고음) ...
	printf("\"The truth is ... \nI am Ironman.\"\n");

	int x, y, z; // 변수를 선언할 때 초기화까지 하는 게 좋다.
	x = 1;
	y = 2;
	z = x + y;

	/* print formatted
	printf 함수의 사용법 
	%i: 정수  %d: 십진수
	*/

	printf("%i + %i = %i\n", x, y, z);

	say_hello(); // 선언만 된 상태에서 함수를 호출한다. 그러면 컴파일이 끝난 다음에 링킹하는 과정에서 함수 definition을 찾아 연결해준다.

	return 0;
}

// debugger 사용방법
// break point를 찍어둔 다음에 실행시킨다.
// Autos에 변수들이 어떻게 변화하는지 살펴본다.

void say_hello(void) // function definition
{	// say_hello를 호출하기 전에 함수를 선언해줘야한다.
	int x = 1;
	x = 10;
	printf("Hello, World!\n");
}