#include "MyLibrary.h"

#include <stdio.h>

// ���̺귯��
// main()�Լ��� ����. -> ���̺귯���� �ٸ� ���α׷��Ӱ� �ۼ��� ���α׷��� �� �����ִ� ��..
// properties -> configuration properties -> general -> Configuration Type -> Application(.exe)�� Library�� �ٲ۴�.
// ���� ���̺귯��(.lib), ���� ���̺귯��(.dll)
// .lib ������ �����ȴ�. (debug/release ������) �ش� ������ �̿��ؼ� �ٸ� ������Ʈ���� ����� �� �ִ�. (debug ���, release ��� �� �� ����)
// lib������ ����� �� release��忡�� ��� - release ��忡�� ������ lib������ ���.. (debug��嵵 ��������)
// ����� ������ ������� #include -> ��ŷ ������ �߻��Ѵ�.(lib������ �� �־���� ����)
// properties -> linker -> input -> additional dependencies -> .lib ���� ����

void say_hello()
{
	printf("Hello\n");
}

void say_world()
{
	printf("World\n");
}