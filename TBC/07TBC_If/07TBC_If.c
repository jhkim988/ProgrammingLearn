#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>
#include <float.h>

#define PERIOD '.'
#define SIZE 100

int main()
{
	// 7.1 분기문 If
	//if (expressions)
	//	statement
	//int number;
	//printf("Input a positive integer: ");
	//scanf("%d", &number);

	// % 연산을 두 번 하는게 비효율적일 수 있다.
	//if (number % 2 == 0)
	//	printf("Even\n");

	//if (number % 2 != 1)
	//	printf("Odd\n");

	//if (expression)
	//	statement1
	//else
	//	statement2
	//if (number % 2 == 0) // % 연산을 한 번만 한다.
	//	printf("Even\n");
	//else
	//	printf("Odd\n");


	// 7.2 표준 입출력 함수들 getchar(), putchar()
	// 1. introduce getchar(), putchar()
	// 2. Use while loop to process character sequences
	// 3. Filter a specific character
	// 4. Convert numbers to asterisks
	// 5. Lower characters to Upper characters

	//char ch;
	//ch = getchar(); // char를 하나 가져온다. buffer
	//putchar(ch); // char 하나를 출력해준다. 

	//// int로 해도 작동한다.
	//int ch1;
	//ch1 = getchar();
	//putchar(ch1);

	// while을 이용하여 문자열을 처리한다. 한 글자씩 처리한다.
	// 실행 하면 getchar()를 통해 한 글자를 입력 받는다. 그러나 곧바로 while문으로 들어가서 입력한 문자를 바로 출력해주진 않는다.
	// why? 작동하는 방식이 다르다.
	// 한 글자씩 받는 함수임에도 여러 글자를 받는다. 버퍼에 모아뒀다가 엔터(줄바꿈)을 치면 여러 글자를 한 번에 받는다.
	// 한 글자씩 받고 실행하는 함수도 존재한다.
	//char ch;
	//while ((ch = getchar()) != '\n')
	//{
		//if (ch == 'f') { // filter
		//	ch = 'x';
		//}
		//else if (ch == 'F') {
		//	ch = 'X';
		//}

		// if (ch == 'f' || ch == 'F') {
		//	ch = 'X';
		//}

		//for (int i = '0'; i <= '9'; i++)
		//{
		//	if (ch == i)
		//		ch = '*';
		//}

		//if (ch >= '0' && ch <= '9')
		//	ch = '*';

		//// 소문자 -> 대문자
		//if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
		//	ch -= 32;
		//else if (ch >= 'A' && ch <= 'Z') // 대문자 -> 소문자
		//	ch += 32;

		//putchar(ch);
	//}


	// 7.3 ctype.h 문자 함수들
	// 입력받은 글자가 대문자인지, 소문자인지, 숫자인지.. -> 아스키 코드에 넣고 분기처리
	// <ctype.h>에 같은 기능을 하는 함수들이 있다.
	//char ch;
	//while ((ch = getchar()) != '\n')
	//{
		//if (islower(ch))
		//	ch = toupper(ch);
		//else if (isupper(ch))
		//	ch = tolower(ch);

	//	if (isdigit(ch))
	//		ch = '*';

	//	putchar(ch);
	//}


	// 7.4 다중 선택 else if
	// 종합소득세 계산 프로그램
	//double bases[] = { 12000000.0, 46000000.0, 88000000.0, 150000000.0, 300000000.0, 500000000.0 };
	//double rates[] = { 6.0 / 100.0, 15.0 / 100.0 , 24.0 / 100.0 , 35.0 / 100.0 , 38.0 / 100.0 , 40.0 / 100.0 , 42.0 / 100.0 };
	//double basic_deduction = 1500000.0;

	//double income = 0.0;
	//double tax = 0.0;

	//scanf("%lf", &income);
	//income -= basic_deduction;

	//// My Try.
	//int findIndex = 0; // 0 ~ 7
	//// 소득 범위를 찾는다.
	//for (int i = 0; i < 6; i++)
	//	if (income > bases[i])
	//		findIndex++;

	//// 세금을 더한다.
	//	for (int j = 0; j <= findIndex; j++)
	//		if (j == findIndex)
	//			if (j == 0)
	//			{
	//				tax += income * rates[j];
	//				printf("tax += income * rates[%d]\n", j);
	//			}
	//			else
	//			{
	//				tax += (income - bases[j - 1]) * rates[j];
	//				printf("tax += (income - bases[%d]) * rates[%d]\n", j - 1, j);
	//			}
	//		else
	//		{
	//			tax += bases[j] * rates[j];
	//			printf("tax += bases[%d] * rates[%d]\n", j, j);
	//		}
	//if (income < 0)
	//	tax = 0;
	//printf("tax = %f\n", tax);

	//if (income <= bases[0])
	//{
	//	tax += income * rates[0];
	//}
	//else if (income <= bases[1])
	//{
	//	tax += bases[0] * rates[0] + (income - bases[0]) * rates[1];
	//}
	//else if (income <= bases[2])
	//{
	//	tax += bases[0] * rates[0] + bases[1] * rates[1] + (income - bases[1]) * rates[2];
	//}
	// ...


	// 7.5 else와 if 짝짓기
	//int number;
	//scanf("%d", &number);

	//if (number == 1)
	//	printf("One");
	//else if (number == 2)
	//	printf("Two");
	//else if (number == 3)
	//	printf("Three");

	////if (number == 1)
	////	printf("One");
	////else
	////	if (number == 2)
	////		printf("Two");
	////	else
	////		if (number == 3)
	////			printf("Three");
	//// else if를 최소 127 단계를 지원해줘야한다.

	//if (number > 5)
	//	if (number < 10)
	//		printf("Larger than 5 smaller than 10\n");
	//else
	//	printf("Less than or equal to 5");
	//// Compilers ignore indenting. 중괄호로 영역을 명확하게 표시해주는 것이 좋다.


	// 7.6 소수 판단 예제
	//// My Try.
	//unsigned num;
	//bool isPrime = true; // flag, try bool type

	//printf("Input positive integer: ");
	//scanf("%u", &num);

	//for (unsigned i = 2; i * i <= num; i++)
	//{
	//	printf("%u %% %u = %u\n", num, i, num % i);
	//	if (!(num % i))
	//	{
	//		isPrime = false;
	//		break;
	//	}
	//}

	//if (isPrime)
	//	printf("%u is a prime number.\n", num);
	//else
	//	printf("%u is not prime number.\n", num);

	//// Find All Divisor
	//unsigned num;
	//printf("Input Positive Integer: ");
	//scanf("%u", &num);
	//printf("Divisor: ");

	//for (unsigned i = 1; i <= num; i++)
	//	if (!(num % i))
	//		printf("%u ", i);

	//printf("\n");

	//// isPrime
	//unsigned num;
	//bool isPrime = true;

	//printf("Input Positive Integer: ");
	//scanf("%u", &num);

	//for (unsigned i = 2; i * i <= num; i++)
	//{
	//	if (!(num % i))
	//	{
	//		isPrime = false;
	//		if (i * i == num)
	//			printf("%u is divisible by %u.\n", num, i);
	//		else
	//			printf("%u is divisible by %u and %u.\n", num, i, num / i);
	//	}
	//}

	//if (isPrime)
	//	printf("%u is a prime number.\n", num);
	//else
	//	printf("%u is not prime number.\n", num);

	// 7.7 논리연산자 Logical operators
	//// &&, ||, !
	//bool test1 = 3 > 2 || 5 > 6;; // true
	//bool test2 = 3 > 2 && 5 > 6;; // false
	//bool test3 = !(5 > 6); // true, equivalent to 5 <= 6

	//char ch;
	//int count = 0;
	//while ((ch = getchar()) != PERIOD)
	//{
	//	// TODO: make exceptions
	//	if (ch != '\n' && ch != ' ')
	//		count++;
	//}
	//printf("%d\n", count);

	//and or not // <iso646.h>
	// 우선순위 ...

	// short-circuit evaluation
	// - logical expressions are evaluated from left to right
	// - && and || are sequence points	
	//int temp = (1 + 2) * (3 + 4); 
	//printf("Before: %d\n", temp); // 21

	//if (temp == 0 && (++temp == 1024))
	//{
	//	// do nothing
	//}
	//printf("After: %d\n", temp); // 21
	//// &&를 평가할 때, 왼쪽의 expression이 false라면 오른쪽의 expression은 평가하지 않는다.

	//int x = 1, y = 2;
	//if (x++ > 0 && x + y == 4)
	//	printf("%d %d\n", x, y);

	//// Ranges
	//for (int i = 0; i < 100; i++)
	//	if (i >= 10 && i <= 20) // 10 <= i <= 20, 문법 오류가 아닌 문맥 오류.. ((10 <= i) <= 20)
	//		printf("%d ", i);
	//printf('\n');

	//for (char c = -128; c < 127; c++)
	//	if (c >= 'a' && c <= 'z')
	//		printf("%c ", c);
	//printf("\n");

	//for (char c = 0; c < 127; c++)
	//	if (islower(c))
	//		printf("%c ", c);


	// 7.8 단어 세기 예제
	//// My Try
	//char ch, prev = '\0';
	//int characters = 0 , words = 0, lines = 0;
	//bool line_flag = false;

	//printf("Enter Text: \n");

	//while ((ch = getchar()) != PERIOD)
	//{
	//	if (!isspace(ch))
	//		characters++;
	//	
	//	if (prev != ' ' && ch == ' ')
	//		words++;

	//	if (ch != '\n' && !line_flag)
	//	{
	//		lines++;
	//		line_flag = true;
	//	}
	//	if (ch == '\n')
	//		line_flag = false;
	//	
	//	prev = ch;
	//}
	//printf("Characters = %d, Words = %d, Lines = %d\n", characters, words, lines);

	//char c;
	//int n_chars = 0;
	//int n_lines = 0;
	//int n_words = 0;
	//bool word_flag = false;
	//bool line_flag = false;

	//printf("Enter text: \n");
	//while ((c = getchar()) != PERIOD)
	//{
	//	if (!isspace(c)) // 입력받은 글자가 빈칸이 아니라면
	//		n_chars++;

	//	if (!isspace(c) && !line_flag) // 입력받은 글자가 빈칸이 아니고 line_flag가 false라면
	//	{
	//		n_lines++;
	//		line_flag = true;
	//	}
	//	if (c == '\n') // 줄바꿈 기호라면 line_flag를 false로 바꿔준다.
	//		line_flag = false;

	//	if (!isspace(c) && !word_flag)
	//	{
	//		n_words++;
	//		word_flag = true;
	//	}
	//		
	//	if (isspace(c))
	//		word_flag = false;
	//}

	//printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);


	// 7.9 조건 연산자 Conditional Operator
	//int temp;
	//temp = true ? 1024 : 7;
	//printf("%d\n", temp);

	//temp = false ? 1024 : 7;
	//printf("%d\n", temp);

	//int number;
	//bool is_even;

	//scanf("%d", &number);
	//is_even = (number % 2) ? false : true;
	//(is_even) ? printf("Even\n") : printf("Odd\n");

	//int a = 1, b = 2;
	//int max = (a > b) ? a : b;


	// 7.10 루프 도우미 continue와 break
	//// continue
	//for (int i = 0; i < 10; i++)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);

	//	//if (i != 5) printf("%d ", i);
	//}

	//// break
	//for (int i = 0; i < 10; i++)
	//{
	//	if (i == 5)
	//		break;
	//	printf("%d ", i);
	//}

	//int count = 0;
	//while (count < 5)
	//{
	//	int c = getchar();
	//	if (c == 'a')
	//		continue;
	//	putchar(c);
	//	count++;
	//}

	//// placeholder -> null statement 같은 것...
	//while (getchar() != '\n')
	//	continue; // placeholder

	//char c;
	//while ((c = getchar()) != '\n')
	//{
	//	if (c == 'a')
	//		continue;
	//	putchar(c);

	//	//if (c != 'a') putchar();
	//}

	//char c;
	//while ((c = getchar()) != '.')
	//{
	//	putchar();
	//}

	//while (1) {
	//	char c = getchar();
	//	if (c == '.')
	//		break;
	//	putchar();
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		if (j == 5)
	//			break;
	//		printf("(%d %d)", i, j);
	//	}

	//}


	// 7.11 최대 최소 평균 구하기 예제
	//// My Try
	//float arr[SIZE];
	//int count = 0;
	//float min, max, ave;

	//// 입력 받기
	//for (int i = 0; i < SIZE; i++)
	//{
	//	if (scanf("%f", &arr[i]) == 0)
	//		break;
	//	count++;
	//}

	//// 입력을 하나도 하지 않았다면?
	//if (count == 0)
	//{
	//	printf("Good bye.\n");
	//}
	//else {
	//	min = arr[0];
	//	max = arr[0];
	//	ave = 0;

	//	for (int i = 0; i < count; i++)
	//	{
	//		ave += arr[i];
	//		if (i == count - 1) break;
	//		min = (arr[i + 1] > arr[i]) ? arr[i] : arr[i + 1];
	//		max = (arr[i + 1] > arr[i]) ? arr[i + 1] : arr[i];
	//		
	//	}
	//	ave /= count;

	//	printf("min = %f, max = %f, ave = %f\n", min, max, ave);
	//}

	//float max = -FLT_MAX;
	//float min = FLT_MAX;
	//float sum = 0.0f;
	//float input;
	//int n = 0;

	//while (scanf("%f", &input) == 1)
	//{
	//	// TODO: ignore negative values
	//	if (input < 0.0f || input > 100.0f) continue;

	//	max = (input > max) ? input : max;
	//	min = (input > min) ? min : input;
	//	sum += input;
	//	n++;
	//}
	//if (n > 0)
	//	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
	//else
	//	printf("No input\n");


	// 7.12 다중 선택 switch와 break
	char c;
	while ((c = getchar()) != '.')
	{
		printf("You love ");
		switch (c) // tolower(c)를 사용해도 된다.
		{
		case 'a': case 'A':
			printf("apple");
			break;
		case 'b': case 'B':
			printf("baseball");
			break;
		case 'c': case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
		}

		printf(".\n");
		while (getchar() != '\n')
			continue;
	}

	// TODO: upper letters ?


	// 7.13 goto를 피하는 방법
//	int size = 15, cost;
//	if (size < 10)
//		goto a;
//	goto b;
//
//a: cost = 50 * size;
//b: cost = 100 * size;
//
//	if (size < 10)
//		cost = 50 * size;
//	else
//		cost = 100 * size;
//
//	// loop
//	char c;
//read: c = getchar();
//	putchar(c);
//	if (c == '.') goto quit;
//	goto read;
//quit:
//
//	while (1)
//	{
//		c = getchar();
//		putchar(c);
//		if (c == '.') break;
//	}


	return 0;
}