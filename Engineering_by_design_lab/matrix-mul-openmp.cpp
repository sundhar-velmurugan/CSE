#include <stdio.h>
#include <omp.h>

int main(){
    int n, i, j, k;
    double t1, t2;
    scanf("Enter n: %d", &n);
    int a[n][n], b[n][n], res[n][n];
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", a[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", b[i][j]);
        }
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            res[i][j]=0;
        }
    }
    
    t1=omp_get_wtime();
    
    #pragma omp parallel{
        int tid = omp_get_thread_num();
        printf("Thread no: %d", tid);
        for(i=0; i<n; i++){
            #pragma omp parallel{
                for(j=0; j<n; j++){
                    #pragma omp paralle{
                        for(k=0; k<n; k++){
                            res[i][j]=a[i][k]+b[k][j];
                        }
                    }
                }
            }
        }
    }
    t2=omp_get_wtime();
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d\t",res[i][j]);
        }
    }
    printf("Time taken: %f", t2-t1);
    
    return 0;
}