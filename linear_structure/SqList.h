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

//初始化顺序表 
Status InitList(SqList &L){	
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	return OK;
}				

//顺序表取值
Status GetElem(SqList L,int i,ElemType &e){
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}				

//顺序表查找
Status LocateElem(SqList L,ElemType e){
	int i;
	for(i=0;i<L.length;i++)
		if(L.elem[i]==e) return i+1;
	return 0;
} 				

//顺序表插入
Status ListInsert(SqList &L,int i,ElemType e){
	int j;
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return ERROR;
	for(j=L.length-1;j>=i-1;j--)	//插入位置元素及之后元素后移 
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;					//将新加元素放入第i个位置 
	++L.length;
	return OK;
} 				 

//顺序表删除
Status ListDelete(SqList &L,int i){
	int j;
	if((i<1)||(i>L.length)) return ERROR;
	for(j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
} 				

 
