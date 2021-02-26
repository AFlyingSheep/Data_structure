//插入排序

//直接插入排序
void InsertSort(SqList &L) {
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];
			L.r[i] = L.r[i - 1];
			for (j = i - 2; L.r[0].key < L.r[j]; j--)
				L.r[j + 1] = L.r[j];
			L.r[j + 1] = L.r[0];
		}
	}
 }

//折半插入排序
void BInsertSort(SqList& L) {
	for (i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];
		low = 1; high = i - 1;
		while (low <= high) {
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key) high = m - 1;
			else low = m + 1;
		}
		for (j = i - 1; j >= high + 1; j--) L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
	}
}

//希尔排序
void ShellInsert(SqList& L, int dk) {
	//对顺序表L做一趟增量是dk的希尔插入排序
	for(i=dk+1;i<L.length;i++)
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk) 
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
}

void ShellSort(SqList& L, int dt[], int t) {
	//按照增量序列dt对顺序表L作t趟希尔排序
	for (k = 0; k < t; k++)
		ShellInsert(L, dt[k]);
}

//以上三种排序空间复杂度均为O(1)，即用到r[0]存储
//直接插入排序可以用于顺序结构和链式结构，希尔排序和折半插入排序均只能用于顺序结构

