#include <stdio.h>
#define N 3
int main(){
    int a[N][N];
    int i,j,flag=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    } //读入数组
    for(i=0;i<N;i++){
        int max=a[i][0];
        int mj=0;
        for(j=0;j<N;j++)
        {
            if(a[i][j]>max){
            max=a[i][j];
            mj=j;
            }
        }
        for(int k=0;k<N;k++)
        {   
            if(max>a[k][mj])
            {
                flag=0;
                break;
            }
            else flag=1;
        }
        if(flag==1){
        printf("find: a[%d][%d]=%d",i,mj,max);
        break;
        }
    }
    if(flag==0) printf("没有鞍点\n");
}