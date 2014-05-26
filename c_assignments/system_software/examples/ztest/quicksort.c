static void quicksort(int a[] /*inout*/, int left, int right ) {
	int i, j, temp;
	int pivot;
	pivot = a[(left+right) / 2];
	i = left;  j = right;
	do {
		while (a[i] < pivot) { i++; }
		while (a[j] > pivot) { j--; }
		if (i <= j) {
			aiPrintf("%d ", a, 20);
			printf("--%d %d--%d %d %d\n",left,right,i,j,pivot);
			temp=a[i];  a[i]=a[j];  a[j]=temp;
			i++;  j--;
		} /*if*/
	} while (i <= j);
	if (left < j) { quicksort( a, left, j); }
	if (i < right) { quicksort( a, i, right); }
}

void aiSort(int a[] /*inout*/, int N) {
	quicksort( a, 0, N-1);
}