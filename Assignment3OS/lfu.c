#include<stdio.h>
int i, j, no_frame, no_ref, flag=0, ref[50], frame[50], pg_frame=0, victim=-1;
int recent[10], optcal[50], count=0;
int optvictim(int index)
{
    int i, j, temp, notfound;
    for(i=0;i<no_frame;i++)
    {
        notfound=1;
        for(j=index;j<no_ref;j++)
        if(frame[i]==ref[j])
        {
            notfound=0;
            optcal[i]=j;
            break;
        }
        if(notfound==1)
        return i;
    }
    temp=optcal[0];
    for(i=1;i<no_frame;i++)
        if(temp<optcal[i])
            temp=optcal[i];
    for(i=0;i<no_frame;i++)
        if(frame[temp]==frame[i])
            return i;
    return 0;
}

void main()
{
    printf("\nLeast Frequently Used Page Replacement Algorithm\n");
    printf("\nEnter the number of Frames: ");
    scanf("%d", &no_frame);
    printf("Enter the number of Reference String: ");
    scanf("%d", &no_ref);
    printf("Enter the Reference String: ");
    for(i=0;i<no_ref;i++)
        scanf("%d", &ref[i]);
    printf("\nThe given String: \t");
    for(i=0;i<no_ref;i++)
        printf("%4d", ref[i]);
    for(i=0;i<no_frame;i++)
    {
        frame[i]=-1;
        optcal[i]=0;
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
                victim=optvictim(i);
            pg_frame++;
            frame[victim]=ref[i];
            for(j=0;j<no_frame;j++)
                printf("%4d", frame[j]);
        }
    }
    printf("\n\nNumber of Page Faults are %d\n\n", pg_frame);
}
