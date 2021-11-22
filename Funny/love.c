#include <stdio.h>
int main()
{
    float x,y,a;
    for(y=1.5f;y>-1.5f;y-=0.1f)
    {
        for(x=-1.5f;x<1.5f;x+=.05f)
        {
            a=x*x+y*y-1;
            putchar(a*a*a-x*x*y*y*y<0.0f?'x':' ');
        }
        sleep(1);
        putchar('\n');
    }
    getchar();
    return 0 ;
}