#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100 
typedef int Status;
typedef char TElemType;

//˫�ױ�﷨
typedef struct PTNode{
	TElemType data;
	int parent; //˫��λ���� 
}PTNode;
//���ṹ
#define MAX_TREE_SIZE 100
typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;	//���ڵ��λ�úͽڵ���� 
}PTree; 
//����˫�� �����Һ���

//��������
//���ӽ��ṹ
typedef struct CTNode {
	int child;
	struct CTNode* next;
}*ChildPtr;
//���ṹ
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;	//������͸�����λ��
}CTree;
//���Һ��� ������˫��

//�����ֵܱ�ʾ������������ʾ����
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
//һ��ָ��ָ���һ�����ӣ���һ��ָ���ֵܽ��
//�Һ����ֵ����� ��˫����