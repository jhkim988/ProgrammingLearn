#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // srand()
#include <time.h> // time()
#include "my_rand.h"

// 12.3
void testLinkage();
// translation unit
int el; // file scope 변수는 프로그램 전체에서 사용할 수 있기 때문에 전역변수라고도 부른다.
static int il; // static: 변수의 범위가 현재 스코프로 제한된다는 의미, 다른 파일 scope에서 사용할 수 없다.
void count()
{
	int ct = 0; // 함수가 끝나면 메모리가 사라진다.
	printf("count = %d %p\n", ct, &ct);
	ct++;
}
void static_count()
{
	static int ct = 0; // 프로그램이 시작돼서 끝날 때까지 메모리에 유지가 된다. 초기화가 한 번만 이루어진다.
	// 스택에 저장되지 않고 데이터/BSS에 저장된다.

	// static 변수에서 - 선언하면서 초기화 vs 선언 후에 값 할당은 차이가 있다.
	// 선언 후 값 할당을 하게 되면 함수가 다시 실행될 때 다시 0을 할당해버리기 때문이다.
	//static int cp;
	//cp = 0;

	printf("static count = %d %p\n", ct, &ct);
	ct++;
}

// 12.5
void func_auto(int k)
{
	int i = k * 2;
	printf("i %lld\n", (long long)&i);
}

// 12.7
void count_caller()
{
	count();
}
void static_count_caller()
{
	static_count();
}

// 12.8
int g_int = 0; // static 변수들은 초기화를 안하면 0으로 해주지만 직접 하는 것이 좋다.
double g_arr[1000];
// constant expression
int x = 5; 
int y = 1 + 2;
size_t z = sizeof(int);
//int x2 = 2 * x;// Error, x is not constant variable.
void func_sec(); // 선언을 해준다.

//int func_static(static int i) // warning (Error in GCC)
//{
//
//}
//int* count_pointer()
//{
//	int ct = 0; // 함수가 끝나면 메모리가 사라진다.
//	printf("count = %d %p\n", ct, &ct);
//	ct++;
//	return &ct;
//	// 포인터를 리턴한다는 것은 받는 쪽에서 포인터를 이용해 작업을 하고 싶다는 의미, 그러나 함수가 끝나면서 메모리를 반환하여 사용할 수 없기 때문에 warning
//}
//int* static_count_pointer()
//{
//	static int ct = 0;
//	printf("static count = %d %p\n", ct, &ct);
//	ct++;
//	return &ct; // 권장하지는 않는다.
//}


// 12.9
//static int g_static = 123; // 파일 내에서만 사용할 수 있는 전역변수

int main()
{
	// 12.1 메모리 레이아웃
	// 스택: 프로그램의 일부에서 큰 메모리가 필요한 경우. 블록에 쌓여진 영역을 실행할 때만 메모리에 올라간다.
		// main함수은 가장 먼저 실행돼서 가장 늦게 끝나기 때문에 여기에 지역변수를 많이 선언하면 스택에 계속 남아 있게 된다.
		// 다른 함수를 만들어서 거기서 필요한 기능만 수행하고 메모리를 반환해주는 것이 좋다.
		// 필요한 메모리를 컴파일 할 때 미리 알고 있기 때문에 스택에 선언된 지역변수는 속도가 빠르다.
	// 자유공간: 스택과 힙 공간의 여유분. 스택과 힙이 동시에 사용하더라도 운영체제에서 가상주소공간을 사용하기 때문에 충돌이 나지 않는다.
		// 이 과정에서 운영체제를 한 번 거치기 때문에 느려지게 된다.
	// 힙: 필요한 메모리의 크기를 미리 알 수 없을 경우
		// 파일, 인터넷, 사용자로부터 scanf로 값을 읽는 경우 필요한 메모리의 크기를 미리 알 수 없다.
		// 컴파일 할 때 미리 메모리 사이즈를 알 수 없다. 힙 공간을 사용한다.
		// 메모리를 사용하고 나면 반납을 해야한다.
	// 전역/정적 변수: 프로그램 전체에서 계속 사용되는 변수들 메모리에 한 번 올라오면 프로그램이 끝날 때까지 메모리에 있어야 한다.
	// 프로그램 코드: TEXT Segment(Read Only, 수정하려고 하면 운영체제가 Run-time 에러 발생) 메모리에 한 번 올라오면 프로그램이 끝날 때까지 메모리에 있어야 한다.


	// 12.2 객체(Object) 식별자(Identifier) L-value R-value
	// object: 값을 저장할 수 있는 메모리의 블럭. 객체 지향 프로그래밍에서는 더 확장된 개념
	// identifier: 변수, 함수, 매크로, 다른 것들의 이름

	//int var_name = 3;
	//int* pt = &var_name;
	//*pt = 1; // *pt is not an identifier. *pt designates an object.

	//int arr[100]; // arr is an identifier. arr is not object. arr는 메모리 공간을 갖고 있지는 않다.
	//arr[0] = 7;

	//// L-value, R-value
	//// L-value: expression referring to an object. left side of an assignment.
	//// R-value: right side, variable, constant, expressions

	//var_name = 3; // modifiable L-value, 메모리 공간을 참조한다.
	//int* ptr = arr;
	//*pt = 7; // *pt is not an identifier but an modifiable L-value expression.

	//int* ptr2 = arr + 2 * var_name; // R-value
	//*(arr + 2 * var_name) = 456; // *(...) L-value

	//const char* str = "Constant string"; // str is a modifiable L-value
	//str = "Second string"; // "Constant string" = "Second String" // impossible
	////str[0] = 'A'; // Error
	////puts(str);

	//char str2[] = "String in an array";
	//str2[0] = 'A';
	////puts(str2);

	
	// 12.3 변수의 영역(Scope)과 연결 상태(Linkage), 객체의 지속 기간(duration)
	// variable scopes(visibility)
	//int local = 1234; // 다른 함수(블럭)에서는 사용할 수 없다.(볼 수가 없다.)

	// C언어에서 변수의 영역 4가지
	// 블럭, 함수, 함수의 프로토타입, 파일(모든 함수의 바깥 영역, global variable)
	// 초기화 되지 않은 전역/정적변수는 컴파일 될 때 BSS영역에 저장되며, 0으로 초기화된다.
	// 프로토타입 변수의 scope는 프로토타입의 선언, 적지 않아도 되지만 VLA는 길이를 지정해줘야 하기 때문에 식별자를 생략할 수 없다.
	// goto문은 파일 어디서든 접근하여 점프할 수 있다.

	// 파일은 컴파일을 하는 최소 단위이다.
	// 컴파일을 따로 해서 만들어진 오브젝트 파일들을 연결해 주는 게 링커다.

	//el = 1024;
	//testLinkage();
	//printf("%d\n", el);

	// duration 메모리의 지속 기간
	// static storage duration - 프로그램이 시작해서 끝날 때까지 static하게 메모리 공간에 머뭄(변수의 static 키워드(linkage type)와 다르다.)
	// automatic storage duration - 지역변수(스택 메모리)
	// allocated storage duration - 동적할당
	// thread storage duration - 멀티스레딩 

	//count();
	//count();
	//static_count();
	//static_count();


	// 12.4 저장 공간의 다섯 가지 분류(Five Storage Classes)
	// static과 static이 아닌 것 두 가지로 나눌 수도 있다.
	// Automatic: 지역변수. 지속기간과 영역을 프로그래머가 일일이 설정하지 않고 자동으로 해준다.
	// Register: 지역변수처럼 사용하지만 register 키워드를 앞에 붙여준다. cpu 안에 레지스터가 있다. 처리속도가 빠르다.
		// 최근에는 컴파일러가 좋아져서, register 변수가 아니여도 레지스터로 올려주기도 한다고 한다.
		// 실무에서 빠르게 처리하고 싶을 경우에는 레지스터 보다 캐싱, 병렬처리, 분산처리, GPU가속 등을 사용하는 것이 좋다.
	// static with internal linkage(고정적 내부연결) 영역: 파일 안, 번역 단위의 내부에서만 사용, 모든 함수들 밖에서 static 키워드 사용
	// static with external linkage(고정적 외부연결) 영역: 파일 안, 번역 단위의 외부로도 연결 가능, 모든 함수들 밖
	// static with no linkage(고정적, 연결없음) 영역: 블록 안, 연결 없음, 블록 안에서 static 키워드 사용
		// 데이터 또는 BSS
		// 지속기간 고정적
	// 할당 메모리(식별자 없음, 5가지에 포함되지 않음): 힙, 지속기간은 프로그래머가 결정, 운영체제에 요청하여 선언


	// 12.5 자동 변수
	// 지속 기간이 자동적으로 결정된다.
	// 프로그램 전체에서 계속 사용할 메모리가 아니라면, 계속 가지고 있을 필요가 없다.
	// scope를 잘 정해줘야한다.
	// 변수가 계속 존재하는게 아니기 때문에 linkage를 유지할 수가 없다.

	// Automatic storage class
	// Automatic storage duration, Block scope, No linkage
	// Any vaiable declared in a block or function header

	//auto int a; // 자동변수를 선언할 때 auto를 붙인다. auto를 안 붙여도 똑같지만 지역변수인 것을 강조.. C++에서는 완전히 다른 키워드이다.
	//a = 1024; // 초기화를 꼭 해줘야한다. BSS에 있는 전역변수들은 컴파일러가 0으로 초기화 해준다. 자동변수들은 스택에 들어갔다 나왔다 빈번하게 사용하기 때문에 컴파일러가 자동으로 초기화해주지 않는다.
	//printf("%d\n", a);
	//auto int b = a * 3;

	//int i = 1;
	//int j = 2;
	//printf("i %lld\n", (long long)&i);

	//{
	//	// 영역이 바뀌면 같은 이름의 변수가 생길 수 있다.
	//	// 가장 안쪽에서 선언된 것을 의미한다.
	//	int i = 3; // name hiding
	//	printf("i %lld\n", (long long)&i);

	//	// j is visible here
	//	printf("j = %d\n", j);

	//	// 영역이 끝나면 영역 안에서 선언된 i가 사라진다. 스택(메모리)에서 빠져나간다.
	//}
	//printf("i %lld\n", (long long)&i); // which i ?

	//// stack frame: 함수 전체에서 필요한 메모리

	//for (int m = 1; m < 2; ++m)
	//	printf("m %lld\n", (long long)&m); // 블럭이 없어도 m의 scope는 한 문장까지

	//func_auto(5); // 함수에 진입하면 스택 프레임 자체가 바뀌어버린다. 함수 내에서 main함수의 변수를 사용할 수 없다.
	//// 함수가 끝나면 함수 안에서 사용한 메모리를 모두 반환하기 위해서

	//for (int m = 3; m < 4; ++m)
	//{
	//	printf("m %lld\n", (long long)&m);
	//}


	// 12.6 레지스터 변수
	// 레지스터란? CPU가 갖고 있는 임시 작업공간
	// CPU와 메모리는 다른 부품, 메인보드의 버스를 통해서 정보를 주고 받는다.
	// 레지스터는 메모리처럼 데이터를 갖고 있을 수 있다. CPU의 일부이기 때문에 빠르게 작동한다.

	// 지속기간, 영역이 자동변수와 같다.
	// 메모리 저장을 레지스터(또는 스택)에 한다.
	// 컴파일러가 꼭 레지스터에 위치시켜주진 않는다.
	//register int r;
	//r = 123;

	// register 변수는 address operator &를 사용할 수 없다.
	//printf("%p\n", &r);
	//int* ptr = &r;


	// 12.7 블록 영역의 정적변수
	// 프로그램이 시작하고 끝날 때까지 메모리에 계속 올라가 있다.
	// 블록 안에서만 사용할 수 있다.(visible)
	// Linkage가 없다. 포인터 등을 통해 간접적으로 접근할 수 있다.

	//count(); // main함수에서 직접호출
	//count();
	//count_caller(); // count_caller()함수를 통해 호출

	//static_count();
	//static_count();
	//static_count_caller();

	// 함수의 파라미터에 static 변수를 넣는다면
	// visual studio - warning: Bad storage class
	// gcc - Error
	// 함수가 실행될 떄는 새로운 스택 프레임이 생성된다.
	// 함수의 파라미터는 함수가 호출될 때 메모리를 배정받는다.
	// 파라미터를 static한 메모리 공간에 넣는 것은 이상하다.

	// 함수에서 포인터를 리턴할 때...
	// count_pointer(), static_count_pointer();


	// 12.8 정적 변수의 외부연결 external linkage
	// 메모리 위치: 데이터/BSS
	// 지속기간: static(프로그램 시작부터 끝까지)
	// 영역: 파일 안
	// 연결 상태: 번역 단위(파일)의 외부로도 연결 가능
	// 선언 방법: 모든 함수들 밖에 선언
	// 컴파일러가 각각의 파일(c파일, 헤더파일)을 따로 컴파일한 후 링커가 연결한 후에 실행파일을 만든다.
	// 변수뿐만 아니라 함수도 연결해준다.

	// File scope, External linkage
	// External storage class
	// External variables

	// file scope 변수는
	// 이 파일 안에서 어느 함수에서나 사용할 수 있다.

	// 이름이 같은 지역변수를 만든다면
	//int g_int = 123; // 이 scope에서는 static 변수 g_int가 name hiding이 된다.

	// referencing declaration
	//extern int g_int; // 이 scope의 바깥에 있는 g_int를 연결시켜달라는 의미. 같은 파일이므로 굳이 링커가 연결해줄 필요가 없다.

	//fun_sec();


	// 12.9 정적 변수의 내부 연결 static variables with internal linkage
	// 번역 단위(파일) 내부에서만 사용
	// 모든 함수 밖에서 static 키워드 사용


	// 12.10 변수의 저장 공간 분류 요약 정리
	// Automatic - 블럭에서, 지역변수
	// Register - 블럭에서, regester 키워드, & 연산자 사용 불가
	// Static internal linkage - 모든 함수 밖에서, static 키워드
	// Static external linkage - 모든 함수 밖에서, 외부에서 extern 키워드
	// Static no linkage - 블럭 안에서, static 키워드


	// 12.11 함수의 저장 공간 분류
	// Storage Classes and Functions
	// - Functions exteranl(by default) or static
	// - A function declaration is assumed to be externs

	// 함수는 프로그램이 시작되면 로딩되고, 메모리에 계속 머무른다.
	// 함수 포인터로 그 주소를 찍어볼 수 있다.
	// 함수의 선언은 기본적으로 extern이다.

	// static 키워드를 붙이면 어떻게 되는지?
	// LNK ERROR, static을 붙이면 해당 파일 안에서만 사용할 수 있다.
	// 프로토타입에만 static을 붙여줘도 해당 파일 안에서만 사용할 수 있다.


	// 12.12 난수 생성기 모듈 만들기 예제
	//rand();
	// 0 ~ RAND_MAX (typically INT_MAX)
	// defined in stdlib.h

	//srand(2); // random seed setting
	//srand((unsigned int)time(0));
	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", rand()); // 완전한 난수를 만들 수 없다.
	//}

	unsigned int next = (unsigned int)time(0);
	for (int i = 0; i < 10; ++i)
	{
		next = next * 1103515245 + 1234; // 유사난수
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}

	printf("\n*** My Try ***\n");
	my_srand(next);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", my_rand());
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", my_rand() % 6 + 1);
	}


	return 0;
}
