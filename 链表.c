#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
//����ṹ��
typedef struct student
{
	//������
	char num[12];
	char name[20];
	float score1;
	float score2;
	float score3;
	float total;
	float ave;
	//ָ����
	struct student *next;
}STUDENT;
//��������ѧ����Ϣ
STUDENT *readList()
{
    int i;
	STUDENT *head,*p,*t;
	//����ͷ���
	head=(STUDENT *)malloc(sizeof(STUDENT));
	//����ͷ����Ƿ񴴽��ɹ�
	if(head==NULL)
	{
		printf("ͷ��㴴��ʧ��\n");
		exit(0);
	}
	//����ͷ�������
	head->next=NULL;
	p=head;
	//�����µĽڵ�
	for(i=1;i<=n;i++)
	{
	t=(STUDENT *)malloc(sizeof(STUDENT));
	//�����½���Ƿ񴴽��ɹ�
	if(t==NULL)
	{
		printf("�ý�㴴��ʧ��");
		exit(0);
	}
	//�����½�������
	printf("�밴˳�������%dλѧ����ѧ�š����������ĳɼ�����ѧ�ɼ���Ӣ��ɼ���",i);
	scanf("%s%s%f%f%f",t->num,t->name,&t->score1,&t->score2,&t->score3);
	//�����½���������
	t->next=p->next;
	p->next=t;
	p=t;
	}
	return(head);//��������ͷָ��
}
//�������ѧ����Ϣ
STUDENT printList(STUDENT *head)
{
    STUDENT *t;
    t=head->next;
    printf("ѧ��ѧ��\tѧ������\t��ѧ����\t�ߵ���ѧ\t��ѧӢ��\n");
    while(t->next!=NULL)
    {
        printf("%s\t%s\t%.1f\t%.1f\t%.1f\n",t->num,t->name,t->score1,t->score2,t->score3);
        t=t->next;
    }
}
//���һ����Ϣ
STUDENT print_one(STUDENT *t)
{
printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
}

