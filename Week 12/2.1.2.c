#include <stdio.h>
int main()
{
    int a[3][4],i,j=1;
    int *p;
    for(i=0;i<12;i++)
    a[0][i]=j++;
    p=a[0];
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++) printf("%-3d", *(p+j+i*4));
        printf("\n");
    }
}