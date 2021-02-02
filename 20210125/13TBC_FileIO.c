#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // SetConsoleOutputCP()

#define MAX 31

int main(int argc, char* argv[])
{
	// 13.1 ���� ������� �۵� ����
	// C���� �ۼ��� ���α׷��� �����ϸ� �ü������ ���̿� stream�� 3���� ������.(���۸� ����ϴ� ����� stream)
	// stdin: Ű���� �Է� -> �ü�� -> ���α׷�
	// stdout: ���α׷� -> �ü�� -> ȭ�������ġ
	// stderr: ���α׷� -> �ü�� -> ȭ�������ġ

	// stream�� ������ �������Ͽ� ���Ͽ� ����� ���� �ִ�.

	// ���Ϸ� �Է�/����� �ϰ� ���� ���� �ִ�.
	// Buffered IO streams

	// C���� �ۼ��� ���α׷��� ����������� �� ���� 2���� ��尡 �ִ�.
	// 1. �ؽ�Ʈ ���� IO stream
	// 2. ���̳ʸ� ���� IO stream

	// �ؽ�Ʈ ���� - �޸����� �̿��ؼ� �ٷ� ���� �� �ִ� ����(������� ���� �� �ִ� �뵵)
	// ���̳ʸ� ���� - �����ϰ� �����͸� �����ϴ� ����(����� ���� ���� ���� ����.)

	// ���α׷����� ������ �����ߴٰ� �����Ѵ�.
	//int i = 34567;

	// �ؽ�Ʈ ���� IO stream������...
	//fprintf(fp, "%d\n", i);
	// �ؽ�Ʈ ���Ͽ� 34567+�ٹٲ�+(EOF)�� ����ȴ�.
	// �ؽ�Ʈ ���� IO stream������ "34567"�̶�� ���� �ϳ��� �����ϴ� ���� �ƴ϶�
	// '3' '4' '5' '6' '7' ���� ������ ���ڸ� �����Ѵ�.
	// �ٹٲ�/EOF/���ڵ������ �ü������ �ٸ���.

	// ���̳ʸ� ���� IO stream������...
	//fwrite(&i, sizeof(i), 1, fp);
	// �ؽ�Ʈ ���� IO stream���� ������ ���ڷ� �ɰ��� �����ϴ� �Ͱ� �޸� ���� "34567"�� �״�� �����Ѵ�.

	// �ü���� ���� �ؽ�Ʈ ������ �����ϴ� ����� �ٸ���.
	// �� ���󼭵� �ٸ���. (�ü���� ��� ����ϵ��� ��ġ�ƴ��� ��)
	// ���α׷��Ӱ� �ǵ������� ���ڵ� ����� �ٲ� ���� �ִ�.
	// ���̳ʸ� ���� IO stream�� �ü������ �����ϴ� ����� �ٸ���. Big Endian/Little Endian


	// 13.2 �ؽ�Ʈ ���� ����� ����
	//int ch;
	//FILE* fr; // ������ ó���� �� �ʿ��� ������ ������ ���� ������

	//unsigned long count = 0;

	//if (argc != 2)
	//{
	//	printf("Usage: %s filename\n", argv[0]);
	//	exit(EXIT_FAILURE);
	//}

	//if ((fr = fopen(argv[1], "r")) == NULL) // open a text file for reading
	//{
	//	// �ϵ��ũ�� �� á�ٰų�, �б� ���� ������ ���� ���� ���ٰų� ���
	//	printf("Can't open %s\n", argv[1]);
	//	exit(EXIT_FAILURE);
	//}

	//// fopen mode strings for text files
	//// r: reading
	//// w: creawting-and-writing or over-writing // ������ ������ ����� ���� �����.
	//// a: appending or creating-and-writing // ������ ������ �̾ �ۼ��Ѵ�.
	//// r+: both reading and writing
	//// w+: reading and writing, over-writing or creating
	//// a+: reading and writing, appending or creating

	//while ((ch = fgetc(fr)) != EOF) // getc(fr)
	//{
	//	//putc(ch, stdout); // same as putchar(ch);
	//	fputc(ch, stdout); // error stream���� �ٲ��� ���� �ִ�.
	//	count++;
	//}
	//fclose(fr);

	//printf("\nFILE %s has %lu characters\n", argv[1], count);

	//// My Try
	//// ������ �о �ٸ� ���Ͽ� ����
	//int ch;
	//FILE* read;
	//FILE* write;
	//unsigned long count = 0;

	//const char* out_filename = "output.txt"; // cmd�� ���� ��ġ���� ������ �����ȴ�.

	//read = fopen(argv[1], "r");
	//write = fopen(out_filename, "w");

	//while ((ch = fgetc(read)) != EOF)
	//{
	//	// ȭ�鿡 ����ϸ鼭 ���ÿ� ������ �ۼ��Ѵ�.
	//	fputc(ch, stdout);
	//	fputc(ch, write);

	//	count++;
	//}
	//fclose(read);
	//fclose(write);

	//printf("\nFILE %s has %lu characters\n", argv[1], count);
	//printf("Copied to %s", out_filename);


	// 13.3 �ؽ�Ʈ ���ڵ��� �ڵ� ������
	// �ü������ �ٹٲ��� �ٸ���.
	// CRLF
	// CR: ���� ���ο��� Ŀ���� ��ġ�� ���� ������ �ű�� ���� \r
	// LF: Ŀ���� ��ġ�� �״�� �ΰ� ���̸� �� ���� ���� �ø��� ���� \n

	// UTF-8 ���ڵ� ���

	// �ѱ۷� �� txt ������ �ƹ� ��ó�� ���� cmdâ���� �а� �Ǹ� ������ ��µȴ�.
	// text ���ϵ� �ᱹ ���̳ʸ��� ����ȴ�.
	// ������ ��� -> ���̳ʸ��� �� text ������ �߸� decoding �Ѱ�
	// �޸������� ���� ���� ����� ��µȴ�.

	// UTF-8�� ���ڵ� �� txt ������ ���� ���� cmdâ���� ������ ��µ�����
	// ansi�� ���ڵ� �� txt ������ ���� ���� cmdâ���� ���������� ��µȴ�.

	//const UINT default_cp = GetConsoleOutputCP(); // ���� ����ϰ� �ִ� CP(code page)�� ��������
	//printf("%u\n", default_cp);

	//int ch;
	//FILE* fr, * fw;

	//const char* in_filename = "����.txt";
	//const char* out_filename = "�纻.txt";

	//unsigned count = 0;

	//if ((fr = fopen(in_filename, "r")) == NULL)
	//{
	//	printf("Can not open %s\n", in_filename);
	//	exit(EXIT_FAILURE);
	//}

	//SetConsoleOutputCP(CP_UTF8); // UTF-8 mode, cmd â�� ����� ���� ���ڵ�

	//fw = fopen(out_filename, "w");
	//while ((ch = fgetc(fr)) != EOF)
	//{
	//	fputc(ch, stdout);
	//	fputc(ch, fw);
	//	count++;
	//}

	//SetConsoleOutputCP(default_cp); // �׷��� UTF-8�� �ٲٸ� ���α׷� �ڵ忡 �ִ� �ѱ��� ��µ��� �ʱ� ������ �ٽ� ������� �ٲ��ش�.
	//printf("\nFILE %s has %lu characters\n", in_filename, count);
	//printf("Copied to %s\n", out_filename);
	//printf("�ѱ� ��� Ȯ��");


	// 13.4 �ؽ�Ʈ ���� ����� �Լ���
	// fprintf(), fscanf(), fgets(), fputs()
	//FILE* fp;
	//char words[MAX] = { '\0' };
	//const char* filename = "record.txt";

	//if ((fp = fopen(filename, "w+")) == NULL) // r+ ���� ������ ������ ���� ���Ѵ�. Try r+, w+, a+
	//{
	//	fprintf(stderr, "Can't open \"%s\" file.\n", filename);
	//	exit(EXIT_FAILURE);
	//}

	//while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.')) // scanf�� Ư���� ���⸦ ����
	//	fprintf(fp, "%s\n", words);

	////while ((fgets(words, MAX, stdin) == NULL) && words[0] != '.') // fgets�� �迭�� ù �ּ� �����͸� �����ϹǷ� NULL�� üũ�ؾ��Ѵ�.
	////	fputs(words, fp);

	//rewind(fp); // go back to beginning of file

	//while (fscanf(fp, "%s", words)== 1)
	//	fprintf(stdout, "%s\n", words);

	////while (fgets(words, MAX, fp) != NULL)
	////	fputs(words, stdout);

	//if (fclose(fp) != 0)
	//	printf(stderr, "Error closing file\n");


	// 13.5 ���̳ʸ� ���� �����
	// fopen() mode string for binary IO
	// "rb", "wb", "ab"
	// "ab+", "a+b"
	// "wb+", "w+b"
	// "rb+", "r+b"
	// C11 - "wx" "wbx" "w+x" "wb+x" "w+bx" overwrite�� ���� �ʰ� fail

	//FILE* fp = fopen("binary_file", "wb");

	//double d = 1.0 / 3.0;
	//int n = 123; // ������ �д� �ʿ��� �迭 ũ�⸦ �𸣴� ��쿡�� ���� �������ִ°� ����.
	//int* parr = (int*)malloc(sizeof(int) * n);
	//if (!parr) exit(1);
	//for (int n = 0; n < 123; ++n)
	//	*(parr + n) = n * 2;
	//// fwrite(address, size, number, stream);
	//fwrite(&d, sizeof(d), 1, fp); // 8 byte
	//fwrite(&n, sizeof(n), 1, fp); // 4 byte
	//fwrite(parr, sizeof(int), n, fp); // 123 * 4 byte
	//// total 504 byte

	//fclose(fp);
	//free(parr);

	//// �д� �ʿ��� � �������� ����� �ִ��� �˰� �־�� �Ѵ�.
	//{
	//	FILE* fp = fopen("binary_file", "rb");
	//	double d;
	//	int n = 0;

	//	fread(&d, sizeof(d), 1, fp);
	//	fread(&n, sizeof(n), 1, fp);

	//	int* parr = (int*)malloc(sizeof(int) * 123);
	//	if (!parr) exit(1);

	//	fread(parr, sizeof(int), n, fp);

	//	printf("fefo = %d\n", feof(fp)); // feof(fp); end of file�� �������� üũ�ϴ� �Լ�, ���Ͽ� �ִ� ���� �� ���缭 ��� �о��� ������ ���������� EOF�� ����

	//	fread(&n, sizeof(n), 1, fp); // EOF ����


	//	printf("fefo = %d\n", feof(fp)); // check
	//	printf("ferror = %d\n", ferror(fp)); // ���� ��Ʈ���� �о�µ� ������ ������. return 0 = OK

	//	fwrite(&n, sizeof(n), 1, fp); // read ����̱� ������ write�� �� �� ����. ������ ����.
	//	printf("ferror = %d\n", ferror(fp)); // ������ ���� ������ ferror(fp)�� 0�� �ƴ� ���� ��ȯ�Ѵ�.

	//	printf("%f\n", d);
	//	printf("%d\n", n);
	//	for (int i = 0; i < n; ++i)
	//		printf("%d ", *(parr + i));
	//	printf("\n");

	//	fclose(fp);
	//	free(parr);
	//}


	// 13.6 ������ ���� ����(Random Access)
	//int ch;
	//long cur;

	//// ABCDEFGHIJKL ...
	//// Current position 0 and read -> A
	//// Current position 1 and read -> B

	//FILE* fp = fopen("test.txt", "r");

	//cur = ftell(fp); // ftell() ���� ��ġ�� �˷��ִ� �Լ�. ���������κ��� n ����Ʈ��ŭ ������ �ִ�
	//printf("ftell() = %ld\n", cur);

	//fseek(fp, 2L, SEEK_SET); // ������(SEEK_SET)���κ��� 2����Ʈ ������ ������ �̵��Ͽ� read �� �غ� �Ѵ�.
	//cur = ftell(fp);
	//printf("ftell() = %ld\n", cur);
	//ch = fgetc(fp); // �����鼭 �� ĭ �̵��Ѵ�.
	//printf("%d %c\n", ch, ch);
	//cur = ftell(fp);
	//printf("ftell() = %ld\n", cur);

	//fseek(fp, 2L, SEEK_CUR); // ���� ��ġ(SEEK_CUR)�� ���� 2����Ʈ ������ ������ �̵��Ͽ� read �� �غ� �Ѵ�.
	//cur = ftell(fp);
	//printf("ftell() = %ld\n", cur);
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//fseek(fp, 0L, SEEK_END); // ������ ��ġ(SEEK_END)�κ��� 0L��ŭ ������ ������ �̵��Ͽ� read �� �غ� �Ѵ�.
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//fseek(fp, -1L, SEEK_END); // ������ ��ġ(SEEK_END)�κ��� -1L��ŭ ������ ������ �̵��Ͽ� read �� �غ� �Ѵ�.
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//fseek(fp, -2L, SEEK_END); // ������ ��ġ(SEEK_END)�κ��� -2L��ŭ ������ ������ �̵��Ͽ� read �� �غ� �Ѵ�.
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//// ���� ũ�Ⱑ �ſ� ū ��쿡�� long Ÿ�� ��� fpos_t ��� Ÿ���� ����Ѵ�.
	//printf("\nfpos_t\n");
	//fpos_t pt;
	//pt = 10;
	//fsetpos(fp, &pt); // fseek�� ����ϴ�
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);
	//fgetpos(fp, &pt); // ftell�� ����ϴ�.
	//printf("%lld\n", pt); // fpos_t�� ���������ڰ� �������� �ʴ´�. ���⼭�� ���ǻ� %lld�� ����Ѵ�.

	//// make a test binary file
	//{
	//	FILE* fp = fopen("binary", "wb");
	//	for (int i = 0; i < 100; ++i)
	//	{
	//		double d = i * 1.11;
	//		fwrite(&d, sizeof(double), 1, fp);
	//	}
	//	fclose(fp);
	//}
	//// read
	//FILE* fp = fopen("binary", "rb");
	//long cur;
	//double d;

	//cur = ftell(fp);
	//printf("Before reading %ld\n", cur);

	//fread(&d, sizeof(double), 1, fp);

	//cur = ftell(fp);
	//printf("After reading %ld\n", cur);

	//printf("%f\n", d);

	//fread(&d, sizeof(double), 1, fp);
	//printf("%f\n", d);

	//cur = ftell(fp);
	//printf("After reading %ld\n", cur);

	//fseek(fp, 32L, SEEK_SET); // 32 = 4 * 8
	//fread(&d, sizeof(double), 1, fp);
	//printf("%f\n", d);

	//fclose(fp);


	// 13.7 ��Ÿ ����� �Լ���
	// ungetc(), fflush(), setvbuf()
	//FILE* fp;
	//int ch;

	//////ungetc(): �� ���ڸ� ���� ������ ���ۿ� �ٽ� �� ���ڸ� �ִ� �Լ�
	////fp = fopen("input.txt", "r");
	////ch = fgetc(fp);
	////fputc(ch, stdout);

	////ungetc(ch, fp); // ch�� �ٽ� ���ۿ� �ִ´�. Try another characters

	////ch = fgetc(fp);
	////fputc(ch, stdout);

	////fclose(fp);

	//// setvbuff(): ������ ������ �ٲ��� �� �ִ�.
	//fp = fopen("input.txt", "r");
	//char buffer[32] = { '\0' };

	//setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); // buffer[] �迭�� ����� ���۷� ����϶�� �ǹ�, _IOLBF(Line), _IOFBF(Full), _IONBF(No)
	//// _IONBF�� ���۸� ������� �ʴ� �ɼ�, �� ���ھ� ���Ͽ��� �����´�. 
	//
	//ch = fgetc(fp); // �� ���ڸ� �о��.

	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i) // ���ۿ� ������ �� ���ִ� ���� Ȯ�� �� �� �ִ�.
	//	printf("%c", buffer[i]);
	//printf("\n");

	//fclose(fp);
	//// ���� -> ����: �ӵ��� ������ ������ �� ���� ���� ���ھ� ��� �����´�.
	//// ���� -> ���α׷�: �ӵ��� ������.
	//// fgetc()�� �� ���ڸ� �����Դµ��� �� ����� ���� �����ϰ� ���۸� �̸� ä�� ���̴�.
	//// buffer dump �� fgetc()���� �����ϸ� ���۰� ����ִ� ���� Ȯ�� �� �� �ִ�. �� �� ���ڸ� �����Դµ��� ���۸� �� ä�� ���̴�.

	//// fflush(): ���۰� �� ������ �ؾ��� ���� ó��
	////fflush(fp);


	// 13.8 �ؽ�Ʈ�� ���̳ʸ�ó�� �о��
	// �ؽ�Ʈ ���ϵ� �ᱹ�� ���̳ʸ� ����
	FILE* fp = fopen("test_binary.txt", "rb");
	unsigned char ch;

	SetConsoleOutputCP(CP_UTF8); // UTF-8 mode

	while (fread(&ch, sizeof(char), 1, fp) > 0) // fread()�� ��ȯ���� ���� ���� ����
	{
		//printf("%c", ch); // binary ���� �����µ��� ����� ��µȴ�.

		printf("%hhu %c\n", ch, ch); // %hhu�� ����ϸ� �ѱ��� �� ������ �ʴ´�.
		// �ٸ� �ܱ�� ����� ���� ���� byte�� �����Ͽ� ����Ѵ�.
	}

	return 0;
}