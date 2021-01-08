#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	// 최소 크기이다. sizeof() 함수를 이용하여 확인해보자.
	// 형식지정자(Format Specifier)를 잘못 사용하면 overflow 등의 문제가 생길 수 있다.

	// char: 1바이트, -128 ~ 127, %c(문자), %hhd
	// unsigned char: 1바이트, 0 ~ 255, %c(문자), %hhu

	// short: 2바이트, -2^15 ~ 2^15 - 1, %hd
	// unsigned shohrt: 2바이트, 0~ 2^16 - 1, %hu

	// int: 4바이트, -2^31 ~ 2^31 -1, %d, %i
	// unsigned int: 4바이트, 0 ~ 2^32 -1, %u

	// long: 4바이트, %ld
	// unsigned long: 4바이트, %lu

	// long long: 8바이트, %lld
	// unsigned long long: 8바이트, %llu

	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U;
	long l = 65537L;
	long long ll = 12345678908642LL;

	printf("char = %hhd, %d, %c\n", c, c, c); // 65, 65, A
	printf("short = %hhd, %hd, %d\n", s, s, s); // -56, 200, 200
	printf("unsigned int = %u, %d\n", ui, ui);
	printf("long = %ld, %hd\n", l, l);
	printf("long long = %lld, %ld", ll, ll);

	return 0;
}