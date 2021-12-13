
#include<stdio.h>
void number(char s[], int a[]){	
	char *p=s;
 	int count,i=0;  
	while(*p!='\0'){
  		while((*p<'0'||*p>'9') && (*p!='\0'))
   			p++;
 		count=0;
  		while(*p>='0'&&*p<='9'){
   			count=count*10+(*p-48);
  	 		p++;
 		}
  		a[i++]=count; 
	}
 	printf("共%d个数：",i);
 	for(i=0;a[i]!=0;i++) 
  		printf("%d  ",a[i]);
}
int main(){
	char s[100];	
	int a[10]={0};
 	gets(s);
 	number(s,a);
 	printf("\n");
 	return 0; 
}
