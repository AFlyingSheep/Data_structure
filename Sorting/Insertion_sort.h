//��������

//ֱ�Ӳ�������
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

//�۰��������
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

//ϣ������
void ShellInsert(SqList& L, int dk) {
	//��˳���L��һ��������dk��ϣ����������
	for(i=dk+1;i<L.length;i++)
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk) 
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
}

void ShellSort(SqList& L, int dt[], int t) {
	//������������dt��˳���L��t��ϣ������
	for (k = 0; k < t; k++)
		ShellInsert(L, dt[k]);
}

//������������ռ临�ӶȾ�ΪO(1)�����õ�r[0]�洢
//ֱ�Ӳ��������������˳��ṹ����ʽ�ṹ��ϣ��������۰���������ֻ������˳��ṹ

