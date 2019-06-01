#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
int main(){
 int n,i,sq;
 double t1=omp_get_wtime();
 double t2;
 printf("\nenter a number :");
 scanf("%d",&n);
 int *res=(int *)calloc(n, sizeof(int));
 int *flag=(int *)calloc(n, sizeof(int));
	for(i=0;i<n;i++){
		res[i]=i+1;
		flag[i]=1;
	}
	flag[0]=-1;
	sq=sqrt(n);
	#pragma omp parallel
	{
		for(i=1;i<=sq;i++){

			if(flag[i]==1){

				for(int j=i+1;j<n;j++){
					if(res[j]%res[i]==0&&flag[j]==1){
						flag[j]=-1;

					}
				}
			}
		}
	}
	 t2=omp_get_wtime();
	for(i=1;i<n;i++){
		if(flag[i]==1)
		printf("%d ",res[i]);
	}
	printf("\ntime taken is %f",t2-t1);

}

