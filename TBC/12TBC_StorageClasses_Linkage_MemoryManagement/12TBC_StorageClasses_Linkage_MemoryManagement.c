#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // srand(), malloc(), free()
#include <time.h> // time()
#include "my_rand.h"
#include "my_constant.h"
#include <Windows.h>

// 12.3
void testLinkage();
// translation unit
int el; // file scope ������ ���α׷� ��ü���� ����� �� �ֱ� ������ ����������� �θ���.
static int il; // static: ������ ������ ���� �������� ���ѵȴٴ� �ǹ�, �ٸ� ���� scope���� ����� �� ����.
void count()
{
	int ct = 0; // �Լ��� ������ �޸𸮰� �������.
	printf("count = %d %p\n", ct, &ct);
	ct++;
}
void static_count()
{
	static int ct = 0; // ���α׷��� ���۵ż� ���� ������ �޸𸮿� ������ �ȴ�. �ʱ�ȭ�� �� ���� �̷������.
	// ���ÿ� ������� �ʰ� ������/BSS�� ����ȴ�.

	// static �������� - �����ϸ鼭 �ʱ�ȭ vs ���� �Ŀ� �� �Ҵ��� ���̰� �ִ�.
	// ���� �� �� �Ҵ��� �ϰ� �Ǹ� �Լ��� �ٽ� ����� �� �ٽ� 0�� �Ҵ��ع����� �����̴�.
	//static int cp;
	//cp = 0;

	printf("static count = %d %p\n", ct, &ct);
	ct++;
}

// 12.5
void func_auto(int k)
{
	int i = k * 2;
	printf("i %lld\n", (long long)&i);
}

// 12.7
void count_caller()
{
	count();
}
void static_count_caller()
{
	static_count();
}

// 12.8
int g_int = 0; // static �������� �ʱ�ȭ�� ���ϸ� 0���� �������� ���� �ϴ� ���� ����.
double g_arr[1000];
// constant expression
int x = 5; 
int y = 1 + 2;
size_t z = sizeof(int);
//int x2 = 2 * x;// Error, x is not constant variable.
void func_sec(); // ������ ���ش�.

//int func_static(static int i) // warning (Error in GCC)
//{
//
//}
//int* count_pointer()
//{
//	int ct = 0; // �Լ��� ������ �޸𸮰� �������.
//	printf("count = %d %p\n", ct, &ct);
//	ct++;
//	return &ct;
//	// �����͸� �����Ѵٴ� ���� �޴� �ʿ��� �����͸� �̿��� �۾��� �ϰ� �ʹٴ� �ǹ�, �׷��� �Լ��� �����鼭 �޸𸮸� ��ȯ�Ͽ� ����� �� ���� ������ warning
//}
//int* static_count_pointer()
//{
//	static int ct = 0;
//	printf("static count = %d %p\n", ct, &ct);
//	ct++;
//	return &ct; // ���������� �ʴ´�.
//}


// 12.9
//static int g_static = 123; // ���� �������� ����� �� �ִ� ��������

// 12.19
DWORD WINAPI ThreadFunc(void* data)
{
	int n = 1;
	Sleep(1000);

	// acnt += n;
	printf("Printing from Thread \n");
	return 0;
}
int main()
{
	// 12.1 �޸� ���̾ƿ�
	// ����: ���α׷��� �Ϻο��� ū �޸𸮰� �ʿ��� ���. ��Ͽ� �׿��� ������ ������ ���� �޸𸮿� �ö󰣴�.
		// main�Լ��� ���� ���� ����ż� ���� �ʰ� ������ ������ ���⿡ ���������� ���� �����ϸ� ���ÿ� ��� ���� �ְ� �ȴ�.
		// �ٸ� �Լ��� ���� �ű⼭ �ʿ��� ��ɸ� �����ϰ� �޸𸮸� ��ȯ���ִ� ���� ����.
		// �ʿ��� �޸𸮸� ������ �� �� �̸� �˰� �ֱ� ������ ���ÿ� ����� ���������� �ӵ��� ������.
	// ��������: ���ð� �� ������ ������. ���ð� ���� ���ÿ� ����ϴ��� �ü������ �����ּҰ����� ����ϱ� ������ �浹�� ���� �ʴ´�.
		// �� �������� �ü���� �� �� ��ġ�� ������ �������� �ȴ�.
	// ��: �ʿ��� �޸��� ũ�⸦ �̸� �� �� ���� ���
		// ����, ���ͳ�, ����ڷκ��� scanf�� ���� �д� ��� �ʿ��� �޸��� ũ�⸦ �̸� �� �� ����.
		// ������ �� �� �̸� �޸� ����� �� �� ����. �� ������ ����Ѵ�.
		// �޸𸮸� ����ϰ� ���� �ݳ��� �ؾ��Ѵ�.
	// ����/���� ����: ���α׷� ��ü���� ��� ���Ǵ� ������ �޸𸮿� �� �� �ö���� ���α׷��� ���� ������ �޸𸮿� �־�� �Ѵ�.
	// ���α׷� �ڵ�: TEXT Segment(Read Only, �����Ϸ��� �ϸ� �ü���� Run-time ���� �߻�) �޸𸮿� �� �� �ö���� ���α׷��� ���� ������ �޸𸮿� �־�� �Ѵ�.


	// 12.2 ��ü(Object) �ĺ���(Identifier) L-value R-value
	// object: ���� ������ �� �ִ� �޸��� ��. ��ü ���� ���α׷��ֿ����� �� Ȯ��� ����
	// identifier: ����, �Լ�, ��ũ��, �ٸ� �͵��� �̸�

	//int var_name = 3;
	//int* pt = &var_name;
	//*pt = 1; // *pt is not an identifier. *pt designates an object.

	//int arr[100]; // arr is an identifier. arr is not object. arr�� �޸� ������ ���� ������ �ʴ�.
	//arr[0] = 7;

	//// L-value, R-value
	//// L-value: expression referring to an object. left side of an assignment.
	//// R-value: right side, variable, constant, expressions

	//var_name = 3; // modifiable L-value, �޸� ������ �����Ѵ�.
	//int* ptr = arr;
	//*pt = 7; // *pt is not an identifier but an modifiable L-value expression.

	//int* ptr2 = arr + 2 * var_name; // R-value
	//*(arr + 2 * var_name) = 456; // *(...) L-value

	//const char* str = "Constant string"; // str is a modifiable L-value
	//str = "Second string"; // "Constant string" = "Second String" // impossible
	////str[0] = 'A'; // Error
	////puts(str);

	//char str2[] = "String in an array";
	//str2[0] = 'A';
	////puts(str2);

	
	// 12.3 ������ ����(Scope)�� ���� ����(Linkage), ��ü�� ���� �Ⱓ(duration)
	// variable scopes(visibility)
	//int local = 1234; // �ٸ� �Լ�(��)������ ����� �� ����.(�� ���� ����.)

	// C���� ������ ���� 4����
	// ��, �Լ�, �Լ��� ������Ÿ��, ����(��� �Լ��� �ٱ� ����, global variable)
	// �ʱ�ȭ ���� ���� ����/���������� ������ �� �� BSS������ ����Ǹ�, 0���� �ʱ�ȭ�ȴ�.
	// ������Ÿ�� ������ scope�� ������Ÿ���� ����, ���� �ʾƵ� ������ VLA�� ���̸� ��������� �ϱ� ������ �ĺ��ڸ� ������ �� ����.
	// goto���� ���� ��𼭵� �����Ͽ� ������ �� �ִ�.

	// ������ �������� �ϴ� �ּ� �����̴�.
	// �������� ���� �ؼ� ������� ������Ʈ ���ϵ��� ������ �ִ� �� ��Ŀ��.

	//el = 1024;
	//testLinkage();
	//printf("%d\n", el);

	// duration �޸��� ���� �Ⱓ
	// static storage duration - ���α׷��� �����ؼ� ���� ������ static�ϰ� �޸� ������ �ӹ�(������ static Ű����(linkage type)�� �ٸ���.)
	// automatic storage duration - ��������(���� �޸�)
	// allocated storage duration - �����Ҵ�
	// thread storage duration - ��Ƽ������ 

	//count();
	//count();
	//static_count();
	//static_count();


	// 12.4 ���� ������ �ټ� ���� �з�(Five Storage Classes)
	// static�� static�� �ƴ� �� �� ������ ���� ���� �ִ�.
	// Automatic: ��������. ���ӱⰣ�� ������ ���α׷��Ӱ� ������ �������� �ʰ� �ڵ����� ���ش�.
	// Register: ��������ó�� ��������� register Ű���带 �տ� �ٿ��ش�. cpu �ȿ� �������Ͱ� �ִ�. ó���ӵ��� ������.
		// �ֱٿ��� �����Ϸ��� ��������, register ������ �ƴϿ��� �������ͷ� �÷��ֱ⵵ �Ѵٰ� �Ѵ�.
		// �ǹ����� ������ ó���ϰ� ���� ��쿡�� �������� ���� ĳ��, ����ó��, �л�ó��, GPU���� ���� ����ϴ� ���� ����.
	// static with internal linkage(������ ���ο���) ����: ���� ��, ���� ������ ���ο����� ���, ��� �Լ��� �ۿ��� static Ű���� ���
	// static with external linkage(������ �ܺο���) ����: ���� ��, ���� ������ �ܺηε� ���� ����, ��� �Լ��� ��
	// static with no linkage(������, �������) ����: ��� ��, ���� ����, ��� �ȿ��� static Ű���� ���
		// ������ �Ǵ� BSS
		// ���ӱⰣ ������
	// �Ҵ� �޸�(�ĺ��� ����, 5������ ���Ե��� ����): ��, ���ӱⰣ�� ���α׷��Ӱ� ����, �ü���� ��û�Ͽ� ����


	// 12.5 �ڵ� ����
	// ���� �Ⱓ�� �ڵ������� �����ȴ�.
	// ���α׷� ��ü���� ��� ����� �޸𸮰� �ƴ϶��, ��� ������ ���� �ʿ䰡 ����.
	// scope�� �� ��������Ѵ�.
	// ������ ��� �����ϴ°� �ƴϱ� ������ linkage�� ������ ���� ����.

	// Automatic storage class
	// Automatic storage duration, Block scope, No linkage
	// Any vaiable declared in a block or function header

	//auto int a; // �ڵ������� ������ �� auto�� ���δ�. auto�� �� �ٿ��� �Ȱ����� ���������� ���� ����.. C++������ ������ �ٸ� Ű�����̴�.
	//a = 1024; // �ʱ�ȭ�� �� ������Ѵ�. BSS�� �ִ� ������������ �����Ϸ��� 0���� �ʱ�ȭ ���ش�. �ڵ��������� ���ÿ� ���� ���Դ� ����ϰ� ����ϱ� ������ �����Ϸ��� �ڵ����� �ʱ�ȭ������ �ʴ´�.
	//printf("%d\n", a);
	//auto int b = a * 3;

	//int i = 1;
	//int j = 2;
	//printf("i %lld\n", (long long)&i);

	//{
	//	// ������ �ٲ�� ���� �̸��� ������ ���� �� �ִ�.
	//	// ���� ���ʿ��� ����� ���� �ǹ��Ѵ�.
	//	int i = 3; // name hiding
	//	printf("i %lld\n", (long long)&i);

	//	// j is visible here
	//	printf("j = %d\n", j);

	//	// ������ ������ ���� �ȿ��� ����� i�� �������. ����(�޸�)���� ����������.
	//}
	//printf("i %lld\n", (long long)&i); // which i ?

	//// stack frame: �Լ� ��ü���� �ʿ��� �޸�

	//for (int m = 1; m < 2; ++m)
	//	printf("m %lld\n", (long long)&m); // ���� ��� m�� scope�� �� �������

	//func_auto(5); // �Լ��� �����ϸ� ���� ������ ��ü�� �ٲ�������. �Լ� ������ main�Լ��� ������ ����� �� ����.
	//// �Լ��� ������ �Լ� �ȿ��� ����� �޸𸮸� ��� ��ȯ�ϱ� ���ؼ�

	//for (int m = 3; m < 4; ++m)
	//{
	//	printf("m %lld\n", (long long)&m);
	//}


	// 12.6 �������� ����
	// �������Ͷ�? CPU�� ���� �ִ� �ӽ� �۾�����
	// CPU�� �޸𸮴� �ٸ� ��ǰ, ���κ����� ������ ���ؼ� ������ �ְ� �޴´�.
	// �������ʹ� �޸�ó�� �����͸� ���� ���� �� �ִ�. CPU�� �Ϻ��̱� ������ ������ �۵��Ѵ�.

	// ���ӱⰣ, ������ �ڵ������� ����.
	// �޸� ������ ��������(�Ǵ� ����)�� �Ѵ�.
	// �����Ϸ��� �� �������Ϳ� ��ġ�������� �ʴ´�.
	//register int r;
	//r = 123;

	// register ������ address operator &�� ����� �� ����.
	//printf("%p\n", &r);
	//int* ptr = &r;


	// 12.7 ��� ������ ��������
	// ���α׷��� �����ϰ� ���� ������ �޸𸮿� ��� �ö� �ִ�.
	// ��� �ȿ����� ����� �� �ִ�.(visible)
	// Linkage�� ����. ������ ���� ���� ���������� ������ �� �ִ�.

	//count(); // main�Լ����� ����ȣ��
	//count();
	//count_caller(); // count_caller()�Լ��� ���� ȣ��

	//static_count();
	//static_count();
	//static_count_caller();

	// �Լ��� �Ķ���Ϳ� static ������ �ִ´ٸ�
	// visual studio - warning: Bad storage class
	// gcc - Error
	// �Լ��� ����� ���� ���ο� ���� �������� �����ȴ�.
	// �Լ��� �Ķ���ʹ� �Լ��� ȣ��� �� �޸𸮸� �����޴´�.
	// �Ķ���͸� static�� �޸� ������ �ִ� ���� �̻��ϴ�.

	// �Լ����� �����͸� ������ ��...
	// count_pointer(), static_count_pointer();


	// 12.8 ���� ������ �ܺο��� external linkage
	// �޸� ��ġ: ������/BSS
	// ���ӱⰣ: static(���α׷� ���ۺ��� ������)
	// ����: ���� ��
	// ���� ����: ���� ����(����)�� �ܺηε� ���� ����
	// ���� ���: ��� �Լ��� �ۿ� ����
	// �����Ϸ��� ������ ����(c����, �������)�� ���� �������� �� ��Ŀ�� ������ �Ŀ� ���������� �����.
	// �����Ӹ� �ƴ϶� �Լ��� �������ش�.

	// File scope, External linkage
	// External storage class
	// External variables

	// file scope ������
	// �� ���� �ȿ��� ��� �Լ������� ����� �� �ִ�.

	// �̸��� ���� ���������� ����ٸ�
	//int g_int = 123; // �� scope������ static ���� g_int�� name hiding�� �ȴ�.

	// referencing declaration
	//extern int g_int; // �� scope�� �ٱ��� �ִ� g_int�� ������Ѵ޶�� �ǹ�. ���� �����̹Ƿ� ���� ��Ŀ�� �������� �ʿ䰡 ����.

	//fun_sec();


	// 12.9 ���� ������ ���� ���� static variables with internal linkage
	// ���� ����(����) ���ο����� ���
	// ��� �Լ� �ۿ��� static Ű���� ���


	// 12.10 ������ ���� ���� �з� ��� ����
	// Automatic - ������, ��������
	// Register - ������, regester Ű����, & ������ ��� �Ұ�
	// Static internal linkage - ��� �Լ� �ۿ���, static Ű����
	// Static external linkage - ��� �Լ� �ۿ���, �ܺο��� extern Ű����
	// Static no linkage - �� �ȿ���, static Ű����


	// 12.11 �Լ��� ���� ���� �з�
	// Storage Classes and Functions
	// - Functions exteranl(by default) or static
	// - A function declaration is assumed to be externs

	// �Լ��� ���α׷��� ���۵Ǹ� �ε��ǰ�, �޸𸮿� ��� �ӹ�����.
	// �Լ� �����ͷ� �� �ּҸ� �� �� �ִ�.
	// �Լ��� ������ �⺻������ extern�̴�.

	// static Ű���带 ���̸� ��� �Ǵ���?
	// LNK ERROR, static�� ���̸� �ش� ���� �ȿ����� ����� �� �ִ�.
	// ������Ÿ�Կ��� static�� �ٿ��൵ �ش� ���� �ȿ����� ����� �� �ִ�.


	// 12.12 ���� ������ ��� ����� ����
	//rand();
	// 0 ~ RAND_MAX (typically INT_MAX)
	// defined in stdlib.h

	//srand(2); // random seed setting
	//srand((unsigned int)time(0));
	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", rand()); // ������ ������ ���� �� ����.
	//}

	//unsigned int next = (unsigned int)time(0);
	//for (int i = 0; i < 10; ++i)
	//{
	//	next = next * 1103515245 + 1234; // ���糭��
	//	next = (unsigned int)(next / 65536) % 32768;
	//	printf("%d\n", (int)next);
	//}

	//printf("\n*** My Try ***\n");
	//my_srand(next);
	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", my_rand());
	//}

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", my_rand() % 6 + 1);
	//}


	// 12.13 �޸� ���� �Ҵ� Dynamic Storage Allocation
	// �����Ҵ� = ������ Ÿ�ӿ��� �޸� �Ҵ��� �������� ���� �ƴ�, ��Ÿ�ӿ��� �����Ǵ� ��
	// ���� �Ҵ� �޸𸮴� �ν��ڰ� ����.(�����͸� �������� ������ �̸��� ����.)
	// ���� Storage Classes�� ���Ե��� �ʴ´�. (�� �޸𸮿� ����.)
	// ���α׷��Ӱ� �ü������ ��û�Ѵ�.
	// �� �� �Ҵ� ������ �� �޸𸮿� ��� �����Ѵ�.
	// ���α׷��Ӱ� �޸𸮸� �ݳ��ϰų� ���α׷��� ������ �޸𸮰� ��ȯ�ȴ�.

	// �ʿ��� �޸��� ũ�⸦ �̸� �� �� ���� ���(������ Ÿ�ӿ� �� �� ����, ��Ÿ�ӿ� �� �� �ִ� ���)
	// �ü���� ���� �ּҰ����� �̿��Ͽ� ��ǻ���� �޸𸮸� ����� ����� �� �ֵ��� ���ش�.
	// malloc()�� ���� �޸𸮸� �Ҵ� �ް� free()�� ���� �ݳ��ؾ� �Ѵ�.

	//// ���ÿ� ����Ǵ� �͵�
	//float x;
	//char str[] = "Dancing with a Star";
	//int arr[100];

	//double* ptr = NULL;
	//ptr = (double*)malloc(30 * sizeof(double)); // �� ����Ʈ �޸𸮸� ��û����, ���� ����ȴ�. �����ʹ� ����(auto)�� ����ȴ�.
	//// ������ ������ �Ҿ������(scope���� �����ų�..) �� �޸𸮿��� �Ҵ� ���� �޸𸮰� ����������, �������� ���ϴ� ��Ȳ�� �����.
	//// ��� �����Ҵ��� �޴ٰ� ���� ������ ������ �����.

	//// malloc()�Լ��� void Ÿ�� �����͸� �����Ѵ�.(��û�� ����Ʈ ��ŭ�� �޸�, �װ��� ù �ּ�)
	//// � Ÿ���� ���� ���� �ƴ϶�, �׳� �����ϰ� �ּҸ� ��ȯ�Ѵٴ� �ǹ�
	//// void Ÿ�� �����͸� �����ϱ� ������ ����ڰ� Ÿ�� ĳ����(�������� (double*))�� ������Ѵ�.
	//// void*: generic pointer��� �ϱ⵵ �Ѵ�.
	//// free(): deallocates the memory
	//// ����ȯ�� �ؼ� Ư���� �ڷ����� �迭�� ��ó�� ����� �� �ִ�.

	//if (ptr == NULL)
	//{
	//	// �ü���� �Ҵ����� �޸𸮰� ���� ��쿡�� NULL �����͸� �������ش�.
	//	puts("Memory allcation failed.");

	//	//exit(EXIT_FAILURE); // is similar to return 1 in main()
	//	//exit(EXIT_SUCCESS); // is similar to return 0 in main()
	//	// exit�� �̿��ϸ� � �Լ������� ������ ���α׷��� ������ �� �ִ�.

	//	exit(EXIT_FAILURE); // �޸� �Ҵ��� �ȵȴٴ� ���� �ſ� �ɰ��ؼ� ���α׷� ������ ��ƴٴ� �ǹ��̴�. �����ϴ� ���� ����.
	//	// ������ó�� ����Ǹ� �ȵǴ� �͵��� ���� ����ó���� ������Ѵ�.
	//	
	//	// �ʹ� ū ������ ��û���� �� ������ �߻��� �� �ִ�.
	//	// ���� ���α׷��� �����ϰ� �־(�޸𸮸� ����ϰ� �־) ���ӵ� �޸� ������ �Ҵ����� �� ���� �� ������ �߻��Ѵ�.
	//}

	//printf("Before free %p\n", ptr);
	//free(ptr); // ptr�� NULL �����Ͷ�� free�� �ص� �ƹ� �ϵ� �Ͼ�� �ʴ´�.
	//printf("After free %p\n", ptr);

	//ptr = NULL; // optional, �����Ѵ�.
	//printf("Null %p\n", ptr);

	//// �迭ó�� ����� �� �ִ�.
	//int n = 5;
	//ptr = (double*)malloc(n * sizeof(double));

	//if (ptr != NULL)
	//{
	//	for (int i = 0; i < n; ++i)
	//		printf("%f", ptr[i]); // 0���� �ʱ�ȭ������ �ʴ´�.
	//	printf("\n");
	//	
	//	for (int i = 0; i < n; ++i)
	//		*(ptr + i) = (double)i;

	//	for (int i = 0; i < n; ++i)
	//		printf("%2.1f ", ptr[i]);
	//	printf("\n");
	//}

	//free(ptr);
	//ptr = NULL;

	// VLA���� ��
	// visual studio �����Ϸ������� VLA�� �������� �ʴ´�.
	// �����Ҵ� �޸𸮴� ����� �ٲ� �� �ֱ� ������ VLA���� ��ȣ�ȴ�.(�ٸ� ����� ���� �޾ƿ´ٴ� ����)
	// VLA�� automatic duration(���ÿ� �ö󰣴�.)
	// �����Ҵ� �޸𸮴� free()�� �� �� ���� ���� ��� �ӹ��� �ִ�.
	// VLA�� ���� �������� ������ �޴´�. ���� ũ�Ⱑ ū ���̴�.(��� ã�Ⱑ �����.)


	// 12.14 �޸� ����(leak)�� free()�� �߿伺 - ����� ��Ʃ��� ���ܵ��� ����
	// debug -> windows -> show diagnostic tools
	//int* ptr_backup = NULL;
	//printf("Dummy output.\n");

	////for(int k = 0; k < 1000000; ++k) // �޸� ����
	//{
	//	int n = 100000000;
	//	int* ptr = (int*)malloc(n * sizeof(int)); // 381mb.. ptr�� block scope

	//	if (!ptr)
	//	{	// �޸𸮸� �����ϰ� ����ϸ�
	//		printf("malloc() failed\n");
	//		exit(EXIT_FAILURE);
	//	}

	//	for (int i = 0; i < n; ++i)
	//		ptr[i] = i + 1;

	//	printf("%d %d\n", ptr[0], ptr[1]);
	//	ptr_backup = ptr;
	//	//free(ptr);
	//	//ptr = NULL;
	//}
	//// block scope�� �����鼭 ptr ������ ������ ���������, �����Ҵ� malloc���� �Ҵ���� �� �޸𸮴� �״�� �����ִ�.
	//printf("Dummy output.\n");

	//printf("%d %d\n", ptr_backup[0], ptr_backup[1]); // free(ptr)�� �ϰ� �����ϸ� ��Ÿ�ӿ����� ����.


	// 12.15 ���� �Ҵ� �޸𸮸� �迭ó�� ����ϱ�
	//int* ptr = NULL;
	//ptr = (int*)malloc(sizeof(int) * 1);
	//if (!ptr) exit(1);
	//*ptr = 1024 * 3;
	//printf("%d\n", *ptr);
	//free(ptr);
	//ptr = NULL;

	//int n = 3;
	//int* ptr = (int*)malloc(sizeof(int) * n);
	//if(!ptr) exit(1);

	//ptr[0] = 123;
	//*(ptr + 1) = 456;
	//*(ptr + 2) = 789;

	//free(ptr);
	//ptr = NULL;

	//int row = 3, col = 2;
	//int(*ptr2d)[2] = (int(*) [2])malloc(sizeof(int) * row * col);
	////int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col); // VLA
	//// �̷��� 2���� �迭�� ����� ���� 1���� �迭�� 2���� �迭ó�� ����ϴ� ���� ����.
	//if (!ptr2d) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr2d[r][c] = c + col * r;
	
	//int row = 3, col = 2;
	//int* ptr = (int*)malloc(sizeof(int) * row * col);

	//if (!ptr) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr[c + col * r] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", *(ptr + c + col * r));
	//	printf("\n");
	//}
	
	//int row = 3, col = 2, depth = 2;
	//int* ptr = (int*)malloc(sizeof(int) * row * col * depth);
	//if (!ptr) exit(1);
	//for (int d = 0; d < depth; d++)
	//	for (int r = 0; r < row; r++)
	//		for (int c = 0; c < col; c++)
	//			ptr[c + col * r + (row * col) * d] = c + col * r + (row * col) * d;

	//for (int d = 0; d < depth; d++)
	//	for (int r = 0; r < row; r++)
	//		for (int c = 0; c < col; c++)
	//		{
	//			int idx = c + col * r + (row * col) * d; // ���� ������� warning?
	//			printf("%d ", *(ptr + idx));
	//		}


	// 12.16 calloc(), realloc()
	//// calloc: contiguous allocation
	//int n = 10;
	//int* ptr = NULL;

	////ptr = (int*)malloc(sizeof(int) * n); // malloc�� �޸𸮸� �Ҵ縸 ���ְ� �ʱ�ȭ�� ������ �ʴ´�.
	//ptr = (int*)calloc(n, sizeof(int)); // malloc �� ���� ���̰� ����. calloc�Լ��� 0���� �ʱ�ȭ�� ���ش�.

	//if (!ptr) exit(1);
	//
	//for (int i = 0; i < n; ++i)
	//	printf("%d ", ptr[i]);
	//printf("\n");

	//// realloc: reallocation ����� ����� �ٽ� �Ҵ��� �ް� ���� �� ����ϴ� �Լ�
	//// ���� ���� �ִ� �޸𸮺��� �� ū �޸𸮸� �Ҵ��Ѵٸ� ������ �޸𸮸� �������ش�. ���� �߰��� �޸𸮿� ���ؼ��� �ʱ�ȭ������ �ʴ´�.
	//// �޸𸮸� �߰��� �Ҵ��� �� �� ���ٸ� NULL�� �����Ѵ�.
	//// argument�� ������, ���� �Ҵ�ް� ���� �޸𸮸� �޴´�.
	//// ù ��° argument�� NULL�̶�� malloc�� �Ȱ���.
	//// �� ��° argument�� 0�̶�� free(ù ��° ����)�� ����.

	//for (int i = 0; i < n; i++)
	//	ptr[i] = i + 1;

	//n = 20;

	//int* ptr2 = NULL;
	//ptr2 = (int*)realloc(ptr, n * sizeof(int));
	//// ptr2 = (int*)realloc(ptr, n * sizeof(int));

	//printf("%p %p\n", ptr, ptr2);

	//if (!ptr2) exit(1);
	//else ptr = NULL;

	//for (int i = 0; i < n; ++i)
	//	printf("%d ", ptr2[i]); // ������ �����͸� ������������ ���� ���� �޸𸮸� �ʱ�ȭ������ �ʴ´�.
	//printf("\n");

	//free(ptr2);


	// 12.17 ���� �Ҵ� �޸𸮿� ���� ���� �з�
	// ���� �Ҵ� �޸� - �� �޸� - free() �� ������ �޸𸮿� �ö� �ִ�.

	// 12.18 �ڷ��� �����ڵ� (Type Qualifiers) - const, volatile, restrict, _Atomic
	//// const
	//// C99 ideompotent
	////const const const int n = 6; // ���� �� �ᵵ �ȴ�. const int n = 6; �׷��� warning
	//typedef const int zip; // zip�̶�� �̸��� const int Ÿ���� ���� ���̴�. const zip = const const int �ε� ������ ����� �ȵǱ� ������..
	////const int i; // �ʱ�ȭ�� �ݵ�� �ؾ��Ѵ�.

	//const int j = 123;
	//const int arr[] = { 1, 2, 3 };

	//float f1 = 3.14f, f2 = 1.2f;

	//const float* pf1 = &f1;
	////*pf1 = 5.0f; // Error
	//pf1 = &f2; // Allowed

	//float* const pf2 = &f2;
	//*pf2 = 6.0f;
	////pf2 = &f1; // Error

	//const float* const pf3 = &f1;
	////*pf3 = 7.0f; // Error
	////pf3 = &f2; // Error

	//// ����� �ֿ� ������� const ���������� ������ ����, ������Ͽ� static const ������ �����.
	//double area_circle = PI * 2.0f * 2.0f;
	//
	//// volatile - �ֹ߼�
	//volatile int vi = 1; // �����Ϸ��� �𸣴� ������ ������ �ٲ� �� �ִٴ� �ǹ�, �����Ϸ��� ����ȭ ���� ����� �ǹ�
	//volatile int* pvi = &vi; // �ٸ� ����̳� �ü���� �ٲ� �� �ִ�. ���� ��� �ð�..
	//
	//int il = vi;
	//// ... something
	//int i2 = vi;
	//// �����Ϸ��� vi ���� �ٲ��� �ʾ��� ���̶�� �Ǵ��ϰ� �ӽ���������� ����(ĳ��)�Ͽ� ����ȭ�� �� �� �ִ�.
	//// �����Ϸ��� �𸣴� ��Ȳ���� �ٲ���ٸ� ������ �����.

	//// restrict
	//// ������ ������Ʈ�� �����ϴ°� �ش� ���� �ϳ� ���̶�� �ǹ�
	//
	//int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int* par = ar;

	//int* __restrict restar = (int*)malloc(10 * sizeof(int)); // restar ������ ���ؼ��� �����ϰڴٴ� �ǹ�
	//if (!restar) exit(1);

	//// ar �迭��, �迭�̸��� ������ �� ���� ������� ������ �� �ִ�.
	//ar[0] += 3;
	//par[0] += 5;
	//// par[0] += 8; �迭�̸��� ������ �� ������ �ٸ��� ������ �����Ϸ��� ����ȭ +8�� ������ ���Ѵ�.

	//restar[0] += 3;
	//restar[0] += 5;
	////restar[0] +=8; // Equivalent, �����Ϸ��� ����ȭ�� ���� ���� �ִ�.
	//// �����Ϸ� ���忡���� ������ restar�� ���ؼ��� �����ϴ��� üũ���� �� ����.


	// 12.19 ��Ƽ ������
	// ���α׷��� "���μ���"���� ����ȴ�.
	// ���� �����尡 �ٸ� �����带 ���� ��� �� �ִ�.
	// ��Ƽ �ھ� CPU -> ���� �����带 �����ų �� �ִ�.

	// ���� �Լ��� ���� �����尡 ���ÿ� �����ų ���
	// �Լ� ������ ���������� ��� storage classes�� ���°�?

	// �ϳ��� ���������� ���� ���� �����尡 �����ϸ�? ������ �����.
	// �޸𸮿� CPU ���̸� �Դٰ��� �ϴ� ���̿� ������ ���� �� �ִ�.

	// C��� ǥ�ؿ����� ��Ƽ �������� ���������� �ʾƼ�, ��κ� �ü������ �������ִ� ���� ����Ѵ�.
	// <Windows.h>

	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	if (thread)
		WaitForSingleObject(thread, INFINITE);

	// �Ϲ������� ���Ǵ� �� gcc�����Ϸ�
	// www.onlinegdb.com/online_c_compiler


	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h> // sleep()
//#include <pthread.h> // pthread�� �����쿡���� ����� �� �ִ�.
//#include <stdatomic.h>
//
//_Atomic int acnt = 0; // atomic type qualifier
//// _Atomic
//// ���� �����忡�� ������ ���������� ������ �� CPU�� �޸𸮰� �и��� �ִ� ������ ���� �ϰ����� ���� ���� �ִ�.
//// �׷� ��Ȳ�� �����ϱ� ���� _Atomic qualifier�� ����Ѵ�.
//// _Atomic ������ ������ �Ϲ������� ������.
//
//void* myThreadFunc(void* vargp)
//{
//	int n = 1; // thread storage duration
//	// ��������, �Լ��� ������ �޸𸮸� ��ȯ�Ѵ�.
//	// thread_id1, thread_id2 ���� �� ī�ǰ� �����.
//	for (int j = 0; j < 10; ++j)
//	{
//		sleep(1);
//		acnt += n;
//		printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
//	}
//	return NULL;
//}
//
//int main()
//{
//	pthread_t thread_id1, thread_id2; // ������ �ĺ�
//	printf("Before Thread\n");
//
//	pthread_create(&thread_id1, NULL, myThreadFunc, NULL); // myThreadFunc �Լ��� �����Ű�� �����带 ���� thread_id1�� �ĺ��� �� �ְ� �Ѵ�.
//	pthread_create(&thread_id2, NULL, myThreadFunc, NULL); // myThreadFunc �Լ��� �޸𸮿� CPU�� �� copy�� �۵��ϰ� �ȴ�.
//
//	pthread_join(thread_id1, NULL); // �����尡 ���� ������ ��ٷ�����Ѵ�.
//	pthread_join(thread_id2, NULL);
//
//	printf("After Thread\n");
//	printf("Atomic %d\n", acnt);
//
//	return 0;
//}