#include<stdio.h>
int main(){
  int num,i,j,k;
  printf("\nEnter a number:");
  scanf("%d",&num);
  for(i=1;i<=num;i++){
      k=0;
      if(num%i==0){
         j=1;
          while(j<=i){
            if(i%j==0)
                 k++;
             j++;
          }
          if(k==2)
             printf("\n%d is a prime factor",i);
      }
   }
   return 0;
}
