#include <stdio.h>
#include <omp.h>

#define SIZE 10000000

int a[SIZE], b[SIZE], c[SIZE];

int main(int argc, char* argv) {
    int i;
    for(i = 0; i < SIZE; i++) {
        a[i] = b[i] = i;
    }

    // 자동으로 for 문을 병렬처리 한다.
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }

    return 0;
}