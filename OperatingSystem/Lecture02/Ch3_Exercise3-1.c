#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 5;

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0) { // child process
        value += 15;
        // printf("Child value = %d\n", value);
        return 0;
    }

    else if (pid > 0) { // parent process
        wait(NULL);
        printf("Parent value = %d\n", value); // what output will be?
    }
}

// Answer: 5 (Not 20)
// 전역변수 주의
// fork()하는 시점에서 프로세스를 복사한다.(이 때 value = 5 이다.)