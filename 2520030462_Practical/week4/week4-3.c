#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();

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

        sleep(20);

        printf("Parent completed\n");
    }

    return 0;
}
