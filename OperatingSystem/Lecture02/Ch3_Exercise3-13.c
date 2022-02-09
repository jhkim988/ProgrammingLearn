#include <stdio.h>
#include <unistd.h>
#include <wait.h>

// What are the pid values?
// answer
// A: 0
// B: child process id
// C: child process id
// D: parent process id
int main()
{
    pid_t pid, pid1;

    pid = fork();
    if (pid == 0) { // child process
        pid1 = getpid(); // 자신의 process id
        printf("A. child: pid = %d\n", pid); // A
        printf("B. child: pid1 = %d\n", pid1); // B
    }
    else if (pid > 0) { // parent process
        pid1 = getpid();
        wait(NULL);
        printf("C. parent: pid = %d\n", pid);  // C
        printf("D. parent: pid1 = %d\n", pid1); // D
        // wait(NULL);
    }
}