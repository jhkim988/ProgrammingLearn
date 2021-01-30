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