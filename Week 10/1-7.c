#include <stdio.h>
int main()
{
    int i=0,j,k;
    int a[]={2,2,2,3,4,4,5,6,7,2,6,7,7,8,9,9,4,10,10};
    int n = sizeof(a)/sizeof(int);
    for(i=0;i<n;i++) printf("%d ",a[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                n--;
                j=i;
            }
        }
    }
    printf("删除相同数字后，数组为：\n");
    for(i=0;i<n;i++) printf("%d ",a[i]);
}