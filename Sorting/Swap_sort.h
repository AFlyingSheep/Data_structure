//��������

//ð������
void BubbleSort(SqList& L) {
	m = L.length - 1; flag = 1;
	while ((m > 0) && (flag == 1)) {
		flag = 0;
		for (j = 1; j <= m; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;	//flag����1����ʾ���˷���������
				t = L.r[j]; L.r[j] = L.r[j + 1]; L.r[j + 1] = t;
			}
			--m;
		}
	}
}
//�ȶ�
//����������ʽ�ṹ
//����n�ϴ�ʱ�����˲���

//��������
int Partition(SqList& L, int low, int high) {
	//��˳���L�е��ӱ�r[low...high]����һ�����򣬷�����Ŧλ��
	L.r[0] = L.r[low];	//����һ��������Ϊ��Ŧ
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
	//����ǰ�ó�ֵ��low=1��high=length
	//��˳���������L.r[low...high]����������
	if (low < high) {
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivoloc + 1, high);
	}
}

void QuickSort(SqList& L) {
	//��˳���L����������
	QSort(L, 1, L.length);
}

//������������������n�ϴ�����
//����������ʽ�ṹ
//���ȶ�