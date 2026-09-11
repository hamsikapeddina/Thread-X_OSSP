#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent Process\n");
    printf("PID  = %d\n", getpid());
    printf("PPID = %d\n", getppid());

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    if(pid == 0)
    {
        printf("\nChild Process - Running\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        sleep(10);

        printf("\nChild Process - Terminating\n");
        exit(0);
    }
    else
    {
        printf("\nParent Process - Running\n");
        printf("PID  = %d\n", getpid());
        printf("PPID = %d\n", getppid());

        sleep(5);

        printf("\nParent Process - Waiting\n");
        wait(NULL);

        printf("Parent Process - Child Terminated\n");
    }

    return  0;
}
