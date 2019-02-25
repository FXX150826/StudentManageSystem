//#include "链表.c"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


//定义结构体
typedef struct student
{
	//数据域
	char num[20];
	char name[20];
	float score1;
	float score2;
	float score3;
	float total;
	float ave;
	//指针域
	struct student *next;
}STUDENT;
STUDENT *readList(int n);
void celestu(STUDENT *head);
STUDENT *celesbj(STUDENT *head);
STUDENT *foundstu(STUDENT *head);
STUDENT *revise(STUDENT *head,int c);
STUDENT printList(STUDENT *head,int c);
//输入
//输入所有学生信息
STUDENT *readList(int n)
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
	t->next=NULL;
	p->next=t;
	p=t;
	}

	return(head);//返回链表头指针
}
//计算
//计算每个学生的总分和平均分
void celestu(STUDENT *head)
{
    STUDENT *t;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
        t->total=t->score1+t->score2+t->score3;
        t->ave=t->total/3;
    }
}
//计算各个科目的平均分
STUDENT *celesbj(STUDENT *head)
{
    STUDENT *t,*p;
    int k=0;
    t=(STUDENT *)malloc(sizeof(STUDENT));//新增结点用于存储各科平均分
    if(t==NULL)
	{
		printf("头结点创建失败\n");
		exit(0);
	}
	p=head;
    strcpy(t->name,"平均分");
    strcpy(t->num,"     \\\\ ");
    t->score1=t->score2=t->score3=0;
    while(p->next!=NULL)
    {
        p=p->next;
        t->score1=t->score1+p->score1;
        t->score2=t->score2+p->score2;
        t->score3=t->score3+p->score3;
        k++;
    }
    t->score1=t->score1/k;
    t->score2=t->score2/k;
    t->score3=t->score3/k;
    t->total=0;
    t->ave=0;
    return (t);
}


//排序

    STUDENT *rank(STUDENT *head,int c)
    {
        STUDENT *f=NULL,*t=NULL,*max=NULL,*maxbf=NULL,*p,*h;
        float m;
        h=head->next;
        while(h!=NULL)
        {
            for(p=h,max=h;p->next!=NULL;p=p->next)
            {
                if(c==32)
                    m=strcmp(max->num,p->next->num);//按学号排序
                else if(c==33)
                    m=strcmp(max->name,p->next->name);//按姓名排序
                else if(c==31||c==131)
                    m=p->next->total-max->total;
                if(m>0)
                {
                    maxbf=p;
                    max=p->next;
                }
            }
            if(f==NULL)
            {
                f=max;
                t=max;
            }
            else
            {
                t->next=max;
                t=max;
            }
            if(max==h)
            {
                h=t->next;
            }
            else
            {
                maxbf->next=max->next;
            }
        }
        t->next=NULL;
        head->next=f;
        return head;
    }

//查询
//查询某个学生成绩
STUDENT *foundstu(STUDENT *head)
{
    int c=1;
    STUDENT *t;
    char num[20];
    printf("请输入该学生学号:");
    scanf("%s",num);
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
        c=strcmp(num,t->num);//比较学号
        if(c==0)
        {
            return (t);
        }
    }
    if(c!=0)
        {
            printf("找不到该学生信息\n");
            return NULL;
        }
}

//更改
STUDENT *revise(STUDENT *head,int c)
{
    STUDENT *t,*p;
    float *m;char *q;
    int n;
    char num[13]="1";
    if(c==51)//增加学生信息
    {
        printf("请输入需要增加的学生人数:");
        scanf("%d",&n);
        t=readList(n);
        p=t;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=head->next;
        head->next=t->next;
    }
    else if(c==52||c==53||c==153||c==152)//修改和删除学生信息
    {
        t=head;
        p=head;

        while(1)
        {
            if(c==53)
            printf("请输入需要修改信息的学生学号");
            else if(c==52)
            printf("请输入需要删除信息的学生学号");
            printf("(输入0退出更改):");
            scanf("%s",num);//录入需要操作的学生学号
            if(strcmp(num,"0")==0)
                break;
            while(t->next!=NULL)
            {
                t=t->next;
                if(strcmp(num,t->num)==0)//按学号搜索学生信息
                {
                    if(c==52)//删除
                    {
                        p->next=t->next;
                        free(t);//释放被删除学生信息的内存
                    }
                    else if(c==53||c==153)//修改
                    {
                        c=c+200;
                        printList(t,c);
                        printf("以下为项目的序号：\n");
                        n=infomenu();
                        switch(n)
                        {
                            case 1:
                                q=t->num;
                                break;
                            case 2:
                                q=t->name;
                                break;
                            case 3:
                                m=&t->score1;
                                break;
                            case 4:
                                m=&t->score2;
                                break;
                            case 5:
                                m=&t->score3;
                                break;
                            case 6:
                                m=&t->total;
                                break;
                            case 7:
                                m=&t->ave;
                                break;
                            case 0:
                                break;
                        }
                        printf("请输入修改后的信息：");
                        if(n!=0)
                        {
                            if(n==1||n==2)
                            {
                                scanf("%s",p);
                                getchar();
                            }
                            else if(n>2)
                            {
                                scanf("%f",m);
                                getchar();
                            }
                            printf("修改后该学生信息如下：\n");
                            printList(t,c);
                        }
                        else if(n==0)
                            break;
                    }
                }
                p=p->next;
            }
        }

    }
    return head;
}
//输出
STUDENT printList(STUDENT *head,int c)
{
    STUDENT *t;
    t=head;
    int n=0;
    //输出所有学生信息
    if(c==11||c==21||c==41||c==32||c==33||c==51||c==52||c==53)
    {
        t=head;
        printf("学生学号\t学生姓名\t大学语文\t高等数学\t大学英语\n");
        while(t->next!=NULL)
        {
            t=t->next;
            printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3);
        }
    }
    else if(c==121||c==122||c==31||c==132||c==133||c==141||c==152||c==153)
    {
        t=head;
        printf("学生学号\t学生姓名\t大学语文\t高等数学\t大学英语\t    总分\t  平均分\n");
        while(t->next!=NULL)
        {
            t=t->next;
            printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
        }
    }
    //输出某一学生信息
    else if(c==22||c==42||c==241||c==253)
    {//未计算总分平均分
     if(c!=241)printf("学生学号\t学生姓名\t大学语文\t高等数学\t大学英语\n");
     printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3);
    }
    else if(c==42||c==53||c==142||c==353)
    {//已计算总分平均分
        printf("学生学号\t学生姓名\t大学语文\t高等数学\t大学英语\t    总分\t  平均分\n");
        printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
    }
    //输出总分或平均分在某一范围内的学生信息
    else if(c==43||c==44||c==45||c==46||c==143||c==144||c==145||c==146)
    {
        int X;
        printf("请输入X的值:");
        scanf("%d",&X);
        printf("学生学号\t学生姓名\t大学语文\t高等数学\t大学英语\t    总分\t  平均分\n");
        if(c==43||c==44||c==45||c==46)
            celestu(head);
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
            if(c==43||c==143)//输出总分小于某值得学生信息
            {
                if(t->total<=X)
                {
                    n++;
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }
            }
            else if(c==44||c==144)//输出总分大于某值得学生信息
            {
                if(t->total>=X)
                {
                    n++;
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }

            }
            else if(c==45||c==145)//输出平均分小于某值得学生信息
            {
                if(t->ave<=X)
                {
                    n++;
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }

            }
            else if(c==46||c==146)//输出平均分大于某值得学生信息
            {
                if(t->ave>=X)
                {
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }

            }
        }

    }
}

