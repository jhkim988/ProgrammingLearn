#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("%u\n", sizeof(_Bool));
	// 0�� 1�� ǥ���ϸ� �Ǳ� ������ 1bit���� �ϰ�����, �ڷ����� �ּ����� ������ ũ��� 1byte��.
	// ���������ڰ� ���� ������ %d�� ����Ѵ�.(0, 1�� ��µȴ�.)
	_Bool b1;
	b1 = 0; // false
	b1 = 1; // true
	printf("%d\n", b1);

	// stdbool.h
	bool b2, b3;
	b2 = true; // ���������� 1
	b3 = false; // ���������� 0
	printf("%d %d\n", b2, b3); // 1, 0
	
	return 0;
}