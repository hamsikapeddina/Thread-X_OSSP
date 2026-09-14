#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t child1, child2;
    int status;

    printf("Parent PID: %d\n", getpid());

    // Create first child
    child1 = fork();

    if (child1 < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (child1 == 0)
    {
        printf("Child 1: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(2);
        printf("Child 1 completed.\n");
        exit(10);
    }

    // Create second child
    child2 = fork();

    if (child2 < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (child2 == 0)
    {
        printf("Child 2: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(3);
        printf("Child 2 completed.\n");
        exit(20);
    }

    // Parent waits for Child 1 using wait()
    printf("\nParent waiting using wait()...\n");

    wait(&status);

    if (WIFEXITED(status))
        printf("A child terminated with exit status: %d\n",
               WEXITSTATUS(status));

    // Parent waits specifically for Child 2 using waitpid()
    printf("Parent waiting for Child 2 using waitpid()...\n");

    waitpid(child2, &status, 0);

    if (WIFEXITED(status))
        printf("Child 2 terminated with exit status: %d\n",
               WEXITSTATUS(status));

    printf("All child processes completed.\n");

    return 0;
}
