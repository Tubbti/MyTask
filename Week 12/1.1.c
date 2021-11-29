#include <stdio.h>
int main()
{
    int a[10],s=0;
    int *p;
    for(p=a;p<a+10;p++) scanf("%d",p);
    for(p=a;p<a+10;p++) if(*p%2==0) s+=*p;
    printf("%d\n",s);
}