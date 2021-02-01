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
	char ch[MAXLEN+1];	//存储串的一维数组 
	int length;			//串的当前长度
}SString; 
//一般第一位不存，从1-255，0位空着

typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;	//块链定义，存储密度为CHUNKSIZE/(CHUNKSIZE+4)

typedef struct{
	Chunk *head,*tail;	//串的头指针，尾指针 
	int curlen;			//串当前长度 
}LString;
 
//模式匹配(暴力破解法) 
int Index_BF(SString S,SString T){
	int i=1,j=1;
	while(i<=S.length&&j<=T.length){
	if(S.ch[i]==T.ch[j]){
		i++;j++;
	} 					//主串子串依次匹配下一个字符 
	else{
		i=i-j+2;j=1;	//指针回溯至下一次匹配 
	}}
	if(j>=T.length) return i-T.length; 
	else return 0;
}

//模式匹配（KMP算法）
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


