#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int pizza = 5900; // (�ڷ���) (������) = (���ͷ� ���);
	//const int angel = 1004; // (������ Qualifier) (�ڷ��� DataType) (��ȣ�� ���, ������ Symbolic constant) = (���ͷ� ���, literal constant); �����ڸ� ����ϸ� ���� �� �ٲٰ� �Ǳ� ������ ��ȣ�� ���...

	//int i = 0;

	// scanf ������ �ذ��ϴ� ���
	// 1. #define _CRT_SECURE_NO_WARNINGS
	// 2. project >> properties >> preprocessor >> Preprocessor Definitions: ...;_CRT_SECURE_NO_WARNINGS
	// 3. vscode���� gcc �����Ϸ��� ����Ѵ�.

	// &(ampersand)�� ���̴� ����
	// &�� ������ �ּҸ� �˰� ���� �� ����Ѵ�. scanf() �Լ��� ������ �ּҸ� �����Ѵ�.
	// scanf() �Լ��� ������ �ּҿ� ���� �����Ѵ�.
	// scanf() �Լ��� ����ڰ� �ܼ�â�� �Է��� �ϱ� ������ ���Ȼ��� ������ �ִ�.
	// microsoft�� scanf_s() �Լ��� ����ϱ� ���Ѵ�.

	//scanf("%d", &i); // &: ampersand
	//printf("Value is %d\n", i);


	// ���� �� ���� �Է¹޾� ���� ���� ����ϴ� ���α׷� �ۼ�
	//int i = 0, j = 0;
	//printf("Input two integers.\n");
	//scanf("%d%d", &i, &j);
	//printf("%d + %d = %d\n", i, j, i + j); // %d�� ������ ���� ������ �¾ƾ� �Ѵ�.

	// ��ȭ�� �޷��� ����Ͽ� ����ϴ� ���α׷�
	float won = 0.0f, dollar = 0.0f;
	printf("Input won\n");
	scanf("%f", &won);
	dollar = won * 0.00089f; // �ڷ��� ����, 0.00089f float�� ���ͷ�
	printf("Dollar = %f\n", dollar); // ��� �ɼ�
	return 0;

	// ����������
	// %c: char
	// %d: decimal number
	// %e: exponential floating-point number
	// %f: floating-point number
	// %i: integer
	// %o: octal number
	// %s: string of characters
	// %u: unsigned decimal number
	// %x: number in hexadecimal(base 16)
	// %%: print a percent sign
	// \%: print a percent sign
}