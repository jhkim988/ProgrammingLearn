#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define true 1
#define NUM_PHILS 5

enum {THINKING, HUNGRAY, EATING} state[NUM_PHILS];

pthread_mutex_t mutex_lock;
pthread_cond_t cond_vars[NUM_PHILS];

int main() {
  int i;
  pthread_t tid;
  init();
  for (i = 0; i < NUM_PHILS; i++) {
    pthread_create(&tid, NULL, philosopher, (void*) &i);
  }
  for (i = 0; i < NUM_PHILS; i++) {
    pthread_join(tid, NULL);
  }
  return 0;
}

void init() {
  int i;
  for (i = 0; i < NUM_PHILS; i++) {
    state[i] = THINKING;
    pthread_cond_init(&)
  }
}