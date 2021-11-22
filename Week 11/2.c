#include <stdio.h>
#include <string.h>
int main()
{
    int i=0;
    char a[10][100];
    for(;i<10;i++) gets(a[i]);
    char max[100];
    char min[100];
    strcpy(max,a[0]);
    strcpy(min,a[0]);
    for(i=1;i<10;i++) 
    {
        if(strcmp(a[i],max)>0)
        {
            strcpy(max,a[i]);
        }
        else if (strcmp(a[i],min)<0)
        {
            strcpy(min,a[i]);
        }
    }
    printf("%s",strcat(min,max));


}