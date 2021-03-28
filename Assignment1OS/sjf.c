#include<stdio.h>
void main()
{
int i, j, k, no_of_process, sum, waiting_time[10], turn_around_time[10], total_waiting_time, total_turn_around_time;
int temp, pos;
int burst_time[10], process[10];
float avg_waiting_time, avg_turn_around_time;
printf("Enter number of processes : \n");
scanf("%d", &no_of_process);
for(i=0; i<no_of_process; i++) {
printf("\n Enter the Burst Time of Process %d : ", i);
scanf("\n %d", &burst_time[i]);
}
for(i=0; i<no_of_process; i++)
process[i] = i;
for(i=0; i<no_of_process; i++)
    {
        pos = i;
        for(j=i+1; j<no_of_process; j++)
        {
            if(burst_time[j] < burst_time[pos])
                pos = j;
        }
  
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
  
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }
printf("\n PROCESS ID \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n\n");
waiting_time[0] = 0;
for(i=0; i<no_of_process; i++) {
sum = 0;
for(k=0; k<i; k++) {
waiting_time[i] = sum+burst_time[k];
sum = waiting_time[i];
}
}
for(i=0; i<no_of_process; i++) {
turn_around_time[i] = burst_time[i] + waiting_time[i];
}
for(i=0; i<no_of_process; i++) {
printf("%5d \t\t%5d \t\t %5d \t\t %5d \n\n", process[i], burst_time[i], waiting_time[i], turn_around_time[i]);
}
total_waiting_time = 0;
total_turn_around_time = burst_time[0];
for(i=1; i<no_of_process; i++) {
total_waiting_time = total_waiting_time + waiting_time[i];
total_turn_around_time = total_turn_around_time + turn_around_time[i];
}
avg_waiting_time = (float)total_waiting_time / no_of_process;
avg_turn_around_time = (float)total_turn_around_time / no_of_process;
printf("\n AVERAGE WAITING TIME %4.2f", avg_waiting_time);
printf("\n AVERAGE TURN AROUND TIME %4.2f\n", avg_turn_around_time);

}