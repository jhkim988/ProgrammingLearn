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
	union my_union
	{
		int i;
		double d;
		char c;
	};

	union my_union uni;						 // ���Ͽ� ���� ����
	printf("%zd\n", sizeof(union my_union)); // 8, ����ü���ٸ� int(4) + double(8) + char(1) = 13
	printf("%lld\n", (long)&uni);
	printf("%ld %ld %ld\n", (long)&uni.i, (long)&uni.d, (long)&uni.c);
	// vs �����Ϸ������� �ּҰ� ��� �����ϴ�. �޸𸮸� �����ϱ� ������..

	union my_union save[10];
	printf("%zd\n", sizeof(save)); // 80

	// debug
	union my_union uni1; // 8����Ʈ, ������ ������ CC CC CC CC
	uni1.c = 'A';		 // 1����Ʈ�� ��� 41 CC CC CC
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// uni1.c = 'A'���� 41(10�������� 65)�� �ٲ��.
	// ��, 0xCCCCCC41 = -858993599�� �ȴ�. (vscompiler)

	uni1.i = 0;	  // 00 00 00 00 ������ 1����Ʈ�� ����ϴ� ���� ����� 4����Ʈ ���
	uni1.c = 'A'; // 41 00 00 00
	// 0x00000041
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i); // uni1.i�� ������ ����ص� 65�� ����� ���´�.(00 00 00 00���� �� �� �ʱ�ȭ �߱� ����)

	uni1.d = 1.2; // 33 33 33 33 33 33 f3 3f
	// 0xf33f333333333333
	printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// uni1.i: 4����Ʈ, 0x 33 33 33 33 = 858993459
	// uni1.d: 8����Ʈ, 1.200...
	// uni1.c: 1����Ʈ, 33(10������ 51), '3'

	union my_union uni2 = uni1; // copy another union
	union my_union uni3 = {10}; // ������(�޸� ��) �� ���� ���ҷθ� �ʱ�ȭ�Ѵ�.
	union my_union uni4 = {.c = 'A'}; // designated initializer
	union my_union unio5 = {.d = 1.23, .i = 100}; // DO NOT RECOMMEND

	uni.i = 123;
	uni.d = 1.2;
	uni.c = 'K';

	printf("%d %f %c\n", uni.i, uni.d, uni.c);

	union my_union* pu = &uni; // pointer to union
	int x = pu->i;

	// char�� �־���� ����� ���� double�� ����ϸ�...
	uni.c = 'A';
	double real = 3.14 * uni.d; // Do Not Recommend

	return 0;
}