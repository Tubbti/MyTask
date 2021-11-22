#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    gets(a);
    int length = strlen(a);
    int b[2][10]={{0,1,2,3,4,5,6,7,8,9}};
    for(int i=0;i<length;i++) 
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            for(int k=0;k<10;k++)
            {
                if(b[0][k]==a[i] - '0')
                {
                    b[1][k]++;
                }
            }
        }
    }
    for(int k=0;k<10;k++)
    {
        if(b[1][k]==0) 
        {
            continue;
        }
        else
        {
            printf("%d---%d\n",b[0][k],b[1][k]);
        }
    }
}