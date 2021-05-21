// source code
// compile -> a.out(program) -> load on memory(process) -> execution

// gcc main.c
// size ./a.out
// text     data    bss     dec     hex     filename
// 1603     604     12      2219    8ab     ./a.out

#include <stdio.h>
#include <stdlib.h>

int x; // uninitialized data section
int y = 15; // initialized data section

int main(int argc, char* argv[]) {
    // argc: argument count
    // argv: argument vector
    
    // argc, argv: stack section
    // main function: stack section

    // local variable: stack section
    int* values;
    int i;

    // memory allocation: heap section
    values = (int*) malloc(sizeof(int)*5);

    // code: text section
    for (int i = 0; i < 5; i++) {
        values[i] = i;
    }

    return 0;
}