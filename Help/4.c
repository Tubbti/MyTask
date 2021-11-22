#include <stdio.h>
int main()
{
    int n,a=1;
    float sum=0;
    printf("Input n = ");
    scanf("%d",&n);
    for(int i=1;i<=100;i++)
    {
        sum+=(float)n/i*a;
        a=-a;
    }
    printf("sum = %f",sum);
}