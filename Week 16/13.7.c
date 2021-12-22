#include <stdio.h>
#include <stdlib.h>
struct student
{
	int num;
	char name[10];
	int score[3];
	float ave;
}stu[5],stu0; 
int main()
{
	FILE *fp1,*fp2;
	int i,j,k;
    fp1=fopen("D:\\stud.txt","r");
    for(i=0;i<5;i++)
	{
		fscanf(fp1,"%d %s %d %d %d %f",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].ave);
    }
    fclose(fp1);
    fp2=fopen("D:\\stu_sort.txt","w");
	for(i=0;i<4;i++)
	{
		k=i;
		for(j=i+1;j<5;j++)
			if(stu[j].ave<stu[k].ave)
				k=j;
		if(i!=k)
		{
			stu0=stu[i];
			stu[i]=stu[k];
			stu[k]=stu0;
		}
	}
	fprintf(fp2,"Num  Name  Score1 Score2 Score3 Average_Score\n");
	for(i=0;i<5;i++)
	{
		fprintf(fp2,"%-6d %-8s ",stu[i].num,stu[i].name);
		for(j=0;j<3;j++) fprintf(fp2,"%-6d",stu[i].score[j]);
		fprintf(fp2,"%5.1f\n",stu[i].ave);
	}
	fclose(fp2);
} 
