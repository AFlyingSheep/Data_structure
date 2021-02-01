#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 255 
#define CHUNKSIZE 80 
typedef int Status;
typedef char ElemType; 

typedef struct{
	char ch[MAXLEN+1];	//�洢����һά���� 
	int length;			//���ĵ�ǰ����
}SString; 
//һ���һλ���棬��1-255��0λ����

typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;	//�������壬�洢�ܶ�ΪCHUNKSIZE/(CHUNKSIZE+4)

typedef struct{
	Chunk *head,*tail;	//����ͷָ�룬βָ�� 
	int curlen;			//����ǰ���� 
}LString;
 
//ģʽƥ��(�����ƽⷨ) 
int Index_BF(SString S,SString T){
	int i=1,j=1;
	while(i<=S.length&&j<=T.length){
	if(S.ch[i]==T.ch[j]){
		i++;j++;
	} 					//�����Ӵ�����ƥ����һ���ַ� 
	else{
		i=i-j+2;j=1;	//ָ���������һ��ƥ�� 
	}}
	if(j>=T.length) return i-T.length; 
	else return 0;
}

//ģʽƥ�䣨KMP�㷨��
int Index_KMP(SString S,SString T,int pos){
	int i=pos,j=1;
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]==T.ch[j]){
			i++;j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>T.length) return i-T.length;
	else return 0;
} 

void get_next(SString T,int &next[]){
	int i=1,j=0;
	next[1]=0; 
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			i++;j++;
			next[i]=j;
		}
		else j=next[j];
	}
}

void get_nextval(SString T,int &nextval[]){
	int i=1;
	nextval[1]=0;
	int j=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;++j;
			if(T.ch[i]!=T.ch[j]) nextval[i]=j;
			else nextval[i]=nextval[j]; 
		}
	}	else j=nextval[j];
}


