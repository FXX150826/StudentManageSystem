#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "����.c"
#include "�˵�.c"


void main()
{
    int ch,ch1,c=0,d=0;
    STUDENT *head=NULL,*t=NULL,*least=NULL,*p=NULL;
    int n;
    printf("\t\t\t\t\t******************************\n");
    printf("\t\t\t\t\t*                            *\n");
    printf("\t\t\t\t\t*    ��ӭ����ѧ������ϵͳ    *\n");
    printf("\t\t\t\t\t*                            *\n");
    printf("\t\t\t\t\t******************************\n");
    printf("������ѧ����������");
    scanf("%d",&n);
    getchar();
    while(1)
    {
        ch=menu();
        switch(ch)
        {
        case 1:
            printf("����\n");
            head=readList(n);
            break;
        case 2:
            ch1=celemenu();
            switch(ch1)
            {
            case 1:
                printf("����ÿ��ѧ�����ֺܷ�ƽ����\n");
                celestu(head);
                c=100;
                printList(head,ch*10+ch1+c);
                break;
            case 2:
                printf("���������Ŀ��ƽ����\n");
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
                printf("��ѧ���ܷ�����\n");
                if(c==0)
                {
                    celestu(head);
                    c=100;
                }
                head=rank(head,ch*10+ch1+c);
                printList(head,ch*10+ch1);
                break;
            case 2:
                printf("��ѧ��ѧ������\n");
                head=rank(head,ch*10+ch1);
                printList(head,ch*10+ch1+c);
                break;
            case 3:
                printf("��ѧ����������\n");
                head=rank(head,ch*10+ch1);
                printList(head,ch*10+ch1+c);
                break;
            case 0:
                break;
            }
            break;
        case 4:
            printf("��ѯ\n");
            ch1=foundmenu();
            switch(ch1)
            {
            case 1:
                printf("��ѯ����ѧ���ɼ�\n");
                printList(head,ch*10+ch1+c);
                if(least!=NULL)
                    printList(least,ch*10+ch1+200);
                break;
            case 2:
                printf("��ѯĳ��ѧ���ɼ�\n");
                t=foundstu(head);
                if(t!=NULL)printList(t,ch*10+ch1+c);
                t=NULL;
                break;
            case 3:
                printf("��ѯ�ܷ�С�ڵ���ĳֵ��ѧ����Ϣ\n");
                printList(head,ch*10+ch1+c);
                break;
            case 4:
                printf("��ѯ�ִܷ��ڵ���ĳֵ��ѧ����Ϣ\n");
                printList(head,ch*10+ch1+c);
                break;
            case 5:
                printf("��ѯƽ����С�ڵ���ĳֵ��ѧ����Ϣ\n");
                printList(head,ch*10+ch1+c);
                break;
            case 6:
                printf("��ѯƽ���ִ��ڵ���ĳֵ��ѧ����Ϣ\n");
                printList(head,ch*10+ch1+c);
                break;
            case 0:
                break;
            }
            break;
        case 5:
            printf("����\n");
            ch1=revisemenu();
            switch(ch1)
            {
            case 1:
                printf("����ѧ����Ϣ\n");
                head=revise(head,ch*10+ch1);
                printList(head,ch*10+ch1);
                c=0;
                break;
            case 2:
                printf("ɾ��ѧ����Ϣ\n");
                head=revise(head,ch*10+ch1+c);
                printList(head,ch*10+ch1+c);
                break;
            case 3:
                printf("�޸�ѧ����Ϣ\n");
                head=revise(head,ch*10+ch1+c);
                break;
            case 0:
                break;
            }
            break;
        case 0:
            printf("�˳�\n");
            exit(0);
            break;
        }
    }
}
