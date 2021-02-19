#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
    #include <stdio.h> // 컴파일러가 위치를 알고 있는 경우.. 대부분 표준 라이브러리
    #include "my_functions.h" 
    #include "my_structures.h"
    #include "my_headers/my_macros.h" // 절대 경로로 해도 된다. vs 설정에서 경로를 추가하면 <>로 바꿀 수 있다.


    return 0;
}