void aiSort(int a[] /*inout*/, int N)
{int i, j, temp;
	for (i=0; i<N; i++) {//takes N(N-1) steps, O(N2)
		j = min(a, i, N-1);
		temp = a[i];  a[i] = a[j]; a[j] = temp;
	} /*for*/
}
