//������

//ɸѡ��������
void HeapAdjust(SqList& L, int s, int m) {
	//����r[s+1..m]�Ѿ��Ƕѣ���r[s..m]����Ϊ��r[s]Ϊ���Ĵ����
	rc = L.r[s];
	for (j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j].key < L.r[j + 1].key) j++;	//jΪ���Һ��ӵĽϴ��±�
		if (rc.key >= L.r[j].key) break;	//�γɴ���˳�ѭ����rc����s��
		L.r[s] = L.r[j];					//���򽫴��ֵ���ڸ���
		s = j;								//������ļ����γɴ����
	}
	L.r[s] = rc;							//rc����s��
}

//������
void CreatHeap(SqList& L) {
	//����������L.r[1..n]���ɴ����
	n = L.length;
	for (i = n / 2; i > 0; i--) {
		HeapAdjust(L, i, n);
	}
}

//������
void HeapSort(SqList& L) {
	//��˳���L���ж�����
	CreatHeap(L);
	for (i = L.length; i > 1; i--) {
		x = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}
//��ÿ�ξ���δ��������һ����¼��Ѷ���¼�������������ֵÿ�ζ������ȥ

//�ռ临�Ӷ�O(1)
//���ȶ�����
//����������ʽ�ṹ
//��¼����ʱ����ʹ�ã���¼�϶��Ч