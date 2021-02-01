#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 1000
typedef int Status;
typedef char QElemType; 

//˳����еĴ洢�ṹ 
typedef struct{
	QElemType *base;
	int front;	//ͷָ�� 
	int rear;	//βָ�� 
}SqQueue;

/*��ʼ�����front=rear
��ӣ�base[rear]=x;rear++;
���ӣ�x=base[front];front++;
�նӱ�־��front==rear;
��rear=MAXSIZE ������� ��������ͼ���� */

//���еĳ�ʼ��(˳���) 
Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXSIZE];
	if(!Q.base) exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

//����г���(˳���) 
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//���(˳���) 
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}

//����(˳���) 
Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.front==Q.rear) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
} 

//ȡ��ͷԪ�� (˳���) 
QElemType GetHead(SqQueue Q){
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
}


//���������Ͷ���
typedef struct Qnode{
	QElemType data;
	struct Qnode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;	//��ͷָ��
	QueuePtr rear;	//��βָ�� 
}LinkQueue;

//�����г�ʼ��
Status InitQueue_Link(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front) exit (OVERFLOW);
	Q.front->next=NULL;
	return OK;
} 

//�����е�����
Status DestroyQueue(LinkQueue &Q){
	QueuePtr p;
	while(Q.front){
	p=Q.front->next;
	free(Q.front);
	Q.front=p; }
} 

//��ӣ������У�
Status Inqueue_Link(LinkQueue &Q,QElemType e){
	QueuePtr p;
	p=new QNode;
	if(!p) exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
} 

//���ӣ������У� 
Status DeQueue_Link(LinkQueue &Q,QElemType &e){
	QueuePtr p;
	if(Q.front==Q.rear) return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	delete p;
	return OK;
}
