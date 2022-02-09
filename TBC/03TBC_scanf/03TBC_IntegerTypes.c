#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	// �ּ� ũ���̴�. sizeof() �Լ��� �̿��Ͽ� Ȯ���غ���.
	// ����������(Format Specifier)�� �߸� ����ϸ� overflow ���� ������ ���� �� �ִ�.

	// char: 1����Ʈ, -128 ~ 127, %c(����), %hhd
	// unsigned char: 1����Ʈ, 0 ~ 255, %c(����), %hhu

	// short: 2����Ʈ, -2^15 ~ 2^15 - 1, %hd
	// unsigned shohrt: 2����Ʈ, 0~ 2^16 - 1, %hu

	// int: 4����Ʈ, -2^31 ~ 2^31 -1, %d, %i
	// unsigned int: 4����Ʈ, 0 ~ 2^32 -1, %u

	// long: 4����Ʈ, %ld
	// unsigned long: 4����Ʈ, %lu

	// long long: 8����Ʈ, %lld
	// unsigned long long: 8����Ʈ, %llu

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