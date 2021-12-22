#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char a[100];
	int i=0;
	fp=fopen("D:\\test.txt","w");
	//In Linux : fp=fopen("/home/tubbti/test.txt","w");
	gets(a);
	while(a[i]!='!')
	{
		if(a[i]>='a'&&a[i]<='z')
		a[i]=a[i]-32;
		fprintf(fp,"%c",a[i]);
		i++;
	}
	/* 
	Check:
	fp=fopen("D:\\test.txt","r");
	fgets(a,strlen(a)+1,fp);
	printf("%s\n",a);
	*/
	fclose(fp);
	return 0;
}
