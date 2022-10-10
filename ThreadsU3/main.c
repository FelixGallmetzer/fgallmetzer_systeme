#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

int ergebnis = 0;
int x = 0;

void *funcThread(void *arg) {
  ergebnis = x * 2;
}

int main() {
  x=2;
  pthread_t thread2;

  pthread_create(&thread2, NULL, funcThread, NULL);
  pthread_join(thread2, NULL);

  printf("x = %i\n", x);
  printf("ergebnis = %i\n", ergebnis);
  return 0;
}