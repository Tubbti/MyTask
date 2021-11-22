#include <stdio.h>
int main(){
    int i,s=0;
    int a[20]={1,1};
    for(i=2;i<20;i++){
        a[i]=a[i-1]+a[i-2];
    }
    for(i=0;i<20;i++){
        if(i%4==0) printf("\n");
        printf("%8d",a[i]);
        s+=a[i];
    }
    printf("\ns=%d",s);
}