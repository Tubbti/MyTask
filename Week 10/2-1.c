#include <stdio.h>
#define N 10 //任意大小
int main(){
    int a[N][N];
    int i,s1=0,s2=0;
    for(i=0;i<N;i++)
    {
        s1+=a[i][i];
        s2+=a[i][N-i];
    }
}