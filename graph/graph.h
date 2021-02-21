#define MaxInt 32767 
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

//邻接矩阵储存表
typedef struct{
	VerTexType vexs[MVNum];		//顶点表 
	ArcType arcs[MVNum][MVNum];	//	邻接矩阵 
	int vexnum,arcnum;			//图当前的点数和遍数 
}AMGraph;	 

//
Status CreateUDN(AMGraph &G){
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	for(i=0;i<G.vexnum;i++)
		for(j=0;J<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);	//	确定v1和v2在G中的位置
		j=LocateVex(G,v2);
		G.arcnum[i][j]=w;
		G.arcnum[j][i]= G.arcnum[i][j];	
	}
	return OK;
}


//邻接表

//结点存储结构
typedef struct VNode{
	VerTexType data;	//结点信息 
	ArcNode *firstarc;
}VNode,AdjList[MVNum];	//AdjList表示邻接表类型 
//边的存储结构 
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	OtherInfo info;
}ArcNode;

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

//采用邻接表表示法创建无向网
Status CreatUDG(ALGraph &G){
	int i,j,k;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++){		//输入各点，构造表头结点表
		cin>>G.vertices[i].data;	//输入顶点值
		G.vertices[i].firstarc=NULL;//初始化表头结点							 
	}
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		ArcNode *p1,*p2;
		p1=new ArcNode;
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		p2=new ArcNode;
		p2->adjvex=i;
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
	} 
	return OK;
}
