#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(SONGER_MESSAGE)
#define N 10;

struct tm *ptr;

typedef struct{
    long num;     //ѡ�ֱ��
    char name[20];  //ѡ������
    float grades[10];  //ѡ�ֳɼ�
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
//void rank();        //����
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
            printf("--------|--------\n");
            printf("%-9d%-6s\n",p1->num,p1->name);
            p1=p1->next;
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
        case 1: /*system("cls");*/ print(); break;
        case 2: /*system("cls");*/ /*rank();*/ break;
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
        printf("��� | ���� | �ɼ� |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | ƽ���ɼ�\n");
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
        printf("\n�Բ�����鿴��ѡ�ֳɼ�������!\n");
    }
    getchar();
}

//menu_select ����-----------------------------

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
            printf("���������������������: ");
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
    FILE *fp;
    SONGER_MESSAGE *p1;
    p1=head;
    fp=fopen("����ѡ������.txt","w");
    fprintf(fp,"--------|--------\n");
    fprintf(fp,"   ��� |  ����\n");
    while(p1!=NULL)
    {
        fprintf(fp,"--------|--------\n");
        fprintf(fp,"   %-9d%-6s\n",p1->num,p1->name);
        p1=p1->next;
    }
    fprintf(fp,"--------|--------\n");
    fclose(fp);
    printf("\n\t�ļ��ѱ��浽\"����ѡ������.txt\"");
}

//creat ����------------------------
void creat()
{
    int i,j;
    float t;
    char c='y';
    while(c=='y'||c=='Y')
    {
        SONGER_MESSAGE *p1=(SONGER_MESSAGE *)malloc(LEN);
        printf("\n������Ҫ¼���ѡ����Ϣ: \n");
        printf("\nѡ�ֱ��: ");
        scanf("%d",&p1->num);
        printf("\nѡ������: ");
        scanf("%s",p1->name);
        printf("\n������10λ��ί�����ĳɼ�: ");
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
            printf("\n�ڴ����ʧ��\n");
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
            printf("\n------ѡ����Ϣ¼��ɹ�------\n");
        }
        printf("�Ƿ����¼��(Y/N): ");
        getchar();
        scanf("%c",&c);
    }
}

//rean ����--------------------------------------

/*void rank()
{
    SONGER_MESSAGE *p1,*p2,*endpt,*p;
    n=0;
    p1=head;
    if(head==NULL&&tail==NULL)
        printf("\n------��ǰ��Ϣ��¼Ϊ��------\n");
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
        printf("\n----------ѡ�ֳɼ���������--------\n");
        printf("---------|--------|--------|--------\n");
        printf("     ���|  ����  |ƽ���ɼ�|  ����  \n");
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

//del ����-------------------------------
void del()
{
    SONGER_MESSAGE *node;
    SONGER_MESSAGE *p1;
    int check=0;
    long del_num;
    printf("\n������Ҫɾ����ѡ�ֱ��: ");
    scanf("%d",&del_num);
    if(head==NULL&&tail==NULL)
    {
        printf("\n��ǰ��Ϣ��¼Ϊ�գ�ɾ��ʧ�ܣ�\n");
    }
    else
    {
        node=head;
        p1=head;
        while(node!=NULL)
        {
            if(node->num==del_num)
            {
                printf("\n--------Ҫɾ����ѡ����Ϣ--------\n");
                printf("--------|--------\n");
                printf("  ���  |  ����  \n");
                printf("--------|--------\n");
                printf("  %-9d%-6s\n",node->num,node->name);
                printf("--------|--------\n");
                check=1;
                if(node==head&&head->next==NULL)
                {
                    head=NULL;
                    tail=head;
                    free(node);
                    printf("\n--------ɾ����Ϣ�ɹ�--------\n");
                }
                else if(node==head&&head->next!=NULL)
                {
                    node=head;
                    head=head->next;
                    free(node);
                    printf("\n--------ɾ����Ϣ�ɹ�--------\n");
                    n=n-1;
                }
                else if(node->next!=NULL)
                {
                    p1->next=node->next;
                    free(node);
                    printf("\n--------ɾ����Ϣ�ɹ�--------\n");
                    n=n-1;
                }
                else if(node->next==NULL)
                {
                    p1->next=NULL;
                    tail=p1;
                    free(node);
                    printf("\n--------ɾ����Ϣ�ɹ�--------\n");
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
        printf("\n�Բ�����Ҫɾ����ѡ����Ϣ������!\n");
    }
    getchar();
}

//color ����----------------------------


/*void color(constunsignedshort color1)
{
    if(color1>=0&&color1<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
    else
        SetConsoleTexAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        ��ɫ��0      ��ɫ��8
        ��ɫ��1        ����ɫ��9
        ��ɫ��2        ����ɫ��10
        ����ɫ��3       ��ǳ��ɫ��11
        ��ɫ��4        ����ɫ��12
        ��ɫ��5        ����ɫ��13
        ��ɫ6         ����ɫ��14
        ��ɫ��7        ����ɫ��15

}
*/

//quit ����------------------------------------------

void quit()
{
    printf("\n\n\t==========����лʹ������ϵͳ��==========\n\n");
}

//menu ����---------------------------------------
void menu()
{
//    system("mode con clos=100 lines=30");
//    color(11);
    printf("\t|-----------------�˵�---------------|\n");
    printf("\t|-----------1.ѡ����Ϣ���-----------|\n");
    printf("\t|-----------2.ѡ����Ϣ¼��-----------|\n");
    printf("\t|-----------3.ѡ����Ϣ����-----------|\n");
    printf("\t|-----------4.ѡ�ֳɼ���ѯ-----------|\n");
    printf("\t|-----------5.ѡ����Ϣ�޸�-----------|\n");
    printf("\t|-----------6.ѡ����Ϣɾ��-----------|\n");
    printf("\t|-----------7.�˳�ϵͳ---------------|\n");
    printf("\t|------------------------------------|\n");
//    color(15);
}

//welcome ����-------------------------------------
int welcome()
{
//    system("mode con cols=65 lines=25");
    printf("\n\n\n\n\n");
    printf("��������������˵�\n");
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
