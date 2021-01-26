#include <stdio.h>

#define YEARS 3
#define MONTHS 12

// 10.7
double average(double[], int);

// 10.8
double average10_8(double*, double*);

// 10.11
void print_array(const int arr[], const int n);
void add_value(int arr[], const int n, const int val);
int sum(const int ar[], const int n);

int main()
{
	// 10.1 배열과 메모리
	//int high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // type name[length] = { ... element ... }
	//int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};

	// index를 이용하여 접근한다.
	//for (int i = 0; i < 12; ++i)
	//	printf("%d, %d\n", high[i], low[i]);

	// arr를 선언하게 되면 연속된 메모리 공간을 할당받는다.
	// int는 4바이트이므로 4바이트씩 4개, 16바이트의 연속된 공간을 할당받는다.
	//int arr[4];
	//arr[0] = 2;
	//arr[1] = 5;
	//arr[2] = 11;
	//arr[3] = 18;
	// 배열은 연속된 메모리 공간을 할당 받기 때문에 arr[0]과 arr[1]의 주소 차이는 4씩 나게 된다.(int형)


	// 10.2 배열의 기본적인 사용방법
	//int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", high[i]);
	//printf("\n");

	//high = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working
	//high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working
	// 선언할 때만 나열해서 초기화 가능하다.

	//printf("%p %p\n", high, &high[0]); // 같다.

	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%lld\n", (long long)&high[i]); // 4씩 커지는것 확인

	// Error, 컴파일러가 잡아주지 않는다.
	//high[12] = 4;
	//high[-1] = 123;

	// const array
	//const int low[MONTHS] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	//low[0] = 1; 배열의 원소를 바꿀 수 없다.

	//int not_init[4]; // try static(storage class)
	//for (int i = 0; i < 4; ++i)
	//	printf("%d\n", not_init[i]); // 컴파일은 된다. Release/Debug, x86/x64에 따라 다르다.

	//int insuff[4] = { 2, 4 };
	//for (int i = 0; i < 4; ++i)
	//	printf("%d\n", insuff[i]); // 비어 있는 것을 0 으로 알아서 채워준다.

	//int over[2] = { 2, 4, 8, 16 }; // 컴파일 에러
	//for (int i = 0; i < 4; ++i)
	//	printf("%d\n", over[i]);

	//const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };
	//printf("%d\n", sizeof(power_of_twos));
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(power_of_twos[0]));

	//// 배열크기를 생략하면 for loop를 다음과 같이 구성할 수 있다.
	//for (int i = 0; i < sizeof(power_of_twos) / sizeof(power_of_twos[0]); ++i) // 동적할당에서는 이렇게 할 수 없다.
	//	printf("%d ", power_of_twos[i]);
	//printf("\n");
	//// Designated initializers
	//int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29 }; // 어느 칸에 어떤 값이 들어갈지 정해준다.
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", days[i]);

	//// array size
	//int arr1[MONTHS];
	//double arr2[2];
	//float arr3[3 * 4 + 1]; // 컴파일할 때 미리 계산해서 처리한다.
	//float arr4[sizeof(int) + 1];
	//float arr5[-10]; // Error
	//float arr6[0]; // Error
	// float arr7[1.5]; // Error
	//float arr8[(int)1.5];

	//int n = 8;
	//float arr9[n]; // Variable-Length Array is optional from C11, visual studio 컴파일러에서는 안된다. 동적할당으로 구현 가능하다.


	// 10.3 포인터의 산술연산 Pointer Arithmetics
	//int* ptr = 0; // (int*) 0, NULL

	//printf("%p %lld\n", ptr, (long long)ptr);
	//ptr++; // 자료형의 크기만큼 더하는 연산이 된다. try ptr += 2; 더하기 빼기 다 된다.
	//printf("%p %lld\n", ptr, (long long)ptr); // 4가 나온다.

	//// void* void 포인터는 산술연산을 할 수 없다.
	//// 단항연산자 +, -는 포인터 산술로 사용할 수 없다.
	////ptr = +ptr; // Error
	////ptr = -ptr; // Error

	//int arr[10];
	//int* ptr1 = &arr[3], * ptr2 = &arr[5];
	//// ptr2 = ptr1 + ptr2; // Not working, 포인터 주소끼리 더하는 것은 안된다.
	//int i = ptr2 - ptr1; // meaning? 포인터 주소끼리 빼는 것은 된다. (array 타입과는 상관 없이 차이는 int이다.) 주소값의 차이를 자료형의 크기(int)로 나눈 값이다. 즉 배열 index의 차이다.

	//printf("%p %p %d\n", ptr1, ptr2, i);


	// 10.4 포인터와 배열
	//int arr[10]; // 40바이트(int 10개) 공간 중 가장 맨 앞 주소
	//const int num = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < num; ++i)
	//	arr[i] = (i + 1) * 100;

	//int* ptr = arr;
	//printf("%p %p %p\n", ptr, arr, &arr[0]);

	//ptr += 2;
	//printf("%p %p %p\n", ptr, arr + 2, &arr[2]);

	//// arr += 2; // invalid

	//printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);

	////warning
	//printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]);

	////int* ptr = NULL;
	////ptr = arr;
	//for (int i = 0, *ptr = arr; i < num; ++i) // scope...(ptr)
	//{
	//	printf("%d %d\n", *ptr++, arr[i]);
	//	// printf("%d %d\n", *(ptr + i), arr[i]);
	//	// printf("%d %d\n", *ptr + i, arr[i]);
	//}


	// 10.5 2차원 배열과 메모리
	//int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	////int arr[2][3] = { 1, 2, 3, 4, 5, 6 }; // 이렇게 해도 된다.
	////int arr[2][3] = { 1, 2 }; // 나머지 원소가 0으로 채워진다.
	//printf("%d\n\n", arr[1][1]);

	//for (int j = 0; j < 2; ++j) // 일반적으로 안쪽 루프가 오른쪽 index를 순회한다. 2중배열도 내부적으로는 1차원이기 때문에 이렇게 하면 순회를 순서대로 할 수 있다.(속도도 빠르다.)
	//{
	//	for (int i = 0; i < 3; ++i)
	//		printf("%d ", arr[j][i]); 
	//	printf("\n");
	//}

	//int* ptr = &arr[0][0];
	//for (int k = 0; k < 6; ++k) // 내부적으로는 1차원이므로 포인터로 바꿔서 1차원처럼 순회할 수 있다.
	//	printf("%d ", ptr[k]);
	//printf("\n\n");

	//printf("%zd %zd\n", sizeof(arr), sizeof(arr[0])); // 24, 12
	//printf("\n");

	
	// 10.6 2차원 배열 연습문제
	//double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	//double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	//double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

	//// 1. Use 2D array
	//// 2. Print data
	//// 3. Calculate and print yearly average temperatures of 3 years
	//// 4. Calculate and print monthly average temperatures for 3 years

	//double temperature[YEARS][MONTHS];
	//for (int i = 0; i < MONTHS; ++i)
	//	temperature[0][i] = year2016[i];
	//for (int i = 0; i < MONTHS; ++i)
	//	temperature[1][i] = year2017[i];
	//for (int i = 0; i < MONTHS; ++i)
	//	temperature[2][i] = year2018[i];

	//// My Try
	//printf("[Temperature Data]\n");
	//for (int i = -1; i < YEARS; ++i)
	//{
	//	if (i == -1)
	//		printf("%-10s", "Year Index :");
	//	else
	//		printf("%-8s %d :", "Year", i);

	//	for (int j = 0; j < MONTHS; ++j)
	//	{
	//		if (i == -1)
	//			printf("%8d", j + 1);
	//		else
	//			printf("%8.1f", temperature[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");

	//printf("[Yearly average temperatures of 3 years]\n");
	//for (int i = 0; i < YEARS; ++i)
	//{
	//	printf("Year %d : ", i);
	//	double sum = 0;
	//	for (int j = 0; j < MONTHS; ++j)
	//	{
	//		sum += temperature[i][j];
	//	}
	//	printf("average temperature = %.1f\n", sum / (double)MONTHS);
	//}
	//printf("\n");

	//printf("[Monthly average temperature for 3 years]\n");
	//printf("%-12s :", "Year Index");
	//for (int i = 0; i < MONTHS; ++i)
	//{
	//	printf("\t%d", i + 1);
	//}
	//printf("\n");
	//printf("%-12s :", "Avg temps");
	//for (int i = 0; i < MONTHS; ++i)
	//{
	//	double sum = 0;
	//	for (int j = 0; j < YEARS; ++j)
	//	{
	//		sum += temperature[j][i];
	//	}
	//	printf("\t%.1f", sum / (double)YEARS);
	//}
	//printf("\n");

	
	// 10.7 배열을 함수에게 전달해주는 방법
	//// 함수에 배열 전체를 전달하는 것 보다 배열의 첫 주소만 전달하는 것이 효율적이다.
	//double arr1[5] = { 10, 13, 12, 7, 8 };
	////double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	//double arr2[3] = { 1.8, -0.2, 6.3 };

	//printf("Address = %p\n", arr1);
	//printf("Size = %zd\n", sizeof(arr1));

	////double avg = 0.0;
	////for (int i = 0; i < 5; ++i)
	////	avg += arr1[i];
	////avg /= (double)5;

	//printf("Avg = %f\n", average(arr1, 5));

	//printf("Address = %p\n", arr2);
	//printf("Size = %zd\n", sizeof(arr2));
	//printf("Avg = %f\n", average(arr2, 3));


	// 10.8 두 개의 포인터로 배열을 함수에게 전달해주는 방법
	//double arr1[5] = { 10, 13, 12, 7, 8 };
	//printf("Avg = %f\n", average10_8(arr1, arr1 + 5));


	// 10.9 포인터 연산 총정리



	// 10.10 const와 배열과 포인터
	// type qualifiers: const, volatile, ...
	//const double PI = 3.14159; // 값을 바꿀 수가 없다. 컴파일러가 막는다.

	//const int arr[5] = { 1, 2, 3, 4, 5 }; // 배열의 원소도 수정할 수 없다.

	//const double arr2[3] = { 1.0, 2.0, 3.0 };
	//double* pd = arr2; // 값이 바뀌어버린다. warnings 포인터 변수에도 const를 붙이면 값을 수정할 수 없게 된다.
	//*pd = 3.0; // pd[0] = 3.0; arr2[0] = 3.0;
	//pd[2] = 1024.0; // arr2[2] = 1024.0;
	//printf("%f %f\n", pd[2], arr2[2]);

	//pd--; // 증감연산자는 된다. 포인터 변수에 들어있는 주소값은 바꿀 수 있게 돼 있다.
	//// 이것조차 바뀌지 않게 하기 위해서는 const double* const pd = arr2;로 작성한다.
	//// const double* : 해당 포인터가 가리키고 있는 메모리를 바꾸지 못한다.
	//// double* const: 포인터변수의 값 자체를 바꾸지 못한다.
	//printf("%f %f\n", pd[2], arr2[2]);


	// 10.11 배열 매개변수와 const
	int arr[] = { 1, 2, 3, 4, 5 };
	const int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	add_value(arr, n, 100);
	print_array(arr, n);

	int s = sum(arr, n);
	printf("Sum is %d\n", s); // sum 함수를 잘못 구현하여 배열의 값이 바뀌었다. 함수 정의에서 인자에 const를 붙여주면 된다.
	print_array(arr, n); 

	return 0;
}

// 10.7
double average(double arr[], int n)
{
	printf("Size = %zd in function average\n",  sizeof(arr)); // 포인터의 size가 나와버린다.
	// 함수에서 배열을 인자로 받을 때는 배열이 아니라 포인터로 받는다.
	// 배열의 크기를 따로 인자로 받아줘야 한다.

	double avg = 0.0;
	for (int i = 0; i < n; ++i)
		avg += arr[i];
	avg /= (double) n;

	return avg;
}

// 10.8
double average10_8(double* start, double* end)
{
	int count = end - start; // 0
	double avg = 0.0;
	while (start < end)
	{
		avg += *start++;
		//count++;
	}
	return avg / (double)count;
}

// 10.11
void print_array(const int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
void add_value(int arr[], const int n, const int val)
{
	for (int i = 0; i < n; ++i)
		arr[i] += val;
}
int sum(const int ar[], const int n) // const를 붙여준다.
{
	int total = 0;
	for (int i = 0; i < n; ++i)
		total += ar[i]; // ++ 일부러 오타
	return total;
}