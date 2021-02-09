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

typedef struct {
	int weight;
	int parent, lch, rch;
}HTNode,*HuffmanTree;

//例：第一个结点权重为5，即可表示为H[i].weight=5;

void CreatHuffmanTree(HuffmanTree HT, int n) {
	if (n <= 1)return;
	int m,i;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (i = 1; i <= m; i++) {
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}
	for (i = 1; i < n; i++) cin >> HT[i].weight;
	//初始化结束，下面开始建立哈夫曼树
	int s1, s2;
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1; HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}


//哈夫曼编码算法实现
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {
//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
	int c, i, start, f;
	HC = new char* [n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	for (i = 1; i <= n; i++) {
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lch == c) cd[start] = '0';
			else				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}//CreateHuffmanCode


