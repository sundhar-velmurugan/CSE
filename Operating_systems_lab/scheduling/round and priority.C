#include<stdio.h>
#include<conio.h>

void round()
{

  int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
    scanf("%d",&at[count]);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

}
struct process
{
	char process_name;
	int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
	int status;
}process_queue[10];

int limit;

void Arrival_Time_Sorting()
{
	struct process temp;
	int i, j;
	for(i = 0; i < limit - 1; i++)
	{
		for(j = i + 1; j < limit; j++)
		{
			if(process_queue[i].arrival_time > process_queue[j].arrival_time)
			{
				temp = process_queue[i];
				process_queue[i] = process_queue[j];
				process_queue[j] = temp;
			}
		}
	}
}

void priority()
{
	int i, time = 0, burst_time = 0, largest;
	char c;
	float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
	printf("\nEnter Total Number of Processes:\t");
	scanf("%d", &limit);
	for(i = 0, c = 'A'; i < limit; i++, c++)
	{
		process_queue[i].process_name = c;
		printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name);
		printf("Enter Arrival Time:\t");
		scanf("%d", &process_queue[i].arrival_time );
		printf("Enter Burst Time:\t");
		scanf("%d", &process_queue[i].burst_time);
		printf("Enter Priority:\t");
		scanf("%d", &process_queue[i].priority);
		process_queue[i].status = 0;
		burst_time = burst_time + process_queue[i].burst_time;
	}
	Arrival_Time_Sorting();
	process_queue[9].priority = -9999;
	printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
	for(time = process_queue[0].arrival_time; time < burst_time;)
	{
		largest = 9;
		for(i = 0; i < limit; i++)
		{
			if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
			{
				largest = i;
			}
		}
		time = time + process_queue[largest].burst_time;
		process_queue[largest].ct = time;
		process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].burst_time;
		process_queue[largest].turnaround_time = process_queue[largest].ct - process_queue[largest].arrival_time;
		process_queue[largest].status = 1;
		wait_time = wait_time + process_queue[largest].waiting_time;
		turnaround_time = turnaround_time + process_queue[largest].turnaround_time;
		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arrival_time, process_queue[largest].burst_time, process_queue[largest].priority, process_queue[largest].waiting_time);
	}
	average_waiting_time = wait_time / limit;
	average_turnaround_time = turnaround_time / limit;
	printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
	printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
}


void main(){
	clrscr();
	round();
	priority();
	getch();
}