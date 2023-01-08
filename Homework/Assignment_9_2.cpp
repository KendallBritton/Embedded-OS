#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    if (fork() == 0){

        printf("a");
        exit(0);

    } else {

        printf("b");
        waitpid(-1, NULL, 0);

    }

    printf("c");
    printf("\n");
    exit(0);

}