
#include "common.h"
#include "seqlist.h"

int  Locate(seqlist L,double num)
{
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last)&&(L.elem[i].num!=num))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	if  (i<=L.last)
	{
		return(i+1);  /*若找到值为e的元素，则返回其序号*/
	}

	else
	{
		printf("在此线性表中没有该元素!\n");
		return(-1);  /*若没找到，则返回空序号*/

	}
}
int  Locate2(seqlist L,double num)
{
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last2)&&(L.elem2[i].num!=num))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	if  (i<=L.last2)
	{
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
	int temp,x,i,j;
	double q;
	printf("请输入1 or 2选择查找选手还是裁判：");
	scanf("%d",&x);
	if(x==1)
    {
        printf("请输入要查找的元素值:\n");
        scanf("%lf",&q);
        temp=Locate(*L,q)-1;
        if(temp!=-1)
        {
            printf("电话-----------姓名-----性别-----表演名称------表演类别--分数----1------2------3------4------5------6------7------8------9------10-----最后得分\n");
            printf("%-15.0lf",L->elem[temp].num);
            printf("%-9s",L->elem[temp].name);
            printf("%-9s",L->elem[temp].sex);
            printf("%-14s",L->elem[temp].play_name);
            printf("%-18s",L->elem[temp].play_category);
            for(j=0;j<=L->last2;j++)

            {
                printf("%-7.2lf",L->elem[temp].score[j]);
            }
            printf("%-7.2lf\n",L->elem[temp].score_avg);
        }
    }
    else
    {
        printf("请输入要查找的元素值:\n");
        scanf("%lf",&q);
        temp=Locate2(*L,q)-1;
        if(temp!=-1)
        {
            printf("电话-----------姓名-----性别\n");
            printf("%-15.0lf",L->elem[temp].num);
            printf("%-9s",L->elem[temp].name);
            printf("%-9s",L->elem[temp].sex);
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
    int i,q;
    int x;
    double tem;
    printf("请输入1 or 2选择修改选手还是裁判：");
	scanf("%d",&x);
	if(x==1)
    {
       printf("请输入要修改的电话：\n");
        scanf("%lf",&tem);
        q=Locate(*L,tem);
        if(q==-1)
        {
            printf("你要修改的元素不存在！\n");
            return ;
        }
        else
        {
            L->elem[q-1].score_max=0;
            L->elem[q-1].score_sum=0;
            L->elem[q-1].score_min=10;
            printf("请输入除去电话以外的信息:\n");
            printf("姓名: ");
            scanf("%s",L->elem[q-1].name);
            printf("性别: ");
            scanf("%s",L->elem[q-1].sex);
            printf("节目名称: ");
            scanf("%s",L->elem[q-1].play_name);
            printf("节目种类: ");
            scanf("%s",L->elem[q-1].play_category);
            printf("评委分数(%d个): ",L->last2+1);
            for(i=0;i<=L->last2;i++)
            {
                scanf("%lf",&L->elem[q-1].score[i]);
                if(L->elem[q-1].score_max<L->elem[q-1].score[i])
                    L->elem[q-1].score_max=L->elem[q-1].score[i];
                if(L->elem[q-1].score_min>L->elem[q-1].score[i])
                    L->elem[q-1].score_min=L->elem[q-1].score[i];
                L->elem[q-1].score_sum+=L->elem[q-1].score[i];
            }
            L->elem[q-1].score_avg=(L->elem[q-1].score_sum-L->elem[q-1].score_max-L->elem[q-1].score_min)/(L->last2-1);
            printf("信息修改完成！\n");
        }
    }
    else
    {
        printf("请输入要修改人的电话：\n");
        scanf("%lf",&tem);
        q=Locate2(*L,tem);
        if(q==-1)
        {
            printf("你要修改的元素不存在！\n");
            return ;
        }
        else
        {
            printf("请输入除去电话以外的信息:\n");
            printf("姓名: ");
            scanf("%s",L->elem2[q-1].name);
            printf("性别: ");
            scanf("%s",L->elem2[q-1].sex);
            printf("信息修改完成！\n");
        }
    }
}

void Delete(seqlist *L)
{
	int j;
	int i,x;
	double q;
	printf("请输入1 or 2选择删除选手还是裁判：");
	scanf("%d",&x);
	if(x==1)
    {
        printf("请输入要删除的元素:\n");
        scanf("%lf",&q);
        i=Locate(*L,q);

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
            onput(L,x);
        }
    }
    else
    {
        printf("请输入要删除的元素:\n");
        scanf("%lf",&q);
        i=Locate2(*L,q);

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
            onput(L,x);
        }
    }
}

int Insert(seqlist *L)
{
	ElemType x1;
	memset(x1.score,0,sizeof(x1.score));
	ElemType2 x2;
	int i;
    printf("请输入1 or 2 选择要插入选手还是裁判: ");
    int w;
    scanf("%d",&w);
    if(w==1)
    {
        x1.score_max=0;
        x1.score_min=10;
        x1.score_sum=0;
        printf("请输入选手的信息:\n");
        printf("电话: ");
        scanf("%lf",&x1.num);
        int temp;
        temp=Locate(*L,x1.num);
        if(temp==-1)
        {
            printf("你输入的号码重复!请重新操作\n");
            return ;
        }
        printf("姓名: ");
        scanf("%s",x1.name);
        printf("性别: ");
        scanf("%s",x1.sex);
        printf("节目名称: ");
        scanf("%s",x1.play_name);
        printf("节目类别: ");
        scanf("%s",x1.play_category);
        printf("请输入选手的%d门分数: ",L->last2+1);
        for(i=0;i<=L->last2;i++)
        {
            scanf("%lf",&x1.score[i]);
            if(x1.score_max<x1.score[i])
                x1.score_max=x1.score[i];
            if(x1.score_min>x1.score[i])
                x1.score_min=x1.score[i];
            x1.score_sum+=x1.score[i];
        }
        x1.score_avg=(x1.score_sum-x1.score_max-x1.score_min)/(L->last2-1);
        printf("信息录入完成！\n");
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
        L->elem[i-1]=x1;
        L->last++;
        onput(L,1);
        return 1;
    }
    else
    {
        printf("请输入要插入的元素:\n");
        printf("电话: ");
        scanf("%lf",&x2.num);
        int temp;
        temp=Locate2(*L,x2.num);
        if(temp==-1)
        {
            printf("你输入的号码重复!,请重新操作\n");
            return ;
        }
        printf("姓名: ");
        scanf("%s",x2.name);
        printf("性别: ");
        scanf("%s",x2.sex);
        printf("信息录入完成！\n");
        printf("请输入要插入的元素的位置:\n");
        scanf("%d",&i);

        int j;

        if(L->last2==MAXSIZE-1)
        {
            printf(" 表满\n");
            return 0;
        }
        if(i<1||i>L->last2+2)
        {
            printf("位序不合法\n");
            return 0;
        }
        for(j=L->last2;j>=i-1;j--)
            L->elem2[j+1]=L->elem2[j];
        L->elem2[i-1]=x2;
        L->last2++;
        onput(L,2);
        return 1;
    }

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
            if(array[i].score_avg > array[begin].score_avg)  // 如果比较的数组元素大于基准数，则交换位置。
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

        if(array[i].score_avg >= array[begin].score_avg)  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
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
	int r,i,j;
    printf("请输入1 or 2选择存入选手信息还是裁判信息: ");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        printf("请输入线性表的长度:");
        scanf("%d",&r);

        L->last = r-1;
        for(i=0;i<=L->last;i++)
        {
            L->elem[i].score_max=0;
            L->elem[i].score_min=10;
            L->elem[i].score_sum=0;
            printf("请输入选手各项信息：\n");
            printf("电话：");
            scanf("%lf",&L->elem[i].num);
            printf("姓名：");
            scanf("%s",L->elem[i].name);
            printf("性别：");
            scanf("%s",L->elem[i].sex);
            printf("节目名称：");
            scanf("%s",L->elem[i].play_name);
            printf("节目类别：");
            scanf("%s",L->elem[i].play_category);
            printf("评委打分(%d个)：",L->last2+1);
            for(j=0;j<=L->last2;j++)
            {
                scanf("%lf",&L->elem[i].score[j]);
                if(L->elem[i].score_max<L->elem[i].score[j])
                    L->elem[i].score_max=L->elem[i].score[j];
                if(L->elem[i].score_min>L->elem[i].score[j])
                    L->elem[i].score_min=L->elem[i].score[j];
                L->elem[i].score_sum+=L->elem[i].score[j];
            }
            L->elem[i].score_avg=(L->elem[i].score_sum-L->elem[i].score_max-L->elem[i].score_min)/(L->last2-1);
        }
        onput(L,x);
    }
    else
    {
        printf("请输入线性表的长度:");
        scanf("%d",&r);

        L->last2 = r-1;
        printf("请输入线性表的各元素值:\n");
        for(i=0; i<=r-1; i++)
        {
            printf("电话: ");
            scanf("%lf",&L->elem2[i].num);
            printf("姓名: ");
            scanf("%s",L->elem2[i].name);
            printf("性别: ");
            scanf("%s",L->elem2[i].sex);
        }
        onput(L,x);
    }
}

void onput(seqlist *L,int x)
{
    if(x==1)
    {
        printf("-------------------------------------------选手：\n");
        int i,j;
        for(i=0;i<=L->last;i++)
        {
            printf("电话-----------姓名-----性别-----表演名称------表演类别--分数----1------2------3------4------5------6------7------8------9------10-----最后得分\n");
            printf("%-15.0lf",L->elem[i].num);
            printf("%-9s",L->elem[i].name);
            printf("%-9s",L->elem[i].sex);
            printf("%-14s",L->elem[i].play_name);
            printf("%-18s",L->elem[i].play_category);
            for(j=0;j<10;j++)
            {
                printf("%-7.2lf",L->elem[i].score[j]);
            }
            printf("%-7.2lf\n",L->elem[i].score_avg);
        }
    }
    else
    {

        printf("-------------------------------------------裁判：\n");
        int i,j;

        for(i=0;i<=L->last2;i++)
        {
            printf("电话-----------姓名-----性别\n");
            printf("%-15.0lf",L->elem2[i].num);
            printf("%-9s",L->elem2[i].name);
            printf("%-9s\n",L->elem2[i].sex);
        }
    }


}

void save(seqlist *L)
{
    FILE *fp;
    fp=fopen("选手信息.csv","w");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");
        return ;
    }
    int i,j;
    fprintf(fp,"电话,姓名,性别,表演名称,表演类别,分数,1,2,3,4,5,6,7,8,9,10,最后得分\n");
    for(i=0;i<=L->last;i++)
    {
        fprintf(fp,"%.0lf,",L->elem[i].num);
        fprintf(fp,"%s,",L->elem[i].name);
        fprintf(fp,"%s,",L->elem[i].sex);
        fprintf(fp,"%s,",L->elem[i].play_name);
        fprintf(fp,"%s,,",L->elem[i].play_category);
        for(j=0;j<10;j++)
        {
            fprintf(fp,"%.2lf,",L->elem[i].score[j]);
        }
        fprintf(fp,"%-2lf\n",L->elem[i].score_avg);
    }
	printf("文件成功保存到《学生信息.csv》中\n");
	fp=fopen("裁判信息.csv","w");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");
        return ;
    }
    fprintf(fp,"电话,姓名,性别\n");
    for(i=0;i<=L->last2;i++)
        {
            fprintf(fp,"%.0lf,",L->elem2[i].num);
            fprintf(fp,"%s,",L->elem2[i].name);
            fprintf(fp,"%s\n",L->elem2[i].sex);
        }
	printf("文件成功保存到《裁判信息.csv》中\n");
}

void login(seqlist *L)
{
    FILE *fp;
    char s[1000];
    int i,j;
    i=0;
    fp=fopen("裁判信息.csv","r");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法读取！\n");
        return ;
    }
    fgets(s,1000,fp);
    while(!feof(fp))
    {
        fscanf(fp,"%lf",&L->elem2[i].num);
        fscanf(fp,",%s",L->elem2[i].name);
        fscanf(fp,",%s\n",L->elem2[i].sex);
        i++;
    }
    L->last2=i-1;
    printf("裁判信息读取成功！\n");
    fclose(fp);
    i=0;
    fp=fopen("选手信息.csv","r");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法读取！\n");
        return ;
    }
    fgets(s,1000,fp);
    while(!feof(fp))
    {
        fscanf(fp,"%lf,",&L->elem[i].num);
        fscanf(fp,"%s,",L->elem[i].sex);
        fscanf(fp,"%s,",L->elem[i].play_name);
        fscanf(fp,"%s,,",L->elem[i].play_category);
        for(j=0;j<=L->last2;j++)
        {
            fscanf(fp,"%lf,",&L->elem[i].score[j]);
            if(L->elem[i].score_max<L->elem[i].score[j])
                L->elem[i].score_max=L->elem[i].score[j];
            if(L->elem[i].score_min>L->elem[i].score[j])
                L->elem[i].score_min=L->elem[i].score[j];
            L->elem[i].score_sum+=L->elem[i].score[j];
        }
        fscanf(fp,"%lf\n",&L->elem[i].score_avg);
        i++;
    }
    L->last=i-1;
    printf("学生信息读取成功！\n");
    fclose(fp);
}
void sort2(seqlist *L)
{
    quicksort(L->elem, L->last+1, 0, L->last);
    onput(L,1);
}

void mean()
{
	seqlist l;
	int t;
	while(1)
	{
		printf("\t|--------------------------------------------------------------|\n");
		printf("\t|                      分数信息管理                            |\n");
		printf("\t|                     1.存入信息                               |\n");
		printf("\t|                     2.查询信息                               |\n");
		printf("\t|                     3.插入信息                               |\n");
		printf("\t|                     4.修改信息                               |\n");
		printf("\t|                     5.删除信息                               |\n");
		printf("\t|                     6.选手分数排序                           |\n");
		printf("\t|                     7.输出选手信息                           |\n");
		printf("\t|                     8.输出裁判信息                           |\n");
		printf("\t|                     9.读取文件                               |\n");
		printf("\t|                     10.退出并保存                             |\n");
		printf("\t|--------------------------------------------------------------|\n");

		printf("请输入1-10:");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : input(&l); break;
			case 2 : look(&l); break;
			case 3 : Insert(&l); break;
			case 4 : Updata(&l); break;
			case 5 : Delete(&l); break;
			case 6 : sort2(&l); break;
			case 7 : onput(&l,1); break;
			case 8 : onput(&l,2); break;
			case 9 : login(&l); break;
			case 10 : save(&l); return 0;

		}
	}
}

void main()
{
	mean();
}
