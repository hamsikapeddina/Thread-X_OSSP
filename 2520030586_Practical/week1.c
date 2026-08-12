#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char command[100];
    pid_t pid;
    int status;

    // Accept command from user
    printf("Enter a Linux command: ");
    scanf("%s", command);

    // Create child process
    pid = fork();

    if (pid < 0)
    {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    else if (pid == 0)
    {
        // Child process
        printf("\n--- Child Process ---\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        printf("Executing command: %s\n\n", command);

        // Execute the command
        execlp(command, command, (char *)NULL);

        // Executes only if execlp fails
        perror("execlp failed");
        exit(1);
    }

    else
    {
        // Parent process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        // Wait for child process
        wait(&status);

        printf("\nChild process completed.\n");

        if (WIFEXITED(status))
        {
            printf("Child exit status: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
