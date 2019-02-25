//#include "����.c"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


//����ṹ��
typedef struct student
{
	//������
	char num[20];
	char name[20];
	float score1;
	float score2;
	float score3;
	float total;
	float ave;
	//ָ����
	struct student *next;
}STUDENT;
STUDENT *readList(int n);
void celestu(STUDENT *head);
STUDENT *celesbj(STUDENT *head);
STUDENT *foundstu(STUDENT *head);
STUDENT *revise(STUDENT *head,int c);
STUDENT printList(STUDENT *head,int c);
//����
//��������ѧ����Ϣ
STUDENT *readList(int n)
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
	t->next=NULL;
	p->next=t;
	p=t;
	}

	return(head);//��������ͷָ��
}
//����
//����ÿ��ѧ�����ֺܷ�ƽ����
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
//���������Ŀ��ƽ����
STUDENT *celesbj(STUDENT *head)
{
    STUDENT *t,*p;
    int k=0;
    t=(STUDENT *)malloc(sizeof(STUDENT));//����������ڴ洢����ƽ����
    if(t==NULL)
	{
		printf("ͷ��㴴��ʧ��\n");
		exit(0);
	}
	p=head;
    strcpy(t->name,"ƽ����");
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


//����

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
                    m=strcmp(max->num,p->next->num);//��ѧ������
                else if(c==33)
                    m=strcmp(max->name,p->next->name);//����������
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

//��ѯ
//��ѯĳ��ѧ���ɼ�
STUDENT *foundstu(STUDENT *head)
{
    int c=1;
    STUDENT *t;
    char num[20];
    printf("�������ѧ��ѧ��:");
    scanf("%s",num);
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
        c=strcmp(num,t->num);//�Ƚ�ѧ��
        if(c==0)
        {
            return (t);
        }
    }
    if(c!=0)
        {
            printf("�Ҳ�����ѧ����Ϣ\n");
            return NULL;
        }
}

//����
STUDENT *revise(STUDENT *head,int c)
{
    STUDENT *t,*p;
    float *m;char *q;
    int n;
    char num[13]="1";
    if(c==51)//����ѧ����Ϣ
    {
        printf("��������Ҫ���ӵ�ѧ������:");
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
    else if(c==52||c==53||c==153||c==152)//�޸ĺ�ɾ��ѧ����Ϣ
    {
        t=head;
        p=head;

        while(1)
        {
            if(c==53)
            printf("��������Ҫ�޸���Ϣ��ѧ��ѧ��");
            else if(c==52)
            printf("��������Ҫɾ����Ϣ��ѧ��ѧ��");
            printf("(����0�˳�����):");
            scanf("%s",num);//¼����Ҫ������ѧ��ѧ��
            if(strcmp(num,"0")==0)
                break;
            while(t->next!=NULL)
            {
                t=t->next;
                if(strcmp(num,t->num)==0)//��ѧ������ѧ����Ϣ
                {
                    if(c==52)//ɾ��
                    {
                        p->next=t->next;
                        free(t);//�ͷű�ɾ��ѧ����Ϣ���ڴ�
                    }
                    else if(c==53||c==153)//�޸�
                    {
                        c=c+200;
                        printList(t,c);
                        printf("����Ϊ��Ŀ����ţ�\n");
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
                        printf("�������޸ĺ����Ϣ��");
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
                            printf("�޸ĺ��ѧ����Ϣ���£�\n");
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
//���
STUDENT printList(STUDENT *head,int c)
{
    STUDENT *t;
    t=head;
    int n=0;
    //�������ѧ����Ϣ
    if(c==11||c==21||c==41||c==32||c==33||c==51||c==52||c==53)
    {
        t=head;
        printf("ѧ��ѧ��\tѧ������\t��ѧ����\t�ߵ���ѧ\t��ѧӢ��\n");
        while(t->next!=NULL)
        {
            t=t->next;
            printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3);
        }
    }
    else if(c==121||c==122||c==31||c==132||c==133||c==141||c==152||c==153)
    {
        t=head;
        printf("ѧ��ѧ��\tѧ������\t��ѧ����\t�ߵ���ѧ\t��ѧӢ��\t    �ܷ�\t  ƽ����\n");
        while(t->next!=NULL)
        {
            t=t->next;
            printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
        }
    }
    //���ĳһѧ����Ϣ
    else if(c==22||c==42||c==241||c==253)
    {//δ�����ܷ�ƽ����
     if(c!=241)printf("ѧ��ѧ��\tѧ������\t��ѧ����\t�ߵ���ѧ\t��ѧӢ��\n");
     printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3);
    }
    else if(c==42||c==53||c==142||c==353)
    {//�Ѽ����ܷ�ƽ����
        printf("ѧ��ѧ��\tѧ������\t��ѧ����\t�ߵ���ѧ\t��ѧӢ��\t    �ܷ�\t  ƽ����\n");
        printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
    }
    //����ֻܷ�ƽ������ĳһ��Χ�ڵ�ѧ����Ϣ
    else if(c==43||c==44||c==45||c==46||c==143||c==144||c==145||c==146)
    {
        int X;
        printf("������X��ֵ:");
        scanf("%d",&X);
        printf("ѧ��ѧ��\tѧ������\t��ѧ����\t�ߵ���ѧ\t��ѧӢ��\t    �ܷ�\t  ƽ����\n");
        if(c==43||c==44||c==45||c==46)
            celestu(head);
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
            if(c==43||c==143)//����ܷ�С��ĳֵ��ѧ����Ϣ
            {
                if(t->total<=X)
                {
                    n++;
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }
            }
            else if(c==44||c==144)//����ִܷ���ĳֵ��ѧ����Ϣ
            {
                if(t->total>=X)
                {
                    n++;
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }

            }
            else if(c==45||c==145)//���ƽ����С��ĳֵ��ѧ����Ϣ
            {
                if(t->ave<=X)
                {
                    n++;
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }

            }
            else if(c==46||c==146)//���ƽ���ִ���ĳֵ��ѧ����Ϣ
            {
                if(t->ave>=X)
                {
                    printf("%8s\t%8s\t%8.1f\t%8.1f\t%8.1f\t%8.1f\t%8.1f\n",t->num,t->name,t->score1,t->score2,t->score3,t->total,t->ave);
                }

            }
        }

    }
}

