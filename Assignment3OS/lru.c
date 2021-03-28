#include<stdio.h>
int i, j, no_frame, no_ref, flag=0, ref[50], frame[50], pg_fault=0, victim=-1;
int recent[10], lru_cal[50], count=0;

int lru_victim()
{
    int i, j, temp1, temp2;
    for(i=0;i<no_frame;i++)
    {
        temp1=frame[i];
        lru_cal[i]=recent[temp1];
    }
    temp2=lru_cal[0];
    for(j=1;j<no_frame;j++)
    {
        if(temp2>lru_cal[j])
        temp2=lru_cal[j];
    }
    for(i=0;i<no_frame;i++)
        if(ref[temp2]==frame[i])
            return i;
        return 0;
}
void main()
{
    printf("\nLeast Recently Used Page Replacement Algorithm\n");
    printf("\nEnter number of Frames: ");
    scanf("%d", &no_frame);
    printf("\nEnter number of Reference String: ");
    scanf("%d", &no_ref);
    printf("\nEnter Reference String: ");
    for(i=0;i<no_ref;i++)
        scanf("%d", &ref[i]);
    printf("\nThe given Reference String:");
    for(i=0;i<no_ref;i++)
        printf("%5d", ref[i]);
    for(i=1;i<=no_frame;i++)
    {
        frame[i]=-1;
        lru_cal[i]=0;
    }
    for(i=0;i<10;i++)
        recent[i]=0;
    printf("\n");
    for(i=0;i<no_ref;i++)
    {
        flag=0;
        printf("\nReference NO %d \t", ref[i]);
        for(j=0;j<no_frame;j++)
        {
            if(frame[j]==ref[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            count++;
            if(count<=no_frame)
                victim++;
            else
                victim=lru_victim();
            pg_fault++;
            frame[victim]=ref[i];
            for(j=0;j<no_frame;j++)
                printf("%5d", frame[j]);
        }
        recent[ref[i]]=i;
    }
    printf("\n\nNumber of Page Faults are %d\n\n", pg_fault);
}
