#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(SONGER_MESSAGE)
#define N 10;

struct tm *ptr;

typedef struct{
    long num;     //选手编号
    char name[20];  //选手姓名
    float grades[10];  //选手成绩
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
//void rank();        //排序
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
            printf("--------|--------\n");
            printf("%-9d%-6s\n",p1->num,p1->name);
            p1=p1->next;
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
        case 1: /*system("cls");*/ print(); break;
        case 2: /*system("cls");*/ /*rank();*/ break;
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
        printf("编号 | 姓名 | 成绩 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 平均成绩\n");
        printf("------|------|-----|----|----|----|----|----|----|----|----|----|----|----------|-------\n");
        while(p1!=NULL)
        {

            if(p1->num == seeknum)
            {
                printf("%-7d%-6s",p1->num,p1->name);
                printf("       ");
                for(i=0;i<10;i++)
                {
                    printf("%.1f  ",p1->grades[i]);
                }
                printf("\t\t %-6.2lf\n",p1->ave);
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
    if(head!=NULL&&check==0)
    {
        printf("\n对不起，你查看的选手成绩不存在!\n");
    }
    getchar();
}

//menu_select 函数-----------------------------

void menu_select()
{
//    char s[100];
    int c;
//    gets(s);
    while(1)
    {
        scanf("%d",&c);
        if(c<1||c>7)
        {
            printf("你的输入有误，请重新输入: ");
//            gets(s);
        }
        else break;
    }
    switch(c)
    {
        case 1 : /*system("cls");*/ browse(); break;
        case 2 : /*system("cls");*/ creat(); break;
        case 3 : /*system("cls");*/ save(); break;
        case 4 : /*system("cls");*/ search(); break;
        case 5 : /*syetem("cls");*/ update(); break;
        case 6 : /*system("cls");*/ del(); break;
        case 7 : /*system("cls");*/ quit(); return ; break;
        default : break;
    }
    getchar();
//    system("cls");
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
    FILE *fp;
    SONGER_MESSAGE *p1;
    p1=head;
    fp=fopen("参赛选手名单.txt","w");
    fprintf(fp,"--------|--------\n");
    fprintf(fp,"   编号 |  姓名\n");
    while(p1!=NULL)
    {
        fprintf(fp,"--------|--------\n");
        fprintf(fp,"   %-9d%-6s\n",p1->num,p1->name);
        p1=p1->next;
    }
    fprintf(fp,"--------|--------\n");
    fclose(fp);
    printf("\n\t文件已保存到\"参赛选手名单.txt\"");
}

//creat 函数------------------------
void creat()
{
    int i,j;
    float t;
    char c='y';
    while(c=='y'||c=='Y')
    {
        SONGER_MESSAGE *p1=(SONGER_MESSAGE *)malloc(LEN);
        printf("\n请输入要录入的选手信息: \n");
        printf("\n选手编号: ");
        scanf("%d",&p1->num);
        printf("\n选手姓名: ");
        scanf("%s",p1->name);
        printf("\n请输入10位评委点评的成绩: ");
        p1->ave = 0;
        for(i=0;i<10;i++)
        {
            scanf("%f",&(p1->grades[i]));
            p1->ave +=p1->grades[i];
        }
        for(i=0;i<10-1;i++)
        for(j=0;j<10-1-i;j++)
        if(p1->grades[j]>p1->grades[j+1])
        {
            t=p1->grades[j];
            p1->grades[j]=p1->grades[j+1];
            p1->grades[j+1]=t;
        }
        p1->ave=(p1->ave-(p1->grades[0]+p1->grades[9]))/8;
        p1->next=NULL;
        if(p1==NULL)
        {
            printf("\n内存分配失败\n");
            n=n-1;
        }
        if(head==NULL&&tail==NULL)
        {
            head=p1;
            head->next=NULL;
            tail=head;
        }
        else
        {
            tail->next=p1;
            tail=p1;
            tail->next=NULL;
            printf("\n------选手信息录入成功------\n");
        }
        printf("是否继续录入(Y/N): ");
        getchar();
        scanf("%c",&c);
    }
}

//rean 函数--------------------------------------

/*void rank()
{
    SONGER_MESSAGE *p1,*p2,*endpt,*p;
    n=0;
    p1=head;
    if(head==NULL&&tail==NULL)
        printf("\n------当前信息记录为空------\n");
    else
    {
        p1=(SONGER_MESSAGE *)malloc(LEN);
        p1->next=head;
        head=p1;
        for(endpt=NULL;endpt!=head;endpt=p)
        {
            for(p=p1=head;p1->next->next!=endpt;p1=p1->next)
            {
                if(p1->next->ave<p1->next->next->ave)
                {
                    p2=p1->next->next;
                    p1->next->next=p2->next;
                    p2->next=p1->next;
                    p1->next=p2;
                    p=p1->next->next;
                }
            }
        }
        p1=head;
        head=head->next;
        free(p1);
        printf("\n----------选手成绩排名如下--------\n");
        printf("---------|--------|--------|--------\n");
        printf("     编号|  姓名  |平均成绩|  名次  \n");
        p1=head;
        while(p1!=NULL)
        {
            printf("--------|--------|--------|--------\n");
            printf("%-9d&-9s%-9.1lf%-5d\n",p1->num,p1->name,p1->ave,n+1);
            n++;
            p1=p1->next;
        }
        print("--------|--------|--------|--------\n");
    }
    getchar();
}*/

//del 函数-------------------------------
void del()
{
    SONGER_MESSAGE *node;
    SONGER_MESSAGE *p1;
    int check=0;
    long del_num;
    printf("\n请输入要删除的选手编号: ");
    scanf("%d",&del_num);
    if(head==NULL&&tail==NULL)
    {
        printf("\n当前信息记录为空，删除失败！\n");
    }
    else
    {
        node=head;
        p1=head;
        while(node!=NULL)
        {
            if(node->num==del_num)
            {
                printf("\n--------要删除的选手信息--------\n");
                printf("--------|--------\n");
                printf("  编号  |  姓名  \n");
                printf("--------|--------\n");
                printf("  %-9d%-6s\n",node->num,node->name);
                printf("--------|--------\n");
                check=1;
                if(node==head&&head->next==NULL)
                {
                    head=NULL;
                    tail=head;
                    free(node);
                    printf("\n--------删除信息成功--------\n");
                }
                else if(node==head&&head->next!=NULL)
                {
                    node=head;
                    head=head->next;
                    free(node);
                    printf("\n--------删除信息成功--------\n");
                    n=n-1;
                }
                else if(node->next!=NULL)
                {
                    p1->next=node->next;
                    free(node);
                    printf("\n--------删除信息成功--------\n");
                    n=n-1;
                }
                else if(node->next==NULL)
                {
                    p1->next=NULL;
                    tail=p1;
                    free(node);
                    printf("\n--------删除信息成功--------\n");
                    n=n-1;
                }
                getchar();
                return ;
            }
            else
            {
                p1=node;
                node=node->next;
            }
        }
    }
    if(head!=NULL&&check==0)
    {
        printf("\n对不起，你要删除的选手信息不存在!\n");
    }
    getchar();
}

//color 函数----------------------------


/*void color(constunsignedshort color1)
{
    if(color1>=0&&color1<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
    else
        SetConsoleTexAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        黑色：0      灰色：8
        蓝色：1        淡蓝色：9
        绿色：2        淡绿色：10
        湖蓝色：3       淡浅绿色：11
        红色：4        淡红色：12
        紫色：5        淡紫色：13
        黄色6         淡黄色：14
        白色：7        亮白色：15

}
*/

//quit 函数------------------------------------------

void quit()
{
    printf("\n\n\t==========》感谢使用评分系统《==========\n\n");
}

//menu 函数---------------------------------------
void menu()
{
//    system("mode con clos=100 lines=30");
//    color(11);
    printf("\t|-----------------菜单---------------|\n");
    printf("\t|-----------1.选手信息浏览-----------|\n");
    printf("\t|-----------2.选手信息录入-----------|\n");
    printf("\t|-----------3.选手信息保存-----------|\n");
    printf("\t|-----------4.选手成绩查询-----------|\n");
    printf("\t|-----------5.选手信息修改-----------|\n");
    printf("\t|-----------6.选手信息删除-----------|\n");
    printf("\t|-----------7.退出系统---------------|\n");
    printf("\t|------------------------------------|\n");
//    color(15);
}

//welcome 函数-------------------------------------
int welcome()
{
//    system("mode con cols=65 lines=25");
    printf("\n\n\n\n\n");
    printf("按任意键进入主菜单\n");
    getch();
//    system("cls");
    menu();
    menu_select();
    return 0;
}
int main()
{
    welcome();
    return 0;
}
