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

//双亲表达法
typedef struct PTNode{
	TElemType data;
	int parent; //双亲位置域 
}PTNode;
//树结构
#define MAX_TREE_SIZE 100
typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;	//根节点的位置和节点个数 
}PTree; 
//好找双亲 不好找孩子

//孩子链表
//孩子结点结构
typedef struct CTNode {
	int child;
	struct CTNode* next;
}*ChildPtr;
//树结构
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;	//结点数和根结点的位置
}CTree;
//好找孩子 不好找双亲

//孩子兄弟表示法（二叉树表示法）
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
//一个指针指向第一个孩子，另一个指向兄弟结点
//找孩子兄弟容易 找双亲难