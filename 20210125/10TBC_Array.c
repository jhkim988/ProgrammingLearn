#include <stdio.h>

#define MONTHS 12

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
	int* ptr = 0; // (int*) 0, NULL

	printf("%p %lld\n", ptr, (long long)ptr);
	ptr++; // 자료형의 크기만큼 더하는 연산이 된다. try ptr += 2; 더하기 빼기 다 된다.
	printf("%p %lld\n", ptr, (long long)ptr); // 4가 나온다.

	// void* void 포인터는 산술연산을 할 수 없다.
	// 단항연산자 +, -는 포인터 산술로 사용할 수 없다.
	//ptr = +ptr; // Error
	//ptr = -ptr; // Error

	int arr[10];
	int* ptr1 = &arr[3], * ptr2 = &arr[5];
	// ptr2 = ptr1 + ptr2; // Not working, 포인터 주소끼리 더하는 것은 안된다.
	int i = ptr2 - ptr1; // meaning? 포인터 주소끼리 빼는 것은 된다. (array 타입과는 상관 없이 차이는 int이다.) 주소값의 차이를 자료형의 크기(int)로 나눈 값이다. 즉 배열 index의 차이다.

	printf("%p %p %d\n", ptr1, ptr2, i);

	return 0;
}