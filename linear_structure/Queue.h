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

//顺序队列的存储结构 
typedef struct{
	QElemType *base;
	int front;	//头指针 
	int rear;	//尾指针 
}SqQueue;

/*初始情况：front=rear
入队：base[rear]=x;rear++;
出队：x=base[front];front++;
空队标志：front==rear;
当rear=MAXSIZE 发生溢出 ：真溢出和假溢出 */

//队列的初始化(顺序表) 
Status InitQueue(SqQueue &Q){
	Q.base=new QElemType[MAXSIZE];
	if(!Q.base) exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

//求队列长度(顺序表) 
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//入队(顺序表) 
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}

//出队(顺序表) 
Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.front==Q.rear) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
} 

//取队头元素 (顺序表) 
QElemType GetHead(SqQueue Q){
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
}


//链队列类型定义
typedef struct Qnode{
	QElemType data;
	struct Qnode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;	//队头指针
	QueuePtr rear;	//队尾指针 
}LinkQueue;

//链队列初始化
Status InitQueue_Link(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front) exit (OVERFLOW);
	Q.front->next=NULL;
	return OK;
} 

//链队列的销毁
Status DestroyQueue(LinkQueue &Q){
	QueuePtr p;
	while(Q.front){
	p=Q.front->next;
	free(Q.front);
	Q.front=p; }
} 

//入队（链队列）
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

//出队（链队列） 
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
