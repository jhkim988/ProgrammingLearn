int main2()
{
	// integer: 내부적으로 2진수
	// real number: 내부적으로 부동소수점(floating point) 표현법 사용
	// 3.14 = 3.14E0 = 3.14e0 = 0.314E1 = 31.4E-1
	// 내부적으로 2진수

	// 부호 없는 정수
	// 8bit unsigned integer
	// 0101 1110 = 2^6 + 2^4 + 2^3 + 2^2 + 2^2 = 94
	
	// 32bit unsigned integer
	// 01010101 01010101 01010101 01010101 = ...


	// 부호 있는 정수
	// 2의 보수 표현법, 부호 없는 정수와 표현 범위가 다르다.
	// 8bit signed integer(0: +, 1: -)
	// +101 1110

	// 32bit signed integer
	// +1010101 01010101 01010101 01010101 = ...
	
	// 부동소수점 - 연산이 느리지만, 하드웨어의 발달로 빨라졌다.
	// sign / Exponent / Fraction
	// 32bit single precision
	// sign(1) / Exponent(8) / Fraction(23)
	// 0.0f;

	// 64bit double precision
	// sign(1) / Exponent(11) / Fraction(52)
	// 0.0 f가 안 붙는다.
	return 0;
}