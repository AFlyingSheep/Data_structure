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

typedef struct{
	ElemType *elem;
	int length;
}SqList;

//��ʼ��˳��� 
Status InitList(SqList &L){	
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	return OK;
}				

//˳���ȡֵ
Status GetElem(SqList L,int i,ElemType &e){
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}				

//˳������
Status LocateElem(SqList L,ElemType e){
	int i;
	for(i=0;i<L.length;i++)
		if(L.elem[i]==e) return i+1;
	return 0;
} 				

//˳������
Status ListInsert(SqList &L,int i,ElemType e){
	int j;
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return ERROR;
	for(j=L.length-1;j>=i-1;j--)	//����λ��Ԫ�ؼ�֮��Ԫ�غ��� 
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;					//���¼�Ԫ�ط����i��λ�� 
	++L.length;
	return OK;
} 				 

//˳���ɾ��
Status ListDelete(SqList &L,int i){
	int j;
	if((i<1)||(i>L.length)) return ERROR;
	for(j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
} 				

 
