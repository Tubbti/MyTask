#include <stdio.h>
int main()
{
    int sum=0,n,S=0;
    printf("Input n: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum+=i;
        S+=sum;
    }
    printf("%d",S);
}