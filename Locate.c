
#include "common.h"
#include "seqlist.h"

int  Locate(seqlist L,int num)
{
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last)&&(L.elem[i].num!=num))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
	if  (i<=L.last)
	{
		printf("��Ԫ�������Ա��е�λ��Ϊ:%d\n",i+1);
		return(i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	}

	else
	{
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
		return(-1);  /*��û�ҵ����򷵻ؿ����*/

	}
}
int  Locate2(seqlist L,int num)
{
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last2)&&(L.elem2[i].num!=num))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
	if  (i<=L.last2)
	{
		printf("��Ԫ�������Ա��е�λ��Ϊ:%d\n",i+1);
		return(i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	}

	else
	{
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
		return(-1);  /*��û�ҵ����򷵻ؿ����*/

	}
}
void look(seqlist *L)
{
	int q,temp,x;
	printf("������1 or 2ѡ����Ҳ��л���ѡ�֣�");
	scanf("%d",&x);
	if(x==1)
    {
        printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
        scanf("%d",&q);
        temp=Locate(*L,q);
        if(temp!=-1)
        {
            printf("�绰-----����-----�Ա�-----��������------�������--����--1--2--3--4--5--6--7--8--9--10--���÷�\n");
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
        printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
        scanf("%d",&q);
        temp=Locate2(*L,q);
        if(temp!=-1)
        {
            printf("�绰-----����-----�Ա�\n");
            printf("%-9d",L->elem[temp-1].num);
            printf("%-9s",L->elem[temp-1].name);
            printf("%-9s",L->elem[temp-1].sex);
        }
    }
/*	printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
	scanf("%d",&q);
	temp=Locate(*L,q);
	if(temp!=-1)
    {
        printf("�绰-----����-----�Ա�-----��������------�������--����--1--2--3--4--5--6--7--8--9--10--���÷�\n");
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
    printf("������1 or 2ѡ���޸Ĳ��л���ѡ�֣�");
	scanf("%d",&x);
	if(x==2)
    {
       printf("������Ҫ�޸ĵĵ绰��\n");
        scanf("%d",&tem);
        q=Locate(*L,tem)-1;
        if(q==-1)
        {
            printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
            return ;
        }
        else
        {
            L->elem[temp-1].score_max=0;
            L->elem[temp-1].score_sum=0;
            L->elem[trmp-1].score_min=10;
            printf("�������ȥ�绰�������Ϣ:\n");
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
            printf("��Ϣ�޸���ɣ�\n");
        }
    }
    else
    {
        printf("������Ҫ�޸ĵĵ绰��\n");
        scanf("%d",&tem);
        q=Locate2(*L,tem)-1;
        if(q==-1)
        {
            printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
            return ;
        }
        else
        {
            printf("�������ȥ�绰�������Ϣ:\n");
            scanf("%s",L->elem[temp-1].name);
            scanf("%s",L->elem[temp-1].sex);
        }
    }
/*    printf("������Ҫ�޸ĵĵ绰��\n");
    scanf("%d",&tem);
    q=Locate(*L,tem)-1;
    if(q==-1)
    {
        printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
        return ;
    }
    else
    {
        L->elem[temp-1].score_max=0;
        L->elem[temp-1].score_sum=0;
        L->elem[trmp-1].score_min=10;
        printf("�������ȥ�绰�������Ϣ:\n");
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
        printf("��Ϣ�޸���ɣ�\n");
    }
*/
}

void Delete(seqlist *L)
{
	int j;
	int i,q,x;
	printf("������1 or 2ѡ��ɾ�����л���ѡ�֣�");
	scanf("%d",&x);
	if(x==1)
    {
        printf("������Ҫɾ����Ԫ��:\n");
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
            printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
            onput(L);
        }
    }
    else
    {
        printf("������Ҫɾ����Ԫ��:\n");
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
            printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
            onput(L);
        }
    }
}

int Insert(seqlist *L)
{
	ElemType x;
	int i;

	printf("������Ҫ�����Ԫ��(�ֱ�Ϊѧ�š�������������Ӣ�C����):\n");
	scanf("%d",&x.num);
	scanf("%s",x.name);
	scanf("%d",&x.math);
	scanf("%d",&x.english);
	scanf("%d",&x.c);
	printf("������Ҫ�����Ԫ�ص�λ��:\n");
	scanf("%d",&i);

	int j;

	if(L->last==MAXSIZE-1)
	{
		printf(" ����\n");
		return 0;
	}
	if(i<1||i>L->last+2)
	{
		printf("λ�򲻺Ϸ�\n");
		return 0;
	}
	for(j=L->last;j>=i-1;j--)
		L->elem[j+1]=L->elem[j];
	L->elem[i-1]=x;
	L->last++;
	onput(L);
	return 1;
}
//����
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
	printf("����-----------------------\n");
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
        i = begin + 1;  // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
        j = end;        // array[end]����������һλ

        while(i < j)
        {
            if(array[i].num > array[begin].num)  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
            {
                swap(&array[i], &array[j]);  // ����������
                j--;
            }
            else
            {
                i++;  // �����������һλ���������׼���Ƚϡ�
            }
        }

        /* ����whileѭ����i = j��
         * ��ʱ���鱻�ָ����������  -->  array[begin+1] ~ array[i-1] < array[begin]
         *                           -->  array[i+1] ~ array[end] > array[begin]
         * ���ʱ������array�ֳ��������֣��ٽ�array[i]��array[begin]���бȽϣ�����array[i]��λ�á�
         * ���array[i]��array[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
         */

        if(array[i].num >= array[begin].num)  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // ����array[i]��array[begin]

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}


void input(seqlist *L)
{
	int r,i;

	printf("���������Ա�ĳ���:");
	scanf("%d",&r);

	L->last = r-1;
	printf("���������Ա�ĸ�Ԫ��ֵ(�ֱ�Ϊѧ�š�������������Ӣ�C����):\n");
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
	printf("���Ա��ִ�Ԫ�أ�\n");
	int i;
	printf("ѧ��-----����-----����-----Ӣ��------C����\n");
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
    fp=fopen("ѧ����Ϣ.txt","w");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");
        return ;
    }
    int i;
    fprintf(fp,"ѧ��-----����-----����-----Ӣ��------C����------�ܳɼ�------ƽ����\n");
    for(i=0;i<=L->last;i++)
	{
		fprintf(fp,"%-9d%-9s%-9d%-10d%-11d%-12d%-10d\n",L->elem[i].num,L->elem[i].name,L->elem[i].math,L->elem[i].english,L->elem[i].c,L->elem[i].sum,L->elem[i].avg);
	}
	printf("�ļ��ɹ����浽��ѧ����Ϣ.txt����\n");
}

void fun1(seqlist *L)
{
	int i;
	printf("ѧ��-----����-----����-----Ӣ��------C����------�ܳɼ�\n");
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
	printf("ѧ��-----����-----����-----Ӣ��------C����------ƽ����\n");
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
    printf("��ѧ�Ų�ѯor������ѯ(1 or 2): ");
    scanf("%d",&x);
    if(x==1)
    {
        int number;
        printf("������ѧ��: ");
        scanf("%d",&number);
        int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
        while ((i<=L->last)&&(L->elem[i].num!=number))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
		printf("ѧ��-----����-----����-----Ӣ��------C����\n");
		printf("%-9d",L->elem[i].num);
		printf("%-9s",L->elem[i].name);
		printf("%-9d",L->elem[i].math);
		printf("%-10d",L->elem[i].english);
		printf("%-10d\n",L->elem[i].c);
    }
    else
    {
        printf("����������: ");
        char name1[20];
        scanf("%s",name1);
        int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
        while ((i<=L->last)&&strcmp(L->elem[i].name,name1))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
        printf("ѧ��-----����-----����-----Ӣ��------C����\n");
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
    printf("�����ܷ�����֮��Ľ����\n");
	printf("ѧ��-----����-----����-----Ӣ��------C����------�ܷ�\n");
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
    printf("������߷֣�%d ��ͷ֣�%d ƽ���֣�%d\n",L->math_max,L->math_min,L->math_avg);
    printf("Ӣ����߷֣�%d ��ͷ֣�%d ƽ���֣�%d\n",L->english_max,L->english_min,L->english_avg);
    printf("c������߷֣�%d ��ͷ֣�%d ƽ���֣�%d\n",L->c_max,L->c_min,L->c_avg);
}
void mean()
{
	seqlist l;
	int t;
	while(1)
	{
		printf("\t|--------------------------------------------------------------|\n");
		printf("\t|                      ѧ����Ϣ����                            |\n");
		printf("\t|                     1.����ѡ����Ϣ                           |\n");
		printf("\t|                     2.��ѯѡ����Ϣ                           |\n");
		printf("\t|                     3.����ѡ����Ϣ                           |\n");
		printf("\t|                     4.�޸�ѡ����Ϣ                           |\n");
		printf("\t|                     5.ɾ��ѡ����Ϣ                           |\n");
		printf("\t|                     6.�������ѡ����Ϣ                       |\n");
		printf("\t|                     7.�˳�������                             |\n");
		printf("\t|--------------------------------------------------------------|\n");
		printf("\t|                     8.�����ܷ�                               |\n");
		printf("\t|                     9.����ƽ����                             |\n");
		printf("\t|                     10.����/ѧ�Ų�ѯ                         |\n");
		printf("\t|                     11.�ܷ�����                              |\n");
		printf("\t|                     12.ͳ�Ʒ���                              |\n");
		printf("\t|--------------------------------------------------------------|\n");
		printf("������1-12:");
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
