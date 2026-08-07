#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
pid_t pid;
pid=fork();
if(pid==0){
printf("Child Process\n");
}
else{
printf("Parent Process\n");
}
return 0;
}
