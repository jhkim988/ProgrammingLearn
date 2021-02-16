#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	unsigned int i = 0;

	// sizeof() �Լ��� �ڷ����� ���� �ְų�, �������� ������ �޸� ����� �˷��ش�.
	sizeof(unsigned int); // ���콺�� ��� ������ ���� �����Ϸ��� �˷��ִ� ���� �ƴ϶� visual studio ���հ���ȯ���� �˷��ִ� ���̴�.
	sizeof(i);

	printf("%u\n", sizeof(unsigned int)); // sizeof()�� unsigned Ÿ���� ���� �����ϱ� ������ %u�� ����ؾ��Ѵ�.
	printf("%u\n", sizeof(i));
	
	// �������� ������ �տ� 0b�� ���ش�. C���� ǥ���� �ƴ�����, �����Ϸ��� ������ ���ش�.
	unsigned int max_unsigned1 = 0b11111111111111111111111111111111;
	unsigned int max_unsigned2 = UINT_MAX;
	printf("%u\n", max_unsigned1);
	printf("%u\n", max_unsigned2);
	
	printf("%d\n", max_unsigned1); // %u�� �ƴ� %d�� ������ -1�� ���´�.
	
	unsigned int example = 1024;
	printf("%d\n", example); // %u�� �ƴ� %d�� �־�����, 1024�� ����� ���´�.

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
	char buffer[33]; // ���ڸ� 33�� �޸𸮿� ������ ������ �� �ִ� �迭�� ����, 4����Ʈ * 8��Ʈ = 32��Ʈ, 33���� ����ϴ� ������ ���߿�...
	_itoa(overflow_unsigned, buffer, 2); // overflow_unsigned�� ��� �ִ� ���ڸ� 2������ �ٲ��ش�.

	// print decimal and binary
	printf("decimal: %u\n", overflow_unsigned);
	printf("binary: %s\n", buffer); // 2���� ���·� ������ش�.

	// 11111111 11111111 11111111 11111111 + 1
	// 1 00000000 00000000 00000000 00000000

	unsigned int underflow_unsigned = 0 - 1;
	printf("%u\n", underflow_unsigned); // 11111111 11111111 11111111 11111111 

	return 0;
}  