#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        printf("Child process\n");
        printf("Child PID = %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Parent process\n");
        printf("Parent PID = %d\n", getpid());

        wait(NULL);

        printf("Child collected\n");
    }

    return 0;
}
