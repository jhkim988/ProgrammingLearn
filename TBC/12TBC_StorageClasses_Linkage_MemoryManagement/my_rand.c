static unsigned int next = 1; // static을 붙여서 파일 외부에서는 my_srand()를 통해서만 수정 가능하게 만든다.

int my_rand()
{
	next = next * 1103515245 + 1234;
	next = (unsigned int)(next / 65536) % 32768;
	return next;
}

void my_srand(unsigned int seed)
{
	next = seed;
}