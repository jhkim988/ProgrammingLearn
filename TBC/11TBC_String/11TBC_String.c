#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 81
#define MESSAGE "A Symbolic string constant"
#define STRLEN 81
#define TEST "A string from #define"
#define NUM_LIMIT 1024

// 11.5
void custom_put(const char* str); // Only two lines
int custom_put2(const char* str); // Add \n, return # of characters

// 11.6
void fit_str(char*, unsigned int);
char* my_strcat(char* str1, char* str2);
int my_strcmp(char* str1, char* str2);

// 11.7
void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

// 11.8
void swapString(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSortString(char* arr[], int n);

// 11.9
void ToUpper(char*);
int PunctCount(const char*);

int main()
{
	// 11.1 ���ڿ��� �����ϴ� ���
	//char words[MAXLENGTH] = "A string in an array"; // ���ڿ� ��ü�� ����, �Ź� ���� ���� �� �� ���� ������ �˳��ϰ� ��´�.
	//const char* pt1 = "A pointer to string"; // �����ͷ� ����

	//puts("Puts() adds a new line at the end."); // puts�Լ��� ���ڿ��� ����Ѵ�.(�ڿ� \n�� �־���)
	//puts(words); // �ʱ�ȭ�� ���� �ʾҴٰ� warning�� ���´�. MAXLENGTH��ŭ ���� �ʱ�ȭ�� �� �ƴϱ� �����̴�.
	//puts(pt1);
	//puts(MESSAGE);

	//words[3] = 'p'; // ��ü�� �ȴ�.
	//puts(words);
	////pt1[8] = 'A'; // ��ü�� �ȵȴ�. const�� ���ֵ� ��Ÿ�� ������ �߻��Ѵ�. ���� �����ͷ� ���ڿ��� ������ ���� const�� �ٿ��ִ� ���� ����.
	//// �б� ���� �޸𸮿� ����� �����Ͱ��� �ٲٷ��� �õ��ϸ� �ü���� �ߴܽ�Ų��.
	//// �迭�� �б�/���Ⱑ ��� ������ �޸𸮸� ���������, ���ڿ� ���ͷ��� ���α׷��� �Ϻ��̱� ������ �б� ���� �޸𸮿� ����� �ִ�.

	//char greeting[50] = "Hello, and""How are" " you" " today!"; // ����ǥ�� �߰��� �־, ���̿� ��ĭ�� �־ �������� �ȴ�.
	////char greeting[50] = "Hello, and How are you today!";
	//puts(greeting);

	//// �����ǥ escape sequence: \"
	//printf("\" To be, or not to be\" Hamlet said.\n");
	//printf("%s, %p, %c\n", "We", "are", *"excellent programmers");
	//// %s: ���ڿ� ����������, %p: ���ڿ��� �迭�̹Ƿ� ù ���ڰ� ����� �ּҸ� ������ش�.
	//// %c: "excellent..."�� �ּҴ� ù ���ڰ� ����� �ּ��̴�. �װ��� indirection�� e�̴�.

	//const char m1[15] = "Love you!";
	//for (int i = 0; i < 15; ++i)
	//	printf("%d ", (int)m1[i]); // Note the null character. ���� ������ ���� 0���� ������ �ִ�.
	//printf("\n");

	//const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };
	//const char m3[] = "Love you, too!";

	//for (int i = 0; i < 15; ++i)
	//	printf("%d ", (int)m2[i]); // \0�� ���� �˾Ƽ� 0�� �־��ش�.
	//printf("\n");

	//for (int i = 0; i < 15; ++i)
	//	printf("%d ", (int)m3[i]);
	//printf("\n");

	//int n = 8;
	//char cookies[1] = { 'A' };
	//char cakes[2 + 5] = { 'A', };
	//char pies[2 * sizeof(long double) + 1] = { 'A', };
	////char crumbs[n]; // VLA

	//char truth[10] = "Truths is ";
	//if (truth == &truth[0]) puts("true!");
	//if (*truth == 'T') puts("true!");
	//if (*(truth + 1) == truth[1]) puts("true!");
	//if (*(truth + 1) == 'r') puts("true!");


	// 11.2 �޸� ���̾ƿ��� ���ڿ�
	//char arr[] = "Hello, World!"; // �迭, �� ��ü�� �޸𸮸� ���� �ִ�.
	//char* str = "Hello, World!"; // ������, ���ڿ��� ù ��° ������ �ּҸ� ����Ű�� �ִ�.
	// str[0] = 'M'; // ��Ÿ�� ���� why??? -> �޸� ���̾ƿ��� ���õ� �ִ�.

	// ������ gcc ����
	// �ּҰ� ���� ��
	// ����� �μ��� ȯ�溯���� 
	// ���� (����������): �����Ϸ��� �޸� ũ�⸦ �̸� ������ �� �ִ� ��쿡 ���� �޸𸮸� ����Ѵ�.(������ ����ϴ� �޸𸮴� �ӵ��� ������.)
	// ��������: �����̳� ���� �� ����� �� �ִ� ����
	// ��: �޸� ũ�⸦ �̸� �� �� ���� ��쿡 �� �޸𸮸� ����Ѵ�.
	// �ʱ�ȭ���� ���� ����/���� ������ (Block Started by Symbol segment)
	// �ʱ�ȭ�� ����/���� ������ (Data segment) // �� ������ ������. Read Write Data segment / Read only data segment
	// ���α׷� �ڵ� (Text segment) �б�����
	// �ּҰ� ���� ��

	// �ϵ��ũ�� ����� ���α׷��� �����Ϸ��� �޸𸮷� �Ű�����Ѵ�.
	// �����ϱ��� ���� ���α׷��� ũ�Ⱑ ������ ���� ���̴�.
	// ���α׷� �ڵ尡 �޸𸮿� �ö�� �ִ� ���¿��� �ü���� ���α׷��� �����ų ��, ���α׷� �ڵ� �޸𸮸� �����ϱ� ��ƴ�. �ü���� �б� �������� �ٲ���´�.
	// �ʱ�ȭ�� ����/���������鵵 ������ �� �� �̹� ������ �ְ�(���α׷��Ӱ� ���ϴ� ������), �ʱ�ȭ���� ���� ����/������������ 0���� �ʱ�ȭ�Ѵ�.

	//char arr[] = "Hello, World!"; // arr��ü�� �޸𸮸� ���� �ֱ� ������ ���ڿ��� �ٲ� �� �ִ�. 
	//char* str = "Hello, World!"; // �����ʹ� string literal�� ����� �ִ� �޸� ������ ������ ������ ����. ���ڿ� ���ͷ��� Read only data segment�� ����.

	//gcc -S main.c // -S �ɼ��� �ָ� ����� �ڵ带 �� �� �ִ�.

	//const char* pt2 = "I am a string!.";
	//const char* pt3 = "I am a string!.";
	//const char* pt4 = "I am a string!!!!!!"; // different

	//const char arr1[] = "I am a string!.";
	//const char arr2[] = "I am a string!.";
	//const char arr3[] = "I am a string!!!!!!"; // different

	//// os�� ���� �ּҰ� �ٸ���.
	//printf("rodata low \t%llu %llu %llu %llu\n", (unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4, (unsigned long long)"I am a string!.");
	//	// pt2 pt3, ���ͷ��� �ּҰ� ����. pt4�� �ٸ���. �����Ϸ��� ���� ���� ���ͷ��� �� ���� �����صΰ� ���� �� ����Ѵ�.
	//	// �����͸� �̿��ؼ� ���ͷ��� �ּҸ� �ٲ� �� �ְ� ����Ѵٸ� ��� �ٲ�� �ǹǷ� ������ �����.
	//printf("stack high \t%llu %llu %llu\n", (unsigned long long)arr1, (unsigned long long)arr2, (unsigned long long)arr3);
	//	// �迭�� ���� �޸𸮸� ���� �ֱ� ������ ��� �ּҰ� �ٸ���
	//printf("stack high \t%llu %llu %llu\n", (unsigned long long)&pt2, (unsigned long long)&pt3, (unsigned long long)&pt4);
	//	// ������ ������ �ּ��̱� ������ ��� �ּҰ� �ٸ���.

	//int i;
	//printf("stack high \t%llu\n", (unsigned long long) & i);

	//char* p5 = (char*)malloc(sizeof(char) * 100);
	//printf("Heap middle \t%llu\n", (unsigned long long) p5);

	//char* p6 = (char*)malloc(sizeof(char) * 100);
	//printf("Heap middle \t%llu\n", (unsigned long long) p6);

	////arr++; // Error
	//pt2++;
	//puts(pt2); // �� �ձ��ڰ� �������.

	//char heart[] = "I Love Kelly!";
	//const char* head = "I Love Helly!";

	//for (int i = 0; i < 6; ++i)
	//	putchar(heart[i]);
	//putchar('\n');

	//for (int i = 0; i < 6; ++i)
	//	putchar(head[i]);
	//putchar('\n');

	//for (int i = 0; i < 6; ++i)
	//	putchar(*(heart + i));
	//putchar('\n');

	//for (int i = 0; i < 6; ++i)
	//	putchar(*(head + i));
	//putchar('\n');

	//while (*(head) == '\0')
	//	putchar(*(head++));
	//putchar('\n');

	//head = heart;
	////heart = head; // Error

	//heart[7] = 'H';
	////head[7] = 'K'; // Error

	//char* word = "Google"; // const  ���̴°� ����.
	////word[2] = 'o'; // Runtime Error
	//puts(word);

	//const char* str1 = "When all the lights arw low, ...";
	//const char* copy;

	//copy = str1; // �ּ� ����

	//printf("%s %p %p\n", str1, str1, &str1); // str1 ������ ���� ��ü�� ���� �޸𸮿� �ְ� ���ڿ��� text segment�� �ִ�.
	//printf("%s %p %p\n", copy, copy, &copy);

	////Note: strcopy(), strncopy() ���� ����


	// 11.3 ���ڿ��� �迭
	//const char* mythings[5] = {
	//	"Dancing in the rain",
	//	"Couting apple",
	//	"Watch movie with friends",
	//	"Writting sad letters",
	//	"Studying the C language"
	//}; // �������� �迭

	//char yourthings[5][40] = {
	//	"Stuyding the C++ language",
	//	"Eating",
	//	"Watching Netflix",
	//	"Walking around till dark",
	//	"Deleting spam emails"
	//}; // �迭�� �迭

	//const char* temp1 = "Dancing in the rain";
	//const char* temp2 = "Studying the C++ language";

	//printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1); // �ּҰ� ����.
	//printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2); // �ּҰ� �ٸ���.
	//printf("%u %u\n", (unsigned)&yourthings[0][0], (unsigned)temp2);
	//printf("\n");

	//printf("%-30s %-30s\n", "My Things", "Your Things");
	//for (int i = 0; i < 5; ++i)
	//	printf("%-30s %-30s\n", mythings[i], yourthings[i]);

	//printf("\nsizeof mythings: %zd, sizeof yourthings: %zd\n", sizeof(mythings), sizeof(yourthings));

	//for (int i = 0; i < 100; ++i)
	//	printf("%c", mythings[0][i]);
	//printf("\n");
	//printf("\n");
	//for (int i = 0; i < 200; ++i)
	//	printf("%d", (int)yourthings[0][i]);
	//printf("\n");
	//for (int i = 0; i < 200; ++i)
	//	printf("%c", yourthings[0][i]);
	//printf("\n");
	//printf("\n");


	// 11.4 ���ڿ��� �Է¹޴� �پ��� �����
	//// ���ڿ��� �Է¹��� �� �̸� ��������� Ȯ���ؾ��Ѵ�.
	////char* name = ""; // Error at Run-time
	//char name[128];
	//int result = scanf("%s", name);

	////scanf() vs gets()
	//// scanf() reads one word
	//// gets() reads one line and remove \n and add \0

	//char words[STRLEN] = "";
	//gets(words); // pointer�� ���ڷ� �޴´�. gets �Լ� ���忡���� �޸��� ���� �𸥴�.(�������� �ޱ� ������)
	////gets_s(words, sizeof(words)); // C11, ����, �Ϻ� �����Ϸ������� ����� �� ����.
	////int result = scanf("%s", words);

	//printf("START\n");
	//printf("%s", words); //no \n at the end
	//puts(words); // puts add \n at the end
	//puts("END");

	//// gets, gets_s ��� �޸� ������ �ʹ� �۰� ������(STRLEN) ��Ÿ�� ������ �߻��Ѵ�.

	//char words[STRLEN] = "";
	//fgets(words, STRLEN, stdin); // ������ �Է� ���� �� ���� �Լ������� stdin(standard input)�� �Է��ϸ� �ܼ� �Էµ� ���� �� �ִ�. 
	//// fgets �Լ��� �д� �������� ũ�Ⱑ �� Ŭ ���� �����ϰ� �۵��ϱ� ������ ���� ���� �Ѿ ��Ÿ�� ������ �߻����� �ʴ´�.
	//// fgets �Լ��� \n�� �������� �ʴ´�.(�Է��Ϸ��� �� �� ���͸� ġ�� ���͵� �Էµȴ�.)
	//// fgets�� �Է� ���� ���ڿ����� \n�� �����غ���
	//
	//// MyTry
	////int i = 0;
	////while (words[i] != '\n')
	////	i++;
	////words[i] = '\0';

	//int i = 0;
	//while (words[i] != '\n' && words[i] != '\0')
	//	i++;
	//if (words[i] == '\n')
	//	words[i] == '\0';

	//fputs(words, stdout); // \n�� �߰������� �ʴ´�.
	//fputs("END", stdout); // stdout�� �ϸ� �ܼ� â�� ������ش�. 

	//char small_array[5]; // \0�� ���Ա��� 4���ڸ� �Է¹��� �� �ִ�.
	//puts("Enter long strings:");
	////fgets(small_array, 5, stdin); // return ���� char*�̴�. ���������� �Է� �޾Ҵٸ� �Է� ���� �����͸� �״�� ��ȯ���ش�. �߸� �Է� �޾Ҵٸ�(End of File�� ������) \0�� ��ȯ�Ѵ�.
	//printf("%p\n", small_array); 
	//printf("%p\n", fgets(small_array, 5, stdin)); // ^Z�� �Է��ϸ� EOF�̴�. EOF�� ������ NULL�� ��ȯ�Ѵ�.
	//
	//fputs(small_array, stdout); // �Է¹����� �� ũ�� �߷��� ��µȴ�.

	//// ���� �� �ɰ��� ���� �� ���� �� �ִ�.
	//char small_array[5];
	//puts("Enter long strings:");
	//while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
	//	fputs(small_array, stdout);

	//// scanf�� �Է� ���� �� ���� ������ ������ �� �ִ�.
	//char str1[6], str2[6];
	//int count = scanf("%5s %5s", str1, str2);
	////int count = scanf("%6s %6s", str1, str2); // run-time error 
	////int count = scanf_s("%s %s", str1, 6, str2, 6); //  ������ ���ڷ� ������ �� �ִ�.
	//printf("%s|%s \n", str1, str2);

	//// custom_string_input �Լ��� ���� ���� ����� ���� �ִ�.


	// 11.5 ���ڿ��� ����ϴ� �پ��� �����
	//char str[60] = "String array initialized";
	//const char* ptr = "A pointer initialized";

	//puts("String with out \\n");
	//puts("END");
	//puts(TEST);
	//puts(TEST + 5);
	//puts(&str[3]);
	////puts(str[3]); // Error
	//puts(ptr + 3);

	// ���ڿ� ���� \0�� ���ٸ�?
	//char str[] = { 'H', 'I', '!' }; // \0�� �־����� ������
	//puts(str); // warning

	// puts() and fputs()
	//char line[100];
	//while (gets(line)) // while(gets(line) != NULL)
	//	puts(line);

	//char line[100];
	//while (fgets(line, 100, stdin))
	//	fputs(line, stdout);

	//char str[] = "Just do it, do it!";
	//printf("%s\n", str);
	//puts(str);

	//char input[100] = "";
	//int ret = scanf("%10s", input); // Input: "Just do it, do it!\n" 10���ڱ��� �޴´�. ���ۿ� ���� ���ڰ� �����ִ�.
	//printf("%s\n", input); // Output: "Just" scanf�� ��ĭ�� ������ �� ���� �ʱ� ������ Just�� ��µȴ�.

	//ret = scanf("%10s", input); // ���ۿ� �����ִ� �ͺ��� �Է� �ޱ� ������ "do"�� ����.
	//printf("%s\n", input); // Output: "do"

	//custom_put("Hello");
	//printf("%d", custom_put2("Hi"));


	// 11.6 �پ��� ���ڿ� �Լ���
	//// strlen: ���ڿ��� ���� ��ȯ
	//char msg[] = "Just,"" do it!";
	//puts(msg);
	//printf("Length %d\n", strlen(msg));
	//fit_str(msg, 4);
	//puts(msg);
	//printf("Length %d\n", strlen(msg));

	//// strcat() and strncat(): concatenation
	//char str1[100] = "First string"; // ù ��° ���ڿ��� �� ���� ���ڿ��� �߰����ִ� ���̱� ������ ������ �˳��� �־�� �Ѵ�.
	//char str2[] = "Second string";

	//strcat(str1, ", ");
	//strcat(str1, str2);
	//// strncat(str, str2, 2); // n���� + '\n'�� �߰����ش�.
	//puts(str1);

	//char my_str1[100] = "First My string_concat";
	//char my_str2[] = "test My String_concat";
	//my_strcat(my_str1, my_str2);
	//puts(my_str1);

	//// strcmp() and strncmp(): compare (not characters)
	//printf("%d\n", strcmp("A", "A")); // ������ 0 ��ȯ
	//printf("%d\n", strcmp("A", "B")); // ������ ������ -1 ��ȯ
	//printf("%d\n", strcmp("B", "A")); // �������� ������ 1 ��ȯ
	//printf("%d\n", strcmp("Hello", "Hello")); // 0
	//printf("%d\n", strcmp("Banana", "Bananas")); // -1
	//printf("%d\n", strcmp("Bananas", "Banana")); // 1
	//printf("%d\n", strncmp("Bananas", "Banana", 6)); // 0, 6���ڱ����� ��

	//printf("%d\n", my_strcmp("A", "A")); // ������ 0 ��ȯ
	//printf("%d\n", my_strcmp("A", "B")); // ������ ������ -1 ��ȯ
	//printf("%d\n", my_strcmp("B", "A")); // �������� ������ 1 ��ȯ
	//printf("%d\n", my_strcmp("Hello", "Hello")); // 0
	//printf("%d\n", my_strcmp("Banana", "Bananas")); // -1
	//printf("%d\n", my_strcmp("Bananas", "Banana")); // 1


	//// strcpy() and strncpy(): copy
	//char dest[100] = "123456789";
	//char source[] = "Start programming!";
	////dest = source; // Error
	////dest = "Start something!"; // Error
	//strcpy(dest, source);
	//strncpy(dest, source, 5); // '\0' is NOT added
	//strcpy(dest, source + 6);
	//strcpy(dest, source);
	//strcpy(dest + 6, "coding!");
	//puts(dest);

	//// sprintf
	//char str[100] = "";
	//int i = 123;
	//double d = 3.14;
	//sprintf(str, "%05d.png %f", i, d); // printf�� ���ڿ��� ���ش�.
	//puts(str);

	//printf("%s\n", strchr("Hello, World", 'W')); // �� ��° ������ ��ġ�� ã�� �����ͷ� �������ش�.
	//
	//printf("%s\n", strpbrk("Hello, World", "ABCDE")); // "ABCDE" �� �ϳ��� �����ϴ� ��ġ�� ã�� ������ ����
	//printf("%s\n", strpbrk("Hello, World", "abcde"));

	//printf("%s\n", strrchr("Hello, World, Hello, World", 'l')); // 'l'�� �����ϴ� ���� ������ �����͸� ã�� ����

	//printf("%s\n", strstr("Hello, World", "wor")); // "wor"�� ���� �����͸� ã�� ����
	//printf("%s\n", strstr("Hello, World", "Wor"));


	// 11.7 ���� ���� ���� Ǯ��
	//int arr[5] = { 64, 25, 12, 22, 11 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//printArray(arr, n);
	//selectionSort(arr, n);
	//printArray(arr, n);


	// 11.8 ���ڿ��� �����͸� �����ϱ�
	//char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	//int n = sizeof(arr) / sizeof(arr[0]);

	//printStringArray(arr, n);
	//selectionSortString(arr, n);
	//printStringArray(arr, n);


	// 11.9 ���� �Լ��� ���ڿ��� ����ϱ�
	//char line[NUM_LIMIT];
	//char* new_line = NULL;
	//fgets(line, NUM_LIMIT, stdin);
	//new_line = strchr(line, '\n'); // find first new line
	//if (new_line)
	//	*new_line = '\0';
	//ToUpper(line);
	//puts(line);
	//printf("%d\n", PunctCount(line));


	return 0;
}
// 11.5
void custom_put(const char* str)
{
	// \n�� ������ �ʴ´�.
	// ������ ��������� putchar()�� �̿��Ѵ�.
	while (*str)
		putchar(*str++);
}
int custom_put2(const char* str)
{
	// \n �߰�
	// ��ȯ������ �� ��������
	int count = 0;
	while (*str)
	{
		putchar(*str++);
		count++;
	}
	putchar('\n');
	return count;
}

// 11.6
void fit_str(char* str, unsigned int num)
{
	if (num < strlen(str))
		str[num] = '\0';
}
char* my_strcat(char* str1, char* str2)
{
	int count = 0;
	char* temp = str1;
	
	// ���ڼ��� ����.
	while (*temp)
	{
		temp++;
		count++;
	}
	temp = str2;
	while (*temp)
	{
		*(str1 + count) = *temp; // str1���� \0�� ������ �̾ str2�� �����.
		count++;
		temp++;
	}
	return str1;

}
int my_strcmp(char* str1, char* str2)
{
	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
			continue;
		}
		else if (*str1 < *str2)
			return -1;
		else
			return 1;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	else if (*str1 == '\0')
		return -1;
	else if (*str2 == '\0')
		return 1;
	else
		printf("Error");
}

// 11.7
void swap(int* xp, int* yp)
{
	int temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;

}
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
		//printArray(arr, n);
	}
}

// 11.8
void swapString(char** xp, char** yp)
{
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void printStringArray(char* arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		char* ptr = arr[i];
		while (*ptr)
			printf("%c", *ptr++);
		printf(" ");
	}
	printf("\n");
}
void selectionSortString(char* arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(arr[j], arr[min_idx]) < 0)
				min_idx = j;
		}
		swapString(&arr[i], &arr[min_idx]);
		//printStringArray(arr, n);
	}
}

// 11.9
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
int PunctCount(const char* str)
{
	int count = 0;
	while (*str)
		if (ispunct(*str++))
			count++;

	return count;
}