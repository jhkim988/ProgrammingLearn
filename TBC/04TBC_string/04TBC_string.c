#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592f

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen and more
#include <inttypes.h> // intmax_t

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


	// ���ڿ��� �޸𸮿� ����Ǵ� ����
	// ���� �ϳ�: 4byte
	// ������ �迭: 4byte * �迭�� ũ��
	// ���� �ϳ�: 1byte
	// ������ �迭: 1byte * �迭�� ũ��
	// ���ڿ��� �������� ����� ǥ���ϱ� ���� �������� \0�� ����.

	int int_arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // �迭�� �ʱ�ȭ �� �� {}�� �̿��Ѵ�. 40byte
	printf("%i %i %i\n", int_arr1[0], int_arr1[1], int_arr1[9]);
	// printf("%i\n", int_arr[10000]); // exited code -1037... 0�� �ƴϴ�

	char str1[10] = "Hello"; // Hello\0
	char str2[10] = { 'H', 'i' };

	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]);

	//char str3[10] = "Hello, World!"; // array size is not enough
	char str3[20] = "Hello, \0World!"; // null character�� �߰��� �־��..
	printf("%s\n", str3); // \0�� ������ ����� ����ȴ�.
	
	for (int i = 0; i < 20; i++)
	{
		printf("%hhi ", str3[i]); // �����δ� �迭�� ���� ����� �ִ�.
	};
	printf("\n");

	// strlen() �Լ�
	char str1_len[100] = "Hello";
	char str2_len[] = "Hello"; // �����Ϸ��� �˾Ƽ� ũ�⿡ �°� ������ �Ҵ����ش�.
	char str3_len[100] = "\0";
	char str4_len[100] = "\n";

	printf("%zu %zu\n", sizeof(str1_len), strlen(str1_len));
	printf("%zu %zu\n", sizeof(str2_len), strlen(str2_len));
	printf("%zu %zu\n", sizeof(str3_len), strlen(str3_len));
	printf("%zu %zu\n", sizeof(str4_len), strlen(str4_len));

	char *str5_len = (char*)malloc(sizeof(char) * 100); // sizeof�� ������ ���� ��ü�� ������(�ּ��� ������)
	str5_len[0] = 'H';
	str5_len[1] = 'e';
	str5_len[2] = 'l';
	str5_len[3] = 'l';
	str5_len[4] = 'o';
	str5_len[5] = '\0';
	printf("%zu %zu\n", sizeof(str5_len), strlen(str5_len));


	// ��ȣ�� ����� ��ó����
	// define PI 3.141592f
	// PI ��� 3.141592f�� �ٲٰ� �������Ѵ�.

	// define ���� const�� ����Ͽ� symbolic constant�� �̿��ϴ� ���� �����Ѵ�.
	// const float pi = 3.141592f;
	float radius, area, circum;

	printf("Input radius\n");
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = 2.0f * PI * radius;
	printf("Area is %f.\n", area);
	printf("Circumference is %f.\n", circum);


	// Manifest Constants(����� �����)
	// 1. #define�� �̿��Ͽ�..
	// 2. <limits.h>�� �ִ� INT_MAX, ...
	// 3. <float.h>�� �ִ� FLT_MAX, ...
	// 4. CHAR_BIT char�� �� bi����... etc

	// printf �Լ��� ��ȯ������
	// printf("���� ���ڿ�", ������1, ������2, ...);
	// %[flags][width][.precision][length]specifier
	printf("%+10.5hi\n", 256);

	// %a, %A: �ε� �Ҽ�����, 16����, p(P)-ǥ���
	// %g, %G: ���� ���� %e�� %f ��� (������ -4���� �۰ų� ���е����� ũ�ų� ���� ��쿡�� %e ���)
	// %p: ������
	// %u %x %X: ��ȣ�� ����.	

	double d = 3.141592653589793238462643383279502884197169399375105820974944; // 8byte�� ���� �� �ִ� �縸 ������� �� ���Ĵ� �����Ϸ��� �߶��ش�.
	printf("%c\n", 'A');
	printf("%s", "I love you.\n");
	printf("Even if there's small chance, \
we owe this to everyone who's not in this room to try.\n");
	
	printf('\n');
	printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX);
	printf("%u %u %u\n", 1024, -1, UINT_MAX);

	printf("\n");
	printf("%f %f %lf\n", 3.141592f, d, d); // printf ���ο��� float�� ����� �� double�� �ٲ������. ��� double�� ����ϴ� �� ���� %lf���� l�� ���ð� �ȴ�.
	printf("%a %A\n", d, d);
	printf("%e %E\n", d, d);

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89);
	printf("%G %G\n", 123456.789, 1234567.89);
	printf("%g %g\n", 0.00012345, 0.000012345);
	printf("%G %G\n", 0.00012345, 0.000012345);

	printf("\n");
	printf("%o\n", 9);
	printf("%p\n", &d); // pointer-of operator

	printf("\n");
	printf("%x %X\n", 11, 11);
	printf("%%\n", d); // d is ignored.

	printf("\n");
	printf("%9d\n", 12345); // 9ĭ���� ä���(��ĭ)
	printf("%09d\n", 12345); // 9ĭ���� ä���(0)
	printf("%.2f\n", 3.141592); // �Ҽ��� 2�ڸ���
	printf("%.20f %.20lf\n", d, d); // double Ÿ���� ���� ���ϴ� ���ڴ� ©����.

	printf("\n");
	int n_printed = printf("Counting!"); // ���� ���� ��ȯ�Ѵ�.
	printf("%u\n", n_printed); // 9


	// ��ȯ �������� ���ľ�
	// %[flags][width][.precision][length]specifier
	// +: ����� ���� + ��ȣ�� �ٿ��ش�.
	// 10: �ּ� 10�ڸ�
	// .5: ���е�
	// h: short
	printf("%+10.5hi", 256);

	// flags: - + (space) # 0
	// -: - flags�� ������ �������� ���̰�, ������ ���������� �ٿ��� ����Ѵ�. (width�� �Բ� ��ߵȴ�.)
	// +: ����ϋ��� + ��ȣ�� �ٿ��ش�.
	// (space): ����� ���� + ��ȣ ��� ��ĭ�� �ִ´�.
	// #: 8����, 16�������� 0, 0x�� �ٿ��ش�.(o, O, x, X specifier ����� ��) a, A, e, E, f, F, g, G������ ����ϰ� �۵��Ѵ�.
	// 0: width�� �Բ� ������� �� ���� �ڸ��� 0���� ä���.

	// width: (number), *
	// (number): ������ ���ڰ� �ּ� ���̰� �ȴ�.
	// *: ����ڰ� *�� ���� ���ڸ� ���� �� �ְ� ���ش�.

	// .precision: (number), *
	// (number): ������ ���ڸ�ŭ ���е��� �������ش�. ���ڰ� �����ϸ� 0���� ä���ش�.
	// *: ����ڰ� *�� ���� ���ڸ� ���� �� �ְ� ���ش�.

	// length: hh, h, l, ll, j, z, t, L
	// length�� ������ Ÿ���� �����̴�.

	printf("%10i\n", 1234567);
	printf("%-10i\n,", 1234567);
	printf("%+i %+i\n". 123, -123);
	printf("% i \n% i\n", 123, -123);
	printf("%X\n", 17);
	printf("%#X\n", 17);
	printf("%05i\n", 123);
	printf("%*i\n", 7, 456);

	printf("\nPrecision\n");
	printf("%.3d\n", 1024); // 1024
	printf("%.5d\n", 1024); // 01024
	printf("%.3f\n", 123456.1234567);
	printf("%.3f\n", 123456.12345);
	printf("%10.3f\n", 123.45678);
	printf("%010.3f\n", 123.45678);
	printf("%.5s\n", "ABCDEFGHIJKLMN"); // ABCED ���� ����
	printf("%.s\n", "ABCDEFGHIJKLMN"); // %0.s

	printf("\nLength\n");
	printf("hhd %hd %d\n", 257, 257, 257); // OverFlow
	printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL); // OverFlow, long long, x86�̸� �ٸ��� ���´�.


	// printf() �Լ��� ���ڵ��� �ؼ��ϴ� ����
	float n1 = 3.14f;
	double n2 = 1.234;
	int n3 = 1024;

	// 1. n1, n2, n3�� �������� �ű��. printf������ float�� double�� ��ȯ�Ͽ� 4byte���� 8byte�� �þ��.
	// 2. %d %d %d���� ��� ������ 4byte�̹Ƿ�, �� 12byte�� �д´�. �׷��� n1�� �� �ɰ��� %d �� ���� ���� n2�� ������ ������ %d�� ���� �ȴ�. n3�� ������ �ʴ´�.
	printf("%f %f %d\n\n", n1, n2, n3);
	
	// Note the warnings in output window
	printf("%d %d %d\n", n1, n2, n3); // (4, 4, 4) N N N
	printf("%lld %lld %d\n\n", n1, n2, n3); // (8, 8, 4) N N Y
	printf("%f %d %d\n\n", n1, n2, n3); // (8, 4, 4) Y N N
	printf("%f %lld %d\n\n", n1, n2, n3); // (8, 8, 4) N N Y 
	

	// scanf() �Լ��� ����
	// *: �����Ѵ�.
	// ����: �Է� ���� �ִ� ����

	// scanf���� double�� �Է� ���� ���� printf�� �ٸ��� %lf�� �̿��ؾ��Ѵ�.
	// ��ĭ�� ������ ��������� ������ �� �ܾ�� ���� �� �ִ�.
	int i_scanf;
	float f_scanf;
	char str_scanf[30];
	scanf("%d %f %s", &i_scanf, &f_scanf, str_scanf); // �迭�� �Է� ���� �� &�� ������ �ʴ´�.
	printf("%d %f %s\n", i_scanf, f_scanf, str_scanf);

	char c_scanf;
	scanf(% c, &c);
	printf("%i\n", c); // blank is 32.. ��ĭ���� �����ϴ� �Ͱ� ����

	// unsignedŸ���� signed�� �Է¹ް� ����Ѵ�.
	// -123�� �Է��ϸ� -123 ����� ��µȴ�.
	// integer�� �Է¹ް� ����߱� ������ ����� ��µȴ�.
	unsigned ui_scanf;
	scanf("%i", &ui_scanf);
	printf("%i\n", ui_scanf);

	unsigned ui2_scanf;
	scanf("%u", &ui2_scanf); // try negative number
	printf("%u\n", ui2_scanf); // overflow
	
	// double�� scanf�� �Է��� �� %lf, printf�� ����� �� %f
	double d_scanf = 0.0;
	scanf("%lf", &d_scanf);
	printf("%f\n", d_scnaf);

	// Width
	char str1_scanf[30];
	scanf("%5s", str1_scanf); // 5���ڱ���, ������ �ڸ���.
	printf("%s\n", str1_scanf);
	
	char c_scanf;
	scanf("%hhd", &c_scanf); // try large numbers
	printf("%i\n", c_scanf);

	int i1_scanf;
	scanf("%i", &i); // try '123ab', '123a456'
	printf("%i\n", i); // ���ڸ� ������ ������ ���� ���ڸ� �־��ش�.

	intmax_t i2_scanf;
	scanf("%ji", &i2_scanf);
	printf("%ji", i2_scanf);

	// Regular characters
	int a_scanf, b_scanf;
	scanf("%d,%d", &a_scanf, &b_scanf); // %d,%d // ","�θ� ���еȴ�. �ٸ� ��ȣ, ���ĺ��� ���� ���� �ִ�.
	printf("%d, %d\n", a_scanf, b_scanf);

	// ������� �޴� �ٸ� �Լ� (�� ���ھ�, Ȥ�� �ٸ� ���Ϸκ��� ...)
	// scanf �Լ��� return �� = �Է¹��� ���� ����

	// * Modifier for printf()
	int i3_scanf = 123;
	int width_scanf = 5;
	printf("Input width: ");
	scanf("%d", &width_scanf);
	printf("%*d\n", width_scanf, i3_scanf);
	
	// * Modifier for scanf()
	int i4_scanf;
	scanf("%*d%*d%d", &i4_scanf); // *�� ������ ���ð� �ż�, �Է��� �� ���� ������ *�� ���� ������ %d�� &i4_scanf�� ����.
	printf("Your thrid input = %d", i4_scanf);

	return 0;
}