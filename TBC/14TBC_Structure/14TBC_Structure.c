#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

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

// 14.16
/*
struct personal_owner {
	char rrn1[7]; // Resident Registration Number
	char rrn2[8]; // ex: 830422-1185600
};
struct company_owner {
	char crn1[4]; // Company Registration Number
	char crn2[3]; // ex: 111-22-33333
	char crn3[6];
};
union data{
	struct personal_owner po;
	struct company_owner co;
};

struct car_data{
	char model[15];
	int status; // 0 = personal, 1 = company
	union data ownerinfo;
};

void print_car(struct car_data car)
{
	printf("----------------------------------\n");
	printf("Car model : %s\n", car.model);
	if (car.status == 0 ) // personal
		printf("Personal Owner: %s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
	else // company
		printf("Company Owner: %s-%s-%s\n", car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
	printf("----------------------------------\n");
}
*/

// 14.17
/*
struct personal_owner
{
	char rrn1[7]; // Resident Registration Number
	char rrn2[8]; // ex: 830422-1185600
};
struct company_owner
{
	char crn1[4]; // Company Registration Number
	char crn2[3]; // ex: 111-22-33333
	char crn3[6];
};
struct car_data
{
	char model[15];
	int status; // 0 = personal, 1 = company
	union
	{
		struct personal_owner po;
		struct company_owner co;
	};
};
void print_car(struct car_data car)
{
	printf("----------------------------------\n");
	printf("Car model : %s\n", car.model);
	if (car.status == 0) // personal
		printf("Personal Owner: %s-%s\n", car.po.rrn1, car.po.rrn2);
	else // company
		printf("Company Owner: %s-%s-%s\n", car.co.crn1, car.co.crn2, car.co.crn3);
	printf("----------------------------------\n");
}
*/
// 14.20
/*
int iamfunction()
{
	return 0;
}
*/

// 14.21
/*
void f1() {
	return;
}
int f2(char i) {
	return i + 1;
}
*/

// 14.22
/*
void ToUpper(char* str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while(*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void UpdateString(char* str, int(*pf)(int)) // int(__cdecl *pf)(int)
{
	while(*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}
*/

// 14.23
/*
// K&R Chapter 5.12
char char3[3] = {'A', 'B', 'C'};
char(*complicated_function1())[3] // char[3] 포인터를 리턴하는 함수
{
	return &char3;
}
// 함수 포인터를 선언하려면 이렇게 해야한다...
char (*(*fptr1)())[3] = complicated_function1;

typedef char(*FRPTC3())[3]; // Function Returns Pointer to Char[3]
typedef char(*(*PTFRPTC3)())[3];

FRPTC3 *fptr2 = complicated_function1;
PTFRPTC3 fptr3 = complicated_function1;

typedef char c3[3];
c3* complicated_function2()
{
	return &char3;
}
*/

// 14.24
/*
int temp(int a)
{
	return 0;
}
int (*g(int a))(int) {
	return temp;
}
*/

// 14.25
/*
int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

struct kid
{
	char name[100];
	int height;
};

int compareKid(const void* first, const void* second)
{
	// MyTry
	//if (((*(struct kid*)first).height) > ((*(struct kid*)second).height))
	//	return 1;
	//else if (((*(struct kid*)first).height) < ((*(struct kid*)second).height))
	//	return -1;
	//else
	//	return 0;

	if (((struct kid*)first)->height > ((struct kid*)second)->height)
		return 1;
	else if (((struct kid*)first)->height < ((struct kid*)second)->height)
		return -1;
	else
		return 0;
}	
*/

// 14.26
void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
	return;
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
	return;
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
	return;
}
void Transpose(char* str)
{
	while (*str)
	{
		if (isupper(*str))
			*str = tolower(*str);
		else
			*str = toupper(*str);
		str++;
	}
	return;
}

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
	// union my_union
	// {
	// 	int i;
	// 	double d;
	// 	char c;
	// };

	// union my_union uni;						 // 유니온 변수 선언
	// printf("%zd\n", sizeof(union my_union)); // 8, 구조체였다면 int(4) + double(8) + char(1) = 13
	// printf("%lld\n", (long)&uni);
	// printf("%ld %ld %ld\n", (long)&uni.i, (long)&uni.d, (long)&uni.c);
	// // vs 컴파일러에서는 주소가 모두 동일하다. 메모리를 공유하기 때문에..

	// union my_union save[10];
	// printf("%zd\n", sizeof(save)); // 80

	// // debug
	// union my_union uni1; // 8바이트, 쓰레기 값으로 CC CC CC CC
	// uni1.c = 'A';		 // 1바이트만 사용 41 CC CC CC
	// printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// // uni1.c = 'A'에서 41(10진법으로 65)로 바뀐다.
	// // 즉, 0xCCCCCC41 = -858993599가 된다. (vscompiler)

	// uni1.i = 0;	  // 00 00 00 00 위에서 1바이트를 사용하는 것을 지우고 4바이트 사용
	// uni1.c = 'A'; // 41 00 00 00
	// // 0x00000041
	// printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i); // uni1.i를 정수로 출력해도 65로 제대로 나온다.(00 00 00 00으로 한 번 초기화 했기 때문)

	// uni1.d = 1.2; // 33 33 33 33 33 33 f3 3f
	// // 0xf33f333333333333
	// printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// // uni1.i: 4바이트, 0x 33 33 33 33 = 858993459
	// // uni1.d: 8바이트, 1.200...
	// // uni1.c: 1바이트, 33(10진수로 51), '3'

	// union my_union uni2 = uni1; // copy another union
	// union my_union uni3 = {10}; // 문법상(메모리 상) 한 가지 원소로만 초기화한다.
	// union my_union uni4 = {.c = 'A'}; // designated initializer
	// union my_union unio5 = {.d = 1.23, .i = 100}; // DO NOT RECOMMEND

	// uni.i = 123;
	// uni.d = 1.2;
	// uni.c = 'K';

	// printf("%d %f %c\n", uni.i, uni.d, uni.c);

	// union my_union* pu = &uni; // pointer to union
	// int x = pu->i;

	// // char를 넣어놓고 사용할 떄는 double로 사용하면...
	// uni.c = 'A';
	// double real = 3.14 * uni.d; // Do Not Recommend

	// 14.16 공용체와 구조체를 함께 사용하기
	// struct car_data my_car = {.model = "Avante", .status = 0, .ownerinfo.po = {"830422", "1185600"}};
	// struct car_data company_car = {.model = "Sonata", .status = 1, .ownerinfo.co = {"111", "22", "33333"}};
	// print_car(my_car);
	// print_car(company_car);

	// 14.17 익명 공용체
	// struct car_data my_car = {.model = "Avante", .status = 0, .po = {"830422", "1185600"}};
	// struct car_data company_car = {.model = "Sonata", .status = 1, .co = {"111", "22", "33333"}};
	// print_car(my_car);
	// print_car(company_car);

	// struct Vector2D
	// {
	// 	union
	// 	{
	// 		struct
	// 		{
	// 			double x, y;
	// 		};
	// 		struct
	// 		{
	// 			double i, j;
	// 		};
	// 		struct
	// 		{
	// 			double arr[2];
	// 		};
	// 	};
	// };
	// typedef struct Vector2D vec2;
	// vec2 v = {3.14, 2.99};
	// printf("%.2f %.2f\n", v.x, v.y);
	// printf("%.2f %.2f\n", v.i, v.j);
	// printf("%.2f %.2f\n", v.arr[0], v.arr[1]);

	// // 배열로 쓰면 for문을 통해 순회할 수 있다.
	// for (int d = 0; d < 2; ++d)
	// {
	// 	printf("%.2f \n", v.arr[d]);
	// }
	
	// 14.18 열거형 Enumerated Types
	// // Motivation
	// // red: 0, oragne: 1, yellow: 2, green: 3, ...
	// // if (c == 2) printf("yellow");

	// // define을 이용하여 Symbolic constant를 만들 수 있지만, 컴파일 타임에 오류를 잡을 수 없다.

	// // 열거형을 사용하자. Enumerated type
	// enum spectrum {red, orange, yellow, green, 	blue, violet};
	// // red: 0, orange: 1, yellow: 2, green: 3, blue: 4, violet: 5
	// // enumerator

	// enum spectrum color;
	// color = blue;
	
	// if (color == yellow)
	// {
	// 	printf("yellow");
	// 	// printf(yellow); // 그냥 정수일 뿐이다.
	// }	
	// // 정수이기 때문에 for문으로 순회가 가능하다.
	// for (color = red; color <= violet; color++) // C++에서는 열거형에 대해서 ++를 사용할 수 없다.
	// {
	// 	printf("%d\n", color);
	// }

	// printf("red = %d, orange = %d", red, orange);

	// enum kids {jackjack, dash, snoopy, nano, pitz};
	// enum kids my_kid = nano;
	// printf("nano %d %d\n", my_kid, nano);

	// enum levels {low = 100, medium = 500, high = 2000};
	// int score = 800;
	// if (score > high)
	// 	printf("High Score\n");
	// else if (score > medium)
	// 	printf("Good jon\n");
	// else if (score > low)
	// 	printf("Not bad\n");
	// else
	// 	printf("Do your best\n");
	
	// enum pet {cat, dog = 10, lion, tiger};
	// printf("cat %d\n", cat); // 0
	// printf("lion %d\n", lion); // 11
	
	// 14.19 열거형 연습문제
	// enum spectrum {red, orange, yellow, green, blue};
	// const char* colors[] = {"red", "orange", "yellow", "green", "blue"};

	// char choice[LEN] = {0, };
	// enum spectrum color;
	// bool color_is_found = false;

	// while (1)
	// {
	// 	printf("Input a color name (empty line to quit)\n");

	// 	// My Try		
	// 	// if (fgets(choice, sizeof(choice), stdin) == NULL || choice[0] == '\n')
	// 	// {
	// 	// 	break;
	// 	// }
	// 	// choice[strlen(choice) - 1] = '\0';

	// 	if (scanf("%[^\n]%*c", choice) != 1)
	// 	{
	// 			break;
	// 	}

	// 	int color;
	// 	for (color = red; color <= blue; ++color)
	// 	{
	// 		if (strcmp(colors[color], choice) == 0)
	// 			{
	// 				color_is_found = true;
	// 				break;
	// 			}
	// 	}

	// 	if (color_is_found)
	// 	{
	// 		switch (color)
	// 		{
	// 			case red:
	// 			printf("Red Zeppelin\n");
	// 			break;
				
	// 			case orange:
	// 			printf("Orange juice\n");
	// 			break;

	// 			case yellow:
	// 			printf("Yellow submarine\n");
	// 			break;

	// 			case green:
	// 			printf("Green green grass of home\n");
	// 			break;

	// 			case blue:
	// 			printf("Blue Baby\n");
	// 			break;
	// 		}
	// 		color_is_found = false;
	// 	} else
	// 	{
	// 		printf("Please try different color %s\n", choice);
	// 	}
	// }
	// printf("Good Bye");

	// 14.20 네임 스페이스 (이름공간)
	// {
	// 	int my_name = 345;
	// 	// double my_name; = 3.14; // 같은 스코프에서 이름이 같으면 안된다.
	// }
	// struct rect // tag가 rect다.
	// {
	// 	double x;
	// 	double y;
	// };
	// // struct rect rect = {1.1, 2.2}; // 구조체 변수 이름을 rect로 할 수 있다. (카테고리가 다르다.)
	// int rect = 123; // C++에서는 허용되지 않는다.

	// // Not Ok
	// // typedef struct rect rect;
	// // rect rect = {1.1, 1.2};
	
	// // int iamfunction = iamfunction(); // 충돌
	
	// // Namespace pollution(공해)
	// // 쓸만한 변수 이름을 이미 다른 곳에서 사용하고 있는 경우가 꽤 많다.
	// // 가급적 네임 스페이스를 작게 사용해야 그런 상황이 적어진다.
	// // 다른 파일에서 이름이 겹치면 Linking 과정에서 오류가 난다.
	// // 전역변수를 적게 사용하거나 static 키워드를 사용 하는 등...

	// 14.21 함수 포인터의 원리
	// void (*pf1)() = f1; // f1 함수가 저장돼 있는 주솟값을 pf1에 저장한다.
	// // void (*pf1)() = &f1; // & 붙여도 되고 안 붙여도 된다. 함수 이름 자체가 주소(포인터)이기 때문에 &를 안 붙여도 된다.

	// int (*pf2)(char) = f2;

	// (*pf1)(); // call f1 via pf1
	// //pf1(); // 이렇게 호출해도 된다.

	// int a = pf2('A');
	// // int a = (*pf2)('A');
	
	// // Text Segment(프로그램 코드, Read only)
	// // 프로그램 작성 -> 컴파일 -> 실행파일 생성(하드디스크에 저장)
	// // 실행파일 실행 -> 운영체제가 프로그램 자체를 메모리에 올린다. -> 프로그램 코드 자체가 저장되는곳이 Text Segment

	// // 함수 포인터 자체는 주솟값을 저장하는 변수 - stack 메모리에 저장된다.
	// // 문자열 리터럴, 함수 이름, 메인함수까지도 text segment에 저장된다. 
	
	// 14.22 함수포인터 사용방법
	// char str[] = "Hello, World!";
	// void (*pf)(char*);

	// pf = ToUpper;
	// // pf = &ToUpper; // Acceptable
	// // pf = ToUpper(str); // Not Acceptable in C

	// printf("String Literal %lld\n", (long)("Hello, World!")); // Text Segment
	// printf("Functional Pointer %lld\n", (long)ToUpper); // Text Segment
	// printf("Variable %lld\n", (long)str); // Stack

	// (*pf)(str);
	// printf("ToUpper %s\n", str);
	// // pf(str); // K&R: No, ANSI: Ok

	// pf = ToLower;
	// (*pf)(str);
	// printf("ToLower %s\n", str);

	// UpdateString(str, toupper);
	// printf("ToUpper %s\n", str);

	// UpdateString(str, tolower);
	// printf("ToLower %s\n", str);

	// // Node: _cdecl is function calling convention(함수 호출 규약)

	// 14.23 자료형에 별명을 붙여주는 typedef
	// // Give Symbolic names(or aliases) to types
	// // Does not create new types
	// typedef unsigned char BYTE; // typedef [별명을 붙여줄 타입] [별명]
	// BYTE x, y[10] = {0, }, *z = &x; // 변수, 배열, 포인터 다 된다.
	// {
	// 	// typedef도 스코프를 갖는다.

	// 	typedef unsigned char byte;

	// 	// 이식성이 높다.
	// 	size_t s = sizeof(byte); // x86: sizeof() -> unsigned int, x64: sizeof() -> unsigned long long
	// 	// unsigned int s = sizeof(byte); // x86
	// 	// unsigned long long s = sizeof(byte); // x64
	// 	// x86, x64 각 경우마다 size_t를 따로 정의해둬서 편리하다.

	// }
	// // byte b; // 스코프 밖이라 사용 불가

	// time_t t = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 몇 초가 지났는지 알려주는 함수

	// printf("%lld\n", t);

	// // typedef vs #define
	// // 기본적으로는 typedef를 권장한다.

	// typedef char* STRING;
	// STRING name = "John Wick", sign = "World";

	// // #define은 전처리기, 즉 컴파일하기 전에 처리가 된다. 단순한 복사-붙여넣기이다.
	// // typedef는 컴파일러가 처리를 해준다.

	// // #define STRING char*
	// // 전처리기가 STRING을 모두 char*로 바꿔버린다.

	// // 위를 아래로 바꾼다.
	// // STRING name, sign;
	// // char* name, sign; // sign은 포인터가 아니게 된다. char* name, *sign;으로 되야하는데...

	// typedef struct complex
	// {
	// 	float real;
	// 	float imag;
	// } COMPLEXT; // typedef struct complex COMPLEX

	// typedef struct
	// {
	// 	double width;
	// 	double height;
	// } rect; // No tag

	// rect r1 = {1.1, 2.2};
	// rect r2 = r1;
	// printf("%f %f\n", r2.width, r2.height);

	// // K&R Chapter 5.12
	// char(*ret_val)[3] = fptr1();
	// printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

	// c3 *my_c3 = fptr2();
	// printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);

	// 14.24 복잡한 선언을 해석하는 요령
	//// 복잡해지는 이유 - *, (), [] (함수의 매개변수가 들어가는 공간, 배열의 index가 들어가는 공간)
	//// 1. 안쪽에서부터 바깥쪽으로 읽어라.
	//// 2. *보다 (), []가 우선순위가 높다.

	//// 식별자(이름)을 먼저 찾는다. (ap)
	//// 우선순위가 높은 []를 확인한다. 즉 ap는 배열이다.
	//// int*을 마지막으로 해석한다. 즉 ap는 int* 10개 배열이다.
	//int* ap[10]; 

	//// typedef를 이용해서 생각하면 쉬워진다.
	//typedef int* pint;
	//pint ap1[10]; // pint의 10개짜리 배열

	//// 1. 이름 찾기 - fp
	//// 2. 우선순위가 높은 ()를 인식 - fp는 함수다. 매개변수로 float가 들어간다.
	//// 3. float*을 리턴하는 함수라는 것을 알 수 있다.
	//float* fp(float);

	//// typedef를 이용해서 생각하면
	//typedef float* pfloat;
	//pfloat fp(float); // pfloat 타입을 반환하는 함수

	//// 1. 일단 포인터다. *pf
	//// 2. (int)를 보면 함수다. 즉 함수 포인터다.
	//// 3. void를 보면, 아무것도 리턴하지 않는 함수 포인터다.
	//void (*pf)(int);

	//// 1. x는 배열이다. []가 *보다 우선순위가 높다.
	//// 2. x는 포인터에 대한 배열이다. *
	//// 3. 이 포인터는 함수에 대한 포인터다. (void)
	//// 4. 이 함수는 int*(정수 포인터)를 리턴하는 함수이다.
	//int* (*x[10])(void);

	//// 안되는 것들이 있다.
	//// 1. 함수는 배열을 반환할 수 없다.
	//// int f(int)[];
	//int(*f(int))[]; // 배열에 대한 포인터를 반환할 수는 있다.

	//// 2. 함수를 반환할 수는 없다.
	//// int g(int)(int);
	//int(*g(int))(int); // 함수에 대한 포인터를 반환할 수는 있다.

	//// 3. 함수의 배열은 불가능하다.
	//// int(x2[10])(int); 
	//int(*x2[10])(int); // 함수 포인터의 배열은 가능하다.

	//typedef int FCN(int); // 함수타입
	//typedef FCN* FCN_PTR; // 함수의 포인터
	//typedef FCN_PTR FCN_PTR_ARRAY[10]; // 함수 포인터의 배열
	//FCN_PTR_ARRAY x3;

	//// More Example
	//int board[6][4]; // board[6]의 배열
	//int** ptr; // *ptr의 포인터

	//int* risks[10]; // 정수 포인터 10개의 배열
	//int(*rusk)[10]; // 정수 배열의 포인터

	//int* off[3][4]; // 정수 포인터의 이중배열
	//int(*uff)[3][4]; // 정수의 이중배열의 포인터
	//int(*uof[3])[4]; // (int[4] 배열의 포인터)의 배열

	//char* fump(int); // char*를 리턴하는 함수
	//char (*frump)(int); // char를 리턴하는 함수의 포인터
	//char (*flump[3])(int); // 함수 포인터의 배열

	//typedef int arr5[5]; // int[5]를 arr5로
	//typedef arr5* p_arr5; // arr5의 포인터를 p_arr5로
	//typedef p_arr5 arrp10[10]; // p_arr5의 10개 배열을 arrp10으로
	
	// 14.25 qsort
	//int arr[] = { 8, 2, 5, 3, 6, 11 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	//qsort(arr, n, sizeof(int), compare); // <stdlib.h>, compare 함수를 구현해줘야한다.

	//for (int i = 0; i < n; ++i)
	//	printf("%d ", arr[i]);

	//float arrf[] = { 8.1f, 2.4f, 5.6f, 3.2f, 6.1f, 11.0f };
	//int n = sizeof(arrf) / sizeof(arrf[0]);

	//qsort(arrf, n, sizeof(float), compare); 

	//for (int i = 0; i < n; ++i)
	//	printf("%.2f ", arrf[i]);

	//struct kid my_friends[] = { "Jack Jack", 40, "Geenie", 300, "Aladdin", 170, "Piona", 150 };
	//const int n = sizeof(my_friends) / sizeof(struct kid);

	//qsort(my_friends, n, sizeof(struct kid), compareKid);

	//for (int i = 0; i < n; ++i)
	//	printf("%s            \t%d\n", my_friends[i].name, my_friends[i].height);

	// 14.26 함수 포인터의 배열
	char options[] = { 'u', 'l', 't' };
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*); // char*를 인자로 받고 리턴하지 않는 함수의 포인터
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose }; // TODO: add a new menu
	printf("Enter a string\n>> ");

	char input[100];
	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	while (true)
	{
		printf("Choose an option:\n");
		printf("u) To Upper\n");
		printf("l) To Lower\n");
		printf("t) Transpose\n");

		char option;
		while (scanf("%c%*[^\n]%*c", &option) != 1)
			printf("Please try again");

		bool found = false;

		// MyTry
		//switch (option)
		//{
		//case 'u':
		//	operations[0](input);
		//	found = true;
		//	break;
		//case 'l':
		//	operations[1](input);
		//	found = true;
		//	break;
		//case't':
		//	operations[2](input);
		//	found = true;
		//	break;
		//}

		for (int i = 0; i < n; ++i)
			if (options[i] == option)
			{
				(*(operations[i]))(input);
				found = true;
				break;
			}

		if (found)
		{
			printf("%s", input);
			break;
		}
		else
			printf("Wrong input, try again\n");

		
	}





	

	return 0;
}