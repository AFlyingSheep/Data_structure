//�鲢����

void MSort(RedType R[], RedType& T[], int low, int high) {
	//R[low..high]�鲢��������T[low,high]
	if (low == high) T[low] = R[low];
	else {
		mid = (low + high) / 2;			//����ǰ����һ��Ϊ����������ѵ�mid
		MSort(R, S, low, mid);			//��������R[low..mid]�ݹ�鲢���򣬽������S[low..mid]
		MSort(R, S, mid + 1, high);		//��������R[mid+1..high]�ݹ�鲢���򣬽������S[mid+1..high]
		Merge(S, T, low, mid, high);	//��S�鲢��T��
	}
}

//�ȶ�����
//��������ʽ�ṹ������Ҫ���Ӵ���ռ䣬���ݹ�ʵ����Ҫ���õݹ鹤��ջ