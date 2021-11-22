#include <stdio.h>
#define N 100
int main()
{
    int n=0;
    char s[N];
    char a;
    while((a=getchar())!='\n') 
    {   
        s[n]=a;
        n++;
    }//导入字符
    char t[n];
    for(int i=0;i<n;i++)
    {
        t[i]=s[n-1-i];
    }
    //完成t[]为s[]的倒序字符串
    char str[n*2];
    for(int i=0;i<n;i++) str[i]=t[i];
    for(int i=n;i<2*n;i++) str[i]=s[i-n];
    for(int i=0;i<2*n;i++) printf("%c",str[i]);
    //若 printf("%s",str); 正确答案后会出现乱码，暂未找到答案
}