#include <stdio.h> 
int main(){
    int i,j,l;
    int len=0;
    for(i=200;i<300;i++){
        for(j=2;j<i;j++){
            if(i%j==0) l=1;
        }
        if(l==0) len++;
        l=0;
    } //得到200-300的素数数量
    int a[len];
    int m=0;
    for(i=200;i<300;i++){
        for(j=2;j<i;j++){
            if(i%j==0) l=1;
        }
        if(l==0){
            a[m]=i;
            m++;
        }
        l=0;
    } //将素数存入数组a中
    int n;
    for(n=0;n<len;n++){
        if(n%4==0) printf("\n");
        printf("%3d\t",a[n]);
        }
}