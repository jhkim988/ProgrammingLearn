#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define SIZE 5
int nums[SIZE] = {0, 1, 2, 3, 4};

int main()
{
    pid_t pid;
    int i;
    pid = fork();

    if (pid == 0) { // child process
        for (int i = 0; i < SIZE; i++) {
            nums[i] *= i;
            printf("CHILD: %d\n", nums[i]); // LINE X
        }
    }
    else if (pid > 0) { // parent process
        wait(NULL); // wait()를 하지 않으면 순서에 대한 보장을 할 수 없다. -> synchronization 필요, 동시성 제어에서 많은 문제가 발생한다
        for(int i = 0; i < SIZE; i++) {
            printf("PARENT: %d\n", nums[i]); // LINE Y
        }
    }

    return 0;
}