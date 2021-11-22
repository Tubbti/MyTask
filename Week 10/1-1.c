#include <stdio.h>
int main(){
    int i,a[10];
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }//录入数据
    int t;
    for(i=0;i<5;i++){
        t=a[i];
        a[i]=a[9-i];
        a[9-i]=t;
    }//倒序排列
    int m=-1,k;
    for(i=0;i<10;i++){
        if(m<a[i]) {
            m=a[i];
            k=i;
        }
    }//找到最大值和下标
    printf("最大值是: %d,下标: %d\n",m,k);

}