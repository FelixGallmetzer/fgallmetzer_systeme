#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *funcThread(void *arg) {
    printf("Thread1 %d\n", pthread_self());
    fflush(stdout);
    sleep(5);
    pthread_exit(NULL);
}

void *funcThread2(void *arg) {
    printf("Thread2 %d\n", pthread_self());
    fflush(stdout);
    sleep(5);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, &funcThread, NULL);
    pthread_create(&thread2, NULL, &funcThread2, NULL);
    sleep(1);
    return pthread_equal(thread1, thread2);
}