#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Current Process id %d\n", getpid());
    printf("Parent Process id %d\n", getppid());

    pid = fork();

    if (pid < 0) {
        printf("Process failed\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child Process\n");
        printf("Current Process id %d", getpid());
        printf("Parent Process id %d", getppid());

        execl("/bin/ls", "ls", "-l", NULL);

        printf("exec() sc failed");
        exit(1);
    }
    else {
        printf("Parent Process waiting for the child process to be executed\n");
        wait(NULL);

        printf("Parent Process Resumed\n");
        printf("Child Process Finished\n");
        exit(0);
    }

    return 0;
}
