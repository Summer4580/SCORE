
#include "common.h"
#include "seqlist.h"

int  Locate(seqlist L,double num)
{
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last)&&(L.elem[i].num!=num))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
	if  (i<=L.last)
	{
		return(i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	}

	else
	{
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
		return(-1);  /*��û�ҵ����򷵻ؿ����*/

	}
}
int  Locate2(seqlist L,double num)
{
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last2)&&(L.elem2[i].num!=num))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
	if  (i<=L.last2)
	{
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
	int temp,x,i,j;
	double q;
	printf("������1 or 2ѡ�����ѡ�ֻ��ǲ��У�");
	scanf("%d",&x);
	if(x==1)
    {
        printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
        scanf("%lf",&q);
        temp=Locate(*L,q)-1;
        if(temp!=-1)
        {
            printf("�绰-----------����-----�Ա�-----��������------�������--����----1------2------3------4------5------6------7------8------9------10-----���÷�\n");
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
        printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
        scanf("%lf",&q);
        temp=Locate2(*L,q)-1;
        if(temp!=-1)
        {
            printf("�绰-----------����-----�Ա�\n");
            printf("%-15.0lf",L->elem[temp].num);
            printf("%-9s",L->elem[temp].name);
            printf("%-9s",L->elem[temp].sex);
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
    int i,q;
    int x;
    double tem;
    printf("������1 or 2ѡ���޸�ѡ�ֻ��ǲ��У�");
	scanf("%d",&x);
	if(x==1)
    {
       printf("������Ҫ�޸ĵĵ绰��\n");
        scanf("%lf",&tem);
        q=Locate(*L,tem);
        if(q==-1)
        {
            printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
            return ;
        }
        else
        {
            L->elem[q-1].score_max=0;
            L->elem[q-1].score_sum=0;
            L->elem[q-1].score_min=10;
            printf("�������ȥ�绰�������Ϣ:\n");
            printf("����: ");
            scanf("%s",L->elem[q-1].name);
            printf("�Ա�: ");
            scanf("%s",L->elem[q-1].sex);
            printf("��Ŀ����: ");
            scanf("%s",L->elem[q-1].play_name);
            printf("��Ŀ����: ");
            scanf("%s",L->elem[q-1].play_category);
            printf("��ί����(%d��): ",L->last2+1);
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
            printf("��Ϣ�޸���ɣ�\n");
        }
    }
    else
    {
        printf("������Ҫ�޸��˵ĵ绰��\n");
        scanf("%lf",&tem);
        q=Locate2(*L,tem);
        if(q==-1)
        {
            printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
            return ;
        }
        else
        {
            printf("�������ȥ�绰�������Ϣ:\n");
            printf("����: ");
            scanf("%s",L->elem2[q-1].name);
            printf("�Ա�: ");
            scanf("%s",L->elem2[q-1].sex);
            printf("��Ϣ�޸���ɣ�\n");
        }
    }
}

void Delete(seqlist *L)
{
	int j;
	int i,x;
	double q;
	printf("������1 or 2ѡ��ɾ��ѡ�ֻ��ǲ��У�");
	scanf("%d",&x);
	if(x==1)
    {
        printf("������Ҫɾ����Ԫ��:\n");
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
            printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
            onput(L,x);
        }
    }
    else
    {
        printf("������Ҫɾ����Ԫ��:\n");
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
            printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
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
    printf("������1 or 2 ѡ��Ҫ����ѡ�ֻ��ǲ���: ");
    int w;
    scanf("%d",&w);
    if(w==1)
    {
        x1.score_max=0;
        x1.score_min=10;
        x1.score_sum=0;
        printf("������ѡ�ֵ���Ϣ:\n");
        printf("�绰: ");
        scanf("%lf",&x1.num);
        int temp;
        temp=Locate(*L,x1.num);
        if(temp==-1)
        {
            printf("������ĺ����ظ�!�����²���\n");
            return ;
        }
        printf("����: ");
        scanf("%s",x1.name);
        printf("�Ա�: ");
        scanf("%s",x1.sex);
        printf("��Ŀ����: ");
        scanf("%s",x1.play_name);
        printf("��Ŀ���: ");
        scanf("%s",x1.play_category);
        printf("������ѡ�ֵ�%d�ŷ���: ",L->last2+1);
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
        printf("��Ϣ¼����ɣ�\n");
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
        L->elem[i-1]=x1;
        L->last++;
        onput(L,1);
        return 1;
    }
    else
    {
        printf("������Ҫ�����Ԫ��:\n");
        printf("�绰: ");
        scanf("%lf",&x2.num);
        int temp;
        temp=Locate2(*L,x2.num);
        if(temp==-1)
        {
            printf("������ĺ����ظ�!,�����²���\n");
            return ;
        }
        printf("����: ");
        scanf("%s",x2.name);
        printf("�Ա�: ");
        scanf("%s",x2.sex);
        printf("��Ϣ¼����ɣ�\n");
        printf("������Ҫ�����Ԫ�ص�λ��:\n");
        scanf("%d",&i);

        int j;

        if(L->last2==MAXSIZE-1)
        {
            printf(" ����\n");
            return 0;
        }
        if(i<1||i>L->last2+2)
        {
            printf("λ�򲻺Ϸ�\n");
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
            if(array[i].score_avg > array[begin].score_avg)  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
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

        if(array[i].score_avg >= array[begin].score_avg)  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
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
	int r,i,j;
    printf("������1 or 2ѡ�����ѡ����Ϣ���ǲ�����Ϣ: ");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        printf("���������Ա�ĳ���:");
        scanf("%d",&r);

        L->last = r-1;
        for(i=0;i<=L->last;i++)
        {
            L->elem[i].score_max=0;
            L->elem[i].score_min=10;
            L->elem[i].score_sum=0;
            printf("������ѡ�ָ�����Ϣ��\n");
            printf("�绰��");
            scanf("%lf",&L->elem[i].num);
            printf("������");
            scanf("%s",L->elem[i].name);
            printf("�Ա�");
            scanf("%s",L->elem[i].sex);
            printf("��Ŀ���ƣ�");
            scanf("%s",L->elem[i].play_name);
            printf("��Ŀ���");
            scanf("%s",L->elem[i].play_category);
            printf("��ί���(%d��)��",L->last2+1);
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
        printf("���������Ա�ĳ���:");
        scanf("%d",&r);

        L->last2 = r-1;
        printf("���������Ա�ĸ�Ԫ��ֵ:\n");
        for(i=0; i<=r-1; i++)
        {
            printf("�绰: ");
            scanf("%lf",&L->elem2[i].num);
            printf("����: ");
            scanf("%s",L->elem2[i].name);
            printf("�Ա�: ");
            scanf("%s",L->elem2[i].sex);
        }
        onput(L,x);
    }
}

void onput(seqlist *L,int x)
{
    if(x==1)
    {
        printf("-------------------------------------------ѡ�֣�\n");
        int i,j;
        for(i=0;i<=L->last;i++)
        {
            printf("�绰-----------����-----�Ա�-----��������------�������--����----1------2------3------4------5------6------7------8------9------10-----���÷�\n");
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

        printf("-------------------------------------------���У�\n");
        int i,j;

        for(i=0;i<=L->last2;i++)
        {
            printf("�绰-----------����-----�Ա�\n");
            printf("%-15.0lf",L->elem2[i].num);
            printf("%-9s",L->elem2[i].name);
            printf("%-9s\n",L->elem2[i].sex);
        }
    }


}

void save(seqlist *L)
{
    FILE *fp;
    fp=fopen("ѡ����Ϣ.csv","w");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");
        return ;
    }
    int i,j;
    fprintf(fp,"�绰,����,�Ա�,��������,�������,����,1,2,3,4,5,6,7,8,9,10,���÷�\n");
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
	printf("�ļ��ɹ����浽��ѧ����Ϣ.csv����\n");
	fp=fopen("������Ϣ.csv","w");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");
        return ;
    }
    fprintf(fp,"�绰,����,�Ա�\n");
    for(i=0;i<=L->last2;i++)
        {
            fprintf(fp,"%.0lf,",L->elem2[i].num);
            fprintf(fp,"%s,",L->elem2[i].name);
            fprintf(fp,"%s\n",L->elem2[i].sex);
        }
	printf("�ļ��ɹ����浽��������Ϣ.csv����\n");
}

void login(seqlist *L)
{
    FILE *fp;
    char s[1000];
    int i,j;
    i=0;
    fp=fopen("������Ϣ.csv","r");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷���ȡ��\n");
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
    printf("������Ϣ��ȡ�ɹ���\n");
    fclose(fp);
    i=0;
    fp=fopen("ѡ����Ϣ.csv","r");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷���ȡ��\n");
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
    printf("ѧ����Ϣ��ȡ�ɹ���\n");
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
		printf("\t|                      ������Ϣ����                            |\n");
		printf("\t|                     1.������Ϣ                               |\n");
		printf("\t|                     2.��ѯ��Ϣ                               |\n");
		printf("\t|                     3.������Ϣ                               |\n");
		printf("\t|                     4.�޸���Ϣ                               |\n");
		printf("\t|                     5.ɾ����Ϣ                               |\n");
		printf("\t|                     6.ѡ�ַ�������                           |\n");
		printf("\t|                     7.���ѡ����Ϣ                           |\n");
		printf("\t|                     8.���������Ϣ                           |\n");
		printf("\t|                     9.��ȡ�ļ�                               |\n");
		printf("\t|                     10.�˳�������                             |\n");
		printf("\t|--------------------------------------------------------------|\n");

		printf("������1-10:");
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
