#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int el; // extern: �ٸ� ���Ͽ� ����� ������ ���
extern int il;

void testLinkage()
{
	printf("DoSomething called\n");
	printf("%d\n", el);
	//printf("%d\n", il); // LNKERROR
	//printf("%d\n", dodgers);

	el++;
}

// 12.8
// ���������� ���� ����ϸ� ������ϱ� ��ƴ�.
void temp()
{
	extern int g_int; // ��� scope������ �ʱ�ȭ �� �� ����.
	// file scope������ �ʱ�ȭ �� �� �ִ�. �ʱ�ȭ�� ��ü���� �� ���� ������Ѵ�.
	g_int += 1000;
}

void fun_sec()
{
	extern int g_int; // referencing declaration
	temp();
	g_int += 7;
	printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}

