 #include<stdio.h>
 #include<unistd.h>
// #include<sys/ipc.h>
// #include<sys/uio.h>
//#include<sys/types.h>
 main()
 {
 int pid,pfd[2],n,a,b,c; if(pipe(pfd)==-1)
 {
 printf("\nError in pipe connection\n"); 
 return 1;
 }
 pid=fork();
 if(pid>0)
{
 printf("\nParent Process");
 printf("\n\n\tFibonacci Series");
 printf("\nEnter the limit for the series:");
scanf("%d",&n);
 close(pfd[0]);
 write(pfd[1],&n,sizeof(n));
 close(pfd[1]);
return 0;
 }
 else
 {
close(pfd[1]); read(pfd[0],&n,sizeof(n)); printf("\nChild Process"); a=0;
 b=1;
 close(pfd[0]);
 printf("\nFibonacci Series is:");
 printf("\n%d\t%d",a,b);
 while(n>2)
 {
 c=a+b;
 printf("\t%d",c);
 a=b;
 b=c;
 n--;
 }
printf("\n");
 }
 }
