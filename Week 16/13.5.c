#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *f1,*f2,*f3;
	char a[100];
	int i=0,n,j;
	char t; 
	f1=fopen("D:\\A.txt","r");
	f2=fopen("D:\\B.txt","r");
	f3=fopen("D:\\C.txt","w");
	a[i]=fgetc(f1);
	while(a[i]!=EOF)
	{
		//Check putchar(a[i]);
		i++;
		a[i]=fgetc(f1);
	}
	fclose(f1);
	a[i]=fgetc(f2);
	while(a[i]!=EOF)
	{
		//Check putchar(a[i]);
		i++;
		a[i]=fgetc(f2);
	}
	fclose(f2);
	for(n=0;n<i;n++)
	{
		for(j=n+1;j<i;j++)
		{
			if(a[n]>a[j])
			{
				t=a[n];
				a[n]=a[j];
				a[j]=t;	
			}
		}
	}
	n=0;
	while(n<i)
	{
		fputc(a[n],f3);
		//Check putchar(a[n]); 
		n++;
	}
	fclose(f3);
}
