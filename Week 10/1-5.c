#include <stdio.h>
int main()
{
    int i,a[10],N=5;
    for(i=1;i<10;i++)
    {
        a[i]=i;
    }
    for(int j=1;j<6;j++)
    {
        for(i=N;i<N+5;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        N--;
    }
}