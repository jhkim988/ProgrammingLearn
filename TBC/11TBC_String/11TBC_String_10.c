#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main_temp(int argc, char* argv[])
{
	// 11.10  명령줄 인수 Command line arguments
	// 지금까지 main함수의 arguments가 없었다.
	// argc는 들어오는 문자열의 개수
	// argv는 문자열의 배열

	//int count;
	//printf("The Command line has %d arguments\n", argc);
	//for (count = 0; count < argc; count++)
	//	printf("Arg %d : %s\n", count, argv[count]);
	//printf("\n");

	// 11TBC_String -> 우클릭 -> properties -> General -> output directory
	// $(Solution)$(Configuration)\
	// Solution: .sln 파일이 있는 곳의 위치
	// Configuration: Debug/Release, x86/x64
	// Target Name: 실행파일의 이름 $(ProjectName)


	// 11.11 문자열을 숫자로 바꾸는 방법들
	// atoi: a to int
	// atof: a to float
	// atol: a to long

	// visual studio에서 command arguments 넣어서 실행하기
	// 11TBC_String -> Properties -> Debugging -> Command Arguments 

	//if (argc < 3)
	//	printf("Wrong Usage of %s\n", argv[0]);
	//else
	//{
	//	//int times = atoi(argv[1]); // 정수를 문자로 입력 받아 정수로 변환한다.
	//	//for (int i = 0; i < times; i++) // 받아온 정수만큼 반복하여 출력한다.
	//	//	puts(argv[2]);

	//	printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
	//}

	// strtol: string to long
	// strtoul: string to unsigned long
	// strtod: string to double

	//char str1[] = "-1024Hello"; //
	//char* end; // 2중포인터가 인자로 들어간다.
	//long l = strtol(str1, &end, 10); // 문자열을 한글자씩 숫자로 변환하다가 변환할 수 없는 곳을 만나면 그 곳의 포인터를 end에 넣어준다.
	//printf("%s %ld %s %d\n", str1, l, end, (int)*end);

	//char str2[] = "10FFHi";
	//l = strtol(str2, &end, 16); 
	//printf("%s %ld %s %d\n", str2, l, end, (int)*end);

	//// Number to strings
	//// sprintf()
	//// _itoa: int to a
	//// _ftoa: float to a
	//char temp[100];
	//puts(_itoa(10, temp, 16)); // 10을 16진수로 바꾼다. temp는 버퍼

	//// _itoa는 표준이 아니다. sprintf를 사용하자
	//sprintf(temp, "%x", 29);
	//puts(temp);

	return 0;
}