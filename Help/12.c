#include <stdio.h>
int main()
{
    double p();
    int n,x;
    printf("Input n and x:\n");
    scanf("%d%d",&n,&x);
    printf("%lf",p(n,x));
}
double p(int n,int x)
{
    if(n==0) 
    {
        return 1;
    }
    else if(n==1)
    {
        return x;
    }
    else
    {
        return ((2*n-1)*p(n-1,x)*x-(n-1)*p(n-2,x)) / n;
    }
}