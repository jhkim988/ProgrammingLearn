#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <wait.h>

void* runner(void* param);

int main() {
    pid_t pid;
    pthread_t tid;

    printf("A = %d\n", getpid());
    pid = fork();
    if (pid == 0) {
        // child process
        pid = fork();
        if (pid > 0) {
            // parent process
            wait(NULL);
            printf("C = %d\n", pid);
        }
        pthread_create(&tid, NULL, runner, NULL);

    } else if (pid > 0) {
        // parent process
        wait(NULL);
        printf("B = %d\n", pid);
    }
    pid = fork();
    if (pid > 0) {
        wait(NULL);
        printf("D = %d\n", pid);
    }
}

void* runner(void* param) {
    printf("Hello, I'm a thread!\n");
}

// a. How many unique processes are created? 6
// b. How many unique threads are created? 2(8) thread_create()로 생기는 것은 2개