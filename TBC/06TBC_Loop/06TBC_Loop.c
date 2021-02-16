#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define NUM_ROWS 15
#define FIRST_CHAR 'A'
#define LAST_CHAR 'L'
#define NUM_DAYS 365
#define SIZE 5

int compute_pow(int base, int exp);

int main()
{
	// 6.1 while �ݺ� �������� scanf()�� ��ȯ�� ����ϱ�
	//int num, sum = 0;
	//int status;
	//
	//printf("Enter an integer (q to quit): ");
	////status = scanf("%d %d", &num, &sum); ����� ��Ī�Ǵ� ������ ��ȯ���ش�.
	//status = scanf("%d", &num);
	//while (status == 1)
	//{
	//	sum += num;
	//	printf("Enter next integer (q to quit): ");
	//	status = scanf("%d", &num);
	//}
	//printf("Sum = %d\n", sum);
	//
	// ª��
	//int num, sum = 0;
	//printf("Enter an integer (q to quit): ");
	//while (scanf("%d", &num) == 1)
	//{
	//	sum += num;
	//	printf("Enter next integer (q to quit): ");
	//}
	//printf("Sum = %d\n", sum);



	// 6.2 �ǻ��ڵ� Pseudo Code
	// � ���α׷��� �� ����ϴ� ����̵� ���� ������ �� �ֵ��� �� �帧�� �ۼ��� �ڵ�

	// 6.3 �������� ���� while
	//
	//while (expression) // expressions�� true�̸�(false�� �ƴϸ�, 0�� �ƴϸ�) �����Ѵ�.
	//	statements
	//
	//
	//int i;
	//i = 1;
	//
	//while (i < 5) // ���� ����, iteration
	//	printf("Hi\n");
	//
	//while (--i < 5) // wrong direction
	//	printf("Hi\n");
	//
	//while (i < 5)
	//{
	//	printf("i before = %d\n", i);
	//	i++;
	//	printf("i after = %d\n", i);
	//};
	//
	//i = 10;
	//while (i++ < 5) // cannot enter
	//	printf("Hi\n");
	//
	//while (scanf("%d", &i) == 1); // (���ڰ� �ƴ�) ���ڸ� �Է¹��� ������ �ݺ�


	// 6.4 ���� ������
	//// <, <=, ==, >=, >, !=
	//int n = 0;
	//while (n++ < 5)
	//	printf("%d", n);
	//printf("\n");
	//
	//char c = 'A';
	//while (c != 'Z')
	//	printf("%c", c++);
	//printf("\n");
	//
	//const double PI = 3.141592653589793238462643383279502884197169399375105820974944;
	//double guess = 0.0;
	//printf("Input pi: ");
	//scanf("%lf", &guess);
	//
	////while (guess != PI) // �Ǽ� ���꿡�� !=�� �� ������� �ʴ´�. <math.h>�� fabs()�Լ��� �̿��Ѵ�.
	//while ( fabs(guess - PI) < 0.01)
	//{
	//	printf("Try again.\n");
	//	scanf("%lf", &guess);
	//}
	//printf("Good!");


	// 6.5 ��ǰ� ����
	//int tv, fv;
	//tv = (1 < 2);
	//fv = (1 > 2);
	//printf("True is %d\n", tv);
	//printf("False is %d\n", fv);
	//
	//int i = -5;
	//while (i)
	//	printf("%d is true\n", i++);
	//printf("%d is false\n", i);
	//
	//i = 5;
	//while (i)
	//	printf("%d is true\n", i--);
	//printf("%d is false\n", i);
	//
	//// 0�̸� false, 0�� �ƴϸ� true


	// 6.6 _Bool �ڷ���
	//int i;
	//i = 5;
	//i == 5;
	////5 = i; // error
	//5 == i;
	//
	//while (i = 5) { /* do something */ };
	//while (i == 5) { /* do something */ };
	//
	// Boolean�� ���������δ� �������̴�.
	//_Bool boolean_true = (2 > 1);
	//_Bool boolean_false = (1 > 2);
	//
	//printf("True is %d\n", boolean_true);
	//printf("False is %d\n", boolean_false);
	//
	//printf(boolean_true ? "True" : "False");
	//printf("\n");
	//printf(boolean_false ? "True" : "False");
	//
	//// <stdbool.h>, Ű����(�Ķ���)�� �ƴϴ�. ���ο��� #define bool _Bool, #define true 1, #define false 0 ���� �� �ִ�.
	//bool bt = true;
	//bool bf = false;
	//
	//printf("\n");
	//printf("True is %d\n", boolean_true);
	//printf("False is %d\n", boolean_false);


	// 6.7 ���� �������� �켱����
	//int x = 1, y = 2, z;
	//x > y + 2; // x > (y + 2);
	//x = y > 2; // x = (y > 2);
	//z = x > y; // z = (x > y);
	//x != y == z; // (x != y) == z;


	// 6.8 for ���� �Ұ�
	//// Indefinite loop vs Counting loop
	//// 	while���� ���� ������ �˻縦 ������, �� ������ ��� �������� �Ű��� �� ����.
	//int i;
	//i = 1;
	//while (i <= 10)
	//{
	//	// do something
	//	i++;
	//};
	//
	//// Counting loop
	//// 1. Counter initialization
	//// 2. Counter check
	//// 3. Counter change
	//for (int i = 1; i <= 10; i++)
	//{
	//	// do something
	//}


	// 6.9 for�� �����ؿ�.
	//for (int i = 10; i > 0; i--)
	//	printf("%d ", i);
	//printf("\n");
	//
	//for (int i = 0; i < 100; i += 8)
	//	printf("%d ", i);
	//printf("\n");
	//
	//for (char c = 'A'; c <= 'Z'; c++)
	//	printf("%c ", c);
	//printf("\n");
	//
	//for (int i = 0; i*i < 100; i++)
	//	printf("%d ", i);
	//printf("\n");
	//
	//for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)
	//	printf("%d ", x);
	//printf("\n");
	//
	//for (double d = 100.0; d < 300; d *= 1.1)
	//	printf("%f\n", d);
	//
	//int i, n;
	//n = 2;
	//for (i = 2; n < 10; /*left blank*/)
	//{
	//	n *= i;
	//	printf("%d\n", n);
	//};
	//
	//for (;;) // ���ѷ���
	//	printf("I love you!");
	//
	//int i = 0;
	//for (printf("Let's go!\n"); i != 7; scanf("%d", &i));

	// 6.10 �پ��� ���� �����ڵ�(�׸��� ����� �ڵ� Ȯ�ι�)
	//int i = 1024;
	//i += 10;
	//i %= 4;
	//i *= 1 + 2; // ���� ������ =�� �켱������ ����.
	//
	//for (int i = 0; i < 10; i += 2)
	//	printf("%d ", i);
	//printf("\n");
	//// �����Ϸ��� �ߴ޷� ����� ����ȭ���� ��ü���� �˰����� �����ϴ� ���� ����.
	//
	//// ����� �ڵ� Ȯ�� ���
	//// ����� ��� ���� �� ��Ŭ�� -> Go to disassembly
	//// i = i + 10;�� i += 10�� assembly �ڵ尡 ����.


	// 6.11 �޸� ������
	//// for���� �����ϰ� ����� �� �ְ� ���ش�.
	//// ������ �� �� �ٸ� Ÿ���� ������ �޸��� ������ ���� ����. int a, double b;
	//for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
	//{
	//	printf("%d %d\n", n, nsqr); // �޸� �����ڰ� �ƴ϶� separators
	//};
	//
	//int i, j;
	//i = 1;
	//i++, j = i; // �޸��� sequence point�̴�. 
	//printf("%d %d\n", i, j); // 2 2
	//
	//int x, y, z;
	//z = x = 1, y = 2;
	//printf("x=%d y=%d z=%d", x, y, z); // 1 2 1
	//printf("\n");
	//
	//z = (x = 1), y = 2;
	//printf("x=%d y=%d z=%d", x, y, z); // 1 2 1
	//printf("\n");
	//
	//z = (x = 1, y = 2);
	//printf("x=%d y=%d z=%d", x, y, z); // 1 2 2
	//printf("\n");
	//
	//// int my_money = 123,456; // error
	//int my_money = (123, 456);
	//printf("%d\n", my_money); // 456


	// 6.12 ������ ���� �ùķ��̼� ����
	// Simulation of a Moving Object
	// - speed: 1.0m/s
	// - dt = 1.0s
	// - Distance traveled during dt = Spped * dt
	// - Step 1: 1.0m
	// - Step 2: 2.0m
	// - Step 3: 3.0m
	//
	//const double speed = 1.0;
	//const unsigned repeat_max = 100;
	//
	//double dt = 0.1;
	//double time = 0.0; // elapsed_time
	//double dist = 0.0; // distance
	//
	//// test
	//for (unsigned i = 0; i < repeat_max; ++i)
	//{
	//	dist += speed * dt;
	//	time += dt;
	//	printf("Elapsed time = %.10f, Distance = %.10f\n", time, dist);
	//};
	//
	//// Zeno's Paradox
	//unsigned i;
	//for (i = 0; i < repeat_max /*&& dist != 2.0*/; ++i)
	//{
	//	dist += speed * dt;
	//	time += dt;
	//	printf("Elapsed time = %.10f, Distance = %.10f\n", time, dist);
	//	dt *= 0.5; // ���ϱⰡ �����⺸�� ������.
	//}
	//printf("%d\n", i);
	//
	//double dist_arch = 0.0;
	//double dist_turtle = 1.0;
	//double speed_arch = 10.0;
	//double speed_turtle = 0.001;
	//time = 0.0;
	//dt = 0.01;
	//
	//unsigned i;
	//printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n", time, dt, dist_arch, dist_turtle);
	//for (i = 0; i < repeat_max; ++i)
	//{
	//	dist_arch += speed_arch * dt;
	//	dist_turtle += speed_turtle * dt;
	//	time += dt;
	//	printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n", time, dt, dist_arch, dist_turtle);
	//	dt *= 0.5;
	//}


	// 6.13 Ż������ ���� do... while
	//// My Try.
	//const int password = 337;
	//int guess;
	//do
	//{
	//	printf("Input password: ");
	//	scanf("%d", &guess);
	//} while (guess != password);
	//printf("Good.\n");
	//
	//const int secret_code = 337;
	//int guess;
	//
	//// �ϴ� �� ���� �Է��� �޾ƾ� �Ѵ�. -> do while���� �̿��Ѵ�.
	//printf("Enter secret code: ");
	//scanf("%d", &guess);
	//while (guess != secret_code)
	//{
	//	printf("Enter secret code: ");
	//	scanf("%d", &guess);
	//}
	//
	//// do while�� ���
	//do
	//{
	//	printf("enter secret code: ");
	//	scanf("%d", &guess);
	//} while (guess != secret_code);
	//
	//// do while���� ������
	//// do[statement] -> while<condition> -> true or false ...


	// 6.14 � ������ ����ұ�?
	// ��������(while, for) vs Ż������(do...while)
	// for(;test;);
	// while(test);
	//
	// for(init; test; update) { body };
	// init; while(test){ body update };
	//
	// for(int i = 0; i < 100; ++i)
	// while(scanf("%d", &num)==1)
	

	// 6.15 ��ø�� ������
	//// My Try
	//char end = 'K';
	//int want_num = 5;
	//for (int i = 0; i < want_num; i++)
	//{
	//	for (char start = 'A'; start <= end; start++)
	//	{
	//		printf("%c ", start);
	//	}
	//	printf("\n");
	//}
	//
	//int r; // row loop
	//int c; // character loop
	//for (r = 0; r < NUM_ROWS; ++r) // outer row loop
	//{
	//	for (c = FIRST_CHAR; c <= LAST_CHAR; c++) // inner character loop
	//	{
	//		printf("%c ", c);
	//	}
	//	printf("\n");
	//}
	//
	//// My Try
	//int r, c;
	//for (r = 0; r < NUM_ROWS; r++)
	//{
	//	for (c = FIRST_CHAR; c <= r + FIRST_CHAR ; c++)
	//	{
	//		printf("%c ", c);
	//	}
	//	printf("\n");
	//}
	//
	//// My Try
	//int r, c;
	//for (r = 0; r < NUM_ROWS; r++)
	//{
	//	for (c = FIRST_CHAR + r; c <= LAST_CHAR; c++)
	//	{
	//		printf("%c ", c);
	//	}
	//	printf("\n");
	//}
	//
	// int r, c;
	//for (r = 0; r < NUM_ROWS; r++)
	//{
	//	for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; c++)
	//	{
	//		printf("%c ", c);
	//	}
	//	printf("\n");
	//}

	// 6.16 �迭�� ��Ÿ�� ����
	//// ���ڿ� ���������� \0�� ���ٴ� ���� �������.
	////char my_chars[] = "Hello, World!";
	////int daily_temperature[NUM_DAYS];
	////double stock_prices_history[NUM_DAYS];
	//
	////printf("%zd\n", sizeof(stock_prices_history));
	////printf("%zd\n", sizeof(double)* NUM_DAYS);
	////printf("%zd\n", sizeof(stock_prices_history[0]));
	//
	//int my_numbers[5];
	//my_numbers[0] = 1; // subscripts, indices, offsets(ù ��° �ּҷκ��� �󸶳� ������ �ִ°�?)
	//my_numbers[1] = 3;
	//my_numbers[2] = 4;
	//my_numbers[3] = 2;
	//my_numbers[4] = 1024;
	//
	////scanf("%d", &my_numbers[0]);
	//scanf("%d", my_numbers); // ��ó�� �ۼ��ص� �ȴ�. (my_numbers�� my_numbers[] �迭�� ù ��° �޸� �ּҸ� ����Ų��.)
	//
	//for (int i = 0; i < 5; i++)
	//	printf("%d\n", my_numbers[i]);
	//
	//// Runtime Error
	////my_numbers[5] = 123; // out of bound -> ������ �� ��(������ Ÿ��)�� ������ ������� �ʴ´�. ������ �ϸ� �� �� ��Ÿ�� ������ �߻��Ѵ�. ����ŷ� ã�� ���� �ִ�.
	//
	////my_numbers = 7; // ������ ����


	// 6.17 for ������ �迭�� �Բ� ����ϱ�
	//int my_arr[SIZE];
	//// prepare for array data
	//for (int i = 0; i < SIZE; i++)
	//	my_arr[i] = i * i;
	//
	//// print array data
	//for (int i = 0; i < SIZE; i++)
	//	printf("%d ", my_arr[i]);
	//
	//// My Try
	//int arr[SIZE];
	//int sum = 0;
	//
	//printf("Enter %d numbers:\n", SIZE);
	//
	//for (int i = 0; i < SIZE; i++)
	//	scanf("%d", &arr[i]);
	//
	//for (int i = 0; i < SIZE; i++)
	//	sum += arr[i];
	//
	//printf("Sum = %d\n", sum);


	// 6.18 ���� �ȿ��� �Լ��� ��ȯ�� ����ϱ�
	// ����ڿ��� �Է� ����: 3 4 -> 3 * 3 * 3 * 3 -> 81 ��� -> ����ڿ��� �Է� ���� ...
	int base, exp;
	int result;

	while (scanf("%d %d", &base, &exp) == 2)
	{
		result = compute_pow(base, exp);
		printf("Result = %d\n", result);
	};


	return 0;
}
compute_pow(int base, int exp)
{
	int i;
	int result = 1;
	for (i = 0; i < exp; i++)
		result *= base;
	return result;
}