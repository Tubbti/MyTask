#include <stdio.h>
int main()
{
    float m=1,sum=2; //m为分母，sum为和
    while(1/m>=1e-6)
    {
        m*=m+1;
        sum+=1/m;
    }
    printf("e=%f\n",sum);
}