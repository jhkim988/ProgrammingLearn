#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
    pid_t pid; // pid: process id, fork()를 호출하면 리턴해준다.

    // fork a child process
    pid = fork(); // 새로운 pid를 받는다.

    if (pid < 0) { // error occurred
        fprintf(stderr, "Fork Failed\n");
    } else if (pid == 0) { // child process
        execlp("/bin/ls", "ls", NULL); // ls라는 명령어를 실행한다.
        printf("Line J\n"); // 실행되지 않는다. 메모리 레이아웃에서 ls로 완전히 교체됐기 때문
    } else { // parent process
        wait(NULL); // wait null을 호출한다.
        printf("Child Complete\n");
    }

    return 0;
}

// 실행 결과
// a.out main.c
// Child Complete

// P0 - main.c 호출, wait(NULL)을 했기 때문에 P1이 끝날 때까지 기다린다.
// P1 - fork()로 생성됨(P0와 P1은 같다.)
// execlp()로 ls를 실행하도록 바꿨다.
// ls를 실행하고, P1이 끝나고 나면 P0가 실행돼서 Child Complete가 출력된다.

// fork()로 프로세스 생성
// 마지막 문장이 끝나면 프로세스가 종료된다.(return)
// 중간에 강제로 끝내기 위해서는 exit()를 호출한다.(exit()도 시스템 콜이다.)
