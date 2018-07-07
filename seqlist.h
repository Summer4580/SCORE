
#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/

struct Player
{
	double num;    //号码
	char name[20];   //姓名
	char sex[5];    //性别
	char play_name[20];    //表演名字
	char play_category[20]; //表演类别
	double score[10];   //分数
	double score_max;
	double score_min;
	double score_avg;
	double score_sum;
};
typedef struct Player ElemType;

struct Referee
{
	double num;    //号码
	char name[20];   //姓名
	char sex[5];
};
typedef struct Referee ElemType2;
typedef struct
{
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	ElemType2 elem2[MAXSIZE];
	int last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
	int last2;
}seqlist;

