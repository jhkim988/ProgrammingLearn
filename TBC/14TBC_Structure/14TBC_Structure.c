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
	// ����ü "����"�� ���� �� �� �޸𸮰� �Ҵ�ȴ�.
	// ����ü ����� ���� ���� �޸� �Ҵ��� ���� �ʴ´�.
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

	ret_val = fgets(st, n, stdin); // scanf()�� ��� ���� ������ �Է� �ޱ� ������..
	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline.. ã�� ���� ���ڰ� ������ �� ��ġ�� ������ ��ȯ
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
	flag = scanf("%[^\n]%*c", nc->first); // [^\n]: \n�� ���� ������ ������� �ǹ�, %*c: c�� �ϳ� �����϶�� �ǹ�(���⼭�� \n)
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
	// ���� Debug ������ �����ȴ�.
	FILE* books_txt = fopen(filename, "w");

	if (books_txt == NULL) { // ������ ���� ������ ��
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
	fwrite(books, sizeof(struct book), n, file); // �� �� �� �ۼ��� �ʿ� ���� ������ ��°�� �־������.

	fclose(file);
}
struct book* read_books(const char* filename, int* n) // n: �� ���� �о�����
{
	// ���� Debug ���������� txt ������ �д´�.
	FILE* books_txt = fopen(filename, "r");

	if (books_txt == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	//char buffer[SLEN] = { '\0' }; // ���� ������� �ʰ� �ٷ� �ִ´�.

	if (fscanf(books_txt, "%d%*c", n) != 1) // %*c, \n ����
	{
		printf("fscanf() Failed");
		exit(1);
	}

	// \n�� �����ϸ� �Ʒ� while�� �ʿ� ����.
	//while (fgetc(books_txt) != '\n');

	struct book* books = (struct book*)malloc(sizeof(struct book) * (*n)); // calloc ����ص� �ȴ�.
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
	// ����� �ӵ�/���� ������ ���� ����ؾ��� ���� binary ������ ����.
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
char(*complicated_function1())[3] // char[3] �����͸� �����ϴ� �Լ�
{
	return &char3;
}
// �Լ� �����͸� �����Ϸ��� �̷��� �ؾ��Ѵ�...
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
	// 14.1 ����ü(Structure)�� �ʿ��� ����
	// Patient
	// name (string)
	// heigth (cm)
	// weight (kg)

	// variables -> �迭��?
	// �迭�� �ڷ����� ���� ������ ������Ʈ���� ������ ����
	// �ڷ����� ���� �ٸ����� �Բ� ����ϸ� ���� ������ ������Ʈ�鳢�� ���� ���� ������?
	// -> ����ü�� �̿��Ѵ�.

	// Dot(.) is structure member operator
	// template - Ʋ

	// 14.2 ����ü�� �⺻���� ����
	//int flag;

	//// ����ü ���� �����ϴ� ���
	//// �� ������ ������ �� char, int, float ũ���� �޸𸮸� �Ҵ����ش�.
	//struct person genie;

	//// ����ü ����� �����Ͽ� ����ϴ� ��� - Dot(.) structure membership operator(member access operator, member operator)
	//strcpy(genie.name, "Will Smith");
	////strncpy(genie.name, "Will Smith", MAX);
	//genie.age = 1000;

	//flag = scanf("%f", &genie.height); // &(genie.height)
	//printf("%f\n", genie.height);

	//// ����ü ���� �ʱ�ȭ�ϴ� ���
	//struct person princess = { "Naomi Scott", 18, 160.0f }; // ������ ���Ѿ� �Ѵ�.
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
	//// Dot(.) ��� arrow(->)�� ����Ѵ�.
	//someone->age = 1001; // arrow operator
	//printf("%s %d\n", someone->name, (*someone).age);

	//// structure declarations in a function
	//// �Լ� �ȿ����� ����ü�� ����ϰ�, scope�� ����� ����� ���ϰ�...
	//struct book
	//{
	//	char title[MAX];
	//	float price;
	//};

	//// No tag
	//struct {
	//	char farm[MAX];
	//	float price;
	//} apple, apple2; // struct variable�� struct {...} �ڿ� �� ���� �ִ�.

	////struct {
	////	char farm[MAX];
	////	float price;
	////} apple3;

	//strcpy(apple.farm, "Trade Joe");
	//apple.price = 1.2f;

	//strcpy(apple2.farm, "Trade Joe");
	//apple2.price = 1.2f;

	//// typedef and struct
	//typedef struct person my_person; // typedef�� �տ� �ٿ��ָ�
	//my_person p3; // ����ü ������ ������ �� struct�� �տ� �ٿ����� �ʾƵ� �ȴ�.

	//typedef struct person person; // ����ü tag�� typedef�� �̸��� ���� ���൵ �ȴ�.(�Ϲ���)

	//typedef struct {
	//	char name[MAX];
	//	char hobby[MAX];
	//} friend;

	//friend f4;

	// 14.3 ����ü�� �޸� �Ҵ�
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
	//// �����δ� 16����Ʈ�̴�.
	//// �����Ϸ��� char�� 4ĭ���� ä���.(padding �� �־���)
	//// padding(struct member alignment)

	//// �޸𸮿� CPU�� �����͸� 1 byte ��(or 1 bit) �ְ���� ������? - �ƴϴ�. (��������.)
	//// �����͸� ��� �����µ� �� ������ 1 word��� �Ѵ�. x86������ 4byte, x64������ 8byte�̴�.
	//
	//struct Padded1 p1;
	//printf("Struct Padded1 p1\n");
	//printf("Sizeof %zd\n", sizeof(struct Padded1));
	//printf("%lld\n", (long long)&p1);
	//printf("%lld\n", (long long)&p1.a);
	//printf("%lld\n", (long long)&p1.b);
	//printf("%lld\n", (long long)&p1.c);
	//printf("\n");

	//// struct�� ���� �� member�� ������ padding�� ������ ��ģ��.
	//struct Padded2
	//{
	//	float a;
	//	double b;
	//	char c;
	//};
	//// 24 ����Ʈ.. ��ȿ�����̴�.
	//// �����Ϸ��� double�� �� word�� ������ ���ؼ� float�� char�� padding�� �ֱ� �����̴�.
	//struct Padded2 p2;
	//printf("Struct Padded2 p2\n");
	//printf("Sizeof %zd\n", sizeof(struct Padded2));
	//printf("%lld\n", (long long)&p2);
	//printf("%lld\n", (long long)&p2.a);
	//printf("%lld\n", (long long)&p2.b);
	//printf("%lld\n", (long long)&p2.c);
	//printf("\n");

	//// ����ü�� �迭..

	//// Properties -> C/C++ -> struct member alignment ������ �� �� �ִ�.

	// 14.4 ����ü�� �迭 ��������
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
	//struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, }; // �ʱ�ȭ�� ���ִ� ���� ����.
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

	// 14.5 ����ü�� �ٸ� ����ü�� ����� ����ϱ� - ��ø ����ü Nested Structure
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

	// 14.6 ����ü�� ������
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
	//// dot operator�� indirection operator���� �켱������ ����.

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

	//struct my_data d2 = d1; // ���������� ���� �������ش�. �ּҴ� �ٸ���.

	//printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	//printf("%f %f\n", d2.arr[0], d2.arr[1]);
	//printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	//// �����Ҵ����� �Ѵٸ�?
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

	//struct my_data d2 = d1; // ���������� �ּҰ��� �����Ѵ�. d1.arr�� d2.arr�� �ּҰ� ���� ������, ���� �޸𸮸� �����ϰ� �ִ�.

	//printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	//printf("%f %f\n", d2.arr[0], d2.arr[1]);
	//printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	// 14.7 ����ü�� �Լ��� �����ϴ� ���
	//struct fortune my_fortune = {
	//	"Wells-Fargo",
	//	4032.27,
	//	"JPMorgan Chase",
	//	8543.94
	//};

	////printf("Total : $%.2f\n", sum(&my_fortune.bank_saving, &my_fortune.fund_invest));
	//printf("Total : $%.2f\n", sum(&my_fortune));

	//struct fortune my_fortune2;
	//my_fortune2 = my_fortune; // �� ����
	//// �Լ��� �־� struct variable�� ���ڷ� �Ѱ��ָ� member�� ���� ��� ����� �Լ��� �����Ѵ�.
	//// my_fortune�� �Լ� �ȿ����� my_fortune�� �ּҴ� �ٸ���.
	//// ���� �����ϱ� ������ �Ͻ������� �޸𸮸� �� ����Ѵ�. ������ ���� �ִ�. �ش� ����ü ���� member ���� ������ ������ �ȴ�.
	//// member value�� �����Ҵ� �޸𸮸� �޾ƿ��� �ּҸ� ����ȴ�.
	//// ���� ����ü�� �Լ� ���ڷ� �־��� ���� """������"""�� �־��ִ� ���� ����.

	// 14.8 ����ü�� �Լ� ��������
	//struct name_count user_name;

	////receive_input(&user_name);
	////count_characters(&user_name);
	////show_result(&user_name);

	//user_name = receive_input_v2();
	//user_name = count_characters_v2(user_name);
	//show_result_v2(user_name);

	// 14.9 ����ü�� �Ҵ� �޸�
	// Dangerous usage
	//struct namect p = { "Jeong-Mo", "Hong" };
	//printf("%s %s\n", p.fname, p.lname); // p.fname�� "Jeong-Mo"�� ù �ּҸ� ����Ű��, "Jeong-Mo"�� TextSegment(ReadOnly)�� ����� �ִ�.

	//int f1 = scanf("%[^\n]%*c", p.lname); // ���� �ٲ��� ���Ѵ�.
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

	// 14.10 ���� ���ͷ� Compound Literal
	//struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f }; // ���� ������ �� ����.

	//// ���� ������ �� �ִ� ��� 1
	//strcpy(book_to_read.title, "Alice in Wonderland");
	//strcpy(book_to_read.author, "Lewis Carroll");
	//book_to_read.price = 20.3f;

	//// ���� ������ �� �ִ� ��� 2
	//struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	//book_to_read = book2;

	//// ��� 2�� ����ȭ�� ��� 3
	//book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f }; // ���� ���ͷ� Compound Literal, L-value�̴�. (R-value�� �ƴϴ�.)

	//printf("%s %s\n", book_to_read.title, book_to_read.author);

	//struct rectangle rec1 = { 1.0, 2.0 };
	//double area = rect_area(rec1);

	//area = rect_area((struct rectangle) { 1.0, 2.0 }); // rec1�� �������� �ʰ� �ٷ� ����Ѵ�.

	//area = rect_area_ptr(&(struct rectangle) { 1.0, 2.0 }); // L-value �̱� ������ �ּ� ������ &�� ����Ͽ� �ּҸ� ������ �� �ִ�.
	//printf("%f\n", area);

	// 14.11 ���༺ �ִ� �迭 ���(Flexible Array Members)
	// Flexible Array Members (struct hack in GCC) ��� -> ǥ��
	//struct flex
	//{
	//	size_t count;
	//	double average;
	//	double values[]; // flexible array member (last member)
	//};

	//// ����ü ũ�� + �߰��� �ް� ���� �迭 ũ�⸸ŭ ���� �Ҵ��� �޾ƾ��Ѵ�.
	//const size_t n = 3;
	//struct flex* pf = (struct flext*)malloc(sizeof(struct flex) + n * sizeof(double)); // �����Ҵ� �迭ó�� ����� �� �ִ�.

	//if (pf == NULL) exit(1);

	//printf("\nFlexible array member\n");
	////printf("Sizeof size_t %zd\n", sizeof(size_t)); // 4
	//printf("Sizeof struct flex %zd\n", sizeof(struct flex)); // 4(+4) + 8  = 16, padding
	//printf("Sizeof *pf %zd\n", sizeof(*pf)); // 16
	//printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double)); // 4(+4) + 8 + 3 * 8 = 40
	//
	//printf("%lld\n", (long long)pf); // ����ü pf�� �ּ�
	//printf("%lld\n", (long long)&pf->count); // ����ü pf�� ù ��° member�� �ּ�
	//printf("%zd\n", sizeof(pf->count)); // 4
	//printf("%lld\n", (long long)&pf->average); // &pf->count�� 8 ���� ����.
	//printf("Address of pf->values %lld\n", (long long)&pf->values); // &pf->average �� 8���� ����. address of array-name
	//printf("Value of pf->values %lld\n", (long long)pf->values); // array-name, ���� ����.
	//	printf("Sizeof pf->values %zd\n", sizeof(pf->values)); // 0, values�� ũ�⸦ �� �� ����.

	//pf->count = n; // ���� �Ҵ��� �޾ұ� ������ ����� ������ �� ����.
	//pf->values[0] = 1.1;
	//pf->values[1] = 2.1;
	//pf->values[2] = 3.1;

	//pf->average = 0.0;
	//for (unsigned i = 0; i < pf->count; ++i)
	//	pf->average += pf->values[i];
	//pf->average /= (double)pf->count;

	//printf("Average = %f\n", pf->average);

	//// flexible �迭�� ������� �ʰ�, ������ ���Ҹ� double*�� �޾�, malloc�� �̿��ؼ� �������شٸ�?
	//struct nonflex
	//{
	//	size_t count;
	//	double average;
	//	double* values; // use malloc()
	//}; // 20 ~ 24byte(padding..), double*�� ������ ��ü�� �޸𸮸� ���� �ִ�.

	//struct nonflex nf;
	//nf.values = (double*)malloc(sizeof(double) * n); // �����Ҵ� �迭�� (��)�޸� ��� ��ġ���� �� ���� ����. (Flexible array�� ����ü �ڿ� �ٷ� �´�.)

	//struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	//if (pf2 == NULL) exit(1);

	////*pf2 = *pf; // Don't copy flexible members, use memcpy() instead
	//// �����Ҵ��� ���� �� 40�̾�����, ����ü�� ũ��� 16�̾���. �����Ϸ� ���忡��, ������ �õ����� �� 16����Ʈ�� ���縦 ���ش�.

	// 14.12 �͸� ����ü
	//struct names
	//{
	//	char first[20];
	//	char last[20];
	//};
	//struct person
	//{
	//	int id;
	//	struct names name; // nested structure member (Dot operator �� �� ���..)
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
	//puts(ted2.first); // Dot operator�� �� ���� �ϰ� �ٷ� first�� ������ �� �ִ�.

	// 14.13 ����ü�� �迭�� ����ϴ� �Լ�
	//struct book my_books[3]; // = {{"The Great Gatsby", "F. Scott Fitzgerald"}, ...};
	//my_books[0] = (struct book){ "The Greate Gatsby", "F. Scott Fitzerald" };
	//my_books[1] = (struct book){ "Hamlet", "Willian Shakespeare" };
	//my_books[2] = (struct book){ "The Odyssey", "Homer" };
	//
	//print_books(my_books, 3);
	//
	//// �����Ҵ����� �ٲ㺸��?
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

	// // 14.14 ����ü ���� ����� ��������
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
	// temp = _getch(); // �ƹ� Ű�� �Է� �ޱ� ����

	// my_books = read_books("books.txt", &n);
	// //read_books2("books.txt", &my_books, &n);
	// print_books(my_books, n);
	// free(my_books);
	// n = 0;

	// 14.15 ����ü(Union)�� ����
	// Union vs Structure

	// ����ü�� ����ϴ�.
	// ����ü�� int, double, char ������ �޸𸮸� �����ϰ�, �߰��� �е��� �� �� �ִ�.
	// �׷��� ����ü�� int, double, char�� �޸𸮸� ���� ����Ѵ�.
	// �� Ÿ���� �ٸ� �����͵��� ���� �޸� ������ ����Ѵ�.
	// union my_union
	// {
	// 	int i;
	// 	double d;
	// 	char c;
	// };

	// union my_union uni;						 // ���Ͽ� ���� ����
	// printf("%zd\n", sizeof(union my_union)); // 8, ����ü���ٸ� int(4) + double(8) + char(1) = 13
	// printf("%lld\n", (long)&uni);
	// printf("%ld %ld %ld\n", (long)&uni.i, (long)&uni.d, (long)&uni.c);
	// // vs �����Ϸ������� �ּҰ� ��� �����ϴ�. �޸𸮸� �����ϱ� ������..

	// union my_union save[10];
	// printf("%zd\n", sizeof(save)); // 80

	// // debug
	// union my_union uni1; // 8����Ʈ, ������ ������ CC CC CC CC
	// uni1.c = 'A';		 // 1����Ʈ�� ��� 41 CC CC CC
	// printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// // uni1.c = 'A'���� 41(10�������� 65)�� �ٲ��.
	// // ��, 0xCCCCCC41 = -858993599�� �ȴ�. (vscompiler)

	// uni1.i = 0;	  // 00 00 00 00 ������ 1����Ʈ�� ����ϴ� ���� ����� 4����Ʈ ���
	// uni1.c = 'A'; // 41 00 00 00
	// // 0x00000041
	// printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i); // uni1.i�� ������ ����ص� 65�� ����� ���´�.(00 00 00 00���� �� �� �ʱ�ȭ �߱� ����)

	// uni1.d = 1.2; // 33 33 33 33 33 33 f3 3f
	// // 0xf33f333333333333
	// printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// // uni1.i: 4����Ʈ, 0x 33 33 33 33 = 858993459
	// // uni1.d: 8����Ʈ, 1.200...
	// // uni1.c: 1����Ʈ, 33(10������ 51), '3'

	// union my_union uni2 = uni1; // copy another union
	// union my_union uni3 = {10}; // ������(�޸� ��) �� ���� ���ҷθ� �ʱ�ȭ�Ѵ�.
	// union my_union uni4 = {.c = 'A'}; // designated initializer
	// union my_union unio5 = {.d = 1.23, .i = 100}; // DO NOT RECOMMEND

	// uni.i = 123;
	// uni.d = 1.2;
	// uni.c = 'K';

	// printf("%d %f %c\n", uni.i, uni.d, uni.c);

	// union my_union* pu = &uni; // pointer to union
	// int x = pu->i;

	// // char�� �־���� ����� ���� double�� ����ϸ�...
	// uni.c = 'A';
	// double real = 3.14 * uni.d; // Do Not Recommend

	// 14.16 ����ü�� ����ü�� �Բ� ����ϱ�
	// struct car_data my_car = {.model = "Avante", .status = 0, .ownerinfo.po = {"830422", "1185600"}};
	// struct car_data company_car = {.model = "Sonata", .status = 1, .ownerinfo.co = {"111", "22", "33333"}};
	// print_car(my_car);
	// print_car(company_car);

	// 14.17 �͸� ����ü
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

	// // �迭�� ���� for���� ���� ��ȸ�� �� �ִ�.
	// for (int d = 0; d < 2; ++d)
	// {
	// 	printf("%.2f \n", v.arr[d]);
	// }
	
	// 14.18 ������ Enumerated Types
	// // Motivation
	// // red: 0, oragne: 1, yellow: 2, green: 3, ...
	// // if (c == 2) printf("yellow");

	// // define�� �̿��Ͽ� Symbolic constant�� ���� �� ������, ������ Ÿ�ӿ� ������ ���� �� ����.

	// // �������� �������. Enumerated type
	// enum spectrum {red, orange, yellow, green, 	blue, violet};
	// // red: 0, orange: 1, yellow: 2, green: 3, blue: 4, violet: 5
	// // enumerator

	// enum spectrum color;
	// color = blue;
	
	// if (color == yellow)
	// {
	// 	printf("yellow");
	// 	// printf(yellow); // �׳� ������ ���̴�.
	// }	
	// // �����̱� ������ for������ ��ȸ�� �����ϴ�.
	// for (color = red; color <= violet; color++) // C++������ �������� ���ؼ� ++�� ����� �� ����.
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
	
	// 14.19 ������ ��������
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

	// 14.20 ���� �����̽� (�̸�����)
	// {
	// 	int my_name = 345;
	// 	// double my_name; = 3.14; // ���� ���������� �̸��� ������ �ȵȴ�.
	// }
	// struct rect // tag�� rect��.
	// {
	// 	double x;
	// 	double y;
	// };
	// // struct rect rect = {1.1, 2.2}; // ����ü ���� �̸��� rect�� �� �� �ִ�. (ī�װ��� �ٸ���.)
	// int rect = 123; // C++������ ������ �ʴ´�.

	// // Not Ok
	// // typedef struct rect rect;
	// // rect rect = {1.1, 1.2};
	
	// // int iamfunction = iamfunction(); // �浹
	
	// // Namespace pollution(����)
	// // ������ ���� �̸��� �̹� �ٸ� ������ ����ϰ� �ִ� ��찡 �� ����.
	// // ������ ���� �����̽��� �۰� ����ؾ� �׷� ��Ȳ�� ��������.
	// // �ٸ� ���Ͽ��� �̸��� ��ġ�� Linking �������� ������ ����.
	// // ���������� ���� ����ϰų� static Ű���带 ��� �ϴ� ��...

	// 14.21 �Լ� �������� ����
	// void (*pf1)() = f1; // f1 �Լ��� ����� �ִ� �ּڰ��� pf1�� �����Ѵ�.
	// // void (*pf1)() = &f1; // & �ٿ��� �ǰ� �� �ٿ��� �ȴ�. �Լ� �̸� ��ü�� �ּ�(������)�̱� ������ &�� �� �ٿ��� �ȴ�.

	// int (*pf2)(char) = f2;

	// (*pf1)(); // call f1 via pf1
	// //pf1(); // �̷��� ȣ���ص� �ȴ�.

	// int a = pf2('A');
	// // int a = (*pf2)('A');
	
	// // Text Segment(���α׷� �ڵ�, Read only)
	// // ���α׷� �ۼ� -> ������ -> �������� ����(�ϵ��ũ�� ����)
	// // �������� ���� -> �ü���� ���α׷� ��ü�� �޸𸮿� �ø���. -> ���α׷� �ڵ� ��ü�� ����Ǵ°��� Text Segment

	// // �Լ� ������ ��ü�� �ּڰ��� �����ϴ� ���� - stack �޸𸮿� ����ȴ�.
	// // ���ڿ� ���ͷ�, �Լ� �̸�, �����Լ������� text segment�� ����ȴ�. 
	
	// 14.22 �Լ������� �����
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

	// // Node: _cdecl is function calling convention(�Լ� ȣ�� �Ծ�)

	// 14.23 �ڷ����� ������ �ٿ��ִ� typedef
	// // Give Symbolic names(or aliases) to types
	// // Does not create new types
	// typedef unsigned char BYTE; // typedef [������ �ٿ��� Ÿ��] [����]
	// BYTE x, y[10] = {0, }, *z = &x; // ����, �迭, ������ �� �ȴ�.
	// {
	// 	// typedef�� �������� ���´�.

	// 	typedef unsigned char byte;

	// 	// �̽ļ��� ����.
	// 	size_t s = sizeof(byte); // x86: sizeof() -> unsigned int, x64: sizeof() -> unsigned long long
	// 	// unsigned int s = sizeof(byte); // x86
	// 	// unsigned long long s = sizeof(byte); // x64
	// 	// x86, x64 �� ��츶�� size_t�� ���� �����صּ� ���ϴ�.

	// }
	// // byte b; // ������ ���̶� ��� �Ұ�

	// time_t t = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �� �ʰ� �������� �˷��ִ� �Լ�

	// printf("%lld\n", t);

	// // typedef vs #define
	// // �⺻�����δ� typedef�� �����Ѵ�.

	// typedef char* STRING;
	// STRING name = "John Wick", sign = "World";

	// // #define�� ��ó����, �� �������ϱ� ���� ó���� �ȴ�. �ܼ��� ����-�ٿ��ֱ��̴�.
	// // typedef�� �����Ϸ��� ó���� ���ش�.

	// // #define STRING char*
	// // ��ó���Ⱑ STRING�� ��� char*�� �ٲ������.

	// // ���� �Ʒ��� �ٲ۴�.
	// // STRING name, sign;
	// // char* name, sign; // sign�� �����Ͱ� �ƴϰ� �ȴ�. char* name, *sign;���� �Ǿ��ϴµ�...

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

	// 14.24 ������ ������ �ؼ��ϴ� ���
	//// ���������� ���� - *, (), [] (�Լ��� �Ű������� ���� ����, �迭�� index�� ���� ����)
	//// 1. ���ʿ������� �ٱ������� �о��.
	//// 2. *���� (), []�� �켱������ ����.

	//// �ĺ���(�̸�)�� ���� ã�´�. (ap)
	//// �켱������ ���� []�� Ȯ���Ѵ�. �� ap�� �迭�̴�.
	//// int*�� ���������� �ؼ��Ѵ�. �� ap�� int* 10�� �迭�̴�.
	//int* ap[10]; 

	//// typedef�� �̿��ؼ� �����ϸ� ��������.
	//typedef int* pint;
	//pint ap1[10]; // pint�� 10��¥�� �迭

	//// 1. �̸� ã�� - fp
	//// 2. �켱������ ���� ()�� �ν� - fp�� �Լ���. �Ű������� float�� ����.
	//// 3. float*�� �����ϴ� �Լ���� ���� �� �� �ִ�.
	//float* fp(float);

	//// typedef�� �̿��ؼ� �����ϸ�
	//typedef float* pfloat;
	//pfloat fp(float); // pfloat Ÿ���� ��ȯ�ϴ� �Լ�

	//// 1. �ϴ� �����ʹ�. *pf
	//// 2. (int)�� ���� �Լ���. �� �Լ� �����ʹ�.
	//// 3. void�� ����, �ƹ��͵� �������� �ʴ� �Լ� �����ʹ�.
	//void (*pf)(int);

	//// 1. x�� �迭�̴�. []�� *���� �켱������ ����.
	//// 2. x�� �����Ϳ� ���� �迭�̴�. *
	//// 3. �� �����ʹ� �Լ��� ���� �����ʹ�. (void)
	//// 4. �� �Լ��� int*(���� ������)�� �����ϴ� �Լ��̴�.
	//int* (*x[10])(void);

	//// �ȵǴ� �͵��� �ִ�.
	//// 1. �Լ��� �迭�� ��ȯ�� �� ����.
	//// int f(int)[];
	//int(*f(int))[]; // �迭�� ���� �����͸� ��ȯ�� ���� �ִ�.

	//// 2. �Լ��� ��ȯ�� ���� ����.
	//// int g(int)(int);
	//int(*g(int))(int); // �Լ��� ���� �����͸� ��ȯ�� ���� �ִ�.

	//// 3. �Լ��� �迭�� �Ұ����ϴ�.
	//// int(x2[10])(int); 
	//int(*x2[10])(int); // �Լ� �������� �迭�� �����ϴ�.

	//typedef int FCN(int); // �Լ�Ÿ��
	//typedef FCN* FCN_PTR; // �Լ��� ������
	//typedef FCN_PTR FCN_PTR_ARRAY[10]; // �Լ� �������� �迭
	//FCN_PTR_ARRAY x3;

	//// More Example
	//int board[6][4]; // board[6]�� �迭
	//int** ptr; // *ptr�� ������

	//int* risks[10]; // ���� ������ 10���� �迭
	//int(*rusk)[10]; // ���� �迭�� ������

	//int* off[3][4]; // ���� �������� ���߹迭
	//int(*uff)[3][4]; // ������ ���߹迭�� ������
	//int(*uof[3])[4]; // (int[4] �迭�� ������)�� �迭

	//char* fump(int); // char*�� �����ϴ� �Լ�
	//char (*frump)(int); // char�� �����ϴ� �Լ��� ������
	//char (*flump[3])(int); // �Լ� �������� �迭

	//typedef int arr5[5]; // int[5]�� arr5��
	//typedef arr5* p_arr5; // arr5�� �����͸� p_arr5��
	//typedef p_arr5 arrp10[10]; // p_arr5�� 10�� �迭�� arrp10����
	
	// 14.25 qsort
	//int arr[] = { 8, 2, 5, 3, 6, 11 };
	//int n = sizeof(arr) / sizeof(arr[0]);

	//qsort(arr, n, sizeof(int), compare); // <stdlib.h>, compare �Լ��� ����������Ѵ�.

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

	// 14.26 �Լ� �������� �迭
	char options[] = { 'u', 'l', 't' };
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*); // char*�� ���ڷ� �ް� �������� �ʴ� �Լ��� ������
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