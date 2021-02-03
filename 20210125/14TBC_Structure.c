#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41
#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3
#define LEN 20

// 14.2
struct person // Person is a tage of structure
{
	// members
	// ����ü "����"�� ���� �� �� �޸𸮰� �Ҵ�ȴ�.
	// ����ü ����� ���� ���� �޸� �Ҵ��� ���� �ʴ´�.
	char name[MAX];
	int age;
	float height;
};

// 14.4
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

	// �����Ҵ����� �Ѵٸ�?
	struct my_data
	{
		int a;
		char c;
		float* arr;
	};

	struct my_data d1 = { 1234, 'A', NULL };
	d1.arr = (float*)malloc(sizeof(float) * 2);
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	struct my_data d2 = d1; // ���������� �ּҰ��� �����Ѵ�. d1.arr�� d2.arr�� �ּҰ� ���� ������, ���� �޸𸮸� �����ϰ� �ִ�.

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);


	// 14.7 ����ü�� �Լ��� �����ϴ� ���


	return 0;
}