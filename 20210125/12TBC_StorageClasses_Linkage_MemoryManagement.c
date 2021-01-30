#include <stdio.h>

// 12.3
void testLinkage();
// translation unit
int el; // file scope 변수는 프로그램 전체에서 사용할 수 있기 때문에 전역변수라고도 부른다.
static int il; // static: 변수의 범위가 현재 스코프로 제한된다는 의미, 다른 파일 scope에서 사용할 수 없다.
void count()
{
	int ct = 0; // 함수가 끝나면 메모리가 사라진다.
	printf("count = %d\n", ct);
	ct++;
}
void static_count()
{
	static int ct = 0; // 프로그램이 시작돼서 끝날 때까지 메모리에 유지가 된다.
	printf("static count = %d\n", ct);
	ct++;
}

// 12.5


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

	auto int a; // 자동변수를 선언할 때 auto를 붙인다. auto를 안 붙여도 똑같지만 지역변수인 것을 강조.. C++에서는 완전히 다른 키워드이다.
	//a = 1024; // 초기화를 꼭 해줘야한다. BSS에 있는 전역변수들은 컴파일러가 0으로 초기화 해준다. 자동변수들은 스택에 들어갔다 나왔다 빈번하게 사용하기 때문에 컴파일러가 자동으로 초기화해주지 않는다.







	return 0;
}
