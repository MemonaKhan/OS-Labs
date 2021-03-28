#include<stdio.h>
struct file
{
    // char fname[10];
    int fno,start,size,block[10];
}f[10];

void main()
{
    int i,j,n;
    printf("Enter number of Files: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter File No:");
        scanf("%d",&f[i].fno);
        printf("Enter Starting block:");
        scanf("%d",&f[i].start);
        f[i].block[0]=f[i].start;
        printf("Enter number of Blocks:");
        scanf("%d",&f[i].size);
        printf("Enter Block numbers:");
        for(j=1;j<=f[i].size;j++)
        {
            scanf("%d",&f[i].block[j]);
        }
    }
    printf("File\tStart\tSize\tBlock\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t",f[i].fno,f[i].start,f[i].size);
        for(j=1;j<=f[i].size-1;j++)
        printf("%d--->",f[i].block[j]);
        printf("%d",f[i].block[j]);
        printf("\n");
    }
}