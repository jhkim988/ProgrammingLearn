#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h> // window에서만 작동한다.
#include <ctype.h>

void display(char cr, int lines, int width);
long get_long(void);
long MyTry_get_long(void);
char get_first_char(void);
char get_choice(void);
int get_integer(void);
void count(void);

int main()
{
	// 8.1 입출력 버퍼
	// 버퍼: 입출력을 할 때 한꺼번에 모아서 하는 것
	// 버퍼가 없으면 _getche() 예제처럼 입력하자마자 한 글자씩 처리한다.
	// 버퍼의 크기는 컴파일러나 시스템에 따라 다르고, 조절할 수도 있다.
	// 적당한 크기의 메모리 공간을 버퍼로 설정하고 입력하면 한 글자씩 버퍼로 옮긴다.
	// 버퍼에 모은 후에 입력이 완료되면 버퍼에 담긴 내용을 통째로 전달한다.
	// 입출력 작업은 컴퓨터 작업 중에 느리기 때문에, 효율적인 방법을 사용해야 한다.
	// 엔터(\n)을 입력하면 버퍼에 담긴 내용을 전달하는 방식

	//char c;
	//while ((c = getchar()) != '.')
	//	putchar(c);

	//// 한글자씩 입출력
	//while ((c = _getche()) != '.') // e는 echo의 약자, _getch()는 내가 입력한 걸 표시하지 않는다.(컴퓨터가 입력해주는 것만 출력)
	//	putchar(c);


	// 8.2 파일의 끝 (End of file, eof)
	//int c;
	//while ((c = getchar()) != EOF) // getchar()의 return 타입은 int, EOF = -1, ctrl + z를 입력하면 입력이 종료, ctrl + c를 하면 운영체제가 강제종료한다.
	//{
	//	// 아스키코드에 음수는 없다. 입력이 다 끝났다는 것을 알려주고 싶을 때(운영체제가 알려준다.) getchar()는 -1을 반환한다.
	//	putchar(c);
	//}

	// stream: 데이터가 흘러가는 것
	// console 입출력에서는 입력한 문자들이 흘러서 작성한 프로그램으로 들어온다.(stream)
	// 파일에 저장돼 있는 데이터들이 흘러서 작성한 프로그램으로
	// 혹은 작성한 프로그램에서 데이터가 흘러 나와서 console창으로 나온다.
	// stream이 언제 끝나는지 표시해줄 때 사용하는 기호 = EOF
	//while (1)
	//{
	//	c = getchar();
	//	printf("%d\n", c); // ctrl + z를 입력하면 -1을 출력한다.
	//	if (c == EOF)
	//		break;
	//}


	// 8.3 입출력 방향 재지정 (redirection)
	// 파일 출력방향 재지정
	//printf("I love apple");

	// 파일에 출력하도록 바꿔본다.
	// cmd 창에서 드라이브 변경하는 방법: 변경할 드라이브 이름 + (:) (ex. C:, D:)
	// dir: 해당 디렉토리의 파일, 폴더들을 출력해준다.
	// explorer . : 현재 위치의 탐색기를 연다.
	// notepad output.txt: 메모장으로 output.txt를 연다.

	// 실행파일이 있는 디렉토리로 이동하여 "08TBC_IOBuffer.exe > output.txt"
	// cmd > output.txt
	// txt 파일에 I love apple이 입력돼 있다.
	// 출력방향을 콘솔창에서 output.txt로 재지정 해준 것이다.


	// 파일 입력방향 재지정
	// cmd > ./08TBC_IOBuffer.exe < input.txt
	// cmd > ./08TBC_IOBuffer.exe < input.txt > output.txt // 이런 것도 가능하다.
	// cmd > ./08TBC_IOBuffer.exe >> output.txt // txt 파일을 새로 쓰지 않고 이어서 쓴다.
	//char str[100];
	//scanf("%s", str);
	//printf("I love %s\n", str);

	// cmd >> copy 08TBC_IOBuffer.exe test.txt
	//printf("Programming");
	//char str[100];
	//scanf("%s", str);
	//printf("I love %s\n", str);

	//// cmd >> test.exe | 08TBC_IOBuffer.exe
	//// test.exe 의 실행 결과가 pipe를 타고 08TBC_IOBuffer.exe로 흘러갔다.


	// 8.4 사용자 인터페이스는 친절하게
	//int count = 0;

	//// 숫자가 두 개씩 올라간다.
	//while (getchar())
	//{
	//	printf("Current count is %d. Continue? (y/n)\n", count);
	//	if (getchar() == 'n')
	//		break;
	//	count++;
	//}

	//// 버퍼에서 첫 번째 글자만 남기고 싹 지워준다.
	//while (1)
	//{
	//	printf("Current count is %d. Continue? (y/n)\n", count);
	//	if (getchar() == 'n') // no를 입력해도 n으로 시작하는 글자이기 때문에 종료된다.
	//		break;

	//	while (getchar() != '\n') 
	//		continue;
	//	count++;
	//}

	//// 좀 더 사용자에게 친절하게
	//while (1)
	//{
	//	printf("Current count is %d. Continue? (y/n)\n", count);
	//	
	//	int c = getchar();

	//	if (c == 'n')
	//		break;
	//	else if (c == 'y')
	//		count++;
	//	else
	//		printf("Please input y or n\n");

	//	while (getchar() != '\n')
	//		continue;
	//}


	// 8.5 숫자와 문자를 섞어서 입력받기
	//char c;
	//int rows, cols;

	//while (1)
	//{
	//	scanf("%c %d %d", &c, &rows, &cols); // scanf는 A 3 2를 입력받고 줄바꿈 기호를 버퍼에 남겨둔다.
	//	while (getchar() != '\n') continue;	// 버퍼를 비워준다.
	//	display(c, rows, cols);

	//	if (c == '\n') // 줄 바꿈 기호와 정수 두 개를 받아야 종료되는 문제가 있다. 따라서 getchar()를 함께 사용하는 것이 좋다.
	//		break; // doesn't work well
	//}

	//printf("Input one character and two integers: \n");
	//while ((c = getchar()) != '\n')
	//{
	//	scanf("%d %d", &rows, &cols);
	//	while (getchar() != '\n') continue;	
	//	display(c, rows, cols);
	//	printf("Input another character and two integers: \n");
	//	printf("Press Enter to quit.\n");
	//}


	// 8.6 입력 확인하기
	//printf("Please input a number between 1 and 100.\n"); // 2 ~ 99
	//long number = MyTry_get_long();

	//while (number <= 1 || number >= 100)
	//{
	//	printf("Wrong Input. Please try agin.\n");
	//	number = MyTry_get_long();
	//}

	//printf("Your input %d is between 1 and 100. Thank you.\n", number);


	// 8.7 입력 스트림과 숫자
	// 기본적으로 cmd 창에 입력한 것을 문자로 받는다.(한 글자씩) 빈칸까지도 받는다.
	// scanf 내부에서 변환을 처리한다. (정수형, 실수형 등) 
	//char str[255];
	//int i, i2;
	//double d;

	//scanf("%s %d %lf", str, &i, &d);
	//printf("%s %d %f\n", str, i, d);

	//scanf("%s %d %d", str, &i, &i2);
	//printf("%s %d %d\n", str, i, i2);
	//
	//char c;
	//while ((c = getchar()) != '\n')
	//	putchar(c);
	//printf("\n");


	// 8.8 메뉴 만들기 예제
	//int choice;

	//while ((choice = get_choice()) != 'q')
	//{

	//	switch (choice)
	//	{
	//	case 'a':
	//		printf("Avengers assemble!\n");
	//		break;
	//	case 'b':
	//		printf("\a");
	//		break;
	//	case 'c':
	//		count();
	//		break;
	//	default:
	//		printf("Error with %d.\n", choice);
	//		exit(1);
	//		break;
	//	}

	//}


	// 8.9 텍스트 파일 읽기
	int c;
	FILE* file = NULL; // *는 포인터, file은 포인터 변수이다. 주소가 저장된다.
	char file_name[] = "my_file.txt"; // TODO: use scanf(...)

	file = fopen(file_name, "r");
	// file의 stream(통로)을 연다. "r" = read, "w" = write, 별도의 옵션이 없을 경우엔 txt 파일을 열게 된다. 파일 저장 방식: 아스키코드, 바이너리
	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}

	while ((c = getc(file)) != EOF)
		putchar(c);

	fclose(file); // 스트림을 닫는다.
	// visual studio에서 실행할 떄는 vcxproj 파일과 같은 경로에 있는 파일이 실행된다.
	// cmd 창에서 실행할 때는 exe 파일과 같은 경로에 있는 파일이 실행된다.



	return 0;
}
void display(char cr, int lines, int width)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < width; j++)
		{
			putchar(cr);
		}
		putchar('\n');
	}
}
long get_long(void)
{
	long input;
	char c;

	printf("Please input an integer and press enter.\n");
	while (scanf("%ld", &input) != 1)
	{
		printf("Your input - ");

		// 제대로 입력을 하지 않았다면 사용자의 입력이 버퍼에 남아있다. 그것을 putchar()로 출력한다.
		while ((c = getchar()) != '\n')
			putchar(c); // input left in buffer

		printf(" - is not an integer. Plese try again.\n");
	}
	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}
long MyTry_get_long(void)
{
	long input = 0;
	char c;
	int string_flag = 1;
	int num_string_flag = 1;
	
	printf("Please input an integer and press enter.\n");
	while (string_flag && num_string_flag)
	{	
		string_flag = 0;
		num_string_flag = 0;

		// 첫 글자부터 숫자가 아니라면 여기로 진입한다.
		while (scanf("%ld", &input) != 1)
		{
			printf("Your input - ");
			while ((c = getchar()) != '\n')
				putchar(c);

			printf(" - is not an integer. Plese try again.\n");
		
			string_flag = 1;
		}

		// 숫자 + 문자의 조합이라면 여기로 진입한다.
		if (!isdigit((c = getchar())) && c != '\n')
		{
			printf("Your input - %ld", input);
			do
				putchar(c);
			while ((c = getchar()) != '\n');
			printf(" - is not an integer. Plese try again.\n");

			num_string_flag = 1;
		}
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}
char get_first_char()
{
	// 입력한 문자 중 첫 번째 글자를 반환한다.
	char ch = getchar();
	while (getchar() != '\n') continue;
	return ch;
}
char get_choice()
{
	char ch;

	printf("Enter the letter of you choice:\n");
	printf("a. avengers\tb. beep\nc. count\tq. quit\n");

	while (!(((ch = get_first_char()) >= 'a' && ch <= 'c') || ch == 'q'))
		printf("Please Try Again.\n");

	return ch;
}
int get_integer()
{
	char ch;
	int input;
	int num_flag = 1, num_string_flag = 1;

	printf("Enter an positive integer:\n");

	while (num_flag && num_string_flag)
	{
		num_string_flag = num_flag = 0;

		// 첫 글자가 숫자가 아니라면
		while (scanf("%d", &input) != 1)
		{
			printf("Please Try Again.\n");
			while (getchar() != '\n') continue; // 버퍼를 비운다.
			num_flag = 1;
		}

		//중간에 숫자가 아닌 게 섞여 있다면
		if ((ch = getchar()) != '\n' && !isdigit(ch))
		{
			printf("Please Try Again.\n");
			while (getchar() != '\n') continue; // 버퍼를 비운다.
			num_string_flag = 1;
			continue;
		}
	}

	return input;
};
void count(void)
{
	char ch;
	unsigned num;
	
	num = get_integer();

	for (unsigned i = 1; i <= num; i++)
		printf("%u\n", i);
}
