#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        // Child: Consumer
        char buffer[100];

        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));

        printf("Child (Consumer) received: %s\n", buffer);

        close(pipefd[0]);
    }
    else
    {
        // Parent: Producer
        char message[] = "Hello from Parent Producer!";

        close(pipefd[0]);

        write(pipefd[1], message, strlen(message) + 1);

        printf("Parent (Producer) sent: %s\n", message);

        close(pipefd[1]);

        wait(NULL);

        printf("\n--- Executing ls -l | grep \".c\" ---\n");

        // Create pipe for ls | grep
        int fd[2];
        pipe(fd);

        pid_t p1 = fork();

        if (p1 == 0)
        {
            // First child: ls -l
            close(fd[0]);

            dup2(fd[1], STDOUT_FILENO);

            close(fd[1]);

            execlp("ls", "ls", "-l", NULL);

            perror("exec ls failed");
            exit(1);
        }

        pid_t p2 = fork();

        if (p2 == 0)
        {
            // Second child: grep ".c"
            close(fd[1]);

            dup2(fd[0], STDIN_FILENO);

            close(fd[0]);

            execlp("grep", "grep", ".c", NULL);

            perror("exec grep failed");
            exit(1);
        }

        close(fd[0]);
        close(fd[1]);

        waitpid(p1, NULL, 0);
        waitpid(p2, NULL, 0);

        printf("Pipeline execution completed.\n");
    }

    return 0;
}
