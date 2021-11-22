#include <stdio.h>
int main()
{
    char s[80];
    char *p;
    p = s;
    gets(p);
    while(*p!='\0')
    {
        if(*p==' ') 
        *p = '*';
        p++;
    }
    puts(s);
    
}