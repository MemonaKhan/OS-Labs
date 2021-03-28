#include<stdio.h>
void main()
{
int i,m,n,tot,s[20];
printf("Enter Total Memory Size: ");
scanf("%d",&tot);
printf("Enter number of Pages: ");
scanf("%d",&n);
printf("Enter Memory for OS: ");
scanf("%d",&m);
for(i=0;i<n;i++)
{
printf("Enter size of page %d: ",i+1);
scanf("%d",&s[i]);
}
tot=tot-m;
for(i=0;i<n;i++)
{
if(tot>=s[i])
{
printf("Allocate page %d\n",i+1);
tot=tot-s[i];
}
else
printf("Process p%d is blocked\n",i+1);
}
printf("External Fragmentation is = %d\n",tot);
}