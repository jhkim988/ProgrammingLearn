#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // SetConsoleOutputCP()

#define MAX 31

int main(int argc, char* argv[])
{
	// 13.1 파일 입출력의 작동 원리
	// C언어로 작성된 프로그램을 실행하면 운영체제와의 사이에 stream이 3개가 열린다.(버퍼를 사용하는 입출력 stream)
	// stdin: 키보드 입력 -> 운영체제 -> 프로그램
	// stdout: 프로그램 -> 운영체제 -> 화면출력장치
	// stderr: 프로그램 -> 운영체제 -> 화면출력장치

	// stream의 방향을 재지정하여 파일에 출력할 수도 있다.

	// 파일로 입력/출력을 하고 싶을 수도 있다.
	// Buffered IO streams

	// C언어로 작성된 프로그램이 파일입출력을 할 때는 2가지 모드가 있다.
	// 1. 텍스트 파일 IO stream
	// 2. 바이너리 파일 IO stream

	// 텍스트 파일 - 메모장을 이용해서 바로 읽을 수 있는 파일(사람들이 읽을 수 있는 용도)
	// 바이너리 파일 - 순수하게 데이터만 저장하는 파일(사람이 직접 읽을 수는 없다.)

	// 프로그램에서 변수를 선언했다고 가정한다.
	//int i = 34567;

	// 텍스트 파일 IO stream에서는...
	//fprintf(fp, "%d\n", i);
	// 텍스트 파일에 34567+줄바꿈+(EOF)이 저장된다.
	// 텍스트 파일 IO stream에서는 "34567"이라는 정수 하나를 저장하는 것이 아니라
	// '3' '4' '5' '6' '7' 같은 식으로 문자를 저장한다.
	// 줄바꿈/EOF/인코딩방식은 운영체제마다 다르다.

	// 바이너리 파일 IO stream에서는...
	//fwrite(&i, sizeof(i), 1, fp);
	// 텍스트 파일 IO stream에서 각각의 문자로 쪼개서 저장하는 것과 달리 정수 "34567"을 그대로 저장한다.

	// 운영체제에 따라서 텍스트 파일을 저장하는 방법이 다르다.
	// 언어에 따라서도 다르다. (운영체제가 영어만 사용하도록 설치됐는지 등)
	// 프로그래머가 의도적으로 인코딩 방식을 바꿀 수도 있다.
	// 바이너리 파일 IO stream도 운영체제마다 저장하는 방식이 다르다. Big Endian/Little Endian


	// 13.2 텍스트 파일 입출력 예제
	//int ch;
	//FILE* fr; // 파일을 처리할 때 필요한 데이터 묶음에 대한 포인터

	//unsigned long count = 0;

	//if (argc != 2)
	//{
	//	printf("Usage: %s filename\n", argv[0]);
	//	exit(EXIT_FAILURE);
	//}

	//if ((fr = fopen(argv[1], "r")) == NULL) // open a text file for reading
	//{
	//	// 하드디스크가 꽉 찼다거나, 읽기 전용 파일을 쓰기 모드로 연다거나 등등
	//	printf("Can't open %s\n", argv[1]);
	//	exit(EXIT_FAILURE);
	//}

	//// fopen mode strings for text files
	//// r: reading
	//// w: creawting-and-writing or over-writing // 파일이 있으면 지우고 새로 만든다.
	//// a: appending or creating-and-writing // 파일이 있으면 이어서 작성한다.
	//// r+: both reading and writing
	//// w+: reading and writing, over-writing or creating
	//// a+: reading and writing, appending or creating

	//while ((ch = fgetc(fr)) != EOF) // getc(fr)
	//{
	//	//putc(ch, stdout); // same as putchar(ch);
	//	fputc(ch, stdout); // error stream으로 바꿔줄 수도 있다.
	//	count++;
	//}
	//fclose(fr);

	//printf("\nFILE %s has %lu characters\n", argv[1], count);

	//// My Try
	//// 파일을 읽어서 다른 파일에 쓰기
	//int ch;
	//FILE* read;
	//FILE* write;
	//unsigned long count = 0;

	//const char* out_filename = "output.txt"; // cmd의 현재 위치에서 파일이 생성된다.

	//read = fopen(argv[1], "r");
	//write = fopen(out_filename, "w");

	//while ((ch = fgetc(read)) != EOF)
	//{
	//	// 화면에 출력하면서 동시에 파일을 작성한다.
	//	fputc(ch, stdout);
	//	fputc(ch, write);

	//	count++;
	//}
	//fclose(read);
	//fclose(write);

	//printf("\nFILE %s has %lu characters\n", argv[1], count);
	//printf("Copied to %s", out_filename);


	// 13.3 텍스트 인코딩과 코드 페이지
	// 운영체제마자 줄바꿈이 다르다.
	// CRLF
	// CR: 현재 라인에서 커서의 위치를 가장 앞으로 옮기는 동작 \r
	// LF: 커서의 위치는 그대로 두고 종이를 한 라인 위로 올리는 동작 \n

	// UTF-8 인코딩 방식

	// 한글로 된 txt 파일을 아무 전처리 없이 cmd창에서 읽게 되면 깨져서 출력된다.
	// text 파일도 결국 바이너리로 저장된다.
	// 깨져서 출력 -> 바이너리로 된 text 파일을 잘못 decoding 한것
	// 메모장으로 읽을 때는 제대로 출력된다.

	// UTF-8로 인코딩 된 txt 파일을 읽을 때는 cmd창에서 깨져서 출력되지만
	// ansi로 인코딩 된 txt 파일을 읽을 때는 cmd창에서 정상적으로 출력된다.

	//const UINT default_cp = GetConsoleOutputCP(); // 현재 사용하고 있는 CP(code page)가 무엇인지
	//printf("%u\n", default_cp);

	//int ch;
	//FILE* fr, * fw;

	//const char* in_filename = "원본.txt";
	//const char* out_filename = "사본.txt";

	//unsigned count = 0;

	//if ((fr = fopen(in_filename, "r")) == NULL)
	//{
	//	printf("Can not open %s\n", in_filename);
	//	exit(EXIT_FAILURE);
	//}

	//SetConsoleOutputCP(CP_UTF8); // UTF-8 mode, cmd 창에 출력할 때의 인코딩

	//fw = fopen(out_filename, "w");
	//while ((ch = fgetc(fr)) != EOF)
	//{
	//	fputc(ch, stdout);
	//	fputc(ch, fw);
	//	count++;
	//}

	//SetConsoleOutputCP(default_cp); // 그러나 UTF-8로 바꾸면 프로그램 코드에 있는 한글이 출력되지 않기 때문에 다시 원래대로 바꿔준다.
	//printf("\nFILE %s has %lu characters\n", in_filename, count);
	//printf("Copied to %s\n", out_filename);
	//printf("한글 출력 확인");


	// 13.4 텍스트 파일 입출력 함수들
	// fprintf(), fscanf(), fgets(), fputs()
	//FILE* fp;
	//char words[MAX] = { '\0' };
	//const char* filename = "record.txt";

	//if ((fp = fopen(filename, "w+")) == NULL) // r+ 모드는 파일이 없으면 열지 못한다. Try r+, w+, a+
	//{
	//	fprintf(stderr, "Can't open \"%s\" file.\n", filename);
	//	exit(EXIT_FAILURE);
	//}

	//while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.')) // scanf의 특성상 띄어쓰기를 기준
	//	fprintf(fp, "%s\n", words);

	////while ((fgets(words, MAX, stdin) == NULL) && words[0] != '.') // fgets는 배열의 첫 주소 포인터를 리턴하므로 NULL로 체크해야한다.
	////	fputs(words, fp);

	//rewind(fp); // go back to beginning of file

	//while (fscanf(fp, "%s", words)== 1)
	//	fprintf(stdout, "%s\n", words);

	////while (fgets(words, MAX, fp) != NULL)
	////	fputs(words, stdout);

	//if (fclose(fp) != 0)
	//	printf(stderr, "Error closing file\n");


	// 13.5 바이너리 파일 입출력
	// fopen() mode string for binary IO
	// "rb", "wb", "ab"
	// "ab+", "a+b"
	// "wb+", "w+b"
	// "rb+", "r+b"
	// C11 - "wx" "wbx" "w+x" "wb+x" "w+bx" overwrite를 하지 않고 fail

	//FILE* fp = fopen("binary_file", "wb");

	//double d = 1.0 / 3.0;
	//int n = 123; // 파일을 읽는 쪽에서 배열 크기를 모르는 경우에는 같이 저장해주는게 좋다.
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

	//// 읽는 쪽에서 어떤 형식으로 저장돼 있는지 알고 있어야 한다.
	//{
	//	FILE* fp = fopen("binary_file", "rb");
	//	double d;
	//	int n = 0;

	//	fread(&d, sizeof(d), 1, fp);
	//	fread(&n, sizeof(n), 1, fp);

	//	int* parr = (int*)malloc(sizeof(int) * 123);
	//	if (!parr) exit(1);

	//	fread(parr, sizeof(int), n, fp);

	//	printf("fefo = %d\n", feof(fp)); // feof(fp); end of file을 만났는지 체크하는 함수, 파일에 있는 것을 딱 맞춰서 모두 읽었기 때문에 마지막글자 EOF만 남음

	//	fread(&n, sizeof(n), 1, fp); // EOF 만남


	//	printf("fefo = %d\n", feof(fp)); // check
	//	printf("ferror = %d\n", ferror(fp)); // 파일 스트림을 읽어가는데 에러가 없는지. return 0 = OK

	//	fwrite(&n, sizeof(n), 1, fp); // read 모드이기 때문에 write를 할 수 없다. 오류가 난다.
	//	printf("ferror = %d\n", ferror(fp)); // 오류가 났기 때문에 ferror(fp)가 0이 아닌 값을 반환한다.

	//	printf("%f\n", d);
	//	printf("%d\n", n);
	//	for (int i = 0; i < n; ++i)
	//		printf("%d ", *(parr + i));
	//	printf("\n");

	//	fclose(fp);
	//	free(parr);
	//}


	// 13.6 파일의 임의 접근(Random Access)
	//int ch;
	//long cur;

	//// ABCDEFGHIJKL ...
	//// Current position 0 and read -> A
	//// Current position 1 and read -> B

	//FILE* fp = fopen("test.txt", "r");

	//cur = ftell(fp); // ftell() 현재 위치를 알려주는 함수. 시작점으로부터 n 바이트만큼 떨어져 있다
	//printf("ftell() = %ld\n", cur);

	//fseek(fp, 2L, SEEK_SET); // 시작점(SEEK_SET)으로부터 2바이트 떨어진 곳으로 이동하여 read 할 준비를 한다.
	//cur = ftell(fp);
	//printf("ftell() = %ld\n", cur);
	//ch = fgetc(fp); // 읽으면서 한 칸 이동한다.
	//printf("%d %c\n", ch, ch);
	//cur = ftell(fp);
	//printf("ftell() = %ld\n", cur);

	//fseek(fp, 2L, SEEK_CUR); // 현재 위치(SEEK_CUR)로 부터 2바이트 떨어진 곳으로 이동하여 read 할 준비를 한다.
	//cur = ftell(fp);
	//printf("ftell() = %ld\n", cur);
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//fseek(fp, 0L, SEEK_END); // 마지막 위치(SEEK_END)로부터 0L만큼 떨어진 곳으로 이동하여 read 할 준비를 한다.
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//fseek(fp, -1L, SEEK_END); // 마지막 위치(SEEK_END)로부터 -1L만큼 떨어진 곳으로 이동하여 read 할 준비를 한다.
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//fseek(fp, -2L, SEEK_END); // 마지막 위치(SEEK_END)로부터 -2L만큼 떨어진 곳으로 이동하여 read 할 준비를 한다.
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);

	//// 파일 크기가 매우 큰 경우에는 long 타입 대신 fpos_t 라는 타입을 사용한다.
	//printf("\nfpos_t\n");
	//fpos_t pt;
	//pt = 10;
	//fsetpos(fp, &pt); // fseek과 비슷하다
	//ch = fgetc(fp);
	//printf("%d %c\n", ch, ch);
	//fgetpos(fp, &pt); // ftell과 비슷하다.
	//printf("%lld\n", pt); // fpos_t의 형식지정자가 존재하지 않는다. 여기서는 편의상 %lld를 사용한다.

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


	// 13.7 기타 입출력 함수들
	// ungetc(), fflush(), setvbuf()
	//FILE* fp;
	//int ch;

	//////ungetc(): 한 글자를 읽은 다음에 버퍼에 다시 그 글자를 넣는 함수
	////fp = fopen("input.txt", "r");
	////ch = fgetc(fp);
	////fputc(ch, stdout);

	////ungetc(ch, fp); // ch를 다시 버퍼에 넣는다. Try another characters

	////ch = fgetc(fp);
	////fputc(ch, stdout);

	////fclose(fp);

	//// setvbuff(): 버퍼의 설정을 바꿔줄 수 있다.
	//fp = fopen("input.txt", "r");
	//char buffer[32] = { '\0' };

	//setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); // buffer[] 배열을 입출력 버퍼로 사용하라는 의미, _IOLBF(Line), _IOFBF(Full), _IONBF(No)
	//// _IONBF는 버퍼를 사용하지 않는 옵션, 한 글자씩 파일에서 가져온다. 
	//
	//ch = fgetc(fp); // 한 글자만 읽어본다.

	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i) // 버퍼에 내용이 꽉 차있는 것을 확인 할 수 있다.
	//	printf("%c", buffer[i]);
	//printf("\n");

	//fclose(fp);
	//// 파일 -> 버퍼: 속도가 느리기 때문에 한 번에 여러 글자씩 묶어서 가져온다.
	//// 버퍼 -> 프로그램: 속도가 빠르다.
	//// fgetc()로 한 글자만 가져왔는데도 더 사용할 것을 예상하고 버퍼를 미리 채운 것이다.
	//// buffer dump 를 fgetc()보다 먼저하면 버퍼가 비어있는 것을 확인 할 수 있다. 즉 한 글자만 가져왔는데도 버퍼를 꽉 채운 것이다.

	//// fflush(): 버퍼가 빌 때까지 해야할 일을 처리
	////fflush(fp);


	// 13.8 텍스트를 바이너리처럼 읽어보기
	// 텍스트 파일도 결국은 바이너리 파일
	FILE* fp = fopen("test_binary.txt", "rb");
	unsigned char ch;

	SetConsoleOutputCP(CP_UTF8); // UTF-8 mode

	while (fread(&ch, sizeof(char), 1, fp) > 0) // fread()의 반환값은 읽은 값의 개수
	{
		//printf("%c", ch); // binary 모드로 열었는데도 제대로 출력된다.

		printf("%hhu %c\n", ch, ch); // %hhu도 출력하면 한글이 잘 나오지 않는다.
		// 다른 외국어를 출력할 때는 여러 byte를 조합하여 사용한다.
	}

	return 0;
}