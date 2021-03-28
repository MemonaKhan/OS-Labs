#include<stdio.h>
void main()
{
int quantum, need[10], waiting_time[10], turn_around_time[10], i, j, no_of_process, n1;
int burst_time[10], flag[10], total_turn_around_time = 0, total_waiting_time = 0;
float avg_waiting_time, avg_turn_around_time;
// printf("\t\t ROUND ROBIN SCHEDULING \n");
printf("Enter the number of Processes : ");
scanf("%d", &no_of_process);
n1 = no_of_process;
printf("Enter the Quantum : ");
scanf("%d", &quantum);
for(i=1; i<=no_of_process; i++) {
// printf("\n Enter the process ID %d",i);
// scanf("%d",&pid[i]);
printf("Enter the Burst Time for the process %d : ",i);
scanf("%d", &burst_time[i]);
need[i] = burst_time[i];
}
for(i=1; i<=no_of_process; i++) {
flag[i] = 1;
waiting_time[i] = 0;
}
while(no_of_process != 0) {
for(i=1; i<=no_of_process; i++) {
if(need[i] >= quantum) {
for(j=1; j<=no_of_process; j++){
if((i != j) && (flag[i] == 1) && (need[j] != 0))
waiting_time[j] += quantum;
}
need[i] -= quantum;
if(need[i] == 0) {
flag[i] = 0;
no_of_process--;
} }
else{
for(j=1; j<=no_of_process; j++){
if((i != j) && (flag[i] == 1) && (need[j] != 0))
waiting_time[j] += need[i];
}
need[i] = 0;
no_of_process--;
flag[i] = 0;
}}}
for(i=1; i<=n1; i++){
turn_around_time[i] = waiting_time[i] + burst_time[i];
total_waiting_time = total_waiting_time + waiting_time[i];
total_turn_around_time = total_turn_around_time + turn_around_time[i];
}
avg_waiting_time = (float)total_waiting_time / n1;
avg_turn_around_time = (float)total_turn_around_time / n1;
// printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");
printf("\n\n Process \t BurstTime \t Waiting Time \t TurnaroundTime\n ");
for(i=1; i<=n1; i++){
printf("\n %5d \t\t %5d \t\t %5d \t\t %5d \n", i, burst_time[i], waiting_time[i], turn_around_time[i]);
}
printf("\n The average Waiting Time=%4.2f", avg_waiting_time);
printf("\n The average Turn around Time=%4.2f\n", avg_turn_around_time);
}