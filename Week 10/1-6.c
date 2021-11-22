#include <stdio.h>
#define N 10
int main(){
    int b,i;
    int a[N]={1,2,3,4,5,6,7,8,9,10}; //假设数列为1-10 有序排列
    printf("插入:\n");
    scanf("%d",&b);
    for(i=0;i<N;i++)
    {
        if(b>=a[N-1])
        {
            for(i=0;i<N;i++) printf("%d ",a[i]);
            printf("%d\n",b);
        }
        else if(b>=a[i]&&b<a[i+1])
        {
            int j;
            for(j=0;j<i+1;j++) printf("%d ",a[j]);
            printf("%d ",b);
            for(j=i+1;j<N;j++) printf("%d ",a[j]);
        }
        else if(b<a[0])
        {
            printf("%d ",b);
            for(i=0;i<N;i++) printf("%d ",a[i]);
        }
    }

}