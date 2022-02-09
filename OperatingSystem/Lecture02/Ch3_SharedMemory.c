#include <stdio.h>
#include <unistd.h>
#include <wait.h>

// Define a shared buffer
#define BUFFER_SIZE 10

typedef struct {

} item;

// buffer -> circular queue
item buffer[BUFFER_SIZE];
int in = 0; // cursor
int out = 0; // cursor

// 전역 공간에 넣으면 제대로 작동하지 않지만, 설명을 위해 적어뒀다.

int main()
{
    // producer:
    item next_produced;

    while (true) {
        // produce an item in next_produced
        next_produced = (item*)malloc(sizeof item);

        while (((in + 1) % BUFFER_SIZE) == out) {
            // do nothing, full buffer
        }

        buffer[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
    }

    // consumer:
    item = next_consumed;

    while (true) {
        while (in == out) {
            // do nothing, empty buffer
        }

        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        // consume the item in next_consumed
    }
}