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
    long num;     //选手编号
    char name[20];  //选手姓名
    float grades[N];  //选手成绩
    double ave;    //平均成绩
    struct songer *next;   //   链表节点
} SONGER_MESSAGE;

SONGER_MESSAGE *head;
SONGER_MESSAGE *tail;

int n=0;
void creat();    //建立链表
void del();     //删除节点
void search();      //成绩查询
void print();       //输出链表
void rank();        //排序
void update();      //选手修改
void menu();        //菜单
void menu_select();     //菜单选择
void browse();      //选手信息浏览
void save();        //选手信息保存
void quit();        //退出

//browse 函数---------------------------------

void browse()
{
    SONGER_MESSAGE *p1;
    if(head == NULL&&tail == NULL)
    {

        printf("\n--------当前信息记录为空--------\n");
    }
    else
    {
        printf("\n--------你要浏览的选手信息如下--------\n");
        printf("--------|--------\n");
        printf("   编号  |  姓名  \n");
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

//search 函数---------------------------

void search()
{
    int c;
    printf("\n请选择查询内容: \n");
    printf("1.选手详细成绩查询  2.选手排名查询\n请输入您的选择：");
    scanf("%d",&c);
    switch(c)
    {
        case 1: system("cls"); print(); break;
        case 2: system("cls"); rank(); break;
    }
}

//print 函数-----------------------

void print()
{
    SONGER_MESSAGE * p1=(SONGER_MESSAGE*)malloc(LEN);
    int check=0,i;
    long seeknum;
    printf("\n请输入要查找的选手编号: ");
    scanf("%d",&seeknum);
    if(head==NULL&&tail==NULL)
    {
        printf("\n对不起，当前记录为空!\n");
    }
    else
    {
        p1=head;
        printf("\n--------你要找的选手成绩如下--------\n");
        printf("------|------|-----|----|----|----|----|----|----|----|----|----|----|----------|-------\n");
        printf("编号 | 姓名 | 成绩 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 平均成绩\n");
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
        printf("\n对不起，你查看的选手成绩不存在!\n");
    }
    getchar();
}

//menu_select 函数-----------------------------

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
            printf("你的输入有误，请重新输入: ");
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

//update 函数----------------------------------

void update()
{
    SONGER_MESSAGE *p1;
    int check=0;
    long updatenum;
    printf("\n 请输入要修改的选手编号:");
    scanf("%d",&updatenum);
    if(head==NULL&tail==NULL)
    {
        printf("\n--------当前信息记录为空--------\n");
    }
    else
    {
        p1=head;
        while(p1!=NULL)
        {
            if(p1->num==updatenum)
            {
                printf("\n-----------你要修改的选手信息如下-----------\n");
                printf("--------|--------\n");
                printf("  编号 | 姓名  \n");
                printf("--------|--------\n");
                printf("%-9d%-6s\n",p1->num,p1->name);
                printf("--------|--------\n");
                printf("\n-----------请重新输入此选手信息---------\n");
                check=1;
                printf("\n修改选手编号为: ");
                scanf("%d",&p1->num);
                printf("\n修改选手姓名为: ");
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
        printf("\n对不起,你要修改的选手信息不存在!\n");
    }
    getchar();
}

// save 函数--------------------------------------
void save()
{

}
