
#define	MAXSIZE  100   /*�˴��ĺ궨�峣����ʾ���Ա���ܴﵽ����󳤶�*/

struct Player
{
	double num;    //����
	char name[20];   //����
	char sex[5];    //�Ա�
	char play_name[20];    //��������
	char play_category[20]; //�������
	double score[10];   //����
	double score_max;
	double score_min;
	double score_avg;
	double score_sum;
};
typedef struct Player ElemType;

struct Referee
{
	double num;    //����
	char name[20];   //����
	char sex[5];
};
typedef struct Referee ElemType2;
typedef struct
{
	ElemType  elem[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	ElemType2 elem2[MAXSIZE];
	int last;    /*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
	int last2;
}seqlist;

