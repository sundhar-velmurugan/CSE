/*
   FCFS Disk Scheduling Algorithm
   Created by: Pirate
*/

#include<stdio.h>
//#include<conio.h>
void main()
{
             int queue[100],n,head,i,j,k,seek=0,diff;
             float avg;
             // clrscr();
             printf("*** FCFS Disk Scheduling Algorithm ***\n");
             printf("Enter the size of Queue\t");
             scanf("%d",&n);
             printf("Enter the Queue\t");
             for(i=1;i<=n;i++)
             {
                          scanf("%d",&queue[i]);
             }
             printf("Enter the initial head position\t");
             scanf("%d",&head);
             queue[0]=head;
             printf("\n");
             for(j=0;j<=n-1;j++)
             {
                          diff=abs(queue[j+1]-queue[j]);
                          seek+=diff;
                         
             }
             printf("\nTotal Seek Time is %d\t",seek);
             avg=seek/(float)n;
             printf("\nAverage Seek Time is %f\t",avg);
            // getch();
}
