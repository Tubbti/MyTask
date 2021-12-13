#include <stdio.h>
int gys(int m,int n);
int main()
{
	int b,x,y;
	scanf("%d %d",&x,&y);
	b=gys(x,y);
	printf("最大公约数:%d",b);
	return 0;
}
int gys(int m,int n)
{
	if(!(m%n))
	return n;
	else return(gys(n,m%n));
}
 
