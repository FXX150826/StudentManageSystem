#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "功能.c"
#include "菜单.c"


void main()
{
    int ch,ch1,c=0,d=0;
    STUDENT *head=NULL,*t=NULL,*least=NULL,*p=NULL;
    int n;
    printf("\t\t\t\t\t******************************\n");
    printf("\t\t\t\t\t*                            *\n");
    printf("\t\t\t\t\t*    欢迎进入学生管理系统    *\n");
    printf("\t\t\t\t\t*                            *\n");
    printf("\t\t\t\t\t******************************\n");
    printf("请输入学生总人数：");
    scanf("%d",&n);
    getchar();
    while(1)
    {
        ch=menu();
        switch(ch)
        {
        case 1:
            printf("输入\n");
            head=readList(n);
            break;
        case 2:
            ch1=celemenu();
            switch(ch1)
            {
            case 1:
                printf("计算每个学生的总分和平均分\n");
                celestu(head);
                c=100;
                printList(head,ch*10+ch1+c);
                break;
            case 2:
                printf("计算各个科目的平均分\n");
                least=celesbj(head);
                if(least!=NULL)printList(least,ch*10+ch1);
                break;
            case 0:
                break;
            }
            break;
        case 3:

            ch1=rankmenu();
            switch(ch1)
            {
            case 1:
                printf("按学生总分排序\n");
                if(c==0)
                {
                    celestu(head);
                    c=100;
                }
                head=rank(head,ch*10+ch1+c);
                printList(head,ch*10+ch1);
                break;
            case 2:
                printf("按学生学号排序\n");
                head=rank(head,ch*10+ch1);
                printList(head,ch*10+ch1+c);
                break;
            case 3:
                printf("按学生姓名排序\n");
                head=rank(head,ch*10+ch1);
                printList(head,ch*10+ch1+c);
                break;
            case 0:
                break;
            }
            break;
        case 4:
            printf("查询\n");
            ch1=foundmenu();
            switch(ch1)
            {
            case 1:
                printf("查询所有学生成绩\n");
                printList(head,ch*10+ch1+c);
                if(least!=NULL)
                    printList(least,ch*10+ch1+200);
                break;
            case 2:
                printf("查询某个学生成绩\n");
                t=foundstu(head);
                if(t!=NULL)printList(t,ch*10+ch1+c);
                t=NULL;
                break;
            case 3:
                printf("查询总分小于等于某值的学生信息\n");
                printList(head,ch*10+ch1+c);
                break;
            case 4:
                printf("查询总分大于等于某值的学生信息\n");
                printList(head,ch*10+ch1+c);
                break;
            case 5:
                printf("查询平均分小于等于某值的学生信息\n");
                printList(head,ch*10+ch1+c);
                break;
            case 6:
                printf("查询平均分大于等于某值的学生信息\n");
                printList(head,ch*10+ch1+c);
                break;
            case 0:
                break;
            }
            break;
        case 5:
            printf("更改\n");
            ch1=revisemenu();
            switch(ch1)
            {
            case 1:
                printf("增加学生信息\n");
                head=revise(head,ch*10+ch1);
                printList(head,ch*10+ch1);
                c=0;
                break;
            case 2:
                printf("删除学生信息\n");
                head=revise(head,ch*10+ch1+c);
                printList(head,ch*10+ch1+c);
                break;
            case 3:
                printf("修改学生信息\n");
                head=revise(head,ch*10+ch1+c);
                break;
            case 0:
                break;
            }
            break;
        case 0:
            printf("退出\n");
            exit(0);
            break;
        }
    }
}
