#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100 
typedef int Status;
typedef char TElemType;

//����������������㷨ʵ��
void DFS(AMGraph G,int v){
	cout<<v;
	visited[v]=true;
	for(w=0;w<G.vexnum;w++){
		if((G.arcs[v][w]!=0)&&(!visited[w]))
		DFS(G,w);
		//w��v���ڽӵ㣬���wδ���ʣ���ݹ����DFS 
	}
} 

//����������� 
void BFS(Graph G,int v){
	cout<<v;	//���ʵ�v������ 
	visited[v]=true;	 
	InitQueue(Q);		//��������Q��ʼ�����ÿ� 
	EnQueue(Q,v);		//v���� 
	while(!QueueEmpty(Q)){	//���зǿ� 
		DeQueue(Q,u);		//��ͷԪ�س��� ����Ϊu 
		for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex((G,u,w)))	
		if(!visited[w]){	//wΪu����δ���ʵ��ڽӶ��� 	
			cout<<w;
			visited[w]=true;
			EnQueue(Q,w);	//w���� 
		}
	}
} 
