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