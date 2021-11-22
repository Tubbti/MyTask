#include <stdio.h>
#define N 10
int main(){
    int a[N][N];
    int m,n;
    printf("Input m and n:\n");
    scanf("%d%d",&m,&n);
    int i,t;
    for(i=0;i<N;i++){
        t=a[i][m];
        a[i][m]=a[i][n];
        a[i][n]=t;
    }
}