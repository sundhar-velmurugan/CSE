//Program : Round Robin
#include<stdio.h>
//#include<conio.h>
typedef struct sjf
{
	int at,bt,ft,tat,wt,pt;
}sjf;

int main()
{
    	int bt[20],gc[20],wt[20],tat[20],bt1[20],st[20],ts,n,i,j,k,count=0,count1,sum_bt=0,tq;
    	int swt=0,stat=0,temp,sq=0,c,p=0;
	float awt,atat; 
        printf("Round Robin Scheduling Algorithm\n");
        printf("=========================== \n");
  	printf("Enter the No of Processes :");
    	scanf("%d",&n);
    	printf("Enter the burst time :");
    	for(i=0; i<n; i++)
    	{	printf("\nProcess %d :",i+1);
		scanf("%d",&bt[i]);
		bt1[i]=bt[i];
		st[i]=bt[i];\
    	}
    	printf("Enter the time slice :");
    	scanf("%d",&ts);
    	tq=ts;
    	for(i=0; i<n; i++)
    		sum_bt=sum_bt+bt[i];
	for(k=0; k<n; k++)
    	{
       		do
		{
	    		for(i=0; i<n; i++)
	   		 {
				if(bt[i]>=ts)
				{
		    			for(j=count; j<(count+ts); j++)
					gc[j]=i+1;
		    			count+=ts;
		    			bt[i]=bt[i]-ts;
				}
				else
				{
		    			for(j=count; j<=(count+bt[i]); j++)
					gc[j]=i+1;
		    			count+=bt[i];
		    			bt[i]=0;	
				}	
	    		}
		}while(bt[k]!=0);
	}

	 while(1)
	{
       		for(i=0,count=0;i<n;i++)
       		{
       			temp=tq;
      		        if(st[i]==0)
      			{
				count++;
				continue;
       			}
			if(st[i]>tq)
				st[i]=st[i]-tq;
			else
				if(st[i]>=0)
				{
					temp=st[i];
					st[i]=0;
				}
			sq=sq+temp;
			tat[i]=sq;
	}
	if(n==count)
		break;
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt1[i];
		swt=swt+wt[i];
		stat=stat+tat[i];
	}
	awt=(float)swt/n;
	atat=(float)stat/n;
        printf("===================================================== \n\n");
	        printf("Process_no | Burst time | Wait time |Turn around time\n");
        printf("===================================================== \n\n");
	
 	for(i=0;i<n;i++)
		printf("    %d          %d           %d           %d\n",i+1,bt1[i],wt[i],tat[i]);
	printf("\nAvg wait time is :%f \nAvg turn around time is :%f",awt,atat);
 	printf("\n \n");
    	printf("GANTT CHART: \n");
    	c=gc[0];
	for(i=1;i<2*n;i++){
		printf("----------------");
	}
	printf("\n");
    	printf("|\tP%d\t",gc[0]);
    	for(i=1;i<sum_bt;i++)
            {
		if(gc[i]!=c)
		{
			printf("|\tP%d\t",gc[i]);
			c=gc[i];
		}
    	}
    	printf("|");
    	printf("\n");
    	printf("0");c=gc[0];
	for(i=1;i<2*n;i++){
		printf("----------------");
	}
	printf("\n");
    	for(i=1;i<sum_bt+1;i++)
    	{    
		p=p+1;
	        if(gc[i]!=c)
	 	{
			printf("\t\t%d",p);
			c=gc[i];
		}
    	}
	printf("\n");
	
   	//getch();
   	return 0;
}
