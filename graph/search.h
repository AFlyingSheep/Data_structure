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

//深度优先搜索遍历算法实现
void DFS(AMGraph G,int v){
	cout<<v;
	visited[v]=true;
	for(w=0;w<G.vexnum;w++){
		if((G.arcs[v][w]!=0)&&(!visited[w]))
		DFS(G,w);
		//w是v的邻接点，如果w未访问，则递归调用DFS 
	}
} 

//广度优先搜索 
void BFS(Graph G,int v){
	cout<<v;	//访问第v个顶点 
	visited[v]=true;	 
	InitQueue(Q);		//辅助队列Q初始化并置空 
	EnQueue(Q,v);		//v进队 
	while(!QueueEmpty(Q)){	//队列非空 
		DeQueue(Q,u);		//队头元素出队 并置为u 
		for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex((G,u,w)))	
		if(!visited[w]){	//w为u的尚未访问的邻接顶点 	
			cout<<w;
			visited[w]=true;
			EnQueue(Q,w);	//w进队 
		}
	}
} 
