#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
printf("Before fork()\n");
fork();
printf("After fork()\n");
return 0;
}
