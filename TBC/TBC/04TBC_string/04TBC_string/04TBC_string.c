#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct MyStruct
{
	int i; // 4 byte
	float f; // 4 byte
};

int main()
{
	char fruit_name; // store only one character.
	printf("What is your favorate fruit?\n");
	scanf("%c", &fruit_name); // be careful with &
	printf("You like %c!\n", fruit_name);

	char fruit_name_modi[40]; // 1byte ��������� 40�� Ȯ��
	printf("What is your favorate fruit?\n");
	scanf("%s", fruit_name_modi); // %s, & ����
	printf("You like %s!\n", fruit_name_modi);

	// 1. sizeof basic types
	//sizeof�� ��ȯ���� unsigned
	int a = 0;
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);

	// �ٸ� �ý��ۿ��� sizeof()�� unsigned int ���� �ٸ� ���� ��ȯ�� ���� �����Ƿ�...
	size_t int_size4 = sizeof(a);
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4); // ���������� %zu
	printf("Size of float type is %zu bytes.\n", float_size);


	// 2. sizeof arrays
	int int_arr[30]; // int_arr[0] = 1024; ... // �迭���� �迭�� �����̸�(int_arr)�� 30���� �޸� ������ ��ǥ�ϴ� �޸� �ּҸ� �ǹ��ϴµ�, �װ��� �� ���ּҴ�.
	int* int_ptr = NULL; // �ּҸ� ���� �� �ִ� ���̸� ���´�. � �ּҸ� �������� ���߿�(�Ʒ�����) ��������. �����Ҵ�
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ... malloc = memory allocation

	printf("Size of array = %zu bytes.\n", sizeof(int_arr)); // 30�� * 4����Ʈ = 120, �ּ��� size�� ������ �� �ƴѰ�?
	printf("Size of array = %zu bytes.\n", sizeof(int_ptr)); // �ּҸ� ���� ������ ������(4)�� ���´�.

	// 3. sizeof character array
	char c = 'a';
	char string[10]; // maximally 9 character + '/0' (null character) // C������ ���ڿ��� ������ �� �������� null character�� �׻� �����Ѵ�.

	size_t char_size = sizeof(char); // 1
	size_t str_size = sizeof(string); // 10

	// 4. sizeof structure
	printf("%zu\n", sizeof(struct MyStruct)); // 8

	return 0;
}