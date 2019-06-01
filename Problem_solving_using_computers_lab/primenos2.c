#include <stdio.h>
//#include <stdlib.h>

int main(){
    //unsigned long long int i,j;
    //int *primes;
    int i,j,z = 1, limit;

    printf("\nEnter the limit: ");
    scanf("%d",&limit);

    int primes[limit];
    //primes = malloc(sizeof(int)*limit);

    for (i=2;i<=limit;i++)
        primes[i]=1;

    for (i=2;i<=limit;i++)
        if (primes[i]!=0)
            for (j=i;i*j<=limit;j++)
                primes[i*j]=0;

    for (i=2;i<=limit;i++)
        if (primes[i]!=0)
            printf("%dth prime = %d\n",z++,i);

return 0;
}
