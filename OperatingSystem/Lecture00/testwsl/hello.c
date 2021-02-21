#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  pid = fork(); // unix system call
  printf("Hello, WSL!\n"); // fork()를 했기 때문에 두 번 출력된다.
  return 0;
}