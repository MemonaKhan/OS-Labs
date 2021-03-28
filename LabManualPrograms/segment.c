#include <stdio.h>
#include <math.h>
int sost;
void gstinfo();
void ptladdr();
struct segtab
{
int sno;
int baddr;
int limit;
int val[10];
}st[10];
void gstinfo()
{
int i,j;
printf("Enter the size of the segment table: ");
scanf("%d",&sost);
for(i=1;i<=sost;i++)
{
printf("Enter the information about segment %d : ",i);
st[i].sno = i;
printf("Enter the base Address: ");
scanf("%d",&st[i].baddr);
printf("Enter the Limit: ");
scanf("%d",&st[i].limit);
for(j=0;j<st[i].limit;j++)
{
printf("Enter the %d address Value: ",(st[i].baddr + j));
scanf("%d",&st[i].val[j]);
}
}
}
void ptladdr()
{
int i,swd,d=0,n,s,disp,paddr;
printf("\n\t\t\t SEGMENT TABLE \n");
printf("\n\tSEG.NO\tBASE ADDRESS\tLIMIT \n\n");
for(i=1;i<=sost;i++)
printf("\t\t%d \t\t%d\t\t%d\n\n",st[i].sno,st[i].baddr,st[i].limit);
printf("\nEnter the logical Address: ");
scanf("%d",&swd);
n=swd;
while (n != 0)
{
n=n/10;
d++;
}
s = swd/pow(10,d-1);
disp = swd%(int)pow(10,d-1);
if(s<=sost)
{
if(disp < st[s].limit)
{
paddr = st[s].baddr + disp;
printf("\nLogical Address is: %d",swd);
printf("\nMapped Physical address is: %d",paddr);
printf("\nThe value is: %d",( st[s].val[disp] ) );
}
else
printf("\nLimit of segment %d is high\n\n",s);
}
else
printf("\nInvalid Segment Address \n");
}
void main()
{
char ch;
gstinfo();
do
{
ptladdr();
printf("\nDo U want to Continue(Y/N)");
flushall();
scanf("%c",&ch);
}while (ch == 'Y' || ch == 'y' );
}