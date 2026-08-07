#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    fork();

    printf("Parent Process id is: %d\n", getpid());

    return 0;
}
