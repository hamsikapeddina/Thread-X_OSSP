#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent process started\n");
    printf("Parent PID: %d\n", getpid());
    printf("Parent PPID: %d\n", getppid());

    pid = fork();


    if (pid == 0)
    {
        
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());

        printf("Child is running...\n");
        sleep(5);

        printf("Child finished execution.\n");
        exit(0);
    }
    else
    {
        
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("Parent is waiting for child...\n");

        wait(NULL);

        printf("Child has terminated.\n");
        printf("Parent process completed.\n");
    }

    return 0;
}
