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

//˳��ջ�Ĵ洢�ṹ 
typedef struct{
	SElemType *base;	//ջ��ָ�� 
	SElemType *top;		//ջ��ָ�� 
	int stacksize;		//ջ����������� 
}SqStack;

//ջ�ĳ�ʼ��(˳��ջ) 
Status InitStack(SqStack &S){
	S.base=new SElemType[MAXSIZE];
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
} 

//��ջ(˳��ջ)
Status Push(SqStack &S,SElemType e){
	if(S.top-S.base==S.stacksize) return ERROR;
	*S.top++=e;
	return OK;
} 

//��ջ(˳��ջ)
Status Pop(SqStack &S,SElemType &e){
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
} 

//ȡջ��Ԫ��(˳��ջ)
SElemType GetTop(SqStack S){
	if(S.top!=S.base)
		return *(S.top-1);
} 

//��ջ�Ĵ洢�ṹ 
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;
/*��ջ��ͷ�ڵ㣬��ͷָ��ָ��ջ��������ͷ�巨*/

//��ջ�ĳ�ʼ��
Status InitStack_Link(LinkStack &S){
	S=NULL;
	return OK;
} 

//��ջ����ջ��
Status Push_Link(LinkStack &S,SElemType e){
	LinkStack p;
	p=new StackNode;
	p->data=e;
	p->next=S;		//��ͷ�ڵ㣬����p->next=S!!! 
	S=p;
	return OK;
} 

//��ջ����ջ��
Status Pop_Link(LinkStack &S,SElemType &e){
	LinkStack p;
	if(S==NULL) return ERROR;
	e=S->data;
	p=S;
	S=S->next;
	delete p;
	return OK;
} 

//ȡջ��Ԫ�أ���ջ��
SElemType GetTop_Link(LinkStack S){
	if(S!=NULL)	return S->data;
} 

