#define MaxInt 32767 
#define MVNum 100
#define MAX_VERTEX_NUM
typedef char VerTexType;
typedef int ArcType;

//����ͼʮ������洢 
typedef struct ArcBox{
	int tailvex,headvex;	//�û���β��ͷ�����λ��
	struct ArcBox *hlink,*tlink;	//�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ������ 
	InfoType *info; 		//�û������Ϣ��ָ�� 
}Arcbox;
typedef struct VexNode{
	VertexType data;	
	ArcBox *firstin,*firstout;	//�ֱ�ָ��ö���ĵ�һ���뻡�ͳ��� 
}VexNode;
typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];	//��ͷ���� 
	int vexnnm,arcnum;				//����ͼ��ǰ�������ͻ��� 
}OLGraph; 
