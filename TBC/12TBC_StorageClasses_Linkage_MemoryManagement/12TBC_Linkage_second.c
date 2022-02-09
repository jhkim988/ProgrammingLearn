#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int el; // extern: 다른 파일에 선언된 변수를 사용
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
// 전역변수를 많이 사용하면 디버깅하기 어렵다.
void temp()
{
	extern int g_int; // 블록 scope에서는 초기화 할 수 없다.
	// file scope에서는 초기화 할 수 있다. 초기화는 전체에서 한 번만 해줘야한다.
	g_int += 1000;
}

void fun_sec()
{
	extern int g_int; // referencing declaration
	temp();
	g_int += 7;
	printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}

