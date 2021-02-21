#pragma once

#include <stdio.h>

void different_function_in_different_file()
{
	printf("This function is %s\n", __func__);
	printf("This is line %d\n", __LINE__);
}