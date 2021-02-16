int main()
{
	// m * 10 ^ n
	// m: significand
	// n: exponent
	// 123.45 = 12345 * 10 ^ (-2) = 1.2345 * 10 ^ 2

	// 4바이트 부동소수점수 10진수 유효숫자 6개
	// sign(1) / exponent(8) / fraction(23)

	printf("%u\n", sizeof(float)); // 4
	printf("%u\n", sizeof(double)); // 8
	printf("%u\n", sizeof(long double)); // 8, long double = double (visual studio) gcc 컴파일러에서는 12

	float f = 123.456f; // float은 literal에 f를 붙여주는게 좋다.(붙이지 않으면 경고)
	double d = 123.456;

	float f2 = 123.456; // 8바이트인 double을 4바이트인 float에 넣으면 잘려나가는 부분이 있다.(truncation)
	double d2 = 123. 456f; // 4바이트인 float를 8바이트인 double에 넣는 것은 아무 문제가 없다.

	int i = 3;
	float f3 = 3.f; // 3.0f
	double d3 = 3.; // 3.0

	float f4 = 1.234e10f;
	float f5 = 0x1.1p1; // e 대신에 p
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f);
	printf("%f %F %e %E\n", d, d, d, d);
	printf("%a %A\n", f5, f5); // %a 16진수로 출력
	printf("%a %A\n", d5, d5);
	
	return 0;
}