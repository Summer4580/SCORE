#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<Windows.h>
#include<time.h>
#define LEN sizeof(SONGER_MESSAGE)
#define N 10;

struct tm *ptr;

typedef struct{
    long num;     //ѡ�ֱ��
    char name[20];  //ѡ������
    float grades[N];  //ѡ�ֳɼ�
    double ave;    //ƽ���ɼ�
    struct songer *next;   //   ����ڵ�
} SONGER_MESSAGE;

SONGER_MESSAGE *head;
SONGER_MESSAGE *tail;

int n=0;
void creat();    //��������
void del();     //ɾ���ڵ�
void search();      //�ɼ���ѯ
void print();       //�������
void rank();        //����
void update();      //ѡ���޸�
void menu();        //�˵�
void menu_select();     //�˵�ѡ��
void browse();      //ѡ����Ϣ���
void save();        //ѡ����Ϣ����
void quit();        //�˳�

//browse ����---------------------------------

void browse()
{
    SONGER_MESSAGE *p1;
    if(head == NULL&&tail == NULL)
    {

        printf("\n--------��ǰ��Ϣ��¼Ϊ��--------\n");
    }
    else
    {
        printf("\n--------��Ҫ�����ѡ����Ϣ����--------\n");
        printf("--------|--------\n");
        printf("   ���  |  ����  \n");
        p1=head;
        while(p1!=NULL)
        {
            printf("--------|--------\n")
            printf("%-9d%-6s\n",pq->num.p1->name);
            p1=p1->nest;
        }
        printf("--------|--------\n");
    }
}

//search ����---------------------------

void search()
{
    int c;
    printf("\n��ѡ���ѯ����: \n");
    printf("1.ѡ����ϸ�ɼ���ѯ  2.ѡ��������ѯ\n����������ѡ��");
    scanf("%d",&c);
    switch(c)
    {
        case 1: system("cls"); print(); break;
        case 2: system("cls"); rank(); break;
    }
}

//print ����-----------------------

void print()
{
    SONGER_MESSAGE * p1=(SONGER_MESSAGE*)malloc(LEN);
    int check=0,i;
    long seeknum;
    printf("\n������Ҫ���ҵ�ѡ�ֱ��: ");
    scanf("%d",&seeknum);
    if(head==NULL&&tail==NULL)
    {
        printf("\n�Բ��𣬵�ǰ��¼Ϊ��!\n");
    }
    else
    {
        p1=head;
        printf("\n--------��Ҫ�ҵ�ѡ�ֳɼ�����--------\n");
        printf("------|------|-----|----|----|----|----|----|----|----|----|----|----|----------|-------\n");
        printf("��� | ���� | �ɼ� | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | ƽ���ɼ�\n");
        printf("------|------|-----|----|----|----|----|----|----|----|----|----|----|----------|-------\n");
        while(p1!=NULL)
        {

            if(p1->num == seeknum)
            {
                printf("%-7d%-6s",p1->num,p1->name);
                printf("     ");
                for(i=0;i<N;i++)
                {
                    printf("%.1f",p1->grades[i]);
                }
                printf("%-6.2lf\n",p1->ave);
                check=1;
                getchar();
                return ;
            }
            else
            {
                p1=p1->next;
            }
        }
    }
    if(head!=NULL&check==0)
    {
        printf("\n�Բ�����鿴��ѡ�ֳɼ�������!\n");
    }
    getchar();
}

//menu_select ����-----------------------------

void menu_select()
{
    char s[100];
    int c;
    gets(s);
    while(1)
    {
        c=atoi(s);
        if(c<1||c>7)
        {
            printf("���������������������: ");
            gets(s);
        }
        else break;
    }
    switch(c)
    {
        case 1 : system("cls"); browse(); break;
        case 2 : system("cls"); creaat(); break;
        case 3 : system("cls"); save(); break;
        case 4 : system("cls"); search(); break;
        case 5 : syetem("cls"); update(); break;
        case 6 : system("cls"); del(); break;
        case 7 : system("cls"); quit(); return ; break;
        default : break;
    }
    getchar();
    system("cls");
    menu();
    menu_select();
}

//update ����----------------------------------

void update()
{
    SONGER_MESSAGE *p1;
    int check=0;
    long updatenum;
    printf("\n ������Ҫ�޸ĵ�ѡ�ֱ��:");
    scanf("%d",&updatenum);
    if(head==NULL&tail==NULL)
    {
        printf("\n--------��ǰ��Ϣ��¼Ϊ��--------\n");
    }
    else
    {
        p1=head;
        while(p1!=NULL)
        {
            if(p1->num==updatenum)
            {
                printf("\n-----------��Ҫ�޸ĵ�ѡ����Ϣ����-----------\n");
                printf("--------|--------\n");
                printf("  ��� | ����  \n");
                printf("--------|--------\n");
                printf("%-9d%-6s\n",p1->num,p1->name);
                printf("--------|--------\n");
                printf("\n-----------�����������ѡ����Ϣ---------\n");
                check=1;
                printf("\n�޸�ѡ�ֱ��Ϊ: ");
                scanf("%d",&p1->num);
                printf("\n�޸�ѡ������Ϊ: ");
                scanf("%s",p1->name);
                return ;
            }
            else
            {
               p1=p1->next;
            }
        }
    }
    if(head!=NULL&&check==0)
    {
        printf("\n�Բ���,��Ҫ�޸ĵ�ѡ����Ϣ������!\n");
    }
    getchar();
}

// save ����--------------------------------------
void save()
{

}
