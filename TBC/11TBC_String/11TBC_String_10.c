#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main_temp(int argc, char* argv[])
{
	// 11.10  ����� �μ� Command line arguments
	// ���ݱ��� main�Լ��� arguments�� ������.
	// argc�� ������ ���ڿ��� ����
	// argv�� ���ڿ��� �迭

	//int count;
	//printf("The Command line has %d arguments\n", argc);
	//for (count = 0; count < argc; count++)
	//	printf("Arg %d : %s\n", count, argv[count]);
	//printf("\n");

	// 11TBC_String -> ��Ŭ�� -> properties -> General -> output directory
	// $(Solution)$(Configuration)\
	// Solution: .sln ������ �ִ� ���� ��ġ
	// Configuration: Debug/Release, x86/x64
	// Target Name: ���������� �̸� $(ProjectName)


	// 11.11 ���ڿ��� ���ڷ� �ٲٴ� �����
	// atoi: a to int
	// atof: a to float
	// atol: a to long

	// visual studio���� command arguments �־ �����ϱ�
	// 11TBC_String -> Properties -> Debugging -> Command Arguments 

	//if (argc < 3)
	//	printf("Wrong Usage of %s\n", argv[0]);
	//else
	//{
	//	//int times = atoi(argv[1]); // ������ ���ڷ� �Է� �޾� ������ ��ȯ�Ѵ�.
	//	//for (int i = 0; i < times; i++) // �޾ƿ� ������ŭ �ݺ��Ͽ� ����Ѵ�.
	//	//	puts(argv[2]);

	//	printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
	//}

	// strtol: string to long
	// strtoul: string to unsigned long
	// strtod: string to double

	//char str1[] = "-1024Hello"; //
	//char* end; // 2�������Ͱ� ���ڷ� ����.
	//long l = strtol(str1, &end, 10); // ���ڿ��� �ѱ��ھ� ���ڷ� ��ȯ�ϴٰ� ��ȯ�� �� ���� ���� ������ �� ���� �����͸� end�� �־��ش�.
	//printf("%s %ld %s %d\n", str1, l, end, (int)*end);

	//char str2[] = "10FFHi";
	//l = strtol(str2, &end, 16); 
	//printf("%s %ld %s %d\n", str2, l, end, (int)*end);

	//// Number to strings
	//// sprintf()
	//// _itoa: int to a
	//// _ftoa: float to a
	//char temp[100];
	//puts(_itoa(10, temp, 16)); // 10�� 16������ �ٲ۴�. temp�� ����

	//// _itoa�� ǥ���� �ƴϴ�. sprintf�� �������
	//sprintf(temp, "%x", 29);
	//puts(temp);

	return 0;
}