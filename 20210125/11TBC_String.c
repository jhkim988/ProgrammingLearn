#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 81
#define MESSAGE "A Symbolic string constant"
#define STRLEN 81

int main()
{
	// 11.1 문자열을 정의하는 방법
	//char words[MAXLENGTH] = "A string in an array"; // 문자열 자체로 선언, 매번 글자 수를 셀 수 없기 때문에 넉넉하게 잡는다.
	//const char* pt1 = "A pointer to string"; // 포인터로 선언

	//puts("Puts() adds a new line at the end."); // puts함수는 문자열을 출력한다.(뒤에 \n을 넣어줌)
	//puts(words); // 초기화가 되지 않았다고 warning이 나온다. MAXLENGTH만큼 전부 초기화한 게 아니기 때문이다.
	//puts(pt1);
	//puts(MESSAGE);

	//words[3] = 'p'; // 교체가 된다.
	//puts(words);
	////pt1[8] = 'A'; // 교체가 안된다. const를 없애도 런타임 에러가 발생한다. 따라서 포인터로 문자열을 선언할 때는 const를 붙여주는 것이 좋다.
	//// 읽기 전용 메모리에 저장된 데이터값을 바꾸려고 시도하면 운영체제가 중단시킨다.
	//// 배열은 읽기/쓰기가 모두 가능한 메모리를 사용하지만, 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장돼 있다.

	//char greeting[50] = "Hello, and""How are" " you" " today!"; // 따옴표가 중간에 있어도, 사이에 빈칸이 있어도 컴파일이 된다.
	////char greeting[50] = "Hello, and How are you today!";
	//puts(greeting);

	//// 겹따옴표 escape sequence: \"
	//printf("\" To be, or not to be\" Hamlet said.\n");
	//printf("%s, %p, %c\n", "We", "are", *"excellent programmers");
	//// %s: 문자열 형식지정자, %p: 문자열도 배열이므로 첫 글자가 저장된 주소를 출력해준다.
	//// %c: "excellent..."의 주소는 첫 글자가 저장된 주소이다. 그것의 indirection은 e이다.

	//const char m1[15] = "Love you!";
	//for (int i = 0; i < 15; ++i)
	//	printf("%d ", (int)m1[i]); // Note the null character. 남는 공간도 전부 0으로 나오고 있다.
	//printf("\n");

	//const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };
	//const char m3[] = "Love you, too!";

	//for (int i = 0; i < 15; ++i)
	//	printf("%d ", (int)m2[i]); // \0을 빼도 알아서 0을 넣어준다.
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


	// 11.2 메모리 레이아웃과 문자열
	//char arr[] = "Hello, World!"; // 배열, 그 자체로 메모리를 갖고 있다.
	//char* str = "Hello, World!"; // 포인터, 문자열의 첫 번째 글자의 주소를 가리키고 있다.
	// str[0] = 'M'; // 런타임 에러 why??? -> 메모리 레이아웃과 관련돼 있다.

	// 리눅스 gcc 기준
	// 주소가 높은 쪽
	// 명령줄 인수와 환경변수들 
	// 스택 (지역변수들): 컴파일러가 메모리 크기를 미리 예측할 수 있는 경우에 스택 메모리를 사용한다.(스택을 사용하는 메모리는 속도가 빠르다.)
	// 자유공간: 스택이나 힙을 더 사용할 수 있는 공간
	// 힙: 메모리 크기를 미리 알 수 없을 경우에 힙 메모리를 사용한다.
	// 초기화되지 않은 전역/정적 변수들 (Block Started by Symbol segment)
	// 초기화된 전역/정적 변수들 (Data segment) // 두 가지로 나뉜다. Read Write Data segment / Read only data segment
	// 프로그램 코드 (Text segment) 읽기전용
	// 주소가 낮은 쪽
	 
	// 하드디스크에 저장된 프로그램을 실행하려면 메모리로 옮겨줘야한다.
	// 컴파일까지 끝난 프로그램은 크기가 고정돼 있을 것이다.
	// 프로그램 코드가 메모리에 올라와 있는 상태에서 운영체제가 프로그램을 실행시킬 때, 프로그램 코드 메모리를 수정하기 어렵다. 운영체제가 읽기 전용으로 바꿔놓는다.
	// 초기화된 전역/정적변수들도 컴파일 할 때 이미 정해져 있고(프로그래머가 원하는 값으로), 초기화되지 않은 전역/정적변수들은 0으로 초기화한다.
	
	//char arr[] = "Hello, World!"; // arr자체가 메모리를 갖고 있기 때문에 문자열을 바꿀 수 있다. 
	//char* str = "Hello, World!"; // 포인터는 string literal이 저장돼 있는 메모리 공간에 수정할 권한이 없다. 문자열 리터럴은 Read only data segment로 들어간다.

	//gcc -S main.c // -S 옵션을 주면 어셈블리 코드를 볼 수 있다.

	//const char* pt2 = "I am a string!.";
	//const char* pt3 = "I am a string!.";
	//const char* pt4 = "I am a string!!!!!!"; // different

	//const char arr1[] = "I am a string!.";
	//const char arr2[] = "I am a string!.";
	//const char arr3[] = "I am a string!!!!!!"; // different

	//// os에 따라 주소가 다르다.
	//printf("rodata low \t%llu %llu %llu %llu\n", (unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4, (unsigned long long)"I am a string!.");
	//	// pt2 pt3, 리터럴의 주소가 같다. pt4만 다르다. 컴파일러가 같은 문자 리터럴을 한 곳에 저장해두고 여러 번 사용한다.
	//	// 포인터를 이용해서 리터럴의 주소를 바꿀 수 있게 허용한다면 모두 바뀌게 되므로 문제가 생긴다.
	//printf("stack high \t%llu %llu %llu\n", (unsigned long long)arr1, (unsigned long long)arr2, (unsigned long long)arr3);
	//	// 배열이 각각 메모리를 갖고 있기 때문에 모두 주소가 다르다
	//printf("stack high \t%llu %llu %llu\n", (unsigned long long)&pt2, (unsigned long long)&pt3, (unsigned long long)&pt4);
	//	// 포인터 변수의 주소이기 때문에 모두 주소가 다르다.

	//int i;
	//printf("stack high \t%llu\n", (unsigned long long) & i);

	//char* p5 = (char*)malloc(sizeof(char) * 100);
	//printf("Heap middle \t%llu\n", (unsigned long long) p5);

	//char* p6 = (char*)malloc(sizeof(char) * 100);
	//printf("Heap middle \t%llu\n", (unsigned long long) p6);

	////arr++; // Error
	//pt2++;
	//puts(pt2); // 맨 앞글자가 사라졌다.

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

	//char* word = "Google"; // const  붙이는게 좋다.
	////word[2] = 'o'; // Runtime Error
	//puts(word);

	//const char* str1 = "When all the lights arw low, ...";
	//const char* copy;

	//copy = str1; // 주소 복사

	//printf("%s %p %p\n", str1, str1, &str1); // str1 포인터 변수 자체는 스택 메모리에 있고 문자열은 text segment에 있다.
	//printf("%s %p %p\n", copy, copy, &copy);

	////Note: strcopy(), strncopy() 깊은 복사


	// 11.3 문자열의 배열
	//const char* mythings[5] = {
	//	"Dancing in the rain",
	//	"Couting apple",
	//	"Watch movie with friends",
	//	"Writting sad letters",
	//	"Studying the C language"
	//}; // 포인터의 배열

	//char yourthings[5][40] = {
	//	"Stuyding the C++ language",
	//	"Eating",
	//	"Watching Netflix",
	//	"Walking around till dark",
	//	"Deleting spam emails"
	//}; // 배열의 배열

	//const char* temp1 = "Dancing in the rain";
	//const char* temp2 = "Studying the C++ language";

	//printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1); // 주소가 같다.
	//printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2); // 주소가 다르다.
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


	// 11.4 문자열을 입력받는 다양한 방법들
	//// 문자열을 입력받을 때 미리 저장공간을 확보해야한다.
	////char* name = ""; // Error at Run-time
	//char name[128];
	//int result = scanf("%s", name);

	////scanf() vs gets()
	//// scanf() reads one word
	//// gets() reads one line and remove \n and add \0

	//char words[STRLEN] = "";
	//gets(words); // pointer를 인자로 받는다. gets 함수 입장에서는 메모리의 끝을 모른다.(시작점만 받기 때문에)
	////gets_s(words, sizeof(words)); // C11, 권장, 일부 컴파일러에서는 사용할 수 없다.
	////int result = scanf("%s", words);

	//printf("START\n");
	//printf("%s", words); //no \n at the end
	//puts(words); // puts add \n at the end
	//puts("END");

	//// gets, gets_s 모두 메모리 공간을 너무 작게 잡으면(STRLEN) 런타임 에러가 발생한다.

	//char words[STRLEN] = "";
	//fgets(words, STRLEN, stdin); // 파일을 입력 받을 때 쓰는 함수이지만 stdin(standard input)을 입력하면 콘솔 입력도 받을 수 있다. 
	//// fgets 함수는 읽는 데이터의 크기가 더 클 것을 예상하고 작동하기 때문에 글자 수를 넘어도 런타임 에러가 발생하지 않는다.
	//// fgets 함수는 \n을 지워주지 않는다.(입력하려고 할 때 엔터를 치면 엔터도 입력된다.)
	//// fgets로 입력 받은 문자열에서 \n을 삭제해보자
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

	//fputs(words, stdout); // \n을 추가해주지 않는다.
	//fputs("END", stdout); // stdout을 하면 콘솔 창에 출력해준다. 

	//char small_array[5]; // \0을 포함까지 4글자를 입력받을 수 있다.
	//puts("Enter long strings:");
	////fgets(small_array, 5, stdin); // return 값이 char*이다. 정상적으로 입력 받았다면 입력 받은 포인터를 그대로 반환해준다. 잘못 입력 받았다면(End of File를 만나면) \0를 반환한다.
	//printf("%p\n", small_array); 
	//printf("%p\n", fgets(small_array, 5, stdin)); // ^Z를 입력하면 EOF이다. EOF를 만나면 NULL을 반환한다.
	//
	//fputs(small_array, stdout); // 입력받은게 더 크면 잘려서 출력된다.

	//// 작은 걸 쪼개서 여러 번 받을 수 있다.
	//char small_array[5];
	//puts("Enter long strings:");
	//while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
	//	fputs(small_array, stdout);
	
	// scanf로 입력 받을 때 글자 개수를 제한할 수 있다.
	char str1[6], str2[6];
	int count = scanf("%5s %5s", str1, str2);
	//int count = scanf("%6s %6s", str1, str2); // run-time error 
	//int count = scanf_s("%s %s", str1, 6, str2, 6); //  개수를 인자로 설정할 수 있다.
	printf("%s|%s \n", str1, str2);

	// custom_string_input 함수를 직접 만들어서 사용할 수도 있다.







	return 0;
}