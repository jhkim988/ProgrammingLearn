static unsigned int next = 1; // static�� �ٿ��� ���� �ܺο����� my_srand()�� ���ؼ��� ���� �����ϰ� �����.

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