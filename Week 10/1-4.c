#include <stdio.h>
int main(){
    int i,a[10];
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    int m,t;
    for(i=0;i<10;i++) {
        for(m=0;m<9-i;m++){
            if(a[m]>a[m+1])
            {
                t=a[m];
                a[m]=a[m+1];
                a[m+1]=t;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}