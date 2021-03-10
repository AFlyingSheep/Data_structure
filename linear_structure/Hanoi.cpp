#include<stdio.h>

void hanoi(int n,char A,char B,char C){
	if(n==1) printf("%c-->%c ",A,C);
	else{
		hanoi(n-1,A,C,B);
		printf("%c-->%c ",A,C);
		hanoi(n-1,B,A,C);
	}
}

int main(){
	int n=100;
	char A='A',B='B',C='C';
	hanoi(n,A,B,C);
}
