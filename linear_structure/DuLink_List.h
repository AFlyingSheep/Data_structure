#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 1000
typedef int Status;
typedef char ElemType; 

//双向链表存储结构
typedef struct DulNode{
	ElemType data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode,*DuLinkList;

//双向链表插入
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	DuLinkList s,p;
	if(!(p=GetElem_DuL(L,i)))
		return ERROR;
	s=new DulNode;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
} 

//双向链表删除
Status ListDelete_DuL(DuLinkList &L,int i){
	DuLinkList s,p;
	if(!(p=GetElem_DuL(L,i)))
		return ERROR;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
	return OK;
} 
