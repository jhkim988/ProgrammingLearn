//#pragma once
#ifndef MY_FUNCTION_1
#define MY_FUNCTION_1 // 비어있는 매크로.. 정의만 해둔다(파일이 include 됐는지, 일종의 flag)

#include <stdio.h>
static void my_function()
{
	printf("my_function_1.h");
}
#endif