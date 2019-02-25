#include <stdio.h>
//菜单函数声明
int menu(void);
int printmenu();
int foundmenu();
int celemenu();
int revisemenu();
int rankmenu();
int infomenu();
//系统主菜单
int menu()
{

	int menusele;
	printf("\n\n");
    printf("\t ---------------------- \n");
	printf("\t*    学生成绩管理：    *\n");
	printf("\t ---------------------- \n");
	printf("\t*  1.录入学生信息      *\n");
	printf("\t ---------------------- \n");
	printf("\t*  2.计算总分和平均分  *\n");
	printf("\t ---------------------- \n");
	printf("\t*  3.按学生成绩排序    *\n");
	printf("\t ---------------------- \n");
	printf("\t*  4.查询学生信息      *\n");
	printf("\t ---------------------- \n");
	printf("\t*  5.更改学生信息      *\n");
	printf("\t ---------------------- \n");
	printf("\t*  0.退出              *\n");
	printf("\t ---------------------- \n");
	printf("\t请输入您的选择：");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>5||menusele<0)
        printf("输入错误请重新输入:");
    }while(menusele>5||menusele<0);

	return menusele;
}

//计算功能菜单
int celemenu()
{
    int menusele;
    printf("\n\n");
    printf("\t -------------------------------- \n");
    printf("\t*    计算                        *\n");
    printf("\t -------------------------------- \n");
    printf("\t*  1.计算每个学生的总分和平均分  *\n");
    printf("\t -------------------------------- \n");
	printf("\t*  2.计算各个科目的平均分        *\n");
	printf("\t -------------------------------- \n");
	printf("\t*  0.返回上一层菜单              *\n");
	printf("\t -------------------------------- \n");
	printf("\t请输入您的选择：");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>2||menusele<0)
        printf("输入错误请重新输入:");
    }while(menusele>2||menusele<0);
	return  menusele;
}

//排序功能菜单
int rankmenu()
{
    int menusele;
    printf("\n\n");
    printf("\t --------------------\n");
    printf("\t*    排序            *\n");
    printf("\t --------------------\n");
    printf("\t*  1.按学生总分排序  *\n");
    printf("\t --------------------\n");
    printf("\t*  2.按学生学号排序  *\n");
    printf("\t --------------------\n");
	printf("\t*  3.按学生姓名排序  *\n");
	printf("\t --------------------\n");
	printf("\t*  0.返回上一层菜单  *\n");
	printf("\t --------------------\n");
	printf("\t请输入您的选择：");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>3||menusele<0)
        printf("输入错误请重新输入:");
    }while(menusele>3||menusele<0);
	return  menusele;
}
//查询功能菜单
int foundmenu()
{
    int menusele;
    printf("\n\n");
    printf("\t --------------------------------------\n");
    printf("\t*    查询                              *\n");
    printf("\t --------------------------------------\n");
    printf("\t*  1.查询所有学生成绩                  *\n");
    printf("\t --------------------------------------\n");
	printf("\t*  2.查询某个学生成绩                  *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  3.查询总分小于等于某值的学生信息    *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  4.查询总分大于等于某值得学生信息    *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  5.查询平均分小于等于某值得学生信息  *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  6.查询平均分大于等于某值得学生信息  *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  0.返回上一层菜单                    *\n");
	printf("\t --------------------------------------\n");
	printf("\t请输入您的选择：");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>6||menusele<0)
        printf("输入错误请重新输入:");
    }while(menusele>6||menusele<0);
	return  menusele;
}
//更改信息功能菜单
int revisemenu()
{
    int menusele;
    printf("\n\n");
    printf("\t --------------------\n");
    printf("\t*    更改            *\n");
    printf("\t --------------------\n");
    printf("\t*  1.增加学生信息    *\n");
    printf("\t --------------------\n");
	printf("\t*  2.删除某学生信息  *\n");
	printf("\t --------------------\n");
	printf("\t*  3.修改某学生信息  *\n");
	printf("\t --------------------\n");
	printf("\t*  0.返回上一层菜单  *\n");
	printf("\t --------------------\n");
	printf("\t请输入您的选择：");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>3||menusele<0)
        printf("输入错误请重新输入:");
    }while(menusele>3||menusele<0);
	return  menusele;
}

int infomenu()
{
	int menusele;
	printf("\n\n");
	printf("\t --------------\n");
	printf("\t*  1.学生学号  *\n");
	printf("\t --------------\n");
	printf("\t*  2.学生姓名  *\n");
	printf("\t --------------\n");
	printf("\t*  3.大学语文  *\n");
	printf("\t --------------\n");
	printf("\t*  4.高等数学  *\n");
	printf("\t --------------\n");
	printf("\t*  5.大学英语  *\n");
	printf("\t --------------\n");
	printf("\t*  6.总分      *\n");
	printf("\t --------------\n");
	printf("\t*  7.平均分    *\n");
	printf("\t --------------\n");
	printf("\t*  0.退出      *\n");
	printf("\t --------------\n");
	printf("\t请输入您的选择：");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>7||menusele<0)
        printf("输入错误请重新输入:");
    }while(menusele>7||menusele<0);

	return menusele;
}








