#include <stdio.h>
int main()
{
    char str[100];
    int i=0,j=0;
    printf("Input:\n");
    gets(str);
    while(str[i]!='\0') i++;
    i--;
    for(;j<i;i--,j++)
    {
        if(str[i]!=str[j]) break;
    }
    if(j>=i) printf("是回文字符串!\n");
    else printf("不是回文字符串!\n");
}