#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 41
#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3
#define LEN 20
#define FUNDLEN 50
#define NLEN 30
#define SLEN 101

// 14.2
/*
struct person // Person is a tage of structure
{
	// members
	// 구조체 "변수"가 선언 될 때 메모리가 할당된다.
	// 구조체 멤버를 만들 때는 메모리 할당이 되지 않는다.
	char name[MAX];
	int age;
	float height;
};
*/
// 14.4
/*
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin); // scanf()는 띄어 쓰기 단위로 입력 받기 때문에..
	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline.. 찾고 싶은 문자가 있으면 그 위치의 포인터 반환
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n') // Clear Buffer
				continue;
	}

	return ret_val;
}
*/
// 14.7
/*
struct fortune {
	char bank_name[FUNDLEN];
	double bank_saving;
	char fund_name[FUNDLEN];
	double fund_invest;
};
double sum(const struct fortune* mf)
{
	return mf->bank_saving + mf->fund_invest;
}
*/
// 14.8
/*
struct name_count
{
	char first[NLEN];
	char last[NLEN];
	int num;
};
void receive_input(struct name_count* nc)
{
	int flag;
	printf("Input your first name:\n>> ");
	//s_gets(nc->first, NLEN);
	flag = scanf("%[^\n]%*c", nc->first); // [^\n]: \n이 나올 때까지 받으라는 의미, %*c: c를 하나 무시하라는 의미(여기서는 \n)
	if (flag != 1) printf("Wrong input\n");

	printf("Input your last name:\n>> ");
	//s_gets(nc->last, NLEN);
	flag = scanf("%[^\n]%*c", nc->last);
	if (flag != 1) printf("Wrong input\n");
}
void count_characters(struct name_count* nc)
{
	int count = 0;
	char* first_ptr = nc->first;
	char* last_ptr = nc->last;
	while (*(first_ptr)++ != '\0')
		count++;
	while (*(last_ptr)++ != '\0')
		count++;

	nc->num = count;
}
void show_result(const struct name_count* nc)
{
	printf("Hi, %s %s. Your name has %d characters.\n",
		nc->first, nc->last, nc->num);
}

struct name_count receive_input_v2()
{
	int flag;
	struct name_count nc;

	printf("Input your first name:\n>> ");
	flag = scanf("%[^\n]%*c", nc.first);
	if (flag != 1) printf("Wrong input\n");

	printf("Input your last name:\n>> ");
	flag = scanf("%[^\n]%*c", nc.last);
	if (flag != 1) printf("Wrong input\n");

	return nc;
}
struct name_count count_characters_v2(struct name_count nc)
{
	int count = 0;
	char* first = nc.first, * last = nc.last;

	while (*first++ != '\0')
		count++;
	while (*last++ != '\0')
		count++;

	nc.num = count;

	return nc;
}
void show_result_v2(struct name_count nc)
{
	printf("Hi, %s %s. Your name has %d characters.\n",
		nc.first, nc.last, nc.num);
}
*/
// 14.9
/*
struct namect {
	char* fname; // use malloc
	char* lname; // use malloc
	int letters;
};
void getinfo(struct namect* nct) // malloc()
{
	int flag;
	char buffer[SLEN] = { 0, };

	printf("Please Enter Your First Name.\n>> ");

	flag = scanf("%[^\n]%*c", buffer);
	if (flag != 1)
	{
		printf("Wrong input\n");
		getinfo(nct);
		return;
	}
	else
	{
		nct->fname = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		if (nct->fname != NULL)
			strcpy(nct->fname, buffer);
		else
		{
			printf("malloc() failed.\n");
			return;
		}
		printf("Please Enter Your Last Name.\n>> ");

		flag = scanf("%[^\n]%*c", buffer);
		if (flag != 1)
		{
			printf("Wrong input\n");
			getinfo(nct);
			return;
		}
		else
		{
			nct->lname = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
			if (nct->lname != NULL)
				strcpy(nct->lname, buffer);
			else
			{
				printf("malloc() failed.\n");
				return;
			}
		}
	}
}
void makeinfo(struct namect* nct) 
{
	nct->letters = strlen(nct->fname) + strlen(nct->lname);
}
void showinfo(const struct namect* nct)
{
	printf("%s %s, Your Name Contains %d Letters.\n", nct->fname, nct->lname, nct->letters);
}
void cleanup(struct namect* nct) // free()
{
	free(nct->fname);
	free(nct->lname);
}
*/
// 14.10
/*
struct book
{
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};
struct rectangle
{
	double width;
	double height;
};
double rect_area(struct rectangle r)
{
	return r.width * r.height;
}
double rect_area_ptr(struct rectangle* r)
{
	return r->width * r->height;
}
*/
// 14.13
/*
void print_books(const struct book books[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].title, books[i].author);
	printf("\n");
}
void printf_books_malloc(const struct book* books_malloc, int n)
{
	for (int i = 0; i < n; ++i)
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books_malloc[i].title, books_malloc[i].author);
	printf("\n");
}
*/

// 14.14
/*
struct book
{
	char name[SLEN];
	char author[SLEN];
};
void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
}
void write_books(const char* filename, const struct book* books, int n)
{
	// 주의 Debug 폴더에 생성된다.
	FILE* books_txt = fopen(filename, "w");

	if (books_txt == NULL) { // 파일을 열지 못했을 때
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fprintf(books_txt, "%d", n);
	fputc('\n', books_txt);

	// My Try
	//for (int i = 0; i < n; ++i)
	//{
	//	fwrite(books[i].name, 1, strlen(books[i].name), books_txt);
	//	fputc('\n', books_txt);
	//	fwrite(books[i].author, 1, strlen(books[i].author), books_txt);
	//	fputc('\n', books_txt);
	//}

	for (int i = 0; i < n; ++i)
		fprintf(books_txt, "%s\n%s\n", books[i].name, books[i].author);

	fclose(books_txt);
}
void write_books_binary(const char* filename, const struct book* books, int n)
{
	FILE* file = fopen(filename, "wb");

	if (file == NULL)
	{
		fputs("Can' open file.", stderr);
		exit(1);
	}

	fwrite(&n, sizeof(n), 1, file);
	fwrite(books, sizeof(struct book), n, file); // 한 줄 씩 작성할 필요 없이 데이터 통째로 넣어버린다.

	fclose(file);
}
struct book* read_books(const char* filename, int* n) // n: 몇 개를 읽었는지
{
	// 주의 Debug 폴더에서의 txt 파일을 읽는다.
	FILE* books_txt = fopen(filename, "r");

	if (books_txt == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	//char buffer[SLEN] = { '\0' }; // 버퍼 사용하지 않고 바로 넣는다.

	if (fscanf(books_txt, "%d%*c", n) != 1) // %*c, \n 제거
	{
		printf("fscanf() Failed");
		exit(1);
	}

	// \n을 제거하면 아래 while이 필요 없다.
	//while (fgetc(books_txt) != '\n');

	struct book* books = (struct book*)malloc(sizeof(struct book) * (*n)); // calloc 사용해도 된다.
	if (!books)
	{
		printf("malloc() failed.\n");
		exit(1);
	}

	// My Try
	//for (int i = 0; i < *n; ++i)
	//{
	//	if (fscanf(books_txt, "%[^\n]%*c", buffer) != 1) printf("fscanf() Failed");
	//	strcpy(books[i].name, buffer);
	//	if (fscanf(books_txt, "%[^\n]%*c", buffer) != 1) printf("fscanf() Failed");
	//	strcpy(books[i].author, buffer);
	//}

	for (int i = 0; i < *n; ++i)
	{
		if (fscanf(books_txt, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author) != 2)
		{
			printf("File read failed");
			exit(1);
		}
	}

	fclose(books_txt);
	return books;
}
void read_books2(const char* filename, struct book** books_dptr, int* n)
{
	FILE* books_txt = fopen(filename, "r");

	if (books_txt == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	//char buffer[SLEN] = { '\0' };

	int num;
	if (fscanf(books_txt, "%d%*c", &num) != 1)
	{
		printf("fscanf() Failed");
	}
	*n = num;

	//while (fgetc(books_txt) != '\n');

	*books_dptr = (struct book*)malloc(sizeof(struct book) * num);

	if (!*books_dptr)
	{
		printf("malloc() failed.\n");
		exit(1);
	}

	//for (int i = 0; i < num; ++i)
	//{
	//	if (fscanf(books_txt, "%[^\n]%*c", buffer) != 1) printf("fscanf() Failed");
	//	strcpy((*books_dptr)[i].name, buffer);
	//	if (fscanf(books_txt, "%[^\n]%*c", buffer) != 1) printf("fscanf() Failed");
	//	strcpy((*books_dptr)[i].author, buffer);
	//}

	for (int i = 0; i < *n; ++i)
	{
		if (fscanf(books_txt, "%[^\n]%*c%[^\n]%*c", (*books_dptr)[i].name, (*books_dptr)[i].author) != 2)
		{
			printf("File read failed");
			exit(1);
		}
	}

	fclose(books_txt);
}
void read_books2_binary(const char* filename, struct book** books_dptr, int* n)
{
	// 입출력 속도/많은 데이터 등을 고려해야할 떄는 binary 포맷이 좋다.
	FILE* file = fopen(filename, "wb");
	if (file == NULL)
	{
		fputs("Can't open file.", stderr);
		exit(1);
	}

	fread(n, sizeof(*n), 1, file);
	struct book* books = (struct book*)calloc(sizeof(struct book), *n);
	if (!books)
	{
		printf("malloc() failed.");
		exit(1);
	}

	fread(books, sizeof(struct book), *n, file);
	fclose(file);
}
*/

int main()
{
	// 14.1 구조체(Structure)가 필요한 이유
	// Patient
	// name (string)
	// heigth (cm)
	// weight (kg)

	// variables -> 배열로?
	// 배열은 자료형이 같은 데이터 오브젝트들이 나열된 형태
	// 자료형이 서로 다르지만 함께 사용하면 편리한 데이터 오브젝트들끼리 모을 수는 없을까?
	// -> 구조체를 이용한다.

	// Dot(.) is structure member operator
	// template - 틀

	// 14.2 구조체의 기본적인 사용법
	//int flag;

	//// 구조체 변수 선언하는 방법
	//// 이 변수를 선언할 때 char, int, float 크기의 메모리를 할당해준다.
	//struct person genie;

	//// 구조체 멤버에 접근하여 사용하는 방법 - Dot(.) structure membership operator(member access operator, member operator)
	//strcpy(genie.name, "Will Smith");
	////strncpy(genie.name, "Will Smith", MAX);
	//genie.age = 1000;

	//flag = scanf("%f", &genie.height); // &(genie.height)
	//printf("%f\n", genie.height);

	//// 구조체 변수 초기화하는 방법
	//struct person princess = { "Naomi Scott", 18, 160.0f }; // 순서를 지켜야 한다.
	//struct person princess2 = {
	//	"Naomi Scott",
	//	18,
	//	160.0f
	//};

	//// Designated initializers
	//struct person beauty = {
	//	.age = 19,
	//	.name = "Bell",
	//	.height = 150.0f
	//};

	//// Pointer to a structure variable
	//struct person* someone;
	//someone = &genie;
	////someone = (struct person*)malloc(sizeof(struct person)); // and free later

	//// Indirect member(ship) operator (or structure pointer operator)
	//// Dot(.) 대신 arrow(->)를 사용한다.
	//someone->age = 1001; // arrow operator
	//printf("%s %d\n", someone->name, (*someone).age);

	//// structure declarations in a function
	//// 함수 안에서만 구조체를 사용하고, scope를 벗어나면 사용을 못하고...
	//struct book
	//{
	//	char title[MAX];
	//	float price;
	//};

	//// No tag
	//struct {
	//	char farm[MAX];
	//	float price;
	//} apple, apple2; // struct variable을 struct {...} 뒤에 쓸 수도 있다.

	////struct {
	////	char farm[MAX];
	////	float price;
	////} apple3;

	//strcpy(apple.farm, "Trade Joe");
	//apple.price = 1.2f;

	//strcpy(apple2.farm, "Trade Joe");
	//apple2.price = 1.2f;

	//// typedef and struct
	//typedef struct person my_person; // typedef를 앞에 붙여주면
	//my_person p3; // 구조체 변수를 선언할 때 struct를 앞에 붙여주지 않아도 된다.

	//typedef struct person person; // 구조체 tag와 typedef의 이름을 같게 해줘도 된다.(일반적)

	//typedef struct {
	//	char name[MAX];
	//	char hobby[MAX];
	//} friend;

	//friend f4;

	// 14.3 구조체의 메모리 할당
	// Well Aligned structure
	//struct Aligned
	//{
	//	int a;
	//	float b;
	//	double c;
	//};
	///*
	//0 1 2 3 4 5 6 7 | 8 9 10 11 12 13 14 15 |
	//|int a | float b| double c              |
	//*/

	//struct Aligned a1, a2;
	//printf("Struct Aligned a1\n");
	//printf("Sizeof %zd\n", sizeof(struct Aligned));
	//printf("%lld\n", (long long)&a1);
	//printf("%lld\n", (long long)&a1.a);
	//printf("%lld\n", (long long)&a1.b);
	//printf("%lld\n", (long long)&a1.c);
	//printf("\n");

	//printf("Struct Aligned a2\n");
	//printf("Sizeof %zd\n", sizeof(struct Aligned));
	//printf("%lld\n", (long long)&a2);
	//printf("%lld\n", (long long)&a2.a);
	//printf("%lld\n", (long long)&a2.b);
	//printf("%lld\n", (long long)&a2.c);
	//printf("\n");

	//// Memory Padding
	//struct Padded1
	//{
	//	char a;
	//	float b;
	//	double c;
	//};

	//// 1 + 4 + 8 = 13byte
	//// 실제로는 16바이트이다.
	//// 컴파일러가 char를 4칸으로 채운다.(padding 을 넣어줌)
	//// padding(struct member alignment)

	//// 메모리와 CPU가 데이터를 1 byte 씩(or 1 bit) 주고받지 않을까? - 아니다. (느려진다.)
	//// 데이터를 묶어서 보내는데 그 단위를 1 word라고 한다. x86에서는 4byte, x64에서는 8byte이다.
	//
	//struct Padded1 p1;
	//printf("Struct Padded1 p1\n");
	//printf("Sizeof %zd\n", sizeof(struct Padded1));
	//printf("%lld\n", (long long)&p1);
	//printf("%lld\n", (long long)&p1.a);
	//printf("%lld\n", (long long)&p1.b);
	//printf("%lld\n", (long long)&p1.c);
	//printf("\n");

	//// struct를 만들 때 member의 순서가 padding에 영향을 미친다.
	//struct Padded2
	//{
	//	float a;
	//	double b;
	//	char c;
	//};
	//// 24 바이트.. 비효율적이다.
	//// 컴파일러가 double을 한 word에 보내기 위해서 float과 char에 padding을 넣기 때문이다.
	//struct Padded2 p2;
	//printf("Struct Padded2 p2\n");
	//printf("Sizeof %zd\n", sizeof(struct Padded2));
	//printf("%lld\n", (long long)&p2);
	//printf("%lld\n", (long long)&p2.a);
	//printf("%lld\n", (long long)&p2.b);
	//printf("%lld\n", (long long)&p2.c);
	//printf("\n");

	//// 구조체의 배열..

	//// Properties -> C/C++ -> struct member alignment 설정을 할 수 있다.

	// 14.4 구조체의 배열 연습문제
	//struct book
	//{
	//	char title[MAX_TITLE];
	//	char author[MAX_AUTHOR];
	//	float price;
	//};

	// My Try
	//struct book booklist[MAX_BOOKS];
	//int index = 0;
	//while (1)
	//{
	//	printf("Input a book title or press [Enter] to stop\n");
	//	printf(">>");

	//	gets(booklist[index].title);

	//	if (booklist[index].title[0] == '\0')
	//	{
	//		break;
	//	}

	//	printf("Input the author\n");
	//	printf(">>");

	//	gets(booklist[index].author);

	//	printf("Input the price\n");
	//	printf(">>");

	//	scanf("%f", &booklist[index++].price);

	//	// Buffer Clear
	//	getchar();
	//}

	//if (index == 0)
	//	printf("No bookcs to show.\n");
	//else
	//{
	//	printf("The list of books:\n");
	//	for (int i = 0; i < index; ++i)
	//		printf("\"%s\" written by %s: $%.1f\n", booklist[i].title, booklist[i].author, booklist[i].price);
	//}

	// Sol
	//struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, }; // 초기화를 해주는 편이 좋다.
	//int count = 0;

	//while (1)
	//{
	//	printf("Input a book title or press [Enter] to stop\n>> ");
	//	if (s_gets(library[count].title, MAX_TITLE) == NULL) break;
	//	if (library[count].title[0] == '\0') break;

	//	printf("Input the author\n>> ");
	//	s_gets(library[count].author, MAX_AUTHOR);

	//	printf("Input the price\n>> ");
	//	scanf("%f", &library[count].price);
	//	while(getchar() != '\n')
	//		continue; // clear buffer

	//	if (count++ >= MAX_BOOKS)
	//	{
	//		printf("No more books.\n");
	//		break;
	//	}
	//}

	//if (count == 0)
	//	printf("No books to show.\n");
	//else
	//{
	//	printf("\nThe list of books:\n");
	//	for (int i = 0; i < count; ++i)
	//		printf("\"%s\" written by %s: $%.1f\n", library[i].title, library[i].author, library[i].price);
	//}

	// 14.5 구조체를 다른 구조체의 멤버로 사용하기 - 중첩 구조체 Nested Structure
	//struct names {
	//	char given[LEN]; // first name
	//	char family[LEN]; // last name
	//};

	//struct reservation {
	//	struct names guest;
	//	struct names host;
	//	char food[LEN];
	//	char place[LEN];

	//	// time
	//	int year;
	//	int month;
	//	int day;
	//	int hours;
	//	int minutes;
	//};

	//struct reservation res = {
	//	.guest = {"Nick", "Carraway"},
	//	.host = {"Jay", "Gatsby"},
	//	.place = "the Gatsby mansion",
	//	.food = "Escargot",
	//	.year = 1925,
	//	.month = 4,
	//	.day = 10,
	//	.hours = 18,
	//	.minutes = 30
	//};

	//printf("Dear %s %s,\nI would like to serve you %s.\nPlease visit %s on %d/%d/%d at %d:%d.\nSincerely,\n%s %s\n",
	//	res.guest.given, res.guest.family, res.food, res.place, res.day, res.month, res.year, res.hours, res.minutes, res.host.given, res.host.family);

	// 14.6 구조체와 포인터
	//struct names {
	//	char given[LEN];
	//	char family[LEN];
	//};
	//struct friend {
	//	struct names full_name;
	//	char mobile[LEN];
	//};

	//struct friend my_friends[2] = {
	//	{{"Ariana", "Grande"}, "1234-1234"},
	//	{{"Taylor", "Swift"}, "6550-8888"}
	//};

	//struct friend* girl_friend;
	//girl_friend = &my_friends[0];

	//printf("%zd\n", sizeof(struct friend));
	//printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);

	//girl_friend++;
	//printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
	//// dot operator가 indirection operator보다 우선순위가 높다.

	//struct my_data
	//{
	//	int a;
	//	char c;
	//	float arr[2];
	//};

	//struct my_data d1 = { 1234, 'A', {1.1f, 2.2f} };
	//d1.arr[0] = 1.1f;
	//d1.arr[1] = 2.2f;

	//printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	//printf("%f %f\n", d1.arr[0], d1.arr[1]);
	//printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	//struct my_data d2 = d1; // 내부적으로 값을 복사해준다. 주소는 다르다.

	//printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	//printf("%f %f\n", d2.arr[0], d2.arr[1]);
	//printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	//// 동적할당으로 한다면?
	//struct my_data
	//{
	//	int a;
	//	char c;
	//	float* arr;
	//};

	//struct my_data d1 = { 1234, 'A', NULL };
	//d1.arr = (float*)malloc(sizeof(float) * 2);
	//d1.arr[0] = 1.1f;
	//d1.arr[1] = 2.2f;

	//printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	//printf("%f %f\n", d1.arr[0], d1.arr[1]);
	//printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	//struct my_data d2 = d1; // 내부적으로 주소값을 복사한다. d1.arr과 d2.arr의 주소가 같기 때문에, 같은 메모리를 공유하고 있다.

	//printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	//printf("%f %f\n", d2.arr[0], d2.arr[1]);
	//printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	// 14.7 구조체를 함수로 전달하는 방법
	//struct fortune my_fortune = {
	//	"Wells-Fargo",
	//	4032.27,
	//	"JPMorgan Chase",
	//	8543.94
	//};

	////printf("Total : $%.2f\n", sum(&my_fortune.bank_saving, &my_fortune.fund_invest));
	//printf("Total : $%.2f\n", sum(&my_fortune));

	//struct fortune my_fortune2;
	//my_fortune2 = my_fortune; // 값 복사
	//// 함수에 넣어 struct variable을 인자로 넘겨주면 member의 값이 모두 복사돼 함수를 실행한다.
	//// my_fortune과 함수 안에서의 my_fortune의 주소는 다르다.
	//// 값을 복사하기 때문에 일시적으로 메모리를 더 사용한다. 느려질 수도 있다. 해당 구조체 안의 member 값이 많으면 문제가 된다.
	//// member value로 동적할당 메모리를 받아오면 주소만 복사된다.
	//// 따라서 구조체를 함수 인자로 넣어줄 때는 """포인터"""로 넣어주는 것이 좋다.

	// 14.8 구조체와 함수 연습문제
	//struct name_count user_name;

	////receive_input(&user_name);
	////count_characters(&user_name);
	////show_result(&user_name);

	//user_name = receive_input_v2();
	//user_name = count_characters_v2(user_name);
	//show_result_v2(user_name);

	// 14.9 구조체와 할당 메모리
	// Dangerous usage
	//struct namect p = { "Jeong-Mo", "Hong" };
	//printf("%s %s\n", p.fname, p.lname); // p.fname은 "Jeong-Mo"의 첫 주소를 가리키고, "Jeong-Mo"는 TextSegment(ReadOnly)에 저장돼 있다.

	//int f1 = scanf("%[^\n]%*c", p.lname); // 값을 바꾸지 못한다.
	//printf("%s %s\n", p.fname, p.lname);

	// Recommended usage
	//struct namect p = { "Jeong-Mo", "Hong" };
	//char buffer[SLEN] = { 0, };
	//int f2 = scanf("%[^\n]%*c", buffer);
	//p.fname = (char*)malloc(strlen(buffer) + 1);
	//if (p.fname != NULL)
	//	strcpy(p.fname, buffer);
	//printf("%s %s\n", p.fname, p.lname);

	// My Try
	//struct namect person;
	//getinfo(&person);
	//makeinfo(&person);
	//showinfo(&person);
	//cleanup(&person);

	// 14.10 복합 리터럴 Compound Literal
	//struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f }; // 값을 수정할 수 없다.

	//// 값을 수정할 수 있는 방법 1
	//strcpy(book_to_read.title, "Alice in Wonderland");
	//strcpy(book_to_read.author, "Lewis Carroll");
	//book_to_read.price = 20.3f;

	//// 값을 수정할 수 있는 방법 2
	//struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	//book_to_read = book2;

	//// 방법 2를 간략화한 방법 3
	//book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f }; // 복합 리터럴 Compound Literal, L-value이다. (R-value가 아니다.)

	//printf("%s %s\n", book_to_read.title, book_to_read.author);

	//struct rectangle rec1 = { 1.0, 2.0 };
	//double area = rect_area(rec1);

	//area = rect_area((struct rectangle) { 1.0, 2.0 }); // rec1을 선언하지 않고 바로 계산한다.

	//area = rect_area_ptr(&(struct rectangle) { 1.0, 2.0 }); // L-value 이기 때문에 주소 연산자 &를 사용하여 주소를 가져올 수 있다.
	//printf("%f\n", area);

	// 14.11 신축성 있는 배열 멤버(Flexible Array Members)
	// Flexible Array Members (struct hack in GCC) 편법 -> 표준
	//struct flex
	//{
	//	size_t count;
	//	double average;
	//	double values[]; // flexible array member (last member)
	//};

	//// 구조체 크기 + 추가로 받고 싶은 배열 크기만큼 동적 할당을 받아야한다.
	//const size_t n = 3;
	//struct flex* pf = (struct flext*)malloc(sizeof(struct flex) + n * sizeof(double)); // 동적할당 배열처럼 사용할 수 있다.

	//if (pf == NULL) exit(1);

	//printf("\nFlexible array member\n");
	////printf("Sizeof size_t %zd\n", sizeof(size_t)); // 4
	//printf("Sizeof struct flex %zd\n", sizeof(struct flex)); // 4(+4) + 8  = 16, padding
	//printf("Sizeof *pf %zd\n", sizeof(*pf)); // 16
	//printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double)); // 4(+4) + 8 + 3 * 8 = 40
	//
	//printf("%lld\n", (long long)pf); // 구조체 pf의 주소
	//printf("%lld\n", (long long)&pf->count); // 구조체 pf의 첫 번째 member의 주소
	//printf("%zd\n", sizeof(pf->count)); // 4
	//printf("%lld\n", (long long)&pf->average); // &pf->count와 8 차이 난다.
	//printf("Address of pf->values %lld\n", (long long)&pf->values); // &pf->average 와 8차이 난다. address of array-name
	//printf("Value of pf->values %lld\n", (long long)pf->values); // array-name, 위와 같다.
	//	printf("Sizeof pf->values %zd\n", sizeof(pf->values)); // 0, values의 크기를 알 수 없다.

	//pf->count = n; // 동적 할당을 받았기 때문에 사이즈를 측정할 수 없다.
	//pf->values[0] = 1.1;
	//pf->values[1] = 2.1;
	//pf->values[2] = 3.1;

	//pf->average = 0.0;
	//for (unsigned i = 0; i < pf->count; ++i)
	//	pf->average += pf->values[i];
	//pf->average /= (double)pf->count;

	//printf("Average = %f\n", pf->average);

	//// flexible 배열을 사용하지 않고, 마지막 원소를 double*로 받아, malloc을 이용해서 연결해준다면?
	//struct nonflex
	//{
	//	size_t count;
	//	double average;
	//	double* values; // use malloc()
	//}; // 20 ~ 24byte(padding..), double*는 포인터 자체의 메모리를 갖고 있다.

	//struct nonflex nf;
	//nf.values = (double*)malloc(sizeof(double) * n); // 동적할당 배열은 (힙)메모리 어디에 위치할지 알 수가 없다. (Flexible array는 구조체 뒤에 바로 온다.)

	//struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	//if (pf2 == NULL) exit(1);

	////*pf2 = *pf; // Don't copy flexible members, use memcpy() instead
	//// 동적할당을 받은 건 40이었지만, 구조체의 크기는 16이었다. 컴파일러 입장에선, 대입을 시도했을 때 16바이트만 복사를 해준다.

	// 14.12 익명 구조체
	//struct names
	//{
	//	char first[20];
	//	char last[20];
	//};
	//struct person
	//{
	//	int id;
	//	struct names name; // nested structure member (Dot operator 두 번 사용..)
	//};
	//struct person2
	//{
	//	int id;
	//	struct { char first[20]; char last[20]; }; // anonymous structure
	//};

	//struct person ted = { 123, {"Bill", "Gates"} };
	//struct person ted3 = { 125, {"Robert", "Hand"} };

	//puts(ted.name.first);
	//puts(ted3.name.first);

	//struct person2 ted2 = { 124, {"Steve", "wozniak"} };
	//// struct person2 ted2 = { 124, "Steve", "wozniak" }; // also works
	//puts(ted2.first); // Dot operator를 한 번만 하고 바로 first로 접근할 수 있다.

	// 14.13 구조체의 배열을 사용하는 함수
	//struct book my_books[3]; // = {{"The Great Gatsby", "F. Scott Fitzgerald"}, ...};
	//my_books[0] = (struct book){ "The Greate Gatsby", "F. Scott Fitzerald" };
	//my_books[1] = (struct book){ "Hamlet", "Willian Shakespeare" };
	//my_books[2] = (struct book){ "The Odyssey", "Homer" };
	//
	//print_books(my_books, 3);
	//
	//// 동적할당으로 바꿔보면?
	//int n = 3;
	//struct book* my_books_malloc = (struct book*)malloc(sizeof(struct book) * n);
	//if (my_books_malloc == NULL)
	//{
	//	printf("malloc() Failed");
	//	exit(1);
	//}
	//my_books_malloc[0] = (struct book){ "The Greate Gatsby", "F. Scott Fitzerald" };
	//my_books_malloc[1] = (struct book){ "Hamlet", "Willian Shakespeare" };
	//my_books_malloc[2] = (struct book){ "The Odyssey", "Homer" };
	//
	//printf_books_malloc(my_books_malloc, 3);

	// // 14.14 구조체 파일 입출력 연습문제
	// int temp;
	// int n = 3;

	// struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);
	// if (!my_books)
	// {
	// 	printf("malloc() failed.\n");
	// 	exit(1);
	// }

	// my_books[0] = (struct book){ "The Greate Gatsby", "F. Scott Fitzerald" };
	// my_books[1] = (struct book){ "Hamlet", "Willian Shakespeare" };
	// my_books[2] = (struct book){ "The Odyssey", "Homer" };

	// print_books(my_books, n);

	// printf("\nWriting to a file.\n");
	// write_books("books.txt", my_books, n);
	// free(my_books);
	// n = 0;
	// printf("Done.\n");

	// printf("\nPress any key to read data from a file.\n\n");
	// temp = _getch(); // 아무 키나 입력 받기 위해

	// my_books = read_books("books.txt", &n);
	// //read_books2("books.txt", &my_books, &n);
	// print_books(my_books, n);
	// free(my_books);
	// n = 0;

	// 14.15 공용체(Union)의 원리
	// Union vs Structure

	// 구조체와 비슷하다.
	// 구조체는 int, double, char 각각이 메모리를 차지하고, 중간에 패딩이 들어갈 수 있다.
	// 그러나 공용체는 int, double, char이 메모리를 같이 사용한다.
	// 즉 타입이 다른 데이터들이 같은 메모리 공간을 사용한다.
	union my_union
	{
		int i;
		double d;
		char c;
	};

	union my_union uni;						 // 유니온 변수 선언
	printf("%zd\n", sizeof(union my_union)); // 8, 구조체였다면 int(4) + double(8) + char(1) = 13
	printf("%lld\n", (long)&uni);
	printf("%ld %ld %ld\n", (long)&uni.i, (long)&uni.d, (long)&uni.c);
	// vs 컴파일러에서는 주소가 모두 동일하다. 메모리를 공유하기 때문에..

	union my_union save[10];
	printf("%zd\n", sizeof(save)); // 80

	// debug
	union my_union uni1; // 8바이트, 쓰레기 값으로 CC CC CC CC
	uni1.c = 'A';		 // 1바이트만 사용 41 CC CC CC
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// uni1.c = 'A'에서 41(10진법으로 65)로 바뀐다.
	// 즉, 0xCCCCCC41 = -858993599가 된다. (vscompiler)

	uni1.i = 0;	  // 00 00 00 00 위에서 1바이트를 사용하는 것을 지우고 4바이트 사용
	uni1.c = 'A'; // 41 00 00 00
	// 0x00000041
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i); // uni1.i를 정수로 출력해도 65로 제대로 나온다.(00 00 00 00으로 한 번 초기화 했기 때문)

	uni1.d = 1.2; // 33 33 33 33 33 33 f3 3f
	// 0xf33f333333333333
	printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// uni1.i: 4바이트, 0x 33 33 33 33 = 858993459
	// uni1.d: 8바이트, 1.200...
	// uni1.c: 1바이트, 33(10진수로 51), '3'

	union my_union uni2 = uni1; // copy another union
	union my_union uni3 = {10}; // 문법상(메모리 상) 한 가지 원소로만 초기화한다.
	union my_union uni4 = {.c = 'A'}; // designated initializer
	union my_union unio5 = {.d = 1.23, .i = 100}; // DO NOT RECOMMEND

	uni.i = 123;
	uni.d = 1.2;
	uni.c = 'K';

	printf("%d %f %c\n", uni.i, uni.d, uni.c);

	union my_union* pu = &uni; // pointer to union
	int x = pu->i;

	// char를 넣어놓고 사용할 떄는 double로 사용하면...
	uni.c = 'A';
	double real = 3.14 * uni.d; // Do Not Recommend

	return 0;
}