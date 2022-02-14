#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int sum = 0;

void* counter(void* param) {
  int k;
  for (int k = 0; k < 10000; k++) {
    sem_wait(&sem);
    sum++;
    sem_post(&sem);
  }
  pthread_exit(0);
}

int main() {
  pthread_t tid[5]; int i;
  sem_init(&sem, 0, 5); // S = 5
  for (i = 0; i < 5; i++) {
    pthread_create(&tid[i], NULL, counter, NULL);
  }
  // Race Condition:
  // sum이라는 변수에 5개의 스레드가 접근하기 때문에 경쟁조건이발생한다.
  for (i = 0; i < 5; i++) {
    pthread_join(tid[i], NULL);
  }
  printf("sum = %d\n", sum);
}