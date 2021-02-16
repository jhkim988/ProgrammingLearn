int main()
{
	// m * 10 ^ n
	// m: significand
	// n: exponent
	// 123.45 = 12345 * 10 ^ (-2) = 1.2345 * 10 ^ 2

	// 4����Ʈ �ε��Ҽ����� 10���� ��ȿ���� 6��
	// sign(1) / exponent(8) / fraction(23)

	printf("%u\n", sizeof(float)); // 4
	printf("%u\n", sizeof(double)); // 8
	printf("%u\n", sizeof(long double)); // 8, long double = double (visual studio) gcc �����Ϸ������� 12

	float f = 123.456f; // float�� literal�� f�� �ٿ��ִ°� ����.(������ ������ ���)
	double d = 123.456;

	float f2 = 123.456; // 8����Ʈ�� double�� 4����Ʈ�� float�� ������ �߷������� �κ��� �ִ�.(truncation)
	double d2 = 123. 456f; // 4����Ʈ�� float�� 8����Ʈ�� double�� �ִ� ���� �ƹ� ������ ����.

	int i = 3;
	float f3 = 3.f; // 3.0f
	double d3 = 3.; // 3.0

	float f4 = 1.234e10f;
	float f5 = 0x1.1p1; // e ��ſ� p
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f);
	printf("%f %F %e %E\n", d, d, d, d);
	printf("%a %A\n", f5, f5); // %a 16������ ���
	printf("%a %A\n", d5, d5);
	
	return 0;
}