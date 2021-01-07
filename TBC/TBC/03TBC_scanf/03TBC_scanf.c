#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// (자료형) (변수명) = (리터럴 상수);
	int pizza = 5900; 
	// (한정자 Qualifier) (자료형 DataType) (기호적 상수 Symbolic constant) = (리터럴 상수 literal constant);
	// 한정자를 사용하면 값을 바꾸지 못하므로 "변수"라는 용어 대신 "기호적 상수"라는 용어를 사용한다.
	const int angel = 1004; 
	
	// scanf 에러를 해결하는 방법
	// 1. #define _CRT_SECURE_NO_WARNINGS
	// 2. project (right click) >> properties >> preprocessor >> Preprocessor Definition: ...;_CRT_SECURE_NO_WARNINGS;
	// 3. vscode에서 gcc 컴파일러를 사용한다.

	// &(ampersand)를 붙이는 이유
	// &는 변수의 주소를 알고 싶을 때 사용한다. scanf() 함수에 변수의 주소를 전달한다.
	// scanf()함수는 사용자가 콘솔창에 입력한 값을 받기 때문에 보안상의 위험이 있다.
	// microsoft는 scanf_s() 함수를 사용하길 권한다.(visual studio의 컴파일러, 다른 컴파일러는 문제 없다.)

	int i = 0;
	scanf("%d", &i);
	printf("Value is%d\n", i);

	// 변수 두 개를 입력받아 더한 값을 출력하는 프로그램 작성
	int num1 = 0, num2 = 0;
	printf("Input two integers.\n");
	scanf("%d%d", &num1, &num2);
	printf("%d + %d = %d\n", num1, num2, num1 + num2);

	//원화를 달러로 계산하여 출력하는 프로그램
	float won = 0.0f, dollar = 0.0f;
	printf("Input Won.\n");
	scanf("%f", &won);
	dollar = won * 0.00089f;
	printf("%f dollar\n", dollar);
	
	// 형식지정자
	// %c: char
	// %d: decimal number
	// %e: exponential floating-point number
	// %f: floating-point number
	// %i: integer
	// %o: octal number
	// %s: string of characters
	// %u: unsigned decimal number
	// %x: number in hexadecimal(base 16)
	// %%: print a percent sign
	// \%: print a percent sign
	return 0;
}