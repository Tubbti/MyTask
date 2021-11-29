#include <stdio.h>
int main()
{
    int a[3][4],i,j,k=1;
    int *p;
    p=a[0];
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
        *(p+k-1)=k;
        k++;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++) printf("%-3d", a[i][j]);
        printf("\n");
    }

}