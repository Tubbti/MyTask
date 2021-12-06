#include <stdio.h>
#define N 10
int main()
{
    FILE *fp;
    int a[N],i,t;
    int *p = a,*max,*min;
    fp=fopen("C:\\my\\sz.txt","w");
    //In Linux fp=fopen("/home/tubbti/my/sz.txt","w");
    for(i=0;i<N;i++) scanf("%d",p+i);
    max=min=&a[0];
    for(i=1;i<N;i++) 
    if(*(p+i)>*max)
    max = p+i;
    else if(*(p+i)<*min)
    min = p+i;
    t=*max;
    *max=*min;
    *min=t;
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);
}
