#include <stdio.h>

#define SIZE 10000000

int a[SIZE], b[SIZE], c[SIZE];

int main(int argc, char* argv) {
    int i;
    for(i = 0; i < SIZE; i++) {
        a[i] = b[i] = i;
    }
    for (int i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }

    return 0;
}