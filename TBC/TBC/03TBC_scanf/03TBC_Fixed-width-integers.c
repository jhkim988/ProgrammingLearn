#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	// C���� �� �ڷ����� '�ּ� �޸� ũ��'���� �����ϱ� ������, �ٸ� �ý��ۿ��� �޸� ũ�Ⱑ �޶� �۵����� ���� ���� �ִ�.
	// ��, �̽ļ��� ���� �� �ִ�. �ڷ����� �޸� ũ�⸦ �����غ���.

	// stdint.h
	int i;
	int32_t i32; // 32bit integer
	int_least8_t i8; // smallest 8 bit
	int_fast8_t f8; // fastest minimum
	intmax_t imax; // biggest signed integers
	uintmax_t uimax; // biggest unsigned integers

	// printf�� ����� �� ������ �߻��Ѵ�.
	// printf()���� ���������ڸ� ����� ��, � Ÿ������ �� ���� ����.
	// inttypes.h�� �װ��� �ذ����ش�.
	// inttypes.h�� ���ο��� �̹� stdint.h�� include �ϰ� �ֱ� ������, inttypes.h�� include �Ѵٸ�, stdint.h�� include �� �ʿ䰡 ����.
	i32 = 1004;
	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32); // ���ڿ��� �ɰ� �� �ִ�.
	printf("me32 = %" PRId32 "\n", i32); // ��ũ�θ� �̿��Ͽ� �ٲ۴�. PRI(print) d(decimal) 32(bit)

	return 0;
}