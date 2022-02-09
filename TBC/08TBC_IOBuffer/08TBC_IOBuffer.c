#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h> // window������ �۵��Ѵ�.
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
	// 8.1 ����� ����
	// ����: ������� �� �� �Ѳ����� ��Ƽ� �ϴ� ��
	// ���۰� ������ _getche() ����ó�� �Է����ڸ��� �� ���ھ� ó���Ѵ�.
	// ������ ũ��� �����Ϸ��� �ý��ۿ� ���� �ٸ���, ������ ���� �ִ�.
	// ������ ũ���� �޸� ������ ���۷� �����ϰ� �Է��ϸ� �� ���ھ� ���۷� �ű��.
	// ���ۿ� ���� �Ŀ� �Է��� �Ϸ�Ǹ� ���ۿ� ��� ������ ��°�� �����Ѵ�.
	// ����� �۾��� ��ǻ�� �۾� �߿� ������ ������, ȿ������ ����� ����ؾ� �Ѵ�.
	// ����(\n)�� �Է��ϸ� ���ۿ� ��� ������ �����ϴ� ���

	//char c;
	//while ((c = getchar()) != '.')
	//	putchar(c);

	//// �ѱ��ھ� �����
	//while ((c = _getche()) != '.') // e�� echo�� ����, _getch()�� ���� �Է��� �� ǥ������ �ʴ´�.(��ǻ�Ͱ� �Է����ִ� �͸� ���)
	//	putchar(c);


	// 8.2 ������ �� (End of file, eof)
	//int c;
	//while ((c = getchar()) != EOF) // getchar()�� return Ÿ���� int, EOF = -1, ctrl + z�� �Է��ϸ� �Է��� ����, ctrl + c�� �ϸ� �ü���� ���������Ѵ�.
	//{
	//	// �ƽ�Ű�ڵ忡 ������ ����. �Է��� �� �����ٴ� ���� �˷��ְ� ���� ��(�ü���� �˷��ش�.) getchar()�� -1�� ��ȯ�Ѵ�.
	//	putchar(c);
	//}

	// stream: �����Ͱ� �귯���� ��
	// console ����¿����� �Է��� ���ڵ��� �귯�� �ۼ��� ���α׷����� ���´�.(stream)
	// ���Ͽ� ����� �ִ� �����͵��� �귯�� �ۼ��� ���α׷�����
	// Ȥ�� �ۼ��� ���α׷����� �����Ͱ� �귯 ���ͼ� consoleâ���� ���´�.
	// stream�� ���� �������� ǥ������ �� ����ϴ� ��ȣ = EOF
	//while (1)
	//{
	//	c = getchar();
	//	printf("%d\n", c); // ctrl + z�� �Է��ϸ� -1�� ����Ѵ�.
	//	if (c == EOF)
	//		break;
	//}


	// 8.3 ����� ���� ������ (redirection)
	// ���� ��¹��� ������
	//printf("I love apple");

	// ���Ͽ� ����ϵ��� �ٲ㺻��.
	// cmd â���� ����̺� �����ϴ� ���: ������ ����̺� �̸� + (:) (ex. C:, D:)
	// dir: �ش� ���丮�� ����, �������� ������ش�.
	// explorer . : ���� ��ġ�� Ž���⸦ ����.
	// notepad output.txt: �޸������� output.txt�� ����.

	// ���������� �ִ� ���丮�� �̵��Ͽ� "08TBC_IOBuffer.exe > output.txt"
	// cmd > output.txt
	// txt ���Ͽ� I love apple�� �Էµ� �ִ�.
	// ��¹����� �ܼ�â���� output.txt�� ������ ���� ���̴�.


	// ���� �Է¹��� ������
	// cmd > ./08TBC_IOBuffer.exe < input.txt
	// cmd > ./08TBC_IOBuffer.exe < input.txt > output.txt // �̷� �͵� �����ϴ�.
	// cmd > ./08TBC_IOBuffer.exe >> output.txt // txt ������ ���� ���� �ʰ� �̾ ����.
	//char str[100];
	//scanf("%s", str);
	//printf("I love %s\n", str);

	// cmd >> copy 08TBC_IOBuffer.exe test.txt
	//printf("Programming");
	//char str[100];
	//scanf("%s", str);
	//printf("I love %s\n", str);

	//// cmd >> test.exe | 08TBC_IOBuffer.exe
	//// test.exe �� ���� ����� pipe�� Ÿ�� 08TBC_IOBuffer.exe�� �귯����.


	// 8.4 ����� �������̽��� ģ���ϰ�
	//int count = 0;

	//// ���ڰ� �� ���� �ö󰣴�.
	//while (getchar())
	//{
	//	printf("Current count is %d. Continue? (y/n)\n", count);
	//	if (getchar() == 'n')
	//		break;
	//	count++;
	//}

	//// ���ۿ��� ù ��° ���ڸ� ����� �� �����ش�.
	//while (1)
	//{
	//	printf("Current count is %d. Continue? (y/n)\n", count);
	//	if (getchar() == 'n') // no�� �Է��ص� n���� �����ϴ� �����̱� ������ ����ȴ�.
	//		break;

	//	while (getchar() != '\n') 
	//		continue;
	//	count++;
	//}

	//// �� �� ����ڿ��� ģ���ϰ�
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


	// 8.5 ���ڿ� ���ڸ� ��� �Է¹ޱ�
	//char c;
	//int rows, cols;

	//while (1)
	//{
	//	scanf("%c %d %d", &c, &rows, &cols); // scanf�� A 3 2�� �Է¹ް� �ٹٲ� ��ȣ�� ���ۿ� ���ܵд�.
	//	while (getchar() != '\n') continue;	// ���۸� ����ش�.
	//	display(c, rows, cols);

	//	if (c == '\n') // �� �ٲ� ��ȣ�� ���� �� ���� �޾ƾ� ����Ǵ� ������ �ִ�. ���� getchar()�� �Բ� ����ϴ� ���� ����.
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


	// 8.6 �Է� Ȯ���ϱ�
	//printf("Please input a number between 1 and 100.\n"); // 2 ~ 99
	//long number = MyTry_get_long();

	//while (number <= 1 || number >= 100)
	//{
	//	printf("Wrong Input. Please try agin.\n");
	//	number = MyTry_get_long();
	//}

	//printf("Your input %d is between 1 and 100. Thank you.\n", number);


	// 8.7 �Է� ��Ʈ���� ����
	// �⺻������ cmd â�� �Է��� ���� ���ڷ� �޴´�.(�� ���ھ�) ��ĭ������ �޴´�.
	// scanf ���ο��� ��ȯ�� ó���Ѵ�. (������, �Ǽ��� ��) 
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


	// 8.8 �޴� ����� ����
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


	// 8.9 �ؽ�Ʈ ���� �б�
	int c;
	FILE* file = NULL; // *�� ������, file�� ������ �����̴�. �ּҰ� ����ȴ�.
	char file_name[] = "my_file.txt"; // TODO: use scanf(...)

	file = fopen(file_name, "r");
	// file�� stream(���)�� ����. "r" = read, "w" = write, ������ �ɼ��� ���� ��쿣 txt ������ ���� �ȴ�. ���� ���� ���: �ƽ�Ű�ڵ�, ���̳ʸ�
	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}

	while ((c = getc(file)) != EOF)
		putchar(c);

	fclose(file); // ��Ʈ���� �ݴ´�.
	// visual studio���� ������ ���� vcxproj ���ϰ� ���� ��ο� �ִ� ������ ����ȴ�.
	// cmd â���� ������ ���� exe ���ϰ� ���� ��ο� �ִ� ������ ����ȴ�.



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

		// ����� �Է��� ���� �ʾҴٸ� ������� �Է��� ���ۿ� �����ִ�. �װ��� putchar()�� ����Ѵ�.
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

		// ù ���ں��� ���ڰ� �ƴ϶�� ����� �����Ѵ�.
		while (scanf("%ld", &input) != 1)
		{
			printf("Your input - ");
			while ((c = getchar()) != '\n')
				putchar(c);

			printf(" - is not an integer. Plese try again.\n");
		
			string_flag = 1;
		}

		// ���� + ������ �����̶�� ����� �����Ѵ�.
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
	// �Է��� ���� �� ù ��° ���ڸ� ��ȯ�Ѵ�.
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

		// ù ���ڰ� ���ڰ� �ƴ϶��
		while (scanf("%d", &input) != 1)
		{
			printf("Please Try Again.\n");
			while (getchar() != '\n') continue; // ���۸� ����.
			num_flag = 1;
		}

		//�߰��� ���ڰ� �ƴ� �� ���� �ִٸ�
		if ((ch = getchar()) != '\n' && !isdigit(ch))
		{
			printf("Please Try Again.\n");
			while (getchar() != '\n') continue; // ���۸� ����.
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
