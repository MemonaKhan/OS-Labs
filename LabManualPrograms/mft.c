#include<stdio.h>
void main()
{
int ms,i,ps[20],n,size,p[20],s,intr=0;
printf("Enter size of Memory: ");
scanf("%d",&ms);
printf("Enter Memory for OS: ");
scanf("%d",&s);
ms-=s;
printf("Enter no. of partitions to be divided: ");
scanf("%d",&n);
size=ms/n;
for(i=0;i<n;i++)
{
printf("Enter Process and Process size: ");
scanf("%d%d",&p[i],&ps[i]);
if(ps[i]<=size)
{
intr=intr+size-ps[i];
printf("Process %d is Allocated\n",p[i]);
}
else
printf("Process %d is Blocked",p[i]);
}
printf("total fragmentation is %d\n",intr);
}