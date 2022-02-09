#include <stdio.h>

#define YEARS 3
#define MONTHS 12
#define ROWS 3
#define COLS 4


// 10.7
double average(double[], int);

// 10.8
double average10_8(double*, double*);

// 10.11
void print_array(const int arr[], const int n);
void add_value(int arr[], const int n, const int val);
int sum(const int ar[], const int n);

// 10.16
int sum2d_1(int ar[ROWS][COLS]); // ROWS, COLS를 넣어주더라도 함수 내에서 사용할 수 없다. #define 한 것을 통해서 접근 가능하게...
int sum2d_2(int ar[][COLS], int row); // row 개수가 몇 개인지 인자로 넣어줘도 된다. (COLS)는 적어줘야한다.
//int sum2d_2(int(*ar)[COLS], int row); // pointer-to-int[COLS]
int sum2d_3(int* ar, int row, int col); // 배열을 넣더라도 배열의 이름은 배열 원소의 첫 주소이기 때문에 포인터로 변환이 된다. 동적할당을 사용할 때도 1차원으로 생각하고 사용하기 때문에...
//int sum2d_3(int*, int, int); //동적할당을 할 때

// 10.17
//int sum2d_4(int row, int col, int ar[row][col]); // 매개변수의 배열에도 들어간다.

// 10.18
int sum1d(int [], int);
int sum2d(int[][COLS], int);

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
	//int arr[] = { 1, 2, 3, 4, 5 };
	//const int n = sizeof(arr) / sizeof(arr[0]);

	//print_array(arr, n);
	//add_value(arr, n, 100);
	//print_array(arr, n);

	//int s = sum(arr, n);
	//printf("Sum is %d\n", s); // sum 함수를 잘못 구현하여 배열의 값이 바뀌었다. 함수 정의에서 인자에 const를 붙여주면 된다.
	//print_array(arr, n);


	// 10.12 2중포인터의 작동원리
	//int a = 7;
	//int* ptr = &a;
	//*ptr = 8;

	//int** pptr = &ptr;
	//**pptr = 9;


	// 10.13 포인터와 배열의 2차원 배열
	// 포인터의 배열을 2차원(혹은 다차원)배열로 사용하는 방법에 대해 알아본다.
	//int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	//int* parr[2] = { arr[0], arr[1] }; // 포인터의 배열

	// two of 1D arrays
	//int arr0[3] = { 1, 2, 3 };
	//int arr1[3] = { 4, 5, 6 };
	//int* parr[2] = { arr0, arr1 }; // arr0, arr1을 하나로 묶어서 이중 for loop로 해결한다.

	//for (int j = 0; j < 2; ++j)
	//{
	//	for (int i = 0; i < 3; ++i)
	//		printf("%d(==%d==%d==%d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]); // 2차원 배열처럼
	//	printf("\n");
	//}
	//printf("\n");

	//// 2D arrays are arrays of 1D arrays.
	//int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	//int* parr0 = arr[0];
	//int* parr1 = arr[1];

	//for (int i = 0; i < 3; ++i)
	//	printf("%d ", parr0[i]);
	//printf("\n");

	//for (int i = 0; i < 3; ++i)
	//	printf("%d ", parr1[i]);
	//printf("\n");

	//// array of pointers works like a 2D array.
	//int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	//int* parr[2];
	//parr[0] = arr[0];
	//parr[1] = arr[1];

	//for (int j = 0; j < 2; ++j)
	//{
	//	for (int i = 0; i < 3; ++i)
	//		printf("%d %d %d %d\n", arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i));
	//	printf("\n");
	//}
	//printf("\n");

	//// Note
	//// parr[0] and parr[1] do not point valid memory by default
	//// &parr[0] != &arr[0]
	//// &parr[0] != parr[0] but &arr[0] == arr[0]

	//printf("%p\n", &parr[0]);
	//printf("%p\n", parr[0]);

	//printf("%p\n", arr);
	//printf("%p\n", &arr[0]);

	//printf("%p\n", arr[0]);
	//printf("%p\n", &arr[0][0]);

	// Array of string of diverse lengths example
	//char* name[] = { "Aladin", "Jasmine", "Magic Carpet", "Genie" }; // 포인터의 배열
	//const int n = sizeof(name) / sizeof(char*);
	//for (int i = 0; i < n; ++i)
	//	printf("%s at %u\n", name[i], (unsigned)name[i]); // use ull in x64, 글자수만큼 차이난다.
	//printf("\n");

	//char aname[][15] = { "Aladin", "Jasmine", "Magic Carpet", "Genie" , "Jafar" }; // aname[]은 char[15]의 배열
	//const int an = sizeof(aname) / sizeof(char[15]);
	//for (int i = 0; i < an; ++i)
	//	printf("%s at %u\n", aname[i], (unsigned)aname[i]); // use ull in x64, 15씩 주소가 차이난다.
	//printf("\n");


	// 10.14 2차원 배열과 포인터
	//float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0, 6.0f, 7.0f, 8.0f} };
	//printf("%u\n", (unsigned)arr2d);
	//printf("%u\n", (unsigned)arr2d[0]);
	//printf("\n");

	//// arr2d points to arr2d[0] (not arr2d[0][0])
	//printf("%u\n", (unsigned)*arr2d);
	//printf("%u\n", (unsigned)&arr2d[0]);
	//printf("%u\n", (unsigned)&arr2d[0][0]);
	//printf("%f %f\n", arr2d[0][0], **arr2d);
	//printf("\n");

	//printf("%u\n", (unsigned)(arr2d + 1));
	//printf("%u\n", (unsigned)(&arr2d[1]));
	//printf("%u\n", (unsigned)(arr2d[1]));
	//printf("%u\n", (unsigned)(*(arr2d[0] + 1)));
	//printf("%u\n", (unsigned)(&arr2d[0] + 1));
	//printf("%u\n", (unsigned)(&arr2d[1][0]));

	//printf("%f\n", *(*(arr2d + 1) + 2));
	//printf("\n");

	//// My Try
	//int test[] = { 1, 2, 3 };
	//printf("TEST\n");
	//printf("%p %p %p\n", test, &test, &test[0]);
	//printf("%p %p %p\n", test + 1, &test + 1, &test[0] + 1);

	//int doubleArrayTest[2][3] = { {1, 2, 3}, {4, 5, 6} };
	//printf("%p %p %p %p\n", doubleArrayTest, &doubleArrayTest[0], doubleArrayTest[0], &doubleArrayTest[0][0]);
	//printf("%p %p %p %p\n", doubleArrayTest + 1, &doubleArrayTest[0] + 1, doubleArrayTest[0] + 1, &doubleArrayTest[0][0] + 1);
	
	//int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	//printf("%p %p %p\n", arr, arr[0] + 1, &arr[0] + 1); // 주소의 차이를 본다. 4, 12 차이
	//printf("%d %d\n", *(arr[0] + 1), **(&arr[0] + 1));

	//for (int j = 0; j < 2; ++j)
	//{
	//	printf("[%d] = %u, %u\n", j, (unsigned)(arr2d[j]), (unsigned)*(arr2d + j));
	//	for (int i = 0; i < 4; ++i)
	//	{
	//		printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));
	//		*(*(arr2d + j) + i) += 1.0f;
	//	}
	//}
	//printf("\n");

	//float(*pa)[4]; // a single pointer to an array of 4 floats
	//float* ap[2]; // an array of two pointers-to-float
	//printf("%zd", sizeof(pa)); // 4
	//printf("%zd", sizeof(ap)); // 8
	//printf("\n");

	//pa = arr2d;
	////pa[0] = arr2d[0]; // Error pa는 배열이 아니라 포인터이기 때문에
	////pa[1] = arr2d[1];

	////ap = arr2d; // Error ap는 포인터가 아니라 배열이므로
	//ap[0] = arr2d[0];
	//ap[1] = arr2d[1];


	// 10.15 포인터의 호환성
	//int n = 5;
	//double x;
	//x = n; // promotion

	//int* p1 = &n;
	//double* pd = &x;
	////pd = p1; // warning, 호환이 안되는 타입(incompatible)
	//pd = (double*)p1; // 캐스팅을 하면 warning이 사라지지만 권장하지 않는다.

	//int* pt;
	//int(*pa)[3]; 
	//int ar1[2][3] = { 3, };
	//int ar2[3][2] = { 7, };
	//int** p2;

	//pt = &ar1[0][0]; // pointer to int
	//for (int i = 0; i < 6; ++i) // 다차원 배열의 원소들을 모두 접근할 수 있다. (메모리가 일렬로 돼 있으므로)
	//	printf("%d ", pt[i]); // *(pt + i)

	//pt = ar1[0];
	////pt = ar1; // warning (error)

	//pa = ar1; // pointer to int[3]
	////pa = ar2; // warning (error)

	//p2 = &pt; // pointer to int*
	//*p2 = ar2[0]; // pointer to int
	////p2 = ar2; // warning (error), ar2를 담기 위해서는 pointer to int[2]를 가져와야한다.
	////int(*test)[2];
	////test = ar2;

	//int x = 20;
	//const int y = 23;
	//int* p1 = &x;
	//const int* p2 = &y; // const를 왼쪽에 붙여주면 indirection을 하면서 값을 못 바꿔준다.
	//const int** pp2 = &p1;

	////p1 = p2; // warning (Error), p2를 const로 선언하면서 indirection을 통해 값을 바꾸지 못하게 하였는데, p1을 통해 값이 바뀔 수 있게 돼 버린다.
	//p2 = p1; //const를 오른쪽에 붙이지 않으면 이게 가능해진다
	////printf("%d\n", *p2);
	////*p1 = 1;
	////printf("%d\n",*p2);
	////*p2 = 123; // Error 

	//int x2 = 30;
	//int* p3 = &x2;

	////**pp2 = x2; // const를 왼쪽에 붙였기 때문에 Error
	//*pp2 = p3; // const를 가운데 붙이면 에러 const int* const *pp2 = &p1;
	//pp2 = &p1; // const를 마지막에 붙이면 에러 const int** const pp2 = &p1;

	//{
	//	// 지양
	//	const int** pp2;
	//	int* p1;
	//	const int n = 13;
	//	pp2 = &p1;
	//	*pp2 = &n; // *pp2 == p1, p1 = &n
	//	*p1 = 10; // p1 == n, n = 10, change n
	//}

	//{
	//	// 지양
	//	const int y;
	//	const int* p2 = &y;
	//	int* p1;
	//	//p1 = p2; // warning (Error in cpp)
	//}


	// 10.16 다차원 배열을 함수에게 전달해주는 방법
	//int data[ROWS][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2} }; // 컴파일 할 때 메모리가 할당된다.
	//printf("%d\n", data[2][3]);

	//int* ptr = &data[0][0];
	//printf("%d\n", *(ptr + 3 + COLS * 2)); // 포인터로 접근하는 방법

	//printf("%d %d %d", sum2d_1(data), sum2d_2(data, ROWS), sum2d_3(data, ROWS, COLS));


	// 10.17 변수로 길이를 정할 수 있는 배열(VLAs, Variable-Length Arrays)
	//int n = 5;
	//float my_arr[n]; // 컴파일 오류, visual studio에서는 지원하지 않는다. https://repl.it
	//printf("Input array length: ");
	//scanf("%d", &n);

	//float my_arr[n]; // 배열의 길이는 symbolic constant나 literal 처럼 컴파일 타임에서 알 수 있는 값만 넣을 수 있다.
	// 한 번 선언되면 배열의 길이를 바꿀 수는 없다.

	//for (int i = 0; i < n; ++i)
	//	my_arr[i] = (float)i;
	//for (int i = 0; i < n; ++i)
	//	printf("%f\n", my_arr[i]);

	//int data[ROWS][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2} };
	//printf("%d\n", sum2d_4(ROWS, COLS, data));

	// 굳이 매크로를 사용할 필요가 없다.
	// visual studio와 달리 #define _CRT_SECURE_NO_WARNINGS을 적을 필요가 없다.


	// 10.18 복합 리터럴과 배열(Compound Literals)
	//int a = 1;
	//3; // Literals ars constans that aren't symbolic
	//3.14f;
	//int b[2] = { 3, 4 };
	//(int[2]) { 3, 4 }; // Compound Literals 같은 자료형뿐만 아니라 다른 자료형끼리 묶은 것도 Compound Literal이라고 한다.

	////int c[2] = (int[2]){ 3, 4 }; // Error

	//int arr1[2] = { 1, 2 };
	//int arr2[2][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	//printf("%d\n", sum1d(arr1, 2));
	//printf("%d\n", sum2d_3(arr2, 2, 4));

	//printf("%d\n", sum1d((int[2]) { 1, 2 }, 2));
	//printf("%d\n", sum2d_3((int[2][4]) { {1, 2, 3, 4}, { 5, 6, 7, 8 } }, 2, 4));

	int* ptr1;
	int(*ptr2)[COLS];
	ptr1 = (int[2]){ 1, 2 };
	ptr2 = (int[2][4]){ {1, 2, 3, 4}, { 5, 6, 7, 8 } };  // ptr2 pointer-to-int[4]...



	printf("%d\n", sum1d(ptr1, 2));
	printf("%d\n", sum2d(ptr2, 2));
	printf("%d\n", sum2d_3(ptr2, 2, 4)); // *ptr2를 전달해야 맞는거 같은데??

	printf("TEST: %d\n", ptr2[0][0]);
	printf("%d\n", **ptr2);
	printf("%d\n", *(*ptr2 + 4));

	return 0;
}

// 10.7
double average(double arr[], int n)
{
	printf("Size = %zd in function average\n", sizeof(arr)); // 포인터의 size가 나와버린다.
	// 함수에서 배열을 인자로 받을 때는 배열이 아니라 포인터로 받는다.
	// 배열의 크기를 따로 인자로 받아줘야 한다.

	double avg = 0.0;
	for (int i = 0; i < n; ++i)
		avg += arr[i];
	avg /= (double)n;

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

// 10.16
int sum2d_1(int ar[ROWS][COLS])
{
	int r, c, tot = 0;
	for (r = 0; r < ROWS; ++r)
		for (c = 0; c < COLS; ++c)
			tot += ar[r][c];
	return tot;
}

int sum2d_2(int ar[][COLS], int row)
{
	int r, c, tot = 0;
	for (r = 0; r < row; ++r)
		for (c = 0; c < COLS; ++c)
			tot += ar[r][c];
	return tot;
}

int sum2d_3(int* ar, int row, int col)
{
	int r, c, tot = 0;
	for (r = 0; r < row; ++r)
		for (c = 0; c < col; ++c)
			tot += *(ar + c + col * r);

	return tot;
}

// 10.17
//int sum2d_4(int row, int col, int ar[row][col])
//{
//	int r, c, tot = 0;
//	for (r = 0; r < row; ++r)
//		for (c = 0; c < COLS; ++c)
//			tot += ar[r][c];
//	return tot;
//}

// 10.18
int sum1d(int arr[], int n)
{
	int tot = 0;
	for (int i = 0; i < n; ++i)
		tot += arr[i];
	return tot;
}
int sum2d(int ar[][COLS], int row)
{
	int r, c, tot = 0;
	for (r = 0; r < row; ++r)
		for (c = 0; c < COLS; ++c)
			tot += ar[r][c];
	return tot;
}