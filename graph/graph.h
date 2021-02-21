#define MaxInt 32767 
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

//�ڽӾ��󴢴��
typedef struct{
	VerTexType vexs[MVNum];		//����� 
	ArcType arcs[MVNum][MVNum];	//	�ڽӾ��� 
	int vexnum,arcnum;			//ͼ��ǰ�ĵ����ͱ��� 
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
		i=LocateVex(G,v1);	//	ȷ��v1��v2��G�е�λ��
		j=LocateVex(G,v2);
		G.arcnum[i][j]=w;
		G.arcnum[j][i]= G.arcnum[i][j];	
	}
	return OK;
}


//�ڽӱ�

//���洢�ṹ
typedef struct VNode{
	VerTexType data;	//�����Ϣ 
	ArcNode *firstarc;
}VNode,AdjList[MVNum];	//AdjList��ʾ�ڽӱ����� 
//�ߵĴ洢�ṹ 
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	OtherInfo info;
}ArcNode;

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

//�����ڽӱ��ʾ������������
Status CreatUDG(ALGraph &G){
	int i,j,k;
	cin>>G.vexnum>>G.arcnum;
	for(i=0;i<G.vexnum;i++){		//������㣬�����ͷ����
		cin>>G.vertices[i].data;	//���붥��ֵ
		G.vertices[i].firstarc=NULL;//��ʼ����ͷ���							 
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
