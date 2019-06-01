//Program : Priority Scheduling.
#include <stdio.h>
#include <stdlib.h>
typedef struct sjf
{
	int at,bt,ft,tat,wt,pt;
}sjf;
sjf Array_Time[20],Array_Time1[20];
int main()
{
	int i,count,val,j,min,n,Gantt[20],Process[20],temp,sum=0,k=0;
	float Tat,Tat1,Wt,Wt1;
	Array_Time[0].wt=Array_Time[0].tat=0;
	printf("NOlgorithm\n");
	printf("=========================== \n");
	printf("\nEnter the Number Of Process : ");
	scanf("%d",&n);
	printf("\n\n");
	for(i=1;i<=n;i++) {

		printf("Enter the details of the Process %d\n",i);
		printf("===================================\n");
		printf("\n Burst Time    :");
		scanf("%d",&Array_Time[i].bt);
		printf("\n Arrival Time  :");
		scanf("%d",&Array_Time[i].at);
		printf("\n Priority      :");
		scanf("%d",&Array_Time[i].pt);
		printf("\n");

	}
	count=Array_Time[1].at;
for(i=1;i<=n;i++)
		count+=Array_Time[i].bt;
	for(i=1;i<=n;i++)
		Array_Time1[i]=Array_Time[i];
	val=Array_Time[1].at;
	do
	{
		min = 9999;
		for(i=1;Array_Time[i].at<=val && i<=n ;i++)
			if(Array_Time[i].pt<min && Array_Time[i].pt>0)
			{
				j=i;
				min=Array_Time[i].pt;
			}

		val+=Array_Time[j].bt;
		Array_Time[j].pt=0;
		Gantt[j]=val;
		Process[j]=j;
		if(Array_Time[j].pt==0)
		{
			Array_Time[j].ft=val;
			Array_Time[j].tat=Array_Time[j].ft-Array_Time[j].at;
			Array_Time[j].wt=Array_Time[j].tat-Array_Time1[j].bt;
		}
	}while(val<count);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++) {
			if(Gantt[i]>Gantt[j]) {
				temp=Gantt[i];
				Gantt[i]=Gantt[j];
				Gantt[j]=temp;
				temp=Process[i];
				Process[i]=Process[j];
				Process[j]=temp;
			}
		}
	}
	printf("\n\n\n\n");
	printf("GANTT CHART\n");
	printf("===========\n");
	printf("\n\n");
	printf("\n");
	for(i=1;i<=n;i++){
		printf("----------------");
	}
	printf("\n");
	for(i=1;i<=n;i++) {
		printf("|\tP%d\t",Process[i]);
	}
	printf("|");
	printf("\n");
	for(i=1;i<=n;i++){
		printf("----------------");
	}
	printf("\n");
	printf("%d\t\t",Array_Time[1].at);
	for(i=1;i<=(n);i++){
		printf("%d\t\t",Gantt[i]);
	}
       	printf("\n\n\n");
	printf("Turn Around Time (TAT) \n");
	printf("====================== \n\n");
		printf("|==============================|\n");
		printf("|    PROCESS    |     TAT      |\n");
		printf("|==============================|\n");
	for(i=1;i<=n;i++) {
		printf("|       P%d      |      %2d      |\n",i,Array_Time[i].tat);
	}
		printf("|==============================|\n");
	sum=0;
	for(i=1;i<=n;i++) {
		sum=sum+Array_Time[i].tat;
	}
	printf("\n\n");
	printf("Total T.A.T of All Processes : %d\n\n",sum);
	Tat1=sum;
	Tat=Tat1/n;
	printf("Average Turn Around Time     : %0.2f",Tat);
printf("\n\n\n");
printf("Waiting Time (Wt) \n");
printf("================= \n\n");
		printf("|==============================|\n");
		printf("|    PROCESS   |     TAT       |\n");
		printf("|==============================|\n");
	for(i=1;i<=n;i++) {
		printf("|      P%d      |      %2d       |\n",i,Array_Time[i].wt);
	}
		printf("|==============================|\n");
	sum=0;
	for(i=1;i<=n;i++) {
		sum=sum+Array_Time[i].wt;
	}
	printf("\n\n");
	printf("Total W.T  of All Processes  : %d\n\n",sum);
	Wt1=sum;
	Wt=Wt1/n;
	printf("Average Wating Time          : %0.2f",Wt);
	printf("\n\n");
	//getch();
	return 0;
}










