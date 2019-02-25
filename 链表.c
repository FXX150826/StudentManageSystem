#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
//定义结构体
typedef struct student
{
	//数据域
	char num[12];
	char name[20];
	float score1;
	float score2;
	float score3;
	float total;
	float ave;
	//指针域
	struct student *next;
}STUDENT;
//输入所有学生信息
STUDENT *readList()
{
    int i;
	STUDENT *head,*p,*t;
	//创建头结点
	head=(STUDENT *)malloc(sizeof(STUDENT));
	//检验头结点是否创建成功
	if(head==NULL)
	{
		printf("头结点创建失败\n");
		exit(0);
	}
	//输入头结点数据
	head->next=NULL;
	p=head;
	//创建新的节点
	for(i=1;i<=n;i++)
	{
	t=(STUDENT *)malloc(sizeof(STUDENT));
	//检验新结点是否创建成功
	if(t==NULL)
	{
		printf("该结点创建失败");
		exit(0);
	}
	//输入新结点的数据
	printf("请按顺序输入第%d位学生的学号、姓名、语文成绩、数学成绩、英语成绩：",i);
	scanf("%s%s%f%f%f",t->num,t->name,&t->score1,&t->score2,&t->score3);
	//将该新结点接入链表
	t->next=p->next;
	p->next=t;
	p=t;
	}
	return(head);//返回链表头指针
}
//输出所有学生信息
STUDENT printList(STUDENT *head)
{
    STUDENT *t;
    t=head->next;
    printf("学生学号\t学生姓名\t大学语文\t高等数学\t大学英语\n");
    while(t->next!=NULL)
    {
        printf("%s\t%s\t%.1f\t%.1f\t%.1f\n",t->num,t->name,t->score1,t->score2,t->score3);
        t=t->next;
    }
}
//输出一条信息
STUDENT print_one(STUDENT *t)
{
printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
}

