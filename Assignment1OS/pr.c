#include <stdio.h>
void main()
{
int i, j, no_of_process, turn_around_time[10], waiting_time[10], burst_time[10], pid[10], pr[10], temp;
int total_waiting_time = 0, total_turn_around_time = 0;
float avg_waiting_time, avg_turn_around_time;
printf("Enter the Number of Processes: ");
scanf("%d", &no_of_process);
for (i=0; i<no_of_process; i++){
pid[i] = i;
printf("Enter the Burst time of Process %d : ", i+1);
scanf("%d", &burst_time[i]);
printf("Enter the Priority of Process %d : ", i+1);
scanf ("%d", &pr[i]);
}
for (i=0; i<no_of_process; i++)
for(j=i+1; j<no_of_process; j++)
{
if (pr[i] > pr[j] ){
temp = pr[i];
pr[i] = pr[j];
pr[j] = temp;
temp = burst_time[i];
burst_time[i] = burst_time[j];
burst_time[j] = temp;
temp = pid[i];
pid[i] = pid[j];
pid[j] = temp;
}}
turn_around_time[0] = burst_time[0];
waiting_time[0] = 0;
for (i=1; i<no_of_process; i++){
waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
turn_around_time[i] = waiting_time[i] + burst_time[i];
}
printf("\n---------------------------------------------------------------\n");
printf("Pid\t Priority\tBurst time\t Waiting Time\tTurn Arround Time\n");
printf("\n--------------------------------------------------------------\n");
for(i=0; i<no_of_process; i++){
printf("\n%d\t\t%d\t%d\t\t%d\t\t%d", pid[i], pr[i], burst_time[i], waiting_time[i], turn_around_time[i]);
}
for(i=0; i<no_of_process; i++)
{
total_turn_around_time = total_turn_around_time + turn_around_time[i];
total_waiting_time = total_waiting_time + waiting_time[i];
}
avg_waiting_time = (float)total_waiting_time / no_of_process;
avg_turn_around_time = (float)total_turn_around_time / no_of_process;
printf("\n\nAverage Waiting Time: %f\nAverage Turn Around Time: %f\n", avg_waiting_time, avg_turn_around_time);
}