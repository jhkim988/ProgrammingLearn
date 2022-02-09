#include <stdio.h>
#include <unistd.h>
#include <wait.h>

typedef struct {
    // ...
} item;

int main()
{
    // send:
    item next_produced;
    while (true) {
        // produce an item in next_produeced
        next_produced = (item*) malloc(sizeof item);
        send(next_produced);
    }

    // receive:
    item next_consumed;
    while (true) {
        // consume an item in next_consumed
        next_consumed = (item*) malloc(sizeof item);
        receive(next_consumed);
    }
}