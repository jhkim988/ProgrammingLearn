#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592f

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen and more
#include <inttypes.h> // intmax_t

struct MyStruct
{
	int i; // 4 byte
	float f; // 4 byte
};

int main()
{
	char fruit_name; // store only one character.
	printf("What is your favorate fruit?\n");
	scanf("%c", &fruit_name); // be careful with &
	printf("You like %c!\n", fruit_name);

	char fruit_name_modi[40]; // 1byte 저장공간을 40개 확보
	printf("What is your favorate fruit?\n");
	scanf("%s", fruit_name_modi); // %s, & 주의
	printf("You like %s!\n", fruit_name_modi);

	// 1. sizeof basic types
	//sizeof의 반환값이 unsigned
	int a = 0;
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);

	// 다른 시스템에서 sizeof()가 unsigned int 말고 다른 값을 반환할 수도 있으므로...
	size_t int_size4 = sizeof(a);
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4); // 형식지정자 %zu
	printf("Size of float type is %zu bytes.\n", float_size);


	// 2. sizeof arrays
	int int_arr[30]; // int_arr[0] = 1024; ... // 배열에서 배열의 변수이름(int_arr)은 30개의 메모리 공간을 대표하는 메모리 주소를 의미하는데, 그것의 맨 앞주소다.
	int* int_ptr = NULL; // 주소를 적을 수 있는 종이만 갖는다. 어떤 주소를 적을지는 나중에(아래에서) 정해진다. 동적할당
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ... malloc = memory allocation

	printf("Size of array = %zu bytes.\n", sizeof(int_arr)); // 30개 * 4바이트 = 120, 주소의 size가 나오는 것 아닌가?
	printf("Size of array = %zu bytes.\n", sizeof(int_ptr)); // 주소를 적는 공간의 사이즈(4)가 나온다.

	// 3. sizeof character array
	char c = 'a';
	char string[10]; // maximally 9 character + '/0' (null character) // C언어에서는 문자열을 저장할 때 마지막에 null character를 항상 저장한다.

	size_t char_size = sizeof(char); // 1
	size_t str_size = sizeof(string); // 10

	// 4. sizeof structure
	printf("%zu\n", sizeof(struct MyStruct)); // 8


	// 문자열이 메모리에 저장되는 구조
	// 숫자 하나: 4byte
	// 숫자의 배열: 4byte * 배열의 크기
	// 문자 하나: 1byte
	// 문자의 배열: 1byte * 배열의 크기
	// 문자열의 마지막이 어딘지 표현하기 위해 마지막에 \0이 들어간다.

	int int_arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // 배열을 초기화 할 때 {}를 이용한다. 40byte
	printf("%i %i %i\n", int_arr1[0], int_arr1[1], int_arr1[9]);
	// printf("%i\n", int_arr[10000]); // exited code -1037... 0이 아니다

	char str1[10] = "Hello"; // Hello\0
	char str2[10] = { 'H', 'i' };

	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]);

	//char str3[10] = "Hello, World!"; // array size is not enough
	char str3[20] = "Hello, \0World!"; // null character를 중간에 넣어보면..
	printf("%s\n", str3); // \0을 만나면 출력이 종료된다.
	
	for (int i = 0; i < 20; i++)
	{
		printf("%hhi ", str3[i]); // 실제로는 배열에 값이 저장돼 있다.
	};
	printf("\n");

	// strlen() 함수
	char str1_len[100] = "Hello";
	char str2_len[] = "Hello"; // 컴파일러가 알아서 크기에 맞게 공간을 할당해준다.
	char str3_len[100] = "\0";
	char str4_len[100] = "\n";

	printf("%zu %zu\n", sizeof(str1_len), strlen(str1_len));
	printf("%zu %zu\n", sizeof(str2_len), strlen(str2_len));
	printf("%zu %zu\n", sizeof(str3_len), strlen(str3_len));
	printf("%zu %zu\n", sizeof(str4_len), strlen(str4_len));

	char *str5_len = (char*)malloc(sizeof(char) * 100); // sizeof는 포인터 변수 자체의 사이즈(주소의 사이즈)
	str5_len[0] = 'H';
	str5_len[1] = 'e';
	str5_len[2] = 'l';
	str5_len[3] = 'l';
	str5_len[4] = 'o';
	str5_len[5] = '\0';
	printf("%zu %zu\n", sizeof(str5_len), strlen(str5_len));


	// 기호적 상수와 전처리기
	// define PI 3.141592f
	// PI 대신 3.141592f로 바꾸고 컴파일한다.

	// define 보다 const를 사용하여 symbolic constant를 이용하는 것을 권장한다.
	// const float pi = 3.141592f;
	float radius, area, circum;

	printf("Input radius\n");
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = 2.0f * PI * radius;
	printf("Area is %f.\n", area);
	printf("Circumference is %f.\n", circum);


	// Manifest Constants(명백한 상수들)
	// 1. #define을 이용하여..
	// 2. <limits.h>에 있는 INT_MAX, ...
	// 3. <float.h>에 있는 FLT_MAX, ...
	// 4. CHAR_BIT char이 몇 bi인지... etc

	// printf 함수의 변환지정자
	// printf("제어 문자열", 아이템1, 아이템2, ...);
	// %[flags][width][.precision][length]specifier
	printf("%+10.5hi\n", 256);

	// %a, %A: 부동 소수점수, 16진수, p(P)-표기법
	// %g, %G: 값에 따라 %e나 %f 사용 (지수가 -4보다 작거나 정밀도보다 크거나 같을 경우에는 %e 사용)
	// %p: 포인터
	// %u %x %X: 부호가 없다.	

	double d = 3.141592653589793238462643383279502884197169399375105820974944; // 8byte에 담을 수 있는 양만 담아지고 그 이후는 컴파일러가 잘라준다.
	printf("%c\n", 'A');
	printf("%s", "I love you.\n");
	printf("Even if there's small chance, \
we owe this to everyone who's not in this room to try.\n");
	
	printf('\n');
	printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX);
	printf("%u %u %u\n", 1024, -1, UINT_MAX);

	printf("\n");
	printf("%f %f %lf\n", 3.141592f, d, d); // printf 내부에서 float를 출력할 때 double로 바꿔버린다. 사실 double을 출력하는 것 따라서 %lf에서 l이 무시가 된다.
	printf("%a %A\n", d, d);
	printf("%e %E\n", d, d);

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89);
	printf("%G %G\n", 123456.789, 1234567.89);
	printf("%g %g\n", 0.00012345, 0.000012345);
	printf("%G %G\n", 0.00012345, 0.000012345);

	printf("\n");
	printf("%o\n", 9);
	printf("%p\n", &d); // pointer-of operator

	printf("\n");
	printf("%x %X\n", 11, 11);
	printf("%%\n", d); // d is ignored.

	printf("\n");
	printf("%9d\n", 12345); // 9칸으로 채운다(빈칸)
	printf("%09d\n", 12345); // 9칸으로 채운다(0)
	printf("%.2f\n", 3.141592); // 소숫점 2자리만
	printf("%.20f %.20lf\n", d, d); // double 타입이 담지 못하는 숫자는 짤린다.

	printf("\n");
	int n_printed = printf("Counting!"); // 글자 수를 반환한다.
	printf("%u\n", n_printed); // 9


	// 변환 지정자의 수식어
	// %[flags][width][.precision][length]specifier
	// +: 양수일 때도 + 기호를 붙여준다.
	// 10: 최소 10자리
	// .5: 정밀도
	// h: short
	printf("%+10.5hi", 256);

	// flags: - + (space) # 0
	// -: - flags가 있으면 왼쪽으로 붙이고, 없으면 오른쪽으로 붙여서 출력한다. (width와 함께 써야된다.)
	// +: 양수일떄도 + 기호를 붙여준다.
	// (space): 양수일 때는 + 기호 대신 빈칸을 넣는다.
	// #: 8진법, 16진법에서 0, 0x를 붙여준다.(o, O, x, X specifier 사용할 떄) a, A, e, E, f, F, g, G에서도 비슷하게 작동한다.
	// 0: width와 함께 사용했을 때 남는 자리를 0으로 채운다.

	// width: (number), *
	// (number): 지정한 숫자가 최소 길이가 된다.
	// *: 사용자가 *에 따로 숫자를 넣을 수 있게 해준다.

	// .precision: (number), *
	// (number): 지정한 숫자만큼 정밀도를 보장해준다. 숫자가 부족하면 0으로 채워준다.
	// *: 사용자가 *에 따로 숫자를 넣을 수 있게 해준다.

	// length: hh, h, l, ll, j, z, t, L
	// length는 데이터 타입의 길이이다.

	printf("%10i\n", 1234567);
	printf("%-10i\n,", 1234567);
	printf("%+i %+i\n". 123, -123);
	printf("% i \n% i\n", 123, -123);
	printf("%X\n", 17);
	printf("%#X\n", 17);
	printf("%05i\n", 123);
	printf("%*i\n", 7, 456);

	printf("\nPrecision\n");
	printf("%.3d\n", 1024); // 1024
	printf("%.5d\n", 1024); // 01024
	printf("%.3f\n", 123456.1234567);
	printf("%.3f\n", 123456.12345);
	printf("%10.3f\n", 123.45678);
	printf("%010.3f\n", 123.45678);
	printf("%.5s\n", "ABCDEFGHIJKLMN"); // ABCED 글자 개수
	printf("%.s\n", "ABCDEFGHIJKLMN"); // %0.s

	printf("\nLength\n");
	printf("hhd %hd %d\n", 257, 257, 257); // OverFlow
	printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL); // OverFlow, long long, x86이면 다르게 나온다.


	// printf() 함수가 인자들을 해석하는 과정
	float n1 = 3.14f;
	double n2 = 1.234;
	int n3 = 1024;

	// 1. n1, n2, n3를 스택으로 옮긴다. printf에서는 float를 double로 변환하여 4byte에서 8byte로 늘어난다.
	// 2. %d %d %d에서 모두 정수형 4byte이므로, 총 12byte를 읽는다. 그러면 n1을 반 쪼개서 %d 두 개에 들어가고 n2의 절반이 나머지 %d에 들어가게 된다. n3는 읽히지 않는다.
	printf("%f %f %d\n\n", n1, n2, n3);
	
	// Note the warnings in output window
	printf("%d %d %d\n", n1, n2, n3); // (4, 4, 4) N N N
	printf("%lld %lld %d\n\n", n1, n2, n3); // (8, 8, 4) N N Y
	printf("%f %d %d\n\n", n1, n2, n3); // (8, 4, 4) Y N N
	printf("%f %lld %d\n\n", n1, n2, n3); // (8, 8, 4) N N Y 
	

	// scanf() 함수의 사용법
	// *: 무시한다.
	// 숫자: 입력 받을 최대 길이

	// scanf에서 double을 입력 받을 때는 printf와 다르게 %lf를 이용해야한다.
	// 빈칸이 있으면 끊어버리기 때문에 한 단어씩만 받을 수 있다.
	int i_scanf;
	float f_scanf;
	char str_scanf[30];
	scanf("%d %f %s", &i_scanf, &f_scanf, str_scanf); // 배열을 입력 받을 땐 &를 붙이지 않는다.
	printf("%d %f %s\n", i_scanf, f_scanf, str_scanf);

	char c_scanf;
	scanf(% c, &c);
	printf("%i\n", c); // blank is 32.. 빈칸으로 구분하는 것과 차이

	// unsigned타입을 signed로 입력받고 출력한다.
	// -123를 입력하면 -123 제대로 출력된다.
	// integer로 입력받고 출력했기 때문에 제대로 출력된다.
	unsigned ui_scanf;
	scanf("%i", &ui_scanf);
	printf("%i\n", ui_scanf);

	unsigned ui2_scanf;
	scanf("%u", &ui2_scanf); // try negative number
	printf("%u\n", ui2_scanf); // overflow
	
	// double을 scanf로 입력할 땐 %lf, printf로 출력할 땐 %f
	double d_scanf = 0.0;
	scanf("%lf", &d_scanf);
	printf("%f\n", d_scnaf);

	// Width
	char str1_scanf[30];
	scanf("%5s", str1_scanf); // 5글자까지, 넘으면 자른다.
	printf("%s\n", str1_scanf);
	
	char c_scanf;
	scanf("%hhd", &c_scanf); // try large numbers
	printf("%i\n", c_scanf);

	int i1_scanf;
	scanf("%i", &i); // try '123ab', '123a456'
	printf("%i\n", i); // 문자를 만나기 전까지 만난 숫자만 넣어준다.

	intmax_t i2_scanf;
	scanf("%ji", &i2_scanf);
	printf("%ji", i2_scanf);

	// Regular characters
	int a_scanf, b_scanf;
	scanf("%d,%d", &a_scanf, &b_scanf); // %d,%d // ","로만 구분된다. 다른 기호, 알파벳을 넣을 수도 있다.
	printf("%d, %d\n", a_scanf, b_scanf);

	// 입출력을 받는 다른 함수 (한 글자씩, 혹은 다른 파일로부터 ...)
	// scanf 함수의 return 값 = 입력받은 값의 개수

	// * Modifier for printf()
	int i3_scanf = 123;
	int width_scanf = 5;
	printf("Input width: ");
	scanf("%d", &width_scanf);
	printf("%*d\n", width_scanf, i3_scanf);
	
	// * Modifier for scanf()
	int i4_scanf;
	scanf("%*d%*d%d", &i4_scanf); // *를 넣으면 무시가 돼서, 입력을 세 개를 받지만 *가 없는 마지막 %d가 &i4_scanf에 들어간다.
	printf("Your thrid input = %d", i4_scanf);

	return 0;
}