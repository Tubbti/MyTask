#include <stdio.h>
int main()
{
    int ss[8] = {17,19,23,37,67,103,739,1949},i;
    int fxs,flag,k,x;
    for(i=0;i<8;i++)
    {
        x=ss[i];
        fxs=0;
        while(x!=0)
        {
            fxs = fxs*10 + x%10;
            x/=10; 
        }
        flag = 1;
        for(k=2;k<=fxs-1;k++)
        if(fxs%k==0)
        {
            flag = 0;
            break;
        }
        if(flag) printf("%d是可逆素数\n",ss[i]);
    }
}