#pragma once 

extern int status;
static int si = 0;
extern int add(int a, int b);
static int multiply(int a, int b) // static function은 function body를 쓸 수 있다.
{
  return a * b;
}

inline int substract(int a, int b)
{
  return a - b;
}

void print_status();
void print_address();