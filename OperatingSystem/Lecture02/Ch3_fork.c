#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // parent process에서는 생성한 child process의 pid를 리턴한다.
    // child proccess에서는 0을 리턴한다.
    pid = fork();
    printf("Hello, Process! %d\n", pid);
}

// main.c -> a.out
// parent 프로세스가 실행돼서 fork()를 통해 child process를 생성한다.
// parent 프로세스가 printf()를 만나 문장을 출력하고 끝난다.
// Ready Queue에 있던 child process가 실행된다.
// child process의 PCB에서 pc(program counter)는 fork()의 다음 문장을 가리키고 있다.
// 따라서 child process도 printf()로 문장을 출력하고 끝난다.