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
typedef char ElemType; 

//线性链表定义
typedef struct LNode{	
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;	

//链表初始化
Status InitList(LinkList &L){	
	L=new LNode;
	L->next=NULL;
	return OK;
} 				

//链表取值
Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p; 
	p=L->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i) return ERROR;
	e=p->data;
	return OK;
} 				

//按值查找 返回地址
LinkList LocateElem(LinkList L,ElemType e){
	LinkList p;
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;
} 				

//链表插入
Status ListInsert(LinkList &L,int i,ElemType e){
	LinkList p,s;
	int j=0;
	p=L;
	while(p&&(j<i-1)){
		p=p->next;++j;}
	if(!p||j>i-1) return ERROR;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
} 				

//链表删除 
Status ListDelete(LinkList &L,int i){
	LinkList p,q;
	p=L;int j=0;
	while((p->next)&&(j<i-1)){
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1)) return ERROR;
	q=p->next;
	p->next=q->next;
	delete q;
	return OK;
} 				

//创建链表--前插法
void CreateList_H(LinkList &L,int n){
	int i;LinkList p;
	L=new LNode;
	L->next=NULL;
	for(i=0;i<n;i++){
		p=new LNode;
		scanf("%s",p->data);
		p->next=L->next;
		L->next=p;
	}
} 

//创建链表--尾插法
void CreateList_R(LinkList &L,int n){
	int i;LinkList p,r;
	L=new LNode;
	L->next=NULL;
	r=L;
	for(i=0;i<n;i++){
		p=new LNode;
		scanf("%s",p->data);
		p->next=NULL;
		r->next=p;
		r=p;
	}
} 

