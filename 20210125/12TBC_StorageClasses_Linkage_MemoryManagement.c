#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // srand()
#include <time.h> // time()
#include "my_rand.h"

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

	unsigned int next = (unsigned int)time(0);
	for (int i = 0; i < 10; ++i)
	{
		next = next * 1103515245 + 1234; // ���糭��
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}

	printf("\n*** My Try ***\n");
	my_srand(next);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", my_rand());
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", my_rand() % 6 + 1);
	}


	return 0;
}
