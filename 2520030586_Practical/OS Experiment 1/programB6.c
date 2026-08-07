#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child Process id is: %d\n", getpid());
    } else {
        printf("Parent Process id is: %d\n", getpid());
    }

    return 0;
}
