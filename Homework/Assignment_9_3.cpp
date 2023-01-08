#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    if (fork() == 0){

        printf("a");
        fflush(stdout);
        exit(0);

    } else {

        printf("b");
        fflush(stdout);
        waitpid(-1, NULL, 0);

    }
    
    printf("c");
    fflush(stdout);
    printf("\n");
    exit(0);

}