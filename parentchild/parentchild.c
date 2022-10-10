#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main (void) {
    int pc = 0;
    pc = fork();

    switch(pc) {
        case -1:
            printf("Fehler\n");
            break;
        case 0:
            printf("Kindprozess PID: %i PPID: %i\n",getpid(),getppid());
            exit(0);
            break;
        default:
            printf("Elternprozess PID: %i PPID: %i PID vom Kind: %i\n",getpid(),getppid(), pc);
            break;
    }
}