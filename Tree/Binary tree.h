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

//二叉树的顺序存储表示 
typedef TElemType SqBiTree[MAXSIZE];
SqBiTree bt;

//二叉树的二叉链表
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//二叉树先序遍历算法（递归算法） 
Status PreOrderTraverse(BiTree T){
	if(T==NULL) return OK;//空二叉树
	else{
		visit(T);//访问根节点
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild); 
	} 
} 

//中序遍历
Status InOrderTraverse(BiTree T){
	if(T==NULL) return OK;
	else{
		InOrderTraverse(T->lchild);
		visit(T);
		InOrderTraverse(T->rchild);
	}
} 

//后序遍历
Status PostOrderTraverse(BiTree T){
	if(T==NULL) return OK;
	else{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T);
	}
} 


//中序遍历的非递归算法
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


//二叉树层次遍历
void LevelOrder(BiTNode *b){
	BiTNode *p;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,b);
	while(!QueueEmpty(qu)){	//队列不为空，循环 
		deQueue(qu,p);	//p出队 
		printf("%c",p->data);	//访问p 
		if(p->lchild!=NULL)	enQueue(qu,p->lchild);	//p有左孩子，左孩子入队 
		if(p->rchild!=NULL) enQueue(qu,p->rchild);	//p有右孩子，右孩子入队 
	}
} 


//创建二叉树
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

//复制二叉树
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

//计算二叉树深度
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

//计算二叉树结点总数
int NodeCount(BiTree T){
	if(T==NULL) return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
} 

//计算叶子结点数
int LeafCount(BiTree T){
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild==NULL) return 1;
	else return LeafCount(T->lchild)+LeafCount(T->rchild);
} 



