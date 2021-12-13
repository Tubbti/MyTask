#include <stdio.h>
#include <string.h>
#define max 1000
int next[max];
int s_len;
char str[max],str_t[max];
void get_next()
{
	int i;
	next[0]=-1;
	for(i=1;i<s_len;++i)
	{
		int j=next[j];
		while(str_t[i]!=str_t[j+1]&&j!=-1)
		j=next[j];
		if(str_t[i]==str_t[j+1])
		next[i]=j+1;
		else
		next[i]=-1;
	}
} 
int kmp(char *str,char *str_t)
{
	int i;
	int len=strlen(str);
	int j;
	int cnt=0;
	s_len=strlen(str_t);
	get_next();
	j=-1;
	for(i=0;i<len;++i)
	{
		if(str[i]!=str_t[j+1]&&j!=-1)
	    j=next[j];
    	if(str[i]==str_t[j+1])
	    {
            ++j;  
	    }
	    if(j==s_len-1)
	    {
	    	cnt++;
    		j=next[j]; 
	    }
	}
	return cnt;
}
int main()
{
	scanf("%s %s",str,str_t);
	printf("%d\n",kmp(str,str_t));

} 










