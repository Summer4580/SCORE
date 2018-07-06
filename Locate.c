
#include "common.h"
#include "seqlist.h"

int  Locate(seqlist L,int num)
{
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last)&&(L.elem[i].num!=num))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	if  (i<=L.last)
	{
		printf("该元素在线性表中的位置为:%d\n",i+1);
		return(i+1);  /*若找到值为e的元素，则返回其序号*/
	}

	else
	{
		printf("在此线性表中没有该元素!\n");
		return(-1);  /*若没找到，则返回空序号*/

	}
}
int  Locate2(seqlist L,int num)
{
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last2)&&(L.elem2[i].num!=num))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	if  (i<=L.last2)
	{
		printf("该元素在线性表中的位置为:%d\n",i+1);
		return(i+1);  /*若找到值为e的元素，则返回其序号*/
	}

	else
	{
		printf("在此线性表中没有该元素!\n");
		return(-1);  /*若没找到，则返回空序号*/

	}
}
void look(seqlist *L)
{
	int q,temp,x;
	printf("请输入1 or 2选择查找裁判还是选手：");
	scanf("%d",&x);
	if(x==1)
    {
        printf("请输入要查找的元素值:\n");
        scanf("%d",&q);
        temp=Locate(*L,q);
        if(temp!=-1)
        {
            printf("电话-----姓名-----性别-----表演名称------表演类别--分数--1--2--3--4--5--6--7--8--9--10--最后得分\n");
            printf("%-9d",L->elem[temp-1].num);
            printf("%-9s",L->elem[temp-1].name);
            printf("%-9s",L->elem[temp-1].sex);
            printf("%-10s",L->elem[temp-1].play_name);
            printf("%-10s",L->elem[temp-1].play_category);
            for(i=0;i<10;i++)
            {
                printf("%-5lf",L->elem[temp-1].score[i]);
            }
            printf("%-5lf",L->elem[temp-1].score_avg);
        }
    }
    else
    {
        printf("请输入要查找的元素值:\n");
        scanf("%d",&q);
        temp=Locate2(*L,q);
        if(temp!=-1)
        {
            printf("电话-----姓名-----性别\n");
            printf("%-9d",L->elem[temp-1].num);
            printf("%-9s",L->elem[temp-1].name);
            printf("%-9s",L->elem[temp-1].sex);
        }
    }
/*	printf("请输入要查找的元素值:\n");
	scanf("%d",&q);
	temp=Locate(*L,q);
	if(temp!=-1)
    {
        printf("电话-----姓名-----性别-----表演名称------表演类别--分数--1--2--3--4--5--6--7--8--9--10--最后得分\n");
        printf("%-9d",L->elem[temp-1].num);
		printf("%-9s",L->elem[temp-1].name);
		printf("%-9s",L->elem[temp-1].sex);
		printf("%-10s",L->elem[temp-1].play_name);
		printf("%-10s",L->elem[temp-1].play_category);
		for(i=0;i<10;i++)
        {
            printf("%-5lf",L->elem[temp-1].score[i]);
        }
        printf("%-5lf",L->elem[temp-1].score_avg);
    }
*/
}

void Updata(seqlist *L)
{
    int tem,i,q,x;
    printf("请输入1 or 2选择修改裁判还是选手：");
	scanf("%d",&x);
	if(x==2)
    {
       printf("请输入要修改的电话：\n");
        scanf("%d",&tem);
        q=Locate(*L,tem)-1;
        if(q==-1)
        {
            printf("你要修改的元素不存在！\n");
            return ;
        }
        else
        {
            L->elem[temp-1].score_max=0;
            L->elem[temp-1].score_sum=0;
            L->elem[trmp-1].score_min=10;
            printf("请输入除去电话以外的信息:\n");
            scanf("%s",L->elem[temp-1].name);
            scanf("%s",L->elem[temp-1].sex);
            scanf("%s",L->elem[temp-1].play_name);
            scanf("%s",L->elem[temp-1].play_category);
            for(i=0;i<10;i++)
            {
                scanf("%lf",&L->elem[temp-1].score[i]);
                if(L->elem[temp-1].score_max<L->elem[temp-1].score[i])
                    L->elem[temp-1].score_max=L->elem[temp-1].score[i];
                if(L->elem[temp-1].score_min>L->elem[temp-1].score[i])
                    L->elem[temp-1].score_min=L->elem[temp-1].score[i];
                L->elem[temp-1].score_sum+=L->elem[temp-1].score[i];
            }
            L->elem[temp-1].score_avg=(L->elem[temp-1].score_sum-L->elem[temp-1].score_max-L->elem[temp-1].score_min)/8;
            printf("信息修改完成！\n");
        }
    }
    else
    {
        printf("请输入要修改的电话：\n");
        scanf("%d",&tem);
        q=Locate2(*L,tem)-1;
        if(q==-1)
        {
            printf("你要修改的元素不存在！\n");
            return ;
        }
        else
        {
            printf("请输入除去电话以外的信息:\n");
            scanf("%s",L->elem[temp-1].name);
            scanf("%s",L->elem[temp-1].sex);
        }
    }
/*    printf("请输入要修改的电话：\n");
    scanf("%d",&tem);
    q=Locate(*L,tem)-1;
    if(q==-1)
    {
        printf("你要修改的元素不存在！\n");
        return ;
    }
    else
    {
        L->elem[temp-1].score_max=0;
        L->elem[temp-1].score_sum=0;
        L->elem[trmp-1].score_min=10;
        printf("请输入除去电话以外的信息:\n");
		scanf("%-9s",L->elem[temp-1].name);
		scanf("%-9s",L->elem[temp-1].sex);
		scanf("%-10s",L->elem[temp-1].play_name);
		scanf("%-10s",L->elem[temp-1].play_category);
		for(i=0;i<10;i++)
        {
            scanf("%-5lf",&L->elem[temp-1].score[i]);
            if(L->elem[temp-1].score_max<L->elem[temp-1].score[i])
                L->elem[temp-1].score_max=L->elem[temp-1].score[i];
            if(L->elem[temp-1].score_min>L->elem[temp-1].score[i])
                L->elem[temp-1].score_min=L->elem[temp-1].score[i];
            L->elem[temp-1].score_sum+=L->elem[temp-1].score[i];
        }
        L->elem[temp-1].score_avg=(L->elem[temp-1].score_sum-L->elem[temp-1].score_max-L->elem[temp-1].score_min)/8;
        printf("信息修改完成！\n");
    }
*/
}

void Delete(seqlist *L)
{
	int j;
	int i,q,x;
	printf("请输入1 or 2选择删除裁判还是选手：");
	scanf("%d",&x);
	if(x==1)
    {
        printf("请输入要删除的元素:\n");
        scanf("%d",&q);
        i=Locate2(*L,q);

        if(i<1)
        {
            return ;
        }
        else
        {
            for(j=i;j<=L->last;j++)
            L->elem[j-1]=L->elem[j];
            L->last--;
            printf("位序为%d的元素已经删除\n",i);
            onput(L);
        }
    }
    else
    {
        printf("请输入要删除的元素:\n");
        scanf("%d",&q);
        i=Locate(*L,q);

        if(i<1)
        {
            return ;
        }
        else
        {
            for(j=i;j<=L->last2;j++)
            L->elem2[j-1]=L->elem2[j];
            L->last2--;
            printf("位序为%d的元素已经删除\n",i);
            onput(L);
        }
    }
}

int Insert(seqlist *L)
{
	ElemType x;
	int i;

	printf("请输入要插入的元素(分别为学号、姓名、高数、英语、C语言):\n");
	scanf("%d",&x.num);
	scanf("%s",x.name);
	scanf("%d",&x.math);
	scanf("%d",&x.english);
	scanf("%d",&x.c);
	printf("请输入要插入的元素的位置:\n");
	scanf("%d",&i);

	int j;

	if(L->last==MAXSIZE-1)
	{
		printf(" 表满\n");
		return 0;
	}
	if(i<1||i>L->last+2)
	{
		printf("位序不合法\n");
		return 0;
	}
	for(j=L->last;j>=i-1;j--)
		L->elem[j+1]=L->elem[j];
	L->elem[i-1]=x;
	L->last++;
	onput(L);
	return 1;
}
//排序
/*int compare(const void *a,const void *b)
{
	int aa=((ElemType*)a)->num;
	int bb=((ElemType*)b)->num;
	if(aa>bb)
	return 0;
	else
	return 1;
}
void tsort(seqlist *L)
{
	seqlist l = *L;
	int i=l.last+1;
	printf("排序-----------------------\n");
	qsort(l.elem,i,sizeof(l.elem[0]),compare);
}*/

void swap(ElemType *a, ElemType *b)
{
    ElemType temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}

void quicksort(ElemType array[], int maxlen, int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
        j = end;        // array[end]是数组的最后一位

        while(i < j)
        {
            if(array[i].num > array[begin].num)  // 如果比较的数组元素大于基准数，则交换位置。
            {
                swap(&array[i], &array[j]);  // 交换两个数
                j--;
            }
            else
            {
                i++;  // 将数组向后移一位，继续与基准数比较。
            }
        }

        /* 跳出while循环后，i = j。
         * 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
         *                           -->  array[i+1] ~ array[end] > array[begin]
         * 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
         * 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
         */

        if(array[i].num >= array[begin].num)  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}


void input(seqlist *L)
{
	int r,i;

	printf("请输入线性表的长度:");
	scanf("%d",&r);

	L->last = r-1;
	printf("请输入线性表的各元素值(分别为学号、姓名、高数、英语、C语言):\n");
	for(i=0; i<=r-1; i++)
	{
		scanf("%d",&L->elem[i].num);
		scanf("%s",L->elem[i].name);
		scanf("%d",&L->elem[i].math);
		scanf("%d",&L->elem[i].english);
		scanf("%d",&L->elem[i].c);
	}
	onput(L);
}

void onput(seqlist *L)
{
	quicksort(L->elem, L->last+1, 0, L->last);
	printf("线性表现存元素：\n");
	int i;
	printf("学号-----姓名-----高数-----英语------C语言\n");
	for(i=0;i<=L->last;i++)
	{
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d\n",L->elem[i].c);
	}
}

void save(seqlist *L)
{
    FILE *fp;
    fp=fopen("学生信息.txt","w");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");
        return ;
    }
    int i;
    fprintf(fp,"学号-----姓名-----高数-----英语------C语言------总成绩------平均分\n");
    for(i=0;i<=L->last;i++)
	{
		fprintf(fp,"%-9d%-9s%-9d%-10d%-11d%-12d%-10d\n",L->elem[i].num,L->elem[i].name,L->elem[i].math,L->elem[i].english,L->elem[i].c,L->elem[i].sum,L->elem[i].avg);
	}
	printf("文件成功保存到《学生信息.txt》中\n");
}

void fun1(seqlist *L)
{
	int i;
	printf("学号-----姓名-----高数-----英语------C语言------总成绩\n");
	for(i=0;i<=L->last;i++)
	{
		L->elem[i].sum=L->elem[i].math+L->elem[i].english+L->elem[i].c;
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d",L->elem[i].c);
		printf("%-10d\n",L->elem[i].sum);
	}
}

void fun2(seqlist *L)
{
    int i;
	printf("学号-----姓名-----高数-----英语------C语言------平均分\n");
	for(i=0;i<=L->last;i++)
	{
		L->elem[i].avg=(L->elem[i].math+L->elem[i].english+L->elem[i].c)/3;
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d",L->elem[i].c);
		printf("%-10d\n",L->elem[i].avg);
	}
}

void fun3(seqlist *L)
{
    int x;
    printf("按学号查询or姓名查询(1 or 2): ");
    scanf("%d",&x);
    if(x==1)
    {
        int number;
        printf("请输入学号: ");
        scanf("%d",&number);
        int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
        while ((i<=L->last)&&(L->elem[i].num!=number))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
		printf("学号-----姓名-----高数-----英语------C语言\n");
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d\n",L->elem[i].c);
    }
    else
    {
        printf("请输入姓名: ");
        char name1[20];
        scanf("%s",name1);
        int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
        while ((i<=L->last)&&strcmp(L->elem[i].name,name1))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
        printf("学号-----姓名-----高数-----英语------C语言\n");
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d\n",L->elem[i].c);
    }
}

void fun4(seqlist *L)
{
    ElemType temp;
    int i,j;
    for(i=0;i<L->last;i++)
        for(j=0;j<L->last-i;j++)
    {
        if(L->elem[j].sum<L->elem[j+1].sum)
        {
            temp=L->elem[j+1];
            L->elem[j+1]=L->elem[j];
            L->elem[j]=temp;
        }
    }
    printf("按照总分排序之后的结果：\n");
	printf("学号-----姓名-----高数-----英语------C语言------总分\n");
	for(i=0;i<=L->last;i++)
	{
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d",L->elem[i].c);
		printf("%-10d\n",L->elem[i].sum);
	}
}

void fun5(seqlist *L)
{
    L->math_max=0;
    L->math_min=101;
    L->math_avg=0;
    L->english_max=0;
    L->english_min=101;
    L->english_avg=0;
    L->c_max=0;
    L->c_min=101;
    L->c_avg=0;
    int i;
    for(i=0;i<=L->last;i++)
    {
        if(L->math_max<L->elem[i].math)
            L->math_max=L->elem[i].math;
        if(L->math_min>L->elem[i].math)
            L->math_min=L->elem[i].math;
            L->math_avg+=L->elem[i].math;
        if(L->english_max<L->elem[i].english)
            L->english_max=L->elem[i].english;
        if(L->english_min>L->elem[i].english)
            L->english_min=L->elem[i].english;
            L->english_avg+=L->elem[i].english;
        if(L->c_max<L->elem[i].c)
            L->c_max=L->elem[i].c;
        if(L->c_min>L->elem[i].c)
            L->c_min=L->elem[i].c;
            L->c_avg+=L->elem[i].c;
    }
    L->math_avg=L->math_avg/(L->last+1);
    L->english_avg=L->english_avg/(L->last+1);
    L->c_avg=L->c_avg/(L->last+1);
    printf("高数最高分：%d 最低分：%d 平均分：%d\n",L->math_max,L->math_min,L->math_avg);
    printf("英语最高分：%d 最低分：%d 平均分：%d\n",L->english_max,L->english_min,L->english_avg);
    printf("c语言最高分：%d 最低分：%d 平均分：%d\n",L->c_max,L->c_min,L->c_avg);
}
void mean()
{
	seqlist l;
	int t;
	while(1)
	{
		printf("\t|--------------------------------------------------------------|\n");
		printf("\t|                      学生信息管理                            |\n");
		printf("\t|                     1.存入选手信息                           |\n");
		printf("\t|                     2.查询选手信息                           |\n");
		printf("\t|                     3.插入选手信息                           |\n");
		printf("\t|                     4.修改选手信息                           |\n");
		printf("\t|                     5.删除选手信息                           |\n");
		printf("\t|                     6.输出所有选手信息                       |\n");
		printf("\t|                     7.退出并保存                             |\n");
		printf("\t|--------------------------------------------------------------|\n");
		printf("\t|                     8.计算总分                               |\n");
		printf("\t|                     9.计算平均分                             |\n");
		printf("\t|                     10.姓名/学号查询                         |\n");
		printf("\t|                     11.总分排序                              |\n");
		printf("\t|                     12.统计分数                              |\n");
		printf("\t|--------------------------------------------------------------|\n");
		printf("请输入1-12:");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : input(&l); break;
			case 2 : look(&l); break;
			case 3 : Insert(&l); break;
			case 4 : Updata(&l); break;
			case 5 : Delete(&l); break;
			case 6 : onput(&l); break;
			case 7 : save(&l); return 0;
			case 8 : fun1(&l); break;
			case 9 : fun2(&l); break;
			case 10 : fun3(&l); break;
			case 11 : fun4(&l); break;
			case 12 : fun5(&l); break;
		}
	}
}

void main()
{
	mean();
}
