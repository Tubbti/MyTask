#include <stdio.h>
#include <string.h>
int main()
{
    char a[10][100];
    char *p[10];
    char *t;
    for(int i=0;i<10;i++) 
    {
        gets(a[i]);
        p[i]=a[i];
    }
    for(int i=0;i<9;i++)
    {
        int k=i;
        for(int j=i+1;j<10;j++)
        {
            if(strcmp(p[j],p[i])>0) k=j;
        }
        if(k!=i)
        {
            t = *(p+i);
            *(p+i) = *(p+k);
            *(p+k) = t;
        }
    }
    for(int i=0;i<10;i++) printf("%s\n",p[i]);
}