#include "my_functions.h"
#include <stdio.h>

int status = 0;

int add(int a, int b)
{
  return a + b;
}

void print_status()
{
  printf("address = %p, value = %d\n", &status, status);
}

void print_address()
{
  printf("print_adress()\n");
  printf("Static function address %p\n", multiply);
  printf("Static variable address %p\n", &si);
}
