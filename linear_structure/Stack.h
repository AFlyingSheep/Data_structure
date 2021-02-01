#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 1000
typedef int Status;
typedef char SElemType; 
typedef char ElemType;

//顺序栈的存储结构 
typedef struct{
	SElemType *base;	//栈底指针 
	SElemType *top;		//栈顶指针 
	int stacksize;		//栈可用最大容量 
}SqStack;

//栈的初始化(顺序栈) 
Status InitStack(SqStack &S){
	S.base=new SElemType[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
} 

//入栈(顺序栈)
Status Push(SqStack &S,SElemType e){
	if(S.top-S.base==S.stacksize) return ERROR;
	*S.top++=e;
	return OK;
} 

//出栈(顺序栈)
Status Pop(SqStack &S,SElemType &e){
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
} 

//取栈顶元素(顺序栈)
SElemType GetTop(SqStack S){
	if(S.top!=S.base)
		return *(S.top-1);
} 

//链栈的存储结构 
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;
/*链栈无头节点，且头指针指向栈顶，运用头插法*/

//链栈的初始化
Status InitStack_Link(LinkStack &S){
	S=NULL;
	return OK;
} 

//入栈（链栈）
Status Push_Link(LinkStack &S,SElemType e){
	LinkStack p;
	p=new StackNode;
	p->data=e;
	p->next=S;		//无头节点，所以p->next=S!!! 
	S=p;
	return OK;
} 

//出栈（链栈）
Status Pop_Link(LinkStack &S,SElemType &e){
	LinkStack p;
	if(S==NULL) return ERROR;
	e=S->data;
	p=S;
	S=S->next;
	delete p;
	return OK;
} 

//取栈顶元素（链栈）
SElemType GetTop_Link(LinkStack S){
	if(S!=NULL)	return S->data;
} 

