#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	// C언어는 각 자료형의 '최소 메모리 크기'만을 규정하기 때문에, 다른 시스템에서 메모리 크기가 달라서 작동하지 않을 수도 있다.
	// 즉, 이식성이 나쁠 수 있다. 자료형의 메모리 크기를 고정해보자.

	// stdint.h
	int i;
	int32_t i32; // 32bit integer
	int_least8_t i8; // smallest 8 bit
	int_fast8_t f8; // fastest minimum
	intmax_t imax; // biggest signed integers
	uintmax_t uimax; // biggest unsigned integers

	// printf를 사용할 때 문제가 발생한다.
	// printf()에서 형식지정자를 사용할 때, 어떤 타입인지 알 수가 없다.
	// inttypes.h가 그것을 해결해준다.
	// inttypes.h는 내부에서 이미 stdint.h를 include 하고 있기 때문에, inttypes.h를 include 한다면, stdint.h를 include 할 필요가 없다.
	i32 = 1004;
	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32); // 문자열을 쪼갤 수 있다.
	printf("me32 = %" PRId32 "\n", i32); // 매크로를 이용하여 바꾼다. PRI(print) d(decimal) 32(bit)

	return 0;
}