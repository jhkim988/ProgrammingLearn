#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // srand(), malloc(), free()
#include <time.h> // time()
#include "my_rand.h"
#include "my_constant.h"
#include <Windows.h>

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

// 12.19
DWORD WINAPI ThreadFunc(void* data)
{
	int n = 1;
	Sleep(1000);

	// acnt += n;
	printf("Printing from Thread \n");
	return 0;
}
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

	//unsigned int next = (unsigned int)time(0);
	//for (int i = 0; i < 10; ++i)
	//{
	//	next = next * 1103515245 + 1234; // 유사난수
	//	next = (unsigned int)(next / 65536) % 32768;
	//	printf("%d\n", (int)next);
	//}

	//printf("\n*** My Try ***\n");
	//my_srand(next);
	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", my_rand());
	//}

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", my_rand() % 6 + 1);
	//}


	// 12.13 메모리 동적 할당 Dynamic Storage Allocation
	// 동적할당 = 컴파일 타임에서 메모리 할당이 정해지는 것이 아닌, 런타임에서 결정되는 것
	// 동적 할당 메모리는 인식자가 없다.(포인터만 가져오고 변수의 이름이 없다.)
	// 따라서 Storage Classes에 포함되지 않는다. (힙 메모리에 들어간다.)
	// 프로그래머가 운영체제에게 요청한다.
	// 한 번 할당 받으면 힙 메모리에 계속 존재한다.
	// 프로그래머가 메모리를 반납하거나 프로그램이 끝나야 메모리가 반환된다.

	// 필요한 메모리의 크기를 미리 알 수 없을 경우(컴파일 타임에 알 수 없고, 런타임에 알 수 있는 경우)
	// 운영체제가 가상 주소공간을 이용하여 컴퓨터의 메모리를 충분히 사용할 수 있도록 해준다.
	// malloc()을 통해 메모리를 할당 받고 free()를 통해 반납해야 한다.

	//// 스택에 저장되는 것들
	//float x;
	//char str[] = "Dancing with a Star";
	//int arr[100];

	//double* ptr = NULL;
	//ptr = (double*)malloc(30 * sizeof(double)); // 몇 바이트 메모리를 요청할지, 힙에 저장된다. 포인터는 스택(auto)에 저장된다.
	//// 포인터 변수를 잃어버리면(scope에서 나가거나..) 힙 메모리에는 할당 받은 메모리가 존재하지만, 접근하지 못하는 상황이 생긴다.
	//// 계속 동적할당을 받다가 힙이 꽉차면 문제가 생긴다.

	//// malloc()함수는 void 타입 포인터를 리턴한다.(요청한 바이트 만큼의 메모리, 그것의 첫 주소)
	//// 어떤 타입을 갖는 것이 아니라, 그냥 순수하게 주소를 반환한다는 의미
	//// void 타입 포인터를 리턴하기 때문에 사용자가 타입 캐스팅(위에서의 (double*))을 해줘야한다.
	//// void*: generic pointer라고 하기도 한다.
	//// free(): deallocates the memory
	//// 형변환을 해서 특정한 자료형의 배열인 것처럼 사용할 수 있다.

	//if (ptr == NULL)
	//{
	//	// 운영체제가 할당해줄 메모리가 없을 경우에는 NULL 포인터를 리턴해준다.
	//	puts("Memory allcation failed.");

	//	//exit(EXIT_FAILURE); // is similar to return 1 in main()
	//	//exit(EXIT_SUCCESS); // is similar to return 0 in main()
	//	// exit을 이용하면 어떤 함수에서도 강제로 프로그램을 종료할 수 있다.

	//	exit(EXIT_FAILURE); // 메모리 할당이 안된다는 것은 매우 심각해서 프로그램 진행이 어렵다는 의미이다. 종료하는 것이 좋다.
	//	// 웹서버처럼 종료되면 안되는 것들은 따로 에러처리를 해줘야한다.
	//	
	//	// 너무 큰 공간을 요청했을 때 오류가 발생할 수 있다.
	//	// 여러 프로그램을 실행하고 있어서(메모리를 사용하고 있어서) 연속된 메모리 공간을 할당해줄 수 없을 때 오류가 발생한다.
	//}

	//printf("Before free %p\n", ptr);
	//free(ptr); // ptr이 NULL 포인터라면 free를 해도 아무 일도 일어나지 않는다.
	//printf("After free %p\n", ptr);

	//ptr = NULL; // optional, 권장한다.
	//printf("Null %p\n", ptr);

	//// 배열처럼 사용할 수 있다.
	//int n = 5;
	//ptr = (double*)malloc(n * sizeof(double));

	//if (ptr != NULL)
	//{
	//	for (int i = 0; i < n; ++i)
	//		printf("%f", ptr[i]); // 0으로 초기화해주지 않는다.
	//	printf("\n");
	//	
	//	for (int i = 0; i < n; ++i)
	//		*(ptr + i) = (double)i;

	//	for (int i = 0; i < n; ++i)
	//		printf("%2.1f ", ptr[i]);
	//	printf("\n");
	//}

	//free(ptr);
	//ptr = NULL;

	// VLA와의 비교
	// visual studio 컴파일러에서는 VLA를 지원하지 않는다.
	// 동적할당 메모리는 사이즈를 바꿀 수 있기 때문에 VLA보다 선호된다.(다른 사이즈를 새로 받아온다는 느낌)
	// VLA는 automatic duration(스택에 올라간다.)
	// 동적할당 메모리는 free()를 할 떄 까지 힙에 계속 머물고 있다.
	// VLA는 스택 사이즈의 제한을 받는다. 힙은 크기가 큰 편이다.(대신 찾기가 힘들다.)


	// 12.14 메모리 누수(leak)와 free()의 중요성 - 비쥬얼 스튜디오 진단도구 사용법
	// debug -> windows -> show diagnostic tools
	//int* ptr_backup = NULL;
	//printf("Dummy output.\n");

	////for(int k = 0; k < 1000000; ++k) // 메모리 누수
	//{
	//	int n = 100000000;
	//	int* ptr = (int*)malloc(n * sizeof(int)); // 381mb.. ptr은 block scope

	//	if (!ptr)
	//	{	// 메모리를 과도하게 사용하면
	//		printf("malloc() failed\n");
	//		exit(EXIT_FAILURE);
	//	}

	//	for (int i = 0; i < n; ++i)
	//		ptr[i] = i + 1;

	//	printf("%d %d\n", ptr[0], ptr[1]);
	//	ptr_backup = ptr;
	//	//free(ptr);
	//	//ptr = NULL;
	//}
	//// block scope를 지나면서 ptr 포인터 변수는 사라졌지만, 동적할당 malloc으로 할당받은 힙 메모리는 그대로 남아있다.
	//printf("Dummy output.\n");

	//printf("%d %d\n", ptr_backup[0], ptr_backup[1]); // free(ptr)을 하고 실행하면 런타임에러가 난다.


	// 12.15 동적 할당 메모리를 배열처럼 사용하기
	//int* ptr = NULL;
	//ptr = (int*)malloc(sizeof(int) * 1);
	//if (!ptr) exit(1);
	//*ptr = 1024 * 3;
	//printf("%d\n", *ptr);
	//free(ptr);
	//ptr = NULL;

	//int n = 3;
	//int* ptr = (int*)malloc(sizeof(int) * n);
	//if(!ptr) exit(1);

	//ptr[0] = 123;
	//*(ptr + 1) = 456;
	//*(ptr + 2) = 789;

	//free(ptr);
	//ptr = NULL;

	//int row = 3, col = 2;
	//int(*ptr2d)[2] = (int(*) [2])malloc(sizeof(int) * row * col);
	////int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col); // VLA
	//// 이렇게 2차원 배열을 만들기 보다 1차원 배열을 2차원 배열처럼 사용하는 것이 좋다.
	//if (!ptr2d) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr2d[r][c] = c + col * r;
	
	//int row = 3, col = 2;
	//int* ptr = (int*)malloc(sizeof(int) * row * col);

	//if (!ptr) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr[c + col * r] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", *(ptr + c + col * r));
	//	printf("\n");
	//}
	
	//int row = 3, col = 2, depth = 2;
	//int* ptr = (int*)malloc(sizeof(int) * row * col * depth);
	//if (!ptr) exit(1);
	//for (int d = 0; d < depth; d++)
	//	for (int r = 0; r < row; r++)
	//		for (int c = 0; c < col; c++)
	//			ptr[c + col * r + (row * col) * d] = c + col * r + (row * col) * d;

	//for (int d = 0; d < depth; d++)
	//	for (int r = 0; r < row; r++)
	//		for (int c = 0; c < col; c++)
	//		{
	//			int idx = c + col * r + (row * col) * d; // 직접 써넣으면 warning?
	//			printf("%d ", *(ptr + idx));
	//		}


	// 12.16 calloc(), realloc()
	//// calloc: contiguous allocation
	//int n = 10;
	//int* ptr = NULL;

	////ptr = (int*)malloc(sizeof(int) * n); // malloc은 메모리를 할당만 해주고 초기화를 해주지 않는다.
	//ptr = (int*)calloc(n, sizeof(int)); // malloc 과 거의 차이가 없다. calloc함수는 0으로 초기화를 해준다.

	//if (!ptr) exit(1);
	//
	//for (int i = 0; i < n; ++i)
	//	printf("%d ", ptr[i]);
	//printf("\n");

	//// realloc: reallocation 사이즈가 변경돼 다시 할당을 받고 싶을 때 사용하는 함수
	//// 원래 갖고 있던 메모리보다 더 큰 메모리를 할당한다면 기존의 메모리를 복사해준다. 새로 추가된 메모리에 대해서는 초기화해주진 않는다.
	//// 메모리를 추가로 할당해 줄 수 없다면 NULL을 리턴한다.
	//// argument로 포인터, 새로 할당받고 싶은 메모리를 받는다.
	//// 첫 번째 argument가 NULL이라면 malloc과 똑같다.
	//// 두 번째 argument가 0이라면 free(첫 번째 인자)와 같다.

	//for (int i = 0; i < n; i++)
	//	ptr[i] = i + 1;

	//n = 20;

	//int* ptr2 = NULL;
	//ptr2 = (int*)realloc(ptr, n * sizeof(int));
	//// ptr2 = (int*)realloc(ptr, n * sizeof(int));

	//printf("%p %p\n", ptr, ptr2);

	//if (!ptr2) exit(1);
	//else ptr = NULL;

	//for (int i = 0; i < n; ++i)
	//	printf("%d ", ptr2[i]); // 기존의 데이터를 복사해주지만 새로 받은 메모리를 초기화해주진 않는다.
	//printf("\n");

	//free(ptr2);


	// 12.17 동적 할당 메모리와 저장 공간 분류
	// 동적 할당 메모리 - 힙 메모리 - free() 할 때까지 메모리에 올라가 있다.

	// 12.18 자료형 한정자들 (Type Qualifiers) - const, volatile, restrict, _Atomic
	//// const
	//// C99 ideompotent
	////const const const int n = 6; // 여러 번 써도 된다. const int n = 6; 그러나 warning
	//typedef const int zip; // zip이라는 이름의 const int 타입을 만든 것이다. const zip = const const int 인데 오류가 생기면 안되기 때문에..
	////const int i; // 초기화를 반드시 해야한다.

	//const int j = 123;
	//const int arr[] = { 1, 2, 3 };

	//float f1 = 3.14f, f2 = 1.2f;

	//const float* pf1 = &f1;
	////*pf1 = 5.0f; // Error
	//pf1 = &f2; // Allowed

	//float* const pf2 = &f2;
	//*pf2 = 6.0f;
	////pf2 = &f1; // Error

	//const float* const pf3 = &f1;
	////*pf3 = 7.0f; // Error
	////pf3 = &f2; // Error

	//// 사용할 주요 상수들을 const 전역변수로 만들지 말고, 헤더파일에 static const 변수로 만든다.
	//double area_circle = PI * 2.0f * 2.0f;
	//
	//// volatile - 휘발성
	//volatile int vi = 1; // 컴파일러가 모르는 곳에서 변수가 바뀔 수 있다는 의미, 컴파일러가 최적화 하지 말라는 의미
	//volatile int* pvi = &vi; // 다른 모듈이나 운영체제가 바꿀 수 있다. 예를 들면 시간..
	//
	//int il = vi;
	//// ... something
	//int i2 = vi;
	//// 컴파일러가 vi 값이 바뀌지 않았을 것이라고 판단하고 임시저장공간에 저장(캐싱)하여 최적화를 할 수 있다.
	//// 컴파일러가 모르는 상황에서 바뀌었다면 문제가 생긴다.

	//// restrict
	//// 데이터 오브젝트에 접근하는게 해당 변수 하나 뿐이라는 의미
	//
	//int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int* par = ar;

	//int* __restrict restar = (int*)malloc(10 * sizeof(int)); // restar 변수를 통해서만 접근하겠다는 의미
	//if (!restar) exit(1);

	//// ar 배열은, 배열이름과 포인터 두 가지 방법으로 접근할 수 있다.
	//ar[0] += 3;
	//par[0] += 5;
	//// par[0] += 8; 배열이름과 포인터 두 가지가 다르기 때문에 컴파일러가 최적화 +8로 해주지 못한다.

	//restar[0] += 3;
	//restar[0] += 5;
	////restar[0] +=8; // Equivalent, 컴파일러가 최적화를 해줄 수도 있다.
	//// 컴파일러 입장에서는 실제로 restar를 통해서만 접근하는지 체크해줄 수 없다.


	// 12.19 멀티 쓰레딩
	// 프로그램이 "프로세스"에서 실행된다.
	// 메인 쓰레드가 다른 쓰레드를 만들어서 띄울 수 있다.
	// 멀티 코어 CPU -> 여러 쓰레드를 실행시킬 수 있다.

	// 같은 함수를 여러 쓰레드가 동시에 실행시킬 경우
	// 함수 내부의 지역변수는 어떠한 storage classes를 갖는가?

	// 하나의 전역변수를 여러 개의 쓰레드가 접근하면? 경쟁이 생긴다.
	// 메모리와 CPU 사이를 왔다갔다 하는 사이에 문제가 생길 수 있다.

	// C언어 표준에서는 멀티 쓰레딩을 지원해주지 않아서, 대부분 운영체제에서 지원해주는 것을 사용한다.
	// <Windows.h>

	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	if (thread)
		WaitForSingleObject(thread, INFINITE);

	// 일반적으로 사용되는 것 gcc컴파일러
	// www.onlinegdb.com/online_c_compiler


	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h> // sleep()
//#include <pthread.h> // pthread는 윈도우에서도 사용할 수 있다.
//#include <stdatomic.h>
//
//_Atomic int acnt = 0; // atomic type qualifier
//// _Atomic
//// 여러 쓰레드에서 동일한 전역변수에 접근할 때 CPU와 메모리가 분리돼 있는 구조에 의해 일관성이 깨질 수도 있다.
//// 그런 상황을 방지하기 위해 _Atomic qualifier를 사용한다.
//// _Atomic 변수의 연산은 일반적으로 느리다.
//
//void* myThreadFunc(void* vargp)
//{
//	int n = 1; // thread storage duration
//	// 지역변수, 함수가 끝나면 메모리를 반환한다.
//	// thread_id1, thread_id2 각각 두 카피가 생긴다.
//	for (int j = 0; j < 10; ++j)
//	{
//		sleep(1);
//		acnt += n;
//		printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
//	}
//	return NULL;
//}
//
//int main()
//{
//	pthread_t thread_id1, thread_id2; // 쓰레드 식별
//	printf("Before Thread\n");
//
//	pthread_create(&thread_id1, NULL, myThreadFunc, NULL); // myThreadFunc 함수를 실행시키는 쓰레드를 만들어서 thread_id1로 식별할 수 있게 한다.
//	pthread_create(&thread_id2, NULL, myThreadFunc, NULL); // myThreadFunc 함수가 메모리와 CPU에 두 copy가 작동하게 된다.
//
//	pthread_join(thread_id1, NULL); // 쓰레드가 끝날 때까지 기다려줘야한다.
//	pthread_join(thread_id2, NULL);
//
//	printf("After Thread\n");
//	printf("Atomic %d\n", acnt);
//
//	return 0;
//}