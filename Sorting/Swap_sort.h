//交换排序

//冒泡排序
void BubbleSort(SqList& L) {
	m = L.length - 1; flag = 1;
	while ((m > 0) && (flag == 1)) {
		flag = 0;
		for (j = 1; j <= m; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;	//flag置于1，表示本趟发生了排序
				t = L.r[j]; L.r[j] = L.r[j + 1]; L.r[j + 1] = t;
			}
			--m;
		}
	}
}
//稳定
//可以用于链式结构
//无序、n较大时，不宜采用

//快速排序
int Partition(SqList& L, int low, int high) {
	//对顺序表L中的子表r[low...high]进行一趟排序，返回枢纽位置
	L.r[0] = L.r[low];	//将第一个数据作为枢纽
	pivotkey = L.r[low].key;
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey) --high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey) ++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList& L, int low, int high) {
	//调用前置初值，low=1，high=length
	//对顺序表子序列L.r[low...high]作快速排序
	if (low < high) {
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivoloc + 1, high);
	}
}

void QuickSort(SqList& L) {
	//对顺序表L做快速排序
	QSort(L, 1, L.length);
}

//快速排序适用于无序、n较大的情况
//很难用于链式结构
//不稳定