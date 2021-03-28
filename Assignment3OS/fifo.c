#include<stdio.h>
int i, j, no_frames, no_ref, flag=0, ref[50], frame[50], pg_fault=0, victim=-1; 
void main()
{
    printf("\nFirst In First Out Page Replacement Algorithm\n"); 
    printf("\nEnter number of Frames: "); 
    scanf("%d", &no_frames); 
    printf("Enter number of Reference String: "); 
    scanf("%d", &no_ref); 
    printf("\nEnter the Reference String: "); 
    for(i=0; i<no_ref; i++)
        scanf("%d", &ref[i]); 
    printf("\nThe given Reference String:"); 
    for(i=0; i<no_ref; i++)
        printf("%5d", ref[i]); 
    for(i=1; i<=no_frames; i++)
        frame[i]=-1; 
    printf("\n"); 
    for(i=0; i<no_ref; i++)
    {
        flag=0; 
        printf("\nReference No %d: \t", ref[i]); 
        for(j=0; j<no_frames; j++)
        {
            if(frame[j]==ref[i])
            {
                flag=1; 
                break; 
            }
        }
        if(flag==0)
        {
            pg_fault++; 
            victim++; 
            victim = victim % no_frames; 
            frame[victim] = ref[i]; 
            for(j=0; j<no_frames; j++)
                printf("%5d", frame[j]); 
        }
    }
    printf("\n\nNumbers of Page Faults are %d\n\n", pg_fault); 
}