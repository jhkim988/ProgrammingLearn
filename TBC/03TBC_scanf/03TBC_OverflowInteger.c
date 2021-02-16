#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	unsigned int i = 0;

	// sizeof() 함수에 자료형을 집어 넣거나, 변수명을 넣으면 메모리 사이즈를 알려준다.
	sizeof(unsigned int); // 마우스를 대면 나오는 값은 컴파일러가 알려주는 것이 아니라 visual studio 통합개발환경이 알려주는 것이다.
	sizeof(i);

	printf("%u\n", sizeof(unsigned int)); // sizeof()는 unsigned 타입의 값을 리턴하기 때문에 %u를 사용해야한다.
	printf("%u\n", sizeof(i));
	
	// 이진수를 쓰려면 앞에 0b를 써준다. C언어에서 표준은 아니지만, 컴파일러가 지원을 해준다.
	unsigned int max_unsigned1 = 0b11111111111111111111111111111111;
	unsigned int max_unsigned2 = UINT_MAX;
	printf("%u\n", max_unsigned1);
	printf("%u\n", max_unsigned2);
	
	printf("%d\n", max_unsigned1); // %u가 아닌 %d를 넣으면 -1이 나온다.
	
	unsigned int example = 1024;
	printf("%d\n", example); // %u가 아닌 %d를 넣었지만, 1024로 제대로 나온다.

	signed int max_signed = INT_MAX;
	printf("max of unsigned int: %u\n", max_unsigned2);
	printf("max of signed int: %d\n", max_signed);

	unsigned int min_unsigned = 0;
	signed int min_signed = INT_MIN;
	printf("min of unsigned int: %u\n", min_unsigned);
	printf("min of signed int: %d\n", min_signed);


	unsigned int overflow_unsigned = UINT_MAX + 1;
	printf("%u\n", overflow_unsigned); // 0, warning: '+' integral constant overflow

	// i to binary representation
	char buffer[33]; // 문자를 33개 메모리에 나란히 저장할 수 있는 배열을 선언, 4바이트 * 8비트 = 32비트, 33개를 사용하는 이유는 나중에...
	_itoa(overflow_unsigned, buffer, 2); // overflow_unsigned가 담고 있는 숫자를 2진수로 바꿔준다.

	// print decimal and binary
	printf("decimal: %u\n", overflow_unsigned);
	printf("binary: %s\n", buffer); // 2진수 형태로 출력해준다.

	// 11111111 11111111 11111111 11111111 + 1
	// 1 00000000 00000000 00000000 00000000

	unsigned int underflow_unsigned = 0 - 1;
	printf("%u\n", underflow_unsigned); // 11111111 11111111 11111111 11111111 

	return 0;
}  