#include<stdio.h>
#include<stdlib.h>

void fcfs(int n, int bt[], int at[], int pid[]){
	int i, j, l=0, *wt, *tat; 
	float avwt=0,avtat=0;
    
    wt=(int *)calloc(n, sizeof(int));
    tat=(int *)calloc(n, sizeof(int));
    
    wt[0]=at[0];
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        wt[i]-=at[i];
    }
    
	printf("\n==============================FCFS Scheduling==========================\n");
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],wt[i],tat[i]);
    }
	 
    avwt/=i;
    avtat/=i;
    
    printf("\n\nGantt Chart: \n\t-");
    
	for(i=0; i<n; i++){
		printf("------");
	}
	
	printf("\n\t|");
	for(i=0; i<n; i++){
		printf("P%d   |", pid[i]);
	}
	
	printf("\n\t-");
	
	for(i=0; i<n; i++){
		printf("------");
	}
	printf("\n\t");
	
	
	for(i=0; i<=n; i++){
		if(l<=9)
			printf("%d     ", l);
		else
			printf("%d    ", l);
		l=bt[i]+l;
	}
	//end of gantt chart
	
    printf("\n\nAverage Waiting Time: %.2f",avwt);
    printf("\nAverage Turnaround Time: %.2f\n",avtat);
}

void sjf(int n, int bt[], int at[], int pid[]){
	int i, j, l=0, *wt, *tat, *tt, btime=0, k=1, ta=0, sum=0, min; 
	float wavg=0,tavg=0,tsum=0,wsum=0;
    
    wt=(int *)calloc(n, sizeof(int));
    tat=(int *)calloc(n, sizeof(int));
    tt=(int *)calloc(n, sizeof(int));
    
    for(j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]<min)
			{
				int temp;
				
				temp=at[k];
				at[k]=at[i];
				at[i]=temp;
				
				temp=bt[k];
				bt[k]=bt[i];
				bt[i]=temp;
				
				temp=pid[k];
				pid[k]=pid[i];
				pid[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
 
	wavg=(wsum/n);
	for(i=0;i<n;i++)
	{
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
 
	tavg=(tsum/n);

	printf("\n==============================SJF Scheduling===========================\n");
	printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",pid[i],at[i],bt[i],wt[i],tt[i]);
	}
	
	printf("\n\nGantt Chart: \n\t-");
    
	for(i=0; i<n; i++){
		printf("------");
	}
	
	printf("\n\t|");
	for(i=0; i<n; i++){
		printf("P%d   |", pid[i]);
	}
	
	printf("\n\t-");
	
	for(i=0; i<n; i++){
		printf("------");
	}
	printf("\n\t");
	
	
	for(i=0; i<=n; i++){
		if(l<=9)
			printf("%d     ", l);
		else
			printf("%d    ", l);
		l=bt[i]+l;
	}
	//end of gantt chart
	
	printf("\n\nAverage Waiting Time: %.2f",wavg);
	printf("\nAverage Turnaround Time: %.2f\n\n",tavg);

}

void input()
{
    int n,*bt, *at, *pid ,i, j;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    pid=(int *)calloc(n, sizeof(int));
    bt=(int *)calloc(n, sizeof(int));
    at=(int *)calloc(n, sizeof(int));
 
    for(i=0;i<n;i++)
    {
    	printf("Process [%d]:\n", i+1);
    	printf("Enter ID: ");
        scanf("%d",&pid[i]);
        printf("Enter burst time: ");
        scanf("%d",&bt[i]);
        printf("Enter arrival time: ");
        scanf("%d",&at[i]);
    }
    
    //sorting based on arrival time
    for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(at[i]>at[j]) {
				int temp;
				
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;

				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
	
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			}
		}
	}
	
    fcfs(n, bt, at, pid);
    sjf(n, bt, at, pid);
}

int main(){
	input();
	return 0;
}
