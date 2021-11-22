#include <stdio.h>
int main()
{
    double x;
    scanf("%lf",&x);
    double fun();
    printf("%lf",fun(x));
}
double fun(double x)
{
    if(x>1) return x*x+1;
    else if(x<=1&&x>=-1) return x*x;
    else return x*x-1;
}