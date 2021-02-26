//堆排序

//筛选法调整堆
void HeapAdjust(SqList& L, int s, int m) {
	//假设r[s+1..m]已经是堆，将r[s..m]调整为以r[s]为根的大根堆
	rc = L.r[s];
	for (j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j].key < L.r[j + 1].key) j++;	//j为左右孩子的较大下标
		if (rc.key >= L.r[j].key) break;	//形成大根退出循环，rc插在s上
		L.r[s] = L.r[j];					//否则将大的值置于根部
		s = j;								//将其余的继续形成大根堆
	}
	L.r[s] = rc;							//rc插入s上
}

//建初堆
void CreatHeap(SqList& L) {
	//把无序序列L.r[1..n]建成大根堆
	n = L.length;
	for (i = n / 2; i > 0; i--) {
		HeapAdjust(L, i, n);
	}
}

//堆排序
void HeapSort(SqList& L) {
	//对顺序表L进行堆排序
	CreatHeap(L);
	for (i = L.length; i > 1; i--) {
		x = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}
//即每次均将未排序的最后一个记录与堆顶记录互换，这样最大值每次都会沉下去

//空间复杂度O(1)
//不稳定排序
//不能用于链式结构
//记录较少时不宜使用，记录较多高效