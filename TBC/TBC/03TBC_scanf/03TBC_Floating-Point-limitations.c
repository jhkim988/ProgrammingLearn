#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{	
	// round-off errors(ex1)
	float a, b;
	a = 1.0E20f + 1.0f;
	b = a - 1.0E20f;
	printf("%f\n", b); // 0.00000

	// round-off errors(ex2)
	a = 0.0f;
	for (int i = 0; i < 100; i++)
	{
		a += 0.01f; // 0.01을 정확히 표현할 수 없어서 오차가 누적된다.
	}
	printf("%f\n", a); // 0.99999

	// overflow
	float max = 3.402823466e+38F;
	printf("%f\n", max);
	max = max * 100.0f;
	printf("%f\n", max); // inf

	// underflow
	float min = 1.401298464e-45F;
	printf("%e\n", min);
	min = min / 100.0f; // subnormal
	printf("%e\n", min); // 0

	// divide by 0
	float divide_by_0 = 104.0f;
	printf("%f\n", divide_by_0);
	divide_by_0 = divide_by_0 / 0.0f;
	printf("%f\n", divide_by_0); // inf

	// out of domain
	float arc_sin_value = asinf(1.0f);
	printf("%f\n", arc_sin_value);

	arc_sin_value = asinf(2.0f);
	printf("%f\n", arc_sin_value); // - nan(ind)

	return 0;
}