//归并排序

void MSort(RedType R[], RedType& T[], int low, int high) {
	//R[low..high]归并排序后放入T[low,high]
	if (low == high) T[low] = R[low];
	else {
		mid = (low + high) / 2;			//将当前序列一分为二，求出分裂点mid
		MSort(R, S, low, mid);			//对子序列R[low..mid]递归归并排序，结果放入S[low..mid]
		MSort(R, S, mid + 1, high);		//对子序列R[mid+1..high]递归归并排序，结果放入S[mid+1..high]
		Merge(S, T, low, mid, high);	//将S归并到T中
	}
}

//稳定排序
//可用于链式结构，不需要附加储存空间，但递归实现需要调用递归工作栈