#include <stdio.h>
//�˵���������
int menu(void);
int printmenu();
int foundmenu();
int celemenu();
int revisemenu();
int rankmenu();
int infomenu();
//ϵͳ���˵�
int menu()
{

	int menusele;
	printf("\n\n");
    printf("\t ---------------------- \n");
	printf("\t*    ѧ���ɼ�����    *\n");
	printf("\t ---------------------- \n");
	printf("\t*  1.¼��ѧ����Ϣ      *\n");
	printf("\t ---------------------- \n");
	printf("\t*  2.�����ֺܷ�ƽ����  *\n");
	printf("\t ---------------------- \n");
	printf("\t*  3.��ѧ���ɼ�����    *\n");
	printf("\t ---------------------- \n");
	printf("\t*  4.��ѯѧ����Ϣ      *\n");
	printf("\t ---------------------- \n");
	printf("\t*  5.����ѧ����Ϣ      *\n");
	printf("\t ---------------------- \n");
	printf("\t*  0.�˳�              *\n");
	printf("\t ---------------------- \n");
	printf("\t����������ѡ��");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>5||menusele<0)
        printf("�����������������:");
    }while(menusele>5||menusele<0);

	return menusele;
}

//���㹦�ܲ˵�
int celemenu()
{
    int menusele;
    printf("\n\n");
    printf("\t -------------------------------- \n");
    printf("\t*    ����                        *\n");
    printf("\t -------------------------------- \n");
    printf("\t*  1.����ÿ��ѧ�����ֺܷ�ƽ����  *\n");
    printf("\t -------------------------------- \n");
	printf("\t*  2.���������Ŀ��ƽ����        *\n");
	printf("\t -------------------------------- \n");
	printf("\t*  0.������һ��˵�              *\n");
	printf("\t -------------------------------- \n");
	printf("\t����������ѡ��");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>2||menusele<0)
        printf("�����������������:");
    }while(menusele>2||menusele<0);
	return  menusele;
}

//�����ܲ˵�
int rankmenu()
{
    int menusele;
    printf("\n\n");
    printf("\t --------------------\n");
    printf("\t*    ����            *\n");
    printf("\t --------------------\n");
    printf("\t*  1.��ѧ���ܷ�����  *\n");
    printf("\t --------------------\n");
    printf("\t*  2.��ѧ��ѧ������  *\n");
    printf("\t --------------------\n");
	printf("\t*  3.��ѧ����������  *\n");
	printf("\t --------------------\n");
	printf("\t*  0.������һ��˵�  *\n");
	printf("\t --------------------\n");
	printf("\t����������ѡ��");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>3||menusele<0)
        printf("�����������������:");
    }while(menusele>3||menusele<0);
	return  menusele;
}
//��ѯ���ܲ˵�
int foundmenu()
{
    int menusele;
    printf("\n\n");
    printf("\t --------------------------------------\n");
    printf("\t*    ��ѯ                              *\n");
    printf("\t --------------------------------------\n");
    printf("\t*  1.��ѯ����ѧ���ɼ�                  *\n");
    printf("\t --------------------------------------\n");
	printf("\t*  2.��ѯĳ��ѧ���ɼ�                  *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  3.��ѯ�ܷ�С�ڵ���ĳֵ��ѧ����Ϣ    *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  4.��ѯ�ִܷ��ڵ���ĳֵ��ѧ����Ϣ    *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  5.��ѯƽ����С�ڵ���ĳֵ��ѧ����Ϣ  *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  6.��ѯƽ���ִ��ڵ���ĳֵ��ѧ����Ϣ  *\n");
	printf("\t --------------------------------------\n");
	printf("\t*  0.������һ��˵�                    *\n");
	printf("\t --------------------------------------\n");
	printf("\t����������ѡ��");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>6||menusele<0)
        printf("�����������������:");
    }while(menusele>6||menusele<0);
	return  menusele;
}
//������Ϣ���ܲ˵�
int revisemenu()
{
    int menusele;
    printf("\n\n");
    printf("\t --------------------\n");
    printf("\t*    ����            *\n");
    printf("\t --------------------\n");
    printf("\t*  1.����ѧ����Ϣ    *\n");
    printf("\t --------------------\n");
	printf("\t*  2.ɾ��ĳѧ����Ϣ  *\n");
	printf("\t --------------------\n");
	printf("\t*  3.�޸�ĳѧ����Ϣ  *\n");
	printf("\t --------------------\n");
	printf("\t*  0.������һ��˵�  *\n");
	printf("\t --------------------\n");
	printf("\t����������ѡ��");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>3||menusele<0)
        printf("�����������������:");
    }while(menusele>3||menusele<0);
	return  menusele;
}

int infomenu()
{
	int menusele;
	printf("\n\n");
	printf("\t --------------\n");
	printf("\t*  1.ѧ��ѧ��  *\n");
	printf("\t --------------\n");
	printf("\t*  2.ѧ������  *\n");
	printf("\t --------------\n");
	printf("\t*  3.��ѧ����  *\n");
	printf("\t --------------\n");
	printf("\t*  4.�ߵ���ѧ  *\n");
	printf("\t --------------\n");
	printf("\t*  5.��ѧӢ��  *\n");
	printf("\t --------------\n");
	printf("\t*  6.�ܷ�      *\n");
	printf("\t --------------\n");
	printf("\t*  7.ƽ����    *\n");
	printf("\t --------------\n");
	printf("\t*  0.�˳�      *\n");
	printf("\t --------------\n");
	printf("\t����������ѡ��");
	do
    {
        scanf("%d",&menusele);
        getchar();
        if(menusele>7||menusele<0)
        printf("�����������������:");
    }while(menusele>7||menusele<0);

	return menusele;
}








