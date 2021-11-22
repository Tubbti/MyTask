#include <stdio.h>
int main(){
    int a[5][3];
    int sum=0;
    float b[5];
    for(int i=0;i<5;i++){
        printf("开始输入第%d位同学的成绩:\n",i+1);
        for(int j=0;j<3;j++){
            printf("开始输入该同学第%d门成绩:\n",j+1);
            scanf("%d",&a[i][j]);
            sum+=a[i][j];
        }
        b[i]=sum/3;
        sum=0;
    }
    int s=0,max=-1,min=101;
    for(int j=0;j<3;j++){
        for(int i=0;i<5;i++){
            if(a[i][j]>max) max=a[i][j];
            if(a[i][j]<min) min=a[i][j];
            s+=a[i][j];
        }
    printf("第%d门课 均分: %f 最高分: %d 最低分: %d\n",j+1,(float)s/5,max,min);
    s=0;
    max=-1;
    min=101;
    }
    for(int i=0;i<5;i++)
	{
        printf("第%d位同学的平均分为:%.2f\n",i+1,b[i]);
    }
}