#include<stdio.h>
void main()
{
    int n,i,j,b[20],sb[20],t[20],x,c[20][20];
    printf("Enter number of Files: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter number of Blocks occupied by File %d: ",i+1);
        scanf("%d",&b[i]);
        printf("Enter the starting block of file %d: ",i+1);
        scanf("%d",&sb[i]);
        t[i]=sb[i];
        for(j=0;j<b[i];j++)
            c[i][j]=sb[i]++;
    }
    printf("File No\tStart block\tLength\n");
    for(i=0;i<n;i++)
        printf("%d\t %d \t\t%d\n",i+1,t[i],b[i]);
        printf("Enter File No: ");
        scanf("%d",&x);
        printf("File No is: %d\n",x);
        printf("Length is:%d\n",b[x-1]);
        printf("Blocks occupied:");
    for(i=0;i<b[x-1];i++)
        printf("%4d",c[x-1][i]);
    printf("\n");
}