#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t child1, child2;
child1 = fork();
if (child1 == 0)
{
    printf("Child 1: PID = %d\n", getpid());
    sleep(2);
    printf("Child 1 completed\n");
    return 0;
}
child2 = fork();
if (child2 == 0)
{
    printf("Child 2: PID = %d\n", getpid());
    sleep(4);
    printf("Child 2 completed\n");
    return 0;
}
printf("Parent: PID = %d\n", getpid());

printf("Waiting for Child 1 using waitpid()\n");
waitpid(child1, NULL, 0);

printf("Child 1 finished\n");
printf("Waiting for Child 2 using wait()\n");
wait(NULL);

printf("Child 2 finished\n");
printf("Parent completed\n");

return 0;
}
