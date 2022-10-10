#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main (void) {
    int rechnung = 0;
    int arg[2];
    pipe(arg);
    if (pipe(arg) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    rechnung = fork();

    switch(rechnung) {
        case -1:
            printf("Fehler\n");
            break;

        case 0:
            int res1 = 3+1;
            close(arg[0]);
            dup2(arg[1],1); //stdout
            if (dup2(arg[1],1) < 0) {
                perror("dup");
                break;
            }
            close(arg[1]);
            printf("%i", res1);
        break;

        default:
            int res2 = 6-4;
            int res3 = 0;
            close(arg[1]);
            dup2(arg[0],0); //stdin
              if (dup2(arg[0],0) < 0) {
                perror("dup");
                break;
            }
            close(arg[0]);
            int w = wait(NULL);
            if (w < 0) {
                perror("wait");
                break;
            }
            scanf("%i", &res3); 
            int res = res2 * res3;
            printf("%i\n", res);
        break;
    }
}