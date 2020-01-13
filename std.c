#include<stdio.h>

struct student
{
	char name[10];
	char number[10];
	int grade;

};




void printRank(struct student a[],int i){

	struct student first;
	struct student last;

	first = a[0];
	last = a[0];


	for (int k = 1; k < i ; ++k)
	{
		if (a[k].grade > first.grade)
		{
			first = a[k];
		}

		if (a[k].grade < last.grade)
		{
			last = a[k];
		}
	}

	printf("%s %s\n",first.name,first.number );

	printf("%s %s\n",last.name,last.number );


}

int main(){

	printf("请输入学生数量：\n");
	int n;
	scanf("%d",&n);

	struct student stds[n];

	// printf("请录入成绩：\n");
	for (int i = 0; i < n; ++i)
	{
		// printf("请输入第%d个同学的姓名 学号 成绩\n",(i+1));
		scanf("%s %s %d",stds[i].name,stds[i].number,&stds[i].grade);
	}

	printRank(stds,n);

	return 0;
}