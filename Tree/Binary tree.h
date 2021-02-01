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

//��������˳��洢��ʾ 
typedef TElemType SqBiTree[MAXSIZE];
SqBiTree bt;

//�������Ķ�������
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��������������㷨���ݹ��㷨�� 
Status PreOrderTraverse(BiTree T){
	if(T==NULL) return OK;//�ն�����
	else{
		visit(T);//���ʸ��ڵ�
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild); 
	} 
} 

//�������
Status InOrderTraverse(BiTree T){
	if(T==NULL) return OK;
	else{
		InOrderTraverse(T->lchild);
		visit(T);
		InOrderTraverse(T->rchild);
	}
} 

//�������
Status PostOrderTraverse(BiTree T){
	if(T==NULL) return OK;
	else{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T);
	}
} 


//��������ķǵݹ��㷨
Status InOrderTraverse_(BiTree T){
	BiTree p;
	BiTree q;
	InitStatck(S);
	p=T;
	while(p||!StackEmpty(S)){
		if(p){
			Push(S,p); p=p->lchild;
		}
		else{
			Pop(S,q);
			printf("%c",q->data);
			p=q->rchild; 
		}
	}
	return OK;
} 


//��������α���
void LevelOrder(BiTNode *b){
	BiTNode *p;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,b);
	while(!QueueEmpty(qu)){	//���в�Ϊ�գ�ѭ�� 
		deQueue(qu,p);	//p���� 
		printf("%c",p->data);	//����p 
		if(p->lchild!=NULL)	enQueue(qu,p->lchild);	//p�����ӣ�������� 
		if(p->rchild!=NULL) enQueue(qu,p->rchild);	//p���Һ��ӣ��Һ������ 
	}
} 


//����������
Status CreateBiTree(BiTree &T){
	scanf(&ch);
	if(ch=="#") T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
} 

//���ƶ�����
Status Copy(BiTree T,BiTree &NewT){
	if(T==NULL){
		NewT=NULL;
		return 0;
	}
	else{
		NewT=new BiTNode;
		Copy(T->lchild,NewT->lchild);
		Copy(T->rchild,NewT->rchild);
	}
} 

//������������
int Depth(BiTree T){
	int m,n;
	if(T==NULL) return 0;
	else{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n) return(m+1);
		else return(n+1);
	}
} 

//����������������
int NodeCount(BiTree T){
	if(T==NULL) return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
} 

//����Ҷ�ӽ����
int LeafCount(BiTree T){
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild==NULL) return 1;
	else return LeafCount(T->lchild)+LeafCount(T->rchild);
} 



