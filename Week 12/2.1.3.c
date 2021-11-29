#include <stdio.h>
int main()
{  
    int a[3][4] ,i, j, k=1;
    int (*q)[4];
    q=a;
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
        *(*(q+i) + j)=k++;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++) printf("%-3d",a[i][j]);
        printf("\n");
    }
}