#include <stdio.h>
int main()
{
    int a,k=0;
    int c,flag;
    scanf("%d",&a);
    if(a<0) 
    {
        flag = 0;
        a = -a;
    }
    else if (a==0) flag = 1;
    int b[100];
    while(a!=0)
    {
        c=a/2;
        k++;
        b[k]=a-c*2;
        a/=2;
    }
    if(!flag) printf("-");
    for(int i=k;i>=1;i--)
    {
        printf("%d",b[i]);
    }
    if(flag == 1) printf("0");
}