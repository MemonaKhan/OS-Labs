#include<signal.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h> 

void my_function()
{
    printf("ALRM Signal Recieved! \n");
    printf("Output from My Function \n");
}
void main()
{
    signal(SIGALRM,my_function);
    alarm(2);
    pause();
    printf("Signal Recieved\n");
    printf("Output from Main Function\n");
}
