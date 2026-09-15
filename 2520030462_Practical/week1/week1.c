#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char command[100];
    pid_t pid;

    printf("Enter a Linux command: ");
    scanf("%99s", command);

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0)
    {
        
        printf("Child Process PID: %d\n", getpid());
        printf("Executing command: %s\n", command);

        execlp(command, command, (char *)NULL);

       
        printf("Exec failed\n");
        exit(1);
    }
    else
    {
       
        printf("Parent Process PID: %d\n", getpid());
        printf("Waiting for child process...\n");

        wait(NULL);

        printf("Child process completed.\n");
    }

    return 0;
}
