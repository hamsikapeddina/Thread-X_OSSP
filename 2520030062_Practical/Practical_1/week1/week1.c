#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child PID = %d\n", getpid());
    }
    else
    {
        printf("Parent PID = %d\n", getpid());
        wait(NULL);
    }

    return 0;
}  

