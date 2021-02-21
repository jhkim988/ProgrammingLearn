#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 16.6
/*
#include <stdio.h> // 컴파일러가 위치를 알고 있는 경우.. 대부분 표준 라이브러리
#include "my_functions.h"
// #include "my_functions.c"
#include "my_structures.h"
#include "my_headers/my_macros.h" // 절대 경로로 해도 된다. vs 설정에서 경로를 추가하면 <>로 바꿀 수 있다.
extern int status;
*/

// 16.7
/*
#include "Header_B.h"
#define TYPE 3
#if TYPE == 1
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function()
{
    printf("Worng compile option!");
}
#endif

#define REPORT // 매크로 이름만 정의, empty macro
//#undef REPORT
int sum(int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; ++k)
    {
        s += k;
#ifdef REPORT
    printf("%d %d\n", s, k);
#endif
    }
    return s;
}

// multiplatform
void say_hello()
{
    // _WIN64, _WIN32, __linux__ 등은 컴파일러가 어딘가에서 define을 해둔다.
    // defined 연산자.. defined(_WIN64) -> 정의가 돼있으면 true 리턴, 안 돼있으면 false 리턴
#ifdef _WIN64
    printf("Hello, WIN64");
#elif _WIN32
    printf("Hello, WIN32");
#elif __linux__
    printf("Hello, linux");
#endif
}
*/

// 16.8
/*
#include "DifferentFile.h"
void different_function()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d\n", __LINE__);
}
*/

// 16.9
/*
#pragma pack(1)
struct s {
    int i;
    char ch;
    double d;
};
*/

// 16.10
/*
#define MYTYPE(X) _Generic((X), \
int: (X + 123), \
float: "float", \
double: "double", \
long: "long", \
int*: "int*", \
default: "other"\
)
*/

// 16.11
/*
// c파일에 직접 넣기보단 헤더파일에서 사용하는 것이 일반적이다.
inline static int foo() // static을 붙이지 않으면 기본적으로 external이기 때문에 gcc, clang에서 컴파일 오류가 발생한다.
{
    return 5;
}
*/

// 16.13
// #include <math.h>

// 16.14
/*
#include <stdlib.h>
// rand() srand() malloc(), free(), ...

void goodbye(void)
{
    printf("Good Bye.\n");
}

void thankyou(void)
{
    printf("Thank you.\n");
}

// 비주얼 스튜디오에서 지원하지 않는다.
//_Noreturn void stop_now(i)
//{
//    if (i > 0) exit(i);
//}
*/

// 16.15
/*
#include <assert.h>
int divide(int a, int b)
{
    // 반드시 만족해야할 조건을 assert()에 넣어준다.
    assert(b != 0);
    //if (b == 0)
    //{
    //    printf("Cannot divide\n");
    //    exit(1);
    //}
    return a / b;
}
*/

// 16.16
/*
#include <string.h>
#define LEN 30
void prt(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
*/

// 16.17
#include <stdarg.h>
#include <string.h>
double average(int num, ...) // '...'는 맨 뒤에 와야한다. '...'만 넣어도 안된다.
{
    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, num); // 매크로, '...' 앞에 있는 가장 마지막 인자를 넣어준다.
    for (i = 0; i < num; ++i)
        sum += va_arg(ap, double); // '...'에서 어떤 타입을 받을지
    va_end(ap); // '...'의 사용이 끝나면..

    return sum / (double)num;
}

double average2(char* format_string, ...)
{
    int num = strlen(format_string);

    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, format_string); // 매크로, '...' 앞에 있는 가장 마지막 인자를 넣어준다.
    for (i = 0; i < num; ++i)
        sum += va_arg(ap, double); // '...'에서 어떤 타입을 받을지
    va_end(ap); // '...'의 사용이 끝나면..

    return sum / (double)num;
}

int main()
{
    // 16.1 전처리기가 해주는 일들
    // 빌드: 프로그램 코드 - 전처리기 - 컴파일러 - 링커 - 실행파일
    // 전처리 - 컴파일러가 이해할 수 있도록 번역, 프로그래머의 효율을 높여주는 기능, 코드를 다양하게 컴파일

    // 16.2
    // // translating preprocessing compiling linking executable

    // // International characters
    // puts("안녕하세요?\n");

    // // Trigraph Sequence
    // // 옛날 키보드에서는 특수문자(#, \, ^ 등)을 입력할 수 없어서 세 글자로 대신 입력했다.
    // // ??= , #
    // // ??/ , \

    // int arr[3] = {1, 2, 3};
    // // printf("arr??(0??) == %d\n", arr??(0??)); // trigraph
    // printf("arr[0] == %d\n", arr[0]);

    // // 에러가 난다면 컴파일 옵션에 /Zc를 입력해야(Trigraph를 사용한다는 의미) 컴파일 오류가 안 난다.
    // // Commandline - additional option - /Zc
    
    // // digraph도 있다.
    // // <: , [
    // // :> , ]
    
    // // printf("arr<:1:> == %d=\n", arr<:1:>); // trigraph는 " " 겹따옴표 내부에서도 치환을 해주지만, digraph는 해주지 않는다.

    // // two physical line vs one logical line
//     printf("This is very very very very very very very very very very very very\
//  long long long long long long long long long long long long long long long long long longline\n");
    // // \을 넣어서 문자열을 보기 좋게 바꾼다. 대신 다음 줄에서 빈칸(들여쓰기)도 같이 입력되기 때문에 없애준다.

    // // Token 단위(빈칸, 줄바꿈, 탭 등을 기준)로 쪼갠다.
    // // 주석은 빈칸 한칸, 빈칸 여러 칸은 빈칸 한 칸으로 바꾼다.
    // int/*a vaiable to count a number*/n = 1;

    // 16.3 #define 매크로
    // // #로 시작 - 전처리 지시자
    // // macro: 여러 명령어를 하나의 명령어로 축약시킨 것

    // // #define SAY_HELLO printf("Hello, world!\n");
    // // preprocessor Macro(name) body(or replacement list)
    // // macro expension

    // // object-like macro vs function-like macro
    // #define ONE 1 // 변수처럼 쓰지만, 전처리기가 ONE을 1로 바꾼 후에 컴파일 하기 때문에 컴파일러 입장에선 변수는 아니다.
    // #define SQUARE(X) X*X // 전처리기가 그냥 단순하게 X*X로 교체한다.

    // #define PI 3.141592
    // #define GRAVITY 9.8
    
    // #define THREE 3
    // #define MESSAGE "Hello world!"

    // #define NINE THREE*THREE
    // #define SAY_HELLO printf("Hello, World!");
    // #define FORMAT "Number is %d\n"
    //  #define WITH_BLANK 1
    // #define MY_CH 'Z'
    // #define MY_ST "Z" // Z\0

    // #define LIMIT 20
    // const int LIM = 50;
    // static int arr1[LIMIT];

    // // static int arr1[LIM]; // gcc에서도 안된다. c++/clang에선 된다.
    // const int LIM2 = 2 * LIMIT;
    // // const int LIM3 = 2 * LIM;  // c++/clang

    // // 아래는 컴파일러에 따라 다르다.
    // // #define SIX 3*2 // 문자열로 해석할지, 표현식으로 해석할지... 등
    // // #define SIX 3   *   2 // ??

    // // Redefine constant
    // #define SIX 2*3
    // #define SIX 2*3
    // // define의 범위는 파일 범위이다.
    // // 헤더파일에 #define이 돼 있고 그 파일을 #include 하면, #include 한 파일에서도 #define이 된 것처럼 사용된다.
    // // 그러는 과정에서 Redefine이 일어날 수 있기 때문에(헤더파일 사용자가 무엇이 있는지 다 알지 못하기 때문에) 허용한다.
    // // #define SIX 2* 3 // 토큰 단위로 봤을 때 다르면 warning이 나온다.

    // #undef SIX
    // #define SIX 2 * 3 // #undef를 해줄 수도 있다.

    // int n = THREE;
    // SAY_HELLO;
    // n = NINE;

    // printf(FORMAT, n);
    // printf("%s\n", MESSAGE);
    // printf("SAY_HELLO NINE\n"); // Not Replaced

    // 16.4 함수같은 매크로
    // // #define ADD(X,Y) ((X)+(Y))
    // // X and Y : macro arguments

    // #define ADD1(X,Y) X+Y // 의도치 않은 결과가 나올 때가 많다.
    // #define ADD2(X,Y) ((X)+(Y))
    // #define SQUARE(X) X*X

    // int sqr = SQUARE(3);
    // int a = 1;

    // printf("%d\n", 2 * ADD1(1, 3)); // 2 * X + Y = 2 * 1 + 3 = 5... 의도한 결과가 아니다
    // printf("%d\n", 2 * ADD2(1, 3)); // 2 * ((1) + (3)) = 2 * 4 = 8

    // printf("%d\n", SQUARE(1 + 2)); // 1 + 2 * 1 + 2 = 5... 의도한 결과가 아니다.
    // printf("%d\n", 100 / SQUARE(3 + 1)); // 100 / 3 + 1 * 3 + 1 = 33 + 3 + 1 = 37... 의도한 결과가 아니다.
    // printf("%d\n", SQUARE(++a)); // ++a * ++a = 3 * 3 = 9 Dangerous..

    // // Stringizing operator #
    // #define SQUARE(X) (X)*(X) 
    // #define PRINT_SQR1(x) printf("The square of %d is %d.\n",x, SQUARE(x));
    // #define PRINT_SQR2(x) printf("The squre of " #x " is %d.\n", SQUARE(x)); // 전처리기가 #x를 문자열로 바꿔버린다.

    // PRINT_SQR1(10);
    // PRINT_SQR2(10);

    // // ## operator
    // // 두 개의 토큰을 하나로 합쳐준다.
    // #define XNAME(n) x ## n
    // #define PRT_XN(n) printf("x" #n " = %d\n", x ## n);

    // printf("\n");
    // int XNAME(1) = 1; // int x1 = 1;
    // int XNAME(2) = 2; // int x2 = 2;

    // PRT_XN(1); // printf("x1 = %d\n", x1);
    // PRT_XN(2); // printf("x2 = %d\n", x2);

    // // 매크로를 함수처럼 사용하기 보다 그냥 함수를 사용하는 것이 좋다.
    // // 컴파일러가 문제를 찾아주지 못한다.

    // // 최근에는 함수로 모두 바꾸고 있다.
    // // 속도도 컴파일러가 최적화 해주는것이 더 빠르다.
    // #define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
    // #define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
    // #define ABS(X,Y) ((X) < 0 ? -(X) : (X))
    
    // 16.5 가변인수 매크로
    // #define PRINT(X, ...) printf("Message " #X ": " __VA_ARGS__)
    // // ... : ellipses
    // // __VA_ARGS__ : one of the predefined macros

    // double x = 48;
    // double y;

    // y = sqrt(x);
    // PRINT(1, "x = %g\n", x); // printf("Message 1 : x = %g\n", x);
    // PRINT(2, "x = %.2f, y = %.4f\n", x, y);

    // 16.6 #include와 헤더파일
    //// include는 단순히 전처리기가 파일 내용을 복사 붙여넣기 하는 것이다.
    //#include "hello_world.h" // hello world 출력.. 이런식으로 코딩하면 안된다.

    //printf("PI = %f\n", PI);
    //printf("%p %d\n", &status, status);
    //print_status();

    //// header file의 static
    //// static 키워드는 파일 스코프를 갖는다.
    //// #include는 복사 붙여넣기 하는 것과 같기 때문에, #include 한 파일에서 파일 스코프를 갖는다.

    //printf("%d\n", multiply(51, 2));

    //printf("main()\n");
    //printf("Static function address %p\n", multiply);
    //printf("Static vatiable address %p\n", &si);

    //print_address();
    //// 직접 my_functions.c 파일을 #include 하면 ststic function/variable의 주소가 같다. (gcc 컴파일러에서는 작동되지 않음 실행 설정을 해줘야 하는듯?)
    //// #include는 코드 내용을 복사/붙여넣기 하는 것과 거의 같기 때문에, main()함수가 있는 파일에서 코드가 복사된 것으로 인식돼 그런 듯하다.
    //// 비주얼 스튜디오에서는 my_functions.h만 #include 해도 링커가 c파일까지 연결해준다.
    //// print_address()를 하면 my_functions.c에 있는 static 변수/함수의 주소가 출력되기 때문에 주소가 다르다..

    //// #pragma once
    //// 헤더가드, 헤더가드가 없으면 중복으로 #include되는 상황이 일어난다. (자기가 자기자신을 #include 될 수도 있다.)
    //// 자기 자신을 #include 하면 Too many include 에러가 나온다.
    //
    ////#ifndef __MY_FUNCTIONS__ // if not define
    ////#define __MY_FUNCTIONS__
    ////#endif // end if

    //// #pragma once가 #ifndef - #define - #endif 과정을 해주는 것이다.

    // 16.7 조건에 따라 다르게 컴파일 하기
    // #undef: #define 했던 것을 undefine 시킨다. 정의가 되지 않은 키워드도 undefine 시킬 수 있다.
    // #pragma once    
    //test_function_A();
    //test_function_B();
    // 중복 #include... already has a body Error

    // #if #elif #else #endif
    // TYPE의 값에 따라 #include를 다르게 하여 다른 함수(이름은 같다.)를 호출한다.
    //my_function();

    //printf("\n%d \n", sum(1, 10));
    //
    //// properties -> C/C++ -> Preprocessor에서 설정을 해서 전처리기 정의 값을 만들 수 있다. (REPORT;)
    //// Debug/Release 모드를 설정하거나 할 수 있다.
    //// Release 모드에서는 세부값이 보이지 않고, Debug 모드에서만 세부 사항이 보일 수 있게끔 코딩할 수도 있다.

    //say_hello();

    // 16.8 미리 정의된 매크로들, #line, #error
    //printf("__FILE__: %s\n", __FILE__); // 현재 매크로가 사용된 파일의 이름을 문자열로 바꿔준다.
    //printf("__DATE__: %s\n", __DATE__); // 전처리(컴파일)가 된 날짜
    //printf("__TIME__: %s\n", __TIME__); // 전처리(컴파일가 된 순간의 시간, 실행하는 시간이 아니다.(따로 있다.)
    //printf("__LINE__: %d\n", __LINE__); // 프로그램 코드의 LINE number
    //printf("__func__: %s\n", __func__); // 함수의 이름

    //different_function();
    //different_function_in_different_file();

    // 비주얼 스튜디오에서는 제공을 해주지 않는다.
    //printf("__STDC__: %d\n", __STDC__); // C언어 표준을 지켰는지?
    //printf("__STDC_HOSTED__: %d\n", __STDC_HOSTED__); // C언어 표준 용어.. hosted vs freestanding KNK p.330 (표준을 더 엄격하게 따르느냐 아니냐)
    //printf("__STDC_VERSION__: %ld\n", __STDC_VERSION__); // C표준의 버전

//#line 7 // 줄 번호를 강제로 바꿔버린다.
//    printf("__LINE__: %d\n", __LINE__);
//
//#line 1 "hello.txt" // 파일 이름도 바꿀 수 있다.
//    printf("__FILE__: %s\n", __FILE__);
//    printf("__LINE__: %d\n", __LINE__);

//#if __LINE__ != 296
//#error Not line 32 // 컴파일 에러를 낸다.
//#endif
//
//
//#if defined(_WIN64) != 1
//#error Not line 33
//#endif

//#if __STDC_VERSION__ != 201112L
//#error Not C11
//#endif

    // 16.9 #pragma 지시자
    // header guard(include guard)
//#pragma once // 표준은 아니었지만 대부분의 컴파일러가 지원해준다.
    // #ifndef - #define - #endif 를 이용해도 된다.
    
    // 컴파일러마다 #pragma 지원이 다르다.
    // #pragma pack(1) // padding 1
    //struct s A;
    //printf("Size of A is : %zd", sizeof(A));

    //_Pragma : 전처리 연산자, 비주얼 스튜디오에서는 지원하지 않는다.
    //_Pragma("pack(1)"); // #pragma pack(1)과 같다. // destringizing을 해서 처리한다...
//#define PACK1 _Pragma("pack(1)")
//PACK1

//#pragma warning(disable: 4477) // 4477 warning을 없앤다.
//#pragma warning(error: 4477) // warning을 error처럼 처리할 수도 있다.

    // 16.10 _Generic 표현식
    // 비주얼 스튜디오에서 지원하지 않는다.
    // Generic programming
    // 코드가 특정한 자료형에 대해서 종속되는 게 아니라, 일반적인/여러가지 자료형에 대해서 모두 작동하는 프로그래밍 코드
    // _Generic: C11에서 추가
    //int d = 5;

    //printf("%d\n", MYTYPE(d));
    //printf("%s\n", MYTYPE(2.0*d));
    //printf("%s\n", MYTYPE(3L));
    //printf("%s\n", MYTYPE(&d));

    // 16.11 inline 함수
    // Function call has overhead
    // set up the call, pass arguments, jump to the function code, and return
    // 오버헤드를 없애기 위한 방법
    // 1. 매크로 - 함수 호출 오버헤드는 없어지지만, 구조적인 프로그램을 만들기는 어렵다.
    // 2. inline function specifier - 컴파일러에게 매크로처럼 바꿔치기 하도록 "제안"한다.

    // inline function은 짧아야 한다.
    // inline function은 internal linkage여야 한다.(gcc, clang) 비주얼 스튜디오에서는 아니어도 가능하다.
    // inline - 코드에 복사 - 붙여넣기를 하는 것이다. 따라서 그것의 주소를 사용할 수 없다.(function pointer)
    //int ret;
    //ret = foo();
    //printf("Output is %d\n", ret);
    // 어셈블리 코드를 확인해보면 inline을 사용하면 function call을 하지 않는 것을 알 수 있다.

    // 16.12 라이브러리
    // MyLibrary.c, MyLibrary.h

    // 16.13 표준 수학 라이브러리
    //printf("%f\n", cos(3.141592));

    //double c = 5.0, b = 4.0, a; // a = ?
    //a = sqrt(c * c - b * b); // double
    //printf("a = %f\n", a);

    //float cf = 5.0f, bf = 4.0f, af;
    //af = sqrtf(cf * cf - bf * bf); // float
    //printf("af = %f\n", af);

    //// 비주얼 스튜디오에서는 지원하지 않는다.
    //// type variants
    //// tgmath.h library(type generit math)

    //#define SQRT(X) _Generic((X),\
    //long double: sqrtl,\
    //default: sqrt,\
    //float: sqrtf)(X)

    //double t1 = SQRT(2.0f);
    //double t2 = SQRT(2.0);

    //if (t1 == t2)
    //    printf("Identical\n");
    //else
    //    printf("Not identical\n");
    //// 다르다..

    //// tgmath.h
    //double a1 = sqrt(2.0f); // 원래 sqrt는 double로 캐스팅 하여 계산한다. tgmath.h의 sqrt는 타입을 파악하여 내부적으로 sqrtf, sqrt를 호출해준다.
    //double a2 = sqrt(2.0);

    //if (a1 == a2)
    //    printf("Identical\n");
    //else
    //    printf("Not identical\n");

    // 16.14 표준 유틸리티 라이브러리
    //// <stdlib.h>
    //// atexit() - 프로그램이 종료될 때 호출할 함수를 등록한다.
    //printf("Purchased?\n");
    //if (getchar() == 'y')
    //    atexit(thankyou);

    //while (getchar() != '\n');
    //printf("Goodbye message?\n");
    //if (getchar() == 'y')
    //    atexit(goodbye);

    //// exit(0);
    //// qsort();

    //// _Noreturn : function specifier, 함수가 끝나고 호출된 곳으로 돌아가지 않고 프로그램을 종료한다.
    //// 비주얼 스튜디오에서 지원하지 않는다.
    ////puts("preparing to stop...");
    ////stop_now(2); // 종료코드 2, 0을 넣어주면 Segmentation fault 에러가 난다. (되돌아가면 안되는 함수가(_Noretur) 돌아갔기 때문..
    ////puts("This code is newver executed.");

    // 16.15 assert 라이브러리
    //// <assert.h>
    //// 반드시 만족해야할 조건을 assert()에 넣어준다.
    //int a, b;
    //int f = scanf("%d%d", &a, &b);
    //
    //printf("a / b = %d", divide(a, b));
    //// Assertion failed
    //// Release 모드에는 Assertion이 작동하지 않는다. 오직 Debug 용

    //// 비주얼 스튜디오에서는 지원하지 않는다.(C++에서는 가능)
    ////_Static_assert(CHAR_BIT == 9, "9-bit char assumed"); // 컴파일 타임에서 잡아준다.

    // 16.16 memcpy()와 memmove()
    //// <string.h>
    //// 꼭 string이 아니더라도 메모리를 복사, 이동할 수 있다.  
    //// memcpy(), memmove()는 문자열의 마지막 null char(\0)을 신경쓰지 않고 오로지 메모리에 대해서만 복사, 이동한다.
    //int arr1[LEN] = { 1, 3, 5, 7, 9, 11 };
    //// int arr[LEN] = {0,};
    //int* arr2 = (int*)malloc(LEN * sizeof(int));
    //if (arr2 == NULL) exit(1);

    ////for (int i = 0; i < LEN; ++i)
    ////    arr2[i] = arr1[i];

    //memcpy(arr2, arr1, sizeof(int) * LEN);
    //prt(arr2, LEN);

    //// memmove() - memcpy와 비슷하지만, 내부적으로 다르다.
    //// int arr1[LEN] = {1, 3, 5, 7, 9, 11}에서 arr1[2]~arr1[5] 4개를 arr1[0]~arr1[3]으로 옮긴다면
    //// 겹치는 부분이 있을 경우 memcpy를 사용하면 문제가 생길 수 있다.(표준에서는..)
    //// memmove()는 복사할 것을 버퍼에 저장해뒀다가 복사하는 방식이기 때문에 겹치는 구간이 있어도 문제가 생기지 않도록 구현돼 있다.
    //memmove(arr1, &arr1[2], sizeof(int) * 4); // 반환값이 void* (return copy of dst)
    //prt(arr1, LEN);

    // 16.17 가변 인수
    double a, b;

    //a = average(3, 1.1, 2.2, 3.3);
    //b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    // average2 - 첫 번째 오는 문자열의 문자 수에 따라 평균값을 구한다.
    a = average2("dd", 1.1, 2.2, 3.3);
    b = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    printf("%lf\n", a);
    printf("%lf\n", b);
    // 디버깅이 힘들기 때문에, 사용하는 것을 권장하지 않는다.

    return 0;
}