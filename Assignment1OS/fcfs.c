#include<stdio.h>
void main(){
int i, no_of_process, sum, waiting_time, turn_around_time, total_waiting_time, total_turn_around_time;
int burst_time[10];
float avg_waiting_time, avg_turn_around_time;
printf("Enter number of processes :\n");
scanf("%d", &no_of_process);
for(i=0; i<no_of_process; i++) {
printf("\n Enter the Burst Time of the process %d : ", i+1);
scanf("\n %d", &burst_time[i]);
}
printf("\n\n FIRST COME FIRST SERVE SCHEDULING ALGORITHM \n");
printf("\n Process ID \t Burst Time \t Waiting Time \t Turn Around Time \n");
printf("1 \t\t %d \t\t 0 \t\t %d \n", burst_time[0], burst_time[0]);
sum=0;
total_waiting_time = 0;
total_turn_around_time = burst_time[0];
for(i=1; i<no_of_process; i++) {
sum += burst_time[i-1];
waiting_time = sum;
turn_around_time = sum + burst_time[i];
total_waiting_time = total_waiting_time + waiting_time;
total_turn_around_time = total_turn_around_time + turn_around_time;
printf("\n %d \t\t %d \t\t %d \t\t %d", i+1, burst_time[i], waiting_time, turn_around_time);
printf("\n\n");
}
avg_waiting_time = (float)total_waiting_time / no_of_process;
avg_turn_around_time = (float)total_turn_around_time / no_of_process;
printf("\n Average Waiting Time %4.2f", avg_waiting_time);
printf("\n Average Turnaround Time %4.2f\n", avg_turn_around_time);
}
