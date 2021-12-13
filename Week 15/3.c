#include <stdio.h>
void tran(int n)
{
    if(n/2!=0) tran(n/2);
    printf("%d",n%2);
}
int main()
{
    int x;
    scanf("%d",&x);
    if(x<0) 
    {
        printf("-");
        x=-x;
    }
    tran(x);
    printf("\n");
}