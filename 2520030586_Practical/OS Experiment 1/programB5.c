#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Current Process id is: %d\n", getpid());
    printf("Parent Process id is: %d\n", getppid());

    return 0;
}
