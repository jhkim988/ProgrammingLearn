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
	// 10.1 �迭�� �޸�
	//int high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // type name[length] = { ... element ... }
	//int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};

	// index�� �̿��Ͽ� �����Ѵ�.
	//for (int i = 0; i < 12; ++i)
	//	printf("%d, %d\n", high[i], low[i]);

	// arr�� �����ϰ� �Ǹ� ���ӵ� �޸� ������ �Ҵ�޴´�.
	// int�� 4����Ʈ�̹Ƿ� 4����Ʈ�� 4��, 16����Ʈ�� ���ӵ� ������ �Ҵ�޴´�.
	//int arr[4];
	//arr[0] = 2;
	//arr[1] = 5;
	//arr[2] = 11;
	//arr[3] = 18;
	// �迭�� ���ӵ� �޸� ������ �Ҵ� �ޱ� ������ arr[0]�� arr[1]�� �ּ� ���̴� 4�� ���� �ȴ�.(int��)


	// 10.2 �迭�� �⺻���� �����
	//int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", high[i]);
	//printf("\n");

	//high = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working
	//high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // not working
	// ������ ���� �����ؼ� �ʱ�ȭ �����ϴ�.

	//printf("%p %p\n", high, &high[0]); // ����.

	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%lld\n", (long long)&high[i]); // 4�� Ŀ���°� Ȯ��

	// Error, �����Ϸ��� ������� �ʴ´�.
	//high[12] = 4;
	//high[-1] = 123;

	// const array
	//const int low[MONTHS] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	//low[0] = 1; �迭�� ���Ҹ� �ٲ� �� ����.

	//int not_init[4]; // try static(storage class)
	//for (int i = 0; i < 4; ++i)
	//	printf("%d\n", not_init[i]); // �������� �ȴ�. Release/Debug, x86/x64�� ���� �ٸ���.

	//int insuff[4] = { 2, 4 };
	//for (int i = 0; i < 4; ++i)
	//	printf("%d\n", insuff[i]); // ��� �ִ� ���� 0 ���� �˾Ƽ� ä���ش�.

	//int over[2] = { 2, 4, 8, 16 }; // ������ ����
	//for (int i = 0; i < 4; ++i)
	//	printf("%d\n", over[i]);

	//const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };
	//printf("%d\n", sizeof(power_of_twos));
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(power_of_twos[0]));

	//// �迭ũ�⸦ �����ϸ� for loop�� ������ ���� ������ �� �ִ�.
	//for (int i = 0; i < sizeof(power_of_twos) / sizeof(power_of_twos[0]); ++i) // �����Ҵ翡���� �̷��� �� �� ����.
	//	printf("%d ", power_of_twos[i]);
	//printf("\n");
	//// Designated initializers
	//int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29 }; // ��� ĭ�� � ���� ���� �����ش�.
	//for (int i = 0; i < MONTHS; ++i)
	//	printf("%d ", days[i]);

	//// array size
	//int arr1[MONTHS];
	//double arr2[2];
	//float arr3[3 * 4 + 1]; // �������� �� �̸� ����ؼ� ó���Ѵ�.
	//float arr4[sizeof(int) + 1];
	//float arr5[-10]; // Error
	//float arr6[0]; // Error
	// float arr7[1.5]; // Error
	//float arr8[(int)1.5];

	//int n = 8;
	//float arr9[n]; // Variable-Length Array is optional from C11, visual studio �����Ϸ������� �ȵȴ�. �����Ҵ����� ���� �����ϴ�.


	// 10.3 �������� ������� Pointer Arithmetics
	//int* ptr = 0; // (int*) 0, NULL

	//printf("%p %lld\n", ptr, (long long)ptr);
	//ptr++; // �ڷ����� ũ�⸸ŭ ���ϴ� ������ �ȴ�. try ptr += 2; ���ϱ� ���� �� �ȴ�.
	//printf("%p %lld\n", ptr, (long long)ptr); // 4�� ���´�.

	//// void* void �����ʹ� ��������� �� �� ����.
	//// ���׿����� +, -�� ������ ����� ����� �� ����.
	////ptr = +ptr; // Error
	////ptr = -ptr; // Error

	//int arr[10];
	//int* ptr1 = &arr[3], * ptr2 = &arr[5];
	//// ptr2 = ptr1 + ptr2; // Not working, ������ �ּҳ��� ���ϴ� ���� �ȵȴ�.
	//int i = ptr2 - ptr1; // meaning? ������ �ּҳ��� ���� ���� �ȴ�. (array Ÿ�԰��� ��� ���� ���̴� int�̴�.) �ּҰ��� ���̸� �ڷ����� ũ��(int)�� ���� ���̴�. �� �迭 index�� ���̴�.

	//printf("%p %p %d\n", ptr1, ptr2, i);


	// 10.4 �����Ϳ� �迭
	//int arr[10]; // 40����Ʈ(int 10��) ���� �� ���� �� �� �ּ�
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


	// 10.5 2���� �迭�� �޸�
	//int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
	////int arr[2][3] = { 1, 2, 3, 4, 5, 6 }; // �̷��� �ص� �ȴ�.
	////int arr[2][3] = { 1, 2 }; // ������ ���Ұ� 0���� ä������.
	//printf("%d\n\n", arr[1][1]);

	//for (int j = 0; j < 2; ++j) // �Ϲ������� ���� ������ ������ index�� ��ȸ�Ѵ�. 2�߹迭�� ���������δ� 1�����̱� ������ �̷��� �ϸ� ��ȸ�� ������� �� �� �ִ�.(�ӵ��� ������.)
	//{
	//	for (int i = 0; i < 3; ++i)
	//		printf("%d ", arr[j][i]); 
	//	printf("\n");
	//}

	//int* ptr = &arr[0][0];
	//for (int k = 0; k < 6; ++k) // ���������δ� 1�����̹Ƿ� �����ͷ� �ٲ㼭 1����ó�� ��ȸ�� �� �ִ�.
	//	printf("%d ", ptr[k]);
	//printf("\n\n");

	//printf("%zd %zd\n", sizeof(arr), sizeof(arr[0])); // 24, 12
	//printf("\n");

	
	// 10.6 2���� �迭 ��������
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

	
	// 10.7 �迭�� �Լ����� �������ִ� ���
	//// �Լ��� �迭 ��ü�� �����ϴ� �� ���� �迭�� ù �ּҸ� �����ϴ� ���� ȿ�����̴�.
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


	// 10.8 �� ���� �����ͷ� �迭�� �Լ����� �������ִ� ���
	//double arr1[5] = { 10, 13, 12, 7, 8 };
	//printf("Avg = %f\n", average10_8(arr1, arr1 + 5));


	// 10.9 ������ ���� ������



	// 10.10 const�� �迭�� ������
	// type qualifiers: const, volatile, ...
	//const double PI = 3.14159; // ���� �ٲ� ���� ����. �����Ϸ��� ���´�.

	//const int arr[5] = { 1, 2, 3, 4, 5 }; // �迭�� ���ҵ� ������ �� ����.

	//const double arr2[3] = { 1.0, 2.0, 3.0 };
	//double* pd = arr2; // ���� �ٲ�������. warnings ������ �������� const�� ���̸� ���� ������ �� ���� �ȴ�.
	//*pd = 3.0; // pd[0] = 3.0; arr2[0] = 3.0;
	//pd[2] = 1024.0; // arr2[2] = 1024.0;
	//printf("%f %f\n", pd[2], arr2[2]);

	//pd--; // ���������ڴ� �ȴ�. ������ ������ ����ִ� �ּҰ��� �ٲ� �� �ְ� �� �ִ�.
	//// �̰����� �ٲ��� �ʰ� �ϱ� ���ؼ��� const double* const pd = arr2;�� �ۼ��Ѵ�.
	//// const double* : �ش� �����Ͱ� ����Ű�� �ִ� �޸𸮸� �ٲ��� ���Ѵ�.
	//// double* const: �����ͺ����� �� ��ü�� �ٲ��� ���Ѵ�.
	//printf("%f %f\n", pd[2], arr2[2]);


	// 10.11 �迭 �Ű������� const
	int arr[] = { 1, 2, 3, 4, 5 };
	const int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	add_value(arr, n, 100);
	print_array(arr, n);

	int s = sum(arr, n);
	printf("Sum is %d\n", s); // sum �Լ��� �߸� �����Ͽ� �迭�� ���� �ٲ����. �Լ� ���ǿ��� ���ڿ� const�� �ٿ��ָ� �ȴ�.
	print_array(arr, n); 

	return 0;
}

// 10.7
double average(double arr[], int n)
{
	printf("Size = %zd in function average\n",  sizeof(arr)); // �������� size�� ���͹�����.
	// �Լ����� �迭�� ���ڷ� ���� ���� �迭�� �ƴ϶� �����ͷ� �޴´�.
	// �迭�� ũ�⸦ ���� ���ڷ� �޾���� �Ѵ�.

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
int sum(const int ar[], const int n) // const�� �ٿ��ش�.
{
	int total = 0;
	for (int i = 0; i < n; ++i)
		total += ar[i]; // ++ �Ϻη� ��Ÿ
	return total;
}