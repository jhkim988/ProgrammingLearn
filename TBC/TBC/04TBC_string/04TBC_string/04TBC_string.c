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

	char fruit_name_modi[40]; // 1byte 저장공간을 40개 확보
	printf("What is your favorate fruit?\n");
	scanf("%s", fruit_name_modi); // %s, & 주의
	printf("You like %s!\n", fruit_name_modi);

	// 1. sizeof basic types
	//sizeof의 반환값이 unsigned
	int a = 0;
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);

	// 다른 시스템에서 sizeof()가 unsigned int 말고 다른 값을 반환할 수도 있으므로...
	size_t int_size4 = sizeof(a);
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4); // 형식지정자 %zu
	printf("Size of float type is %zu bytes.\n", float_size);


	// 2. sizeof arrays
	int int_arr[30]; // int_arr[0] = 1024; ... // 배열에서 배열의 변수이름(int_arr)은 30개의 메모리 공간을 대표하는 메모리 주소를 의미하는데, 그것의 맨 앞주소다.
	int* int_ptr = NULL; // 주소를 적을 수 있는 종이만 갖는다. 어떤 주소를 적을지는 나중에(아래에서) 정해진다. 동적할당
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ... malloc = memory allocation

	printf("Size of array = %zu bytes.\n", sizeof(int_arr)); // 30개 * 4바이트 = 120, 주소의 size가 나오는 것 아닌가?
	printf("Size of array = %zu bytes.\n", sizeof(int_ptr)); // 주소를 적는 공간의 사이즈(4)가 나온다.

	// 3. sizeof character array
	char c = 'a';
	char string[10]; // maximally 9 character + '/0' (null character) // C언어에서는 문자열을 저장할 때 마지막에 null character를 항상 저장한다.

	size_t char_size = sizeof(char); // 1
	size_t str_size = sizeof(string); // 10

	// 4. sizeof structure
	printf("%zu\n", sizeof(struct MyStruct)); // 8

	return 0;
}