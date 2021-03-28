#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
    int ret;
    printf("Demonstration of Fork/Exec\n\n");
    ret = fork();
    if(ret>0){
        printf("This is Parent process it will Wait \n");
        wait(NULL);
    }
    else if (ret == 0){
        printf("Child Process ID: %d \nFork Returned: %d \n", getpid(),ret);
        execl("/bin/date","date",(char*)0);
    }
}