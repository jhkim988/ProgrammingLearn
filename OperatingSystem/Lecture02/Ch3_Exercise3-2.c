#import <stdio.h>
#import <unistd.h>
#import <wait.h>

// How many processes are created?
// answer) 8

// P0 -> fork1 -> fork2 -> fork3
// P1 -> fork2 -> fork3
// P2 -> fork3
// P3 -> fork3
// P4
// P5
// P6
// P7
int main()
{
    fork();
    fork();
    fork();

    return 0;
}