#include <stdio.h>
int main()
{
    int n;
    long sum();
    scanf("%d",&n);
    printf("%ld",sum(n));
}
long sum(int n)
{
    long sum=0;
    for(int i=1;i<=n;i++) 
    {
        sum+=i;
    }
    return sum;
}