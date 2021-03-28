#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/uio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>

void main()
{
    int pid,pfd[2],n,a,b,c;
    if(pipe(pfd)==-1)
    {
        printf("\nError in Pipe Connection\n");
        exit(1);
    }
    pid=fork();
    if(pid>0)
    {
        printf("\nParent Process");
        printf("\nFibonacci Series");
        printf("\nEnter the Limit for the Series: ");
        scanf("%d",&n);
        close(pfd[0]);
        write(pfd[1],&n,sizeof(n));
        close(pfd[1]);
        exit(0);
    }
    else
    {
        close(pfd[1]);
        read(pfd[0],&n,sizeof(n));
        printf("\nChild Process");
        a=0;
        b=1;
        close(pfd[0]);
        printf("\nFibonacci Series is:");
        printf("\n%d\n%d\n",a,b);
        while(n>2)
        {
            c=a+b;
            printf("%d\n",c);
            a=b;
            b=c;
            n--;
        } 
    } 
}