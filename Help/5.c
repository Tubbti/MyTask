#include <stdio.h>
int main()
{
    int flag = 0;
    for(int i=1900;i<=2000;i++)
    {
        if((i%4==0 && i%100!=0)||(i%400==0))
        {
            printf("%d ",i);
            flag++;
        }
        if(flag == 3)
        {
            printf("\n");
            flag = 0;
        }
        
    }
}