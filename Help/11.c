#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int Judge();
    printf("%d",Judge(a));
}
int Judge(int a)
{
    int flag =1;
    if(a==1) flag = 0;
    for(int i=2;i<a-1;i++)
    {
        if(a%i==0){
            flag = 0;
            break;
        }
    }
    if(flag ==1) return 1;
    else return 0;
}