#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>

int value = 0;
void* runner(void* param);

int main(int argc, char* argv) {
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;

    pid = fork();

    if (pid == 0) {
        // child process
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("Child: value = %d\n", value);
    } else if (pid > 0) {
        // parent process
        wait(NULL);
        printf("Parent: value = %d\n", value);
    }
    return 0;
}

void* runner(void* param) {
    value = 5;
    pthread_exit(0);
}