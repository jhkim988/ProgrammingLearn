#include <stdio.h>

void say_hello(void); // �Լ� ����, prototyping, function declaration

int main()
{
	// escape sequence: \n, \", \s, \t, \a(�����) ...
	printf("\"The truth is ... \nI am Ironman.\"\n");

	int x, y, z; // ������ ������ �� �ʱ�ȭ���� �ϴ� �� ����.
	x = 1;
	y = 2;
	z = x + y;

	/* print formatted
	printf �Լ��� ���� 
	%i: ����  %d: ������
	*/

	printf("%i + %i = %i\n", x, y, z);

	say_hello(); // ���� �� ���¿��� �Լ��� ȣ���Ѵ�. �׷��� �������� ���� ������ ��ŷ�ϴ� �������� �Լ� definition�� ã�� �������ش�.

	return 0;
}

// debugger �����
// break point�� ���� ������ �����Ų��.
// Autos�� �������� ��� ��ȭ�ϴ��� ���캻��.

void say_hello(void) // function definition
{	// say_hello�� ȣ���ϱ� ���� �Լ��� ����������Ѵ�.
	int x = 1;
	x = 10;
	printf("Hello, World!\n");
}