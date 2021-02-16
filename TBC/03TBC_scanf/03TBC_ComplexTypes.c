#include <stdio.h>
#include <complex.h>

int main()
{
	// 컴파일러마다 지원해주는게 다르다. visual stuio에서는 많은 기능을 제공하고 있진 않다.
	_Dcomplex z;
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;

	// gcc 컴파일러에서
	double _Complex z = 1 + 2 * I;
	z = 1 / z;
	printf("1 / (1.0 + 2.0i) = %.1f%+.1fi\n", creal(z), cimag(z));

	return 0;
}