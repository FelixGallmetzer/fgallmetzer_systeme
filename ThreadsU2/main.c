#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *zaehlThread(void *arg) {
    for (int i = 10; i >= 0; i--) {
        printf("%i\n", i);
        sleep(1);
    }
    fflush(stdout);  
}

int main() {
    pthread_t mythread;
    pthread_create(&mythread, NULL, &zaehlThread, NULL);
    sleep(11);
    pthread_exit(NULL);
    return 0;
}