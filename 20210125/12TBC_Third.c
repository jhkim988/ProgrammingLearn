#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int; // referencing declaration
void func_third()
{
	g_int += 1;
	printf("g_int in func_third() %d %p\n", g_int, &g_int);
}