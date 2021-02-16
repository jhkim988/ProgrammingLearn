#include <stdio.h>
#include <stdbool.h>

int main()
{
	printf("%u\n", sizeof(_Bool));
	// 0과 1만 표현하면 되기 때문에 1bit여야 하겠지만, 자료형의 최소한의 데이터 크기는 1byte다.
	// 형식지정자가 없기 때문에 %d로 출력한다.(0, 1로 출력된다.)
	_Bool b1;
	b1 = 0; // false
	b1 = 1; // true
	printf("%d\n", b1);

	// stdbool.h
	bool b2, b3;
	b2 = true; // 내부적으론 1
	b3 = false; // 내부적으론 0
	printf("%d %d\n", b2, b3); // 1, 0
	
	return 0;
}