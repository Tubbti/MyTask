#include<stdio.h>
struct student
{
	int num;
	char name[10];
	int score[3];
	float ave;
} stu[5];
int main()
{
	FILE *fp;
	int i,j,sum=0;
	//In Linux fp=fopen("home/tubbti/stud.txt","w");
	fp=fopen("D:\\stud.txt","w");
	for (i=0; i<5; i++) {
        stu[i].ave = 0;
		printf("Print your Num , Name and Scores:\n");
        scanf("%d %s", &stu[i].num, &stu[i].name);
		for(j=0;j<3;j++) 
		{
			scanf("%d",&stu[i].score[j]);
			stu[i].ave +=stu[i].score[j];
		}
		stu[i].ave /=3;
	}  
	for(i=0;i<5;i++)
	{
		fprintf(fp,"%-6d %-8s ",stu[i].num,stu[i].name);
		for(j=0;j<3;j++) fprintf(fp,"%-8d",stu[i].score[j]);
		fprintf(fp,"%5.1f\n",stu[i].ave);
	}
	fclose(fp);
}
