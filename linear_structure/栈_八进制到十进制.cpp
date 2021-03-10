#include<stdio.h>
#define MAX 100
typedef struct {
	int *base;
	int *top;
	int length=MAX;
}Sqstack;

void Init(Sqstack &s){
	s.base=new int[MAX];
	s.top=s.base;
}

int In_stack(Sqstack &s,int e){
	if(s.top-s.base==s.length) return 0;
	*s.top++=e;
	return 1;
}

int Out_stack(Sqstack &s,int &e){
	if(s.top==s.base) return 0;
	e=*--s.top;
	return 1;
}

void trans(int a){
	int n=0;
	int t=0;
	int asa=0;
	Sqstack s;
	Init(s);
	while(a>=1){
		n=a%8;
		In_stack(s,n);
		a=a/8;
	}
	asa=Out_stack(s,t); 
	while(asa!=0){
		printf("%d",t);
		asa=Out_stack(s,t); 
	}
} 

int main(){
	trans(231231);
}
