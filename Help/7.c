#include <stdio.h>
int main()
{
    int a,sum;
    printf("Input :\n");
    scanf("%d",&a);
    for(sum=0;a!=0;)
    {
        sum+=a%10;
        a/=10;
    }
    printf("%d\n",sum);
}