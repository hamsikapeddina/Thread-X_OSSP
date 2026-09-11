#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    char command[50];

    printf("Enter command: ");
    scanf("%s", command);

    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child PID = %d\n", getpid());
        execlp(command, command, NULL);
        exit(1);
    }
    else
    {
        printf("Parent PID = %d\n", getpid());
        wait(NULL);
        printf("Child process completed\n");
    }

    return 0;
}
