#include <stdio.h>
#include <unistd.h>

// How many processes are created?
// answer) 2^4 = 16

int main()
{
    int i;
    for(int i = 0; i < 4; i++) {
        pid_t pid = fork();
        // printf("Hello fork()! %d\n", pid); // testing
    }

    // printf("Hello fork()!\n"); // testing
    return 0;
}