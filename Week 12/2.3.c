#include <string.h>
#include <ctype.h>
main()
{
    char *text="  I  will  pass  the  examination  in  the  summer  holiday." ;
    int n, i, j, word;
    char a[20][80];
    while(*text==' ')  text++;  /*去掉前导空格*/
    n=0; j=0;
    for(i=0; i<strlen(text); i++)
    if(isalpha(*(text+i)))  /* isalpha 函数的功能是判断其参数是否为字母，要加"ctype.h"*/
    {
        a[n][j++]= *(text+i); 
        word=0;
    }
    else if(word==0)
    {  
        word=1;
        j=0;
        n++;
    }
    
    printf("It has %d word.\n\n", n);
    for(i=0;i<n;i++)
    puts(a[i]);
}
