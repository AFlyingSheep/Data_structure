#include<stdlib.h>
#include"�������.h"
#include"˳������.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 1000
typedef int Status;
typedef char ElemType; 

void MergeList(List &LA,List &LB){
	//�����������Ա�LB�е�����LA�е����ݲ��뵽LA�� 
	ElemType e;
	m=ListLength(LA);
	n=ListLength(LB);
	for(i=1;i<=n;i++){
		GetElem(LB,i,e);
		if(!LocateElem(LA,e))
			ListInsert(LA,++m,e);
	}
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC){
	//��֪˳�������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	SqList *pa,*pb,*pc,*pa_last,*pb_last;
	LC.length=LA.length+LB.length;
	LC.elem=new ElemType[LC.length];
	pc=LC.elem;
	pa=LA.elem,pb=LB.elem;
	pa_last=LA.elem+LA.length-1;
	pb_last=LB.elem+LB.length-1;
	while((pa<pa_last)&&(pb<=pb_last)){
		if(*pa<=*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;
	while(pb<=pb_last) *pc++=*pb++;
} 

void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC){
	//��֪������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢LA��LB�õ�LC��LCԪ�� ��ֵ�ǵݼ�����
	LinkList pa,pb,pc;
	pa=LA->next;pb=LB->next;
	LC=LA;
	pc=LC;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next; 
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next; 
		}
	}
	pc->next=pa?pa:pb;
	delete LB;
} 

