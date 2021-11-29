#include <stdio.h>
#include <string.h>
#define N 5
int main()
{
    char s[N][20];    //假设每个串的串长都小于20
    char h[40]="";
    char *p[N];      //借助指针数组，可以只交换指向串的指针，不交换串本身
    int i,j,k;
    for(i=0;i<N;i++)  //让指针数组p的每一个元素依次存放s每行的首地址
    p[i]=&s[i][0];
    for(i=0;i<N;i++)  //读入5个串，存放到s的每一行中
    gets(s[i]);
    //以下用选择法排序
    for(i=0;i<=N-2;i++)
    {
        k=i;
        for(j=i+1;j<=N-1;j++)
        if(strcmp(s[j],s[i]))k=j;
        if(k!=i)
        {
            char *t;
            t=p[i];
            p[i]=p[j];
            p[j]=t;
        }
    }
    puts("降序排列后：");
    for(i=0;i<N;i++)
    puts(*p[i]);
    h[40]= strcat(*p[4],*p[0]);
    printf("合并后的串:%s\n", h);
}
