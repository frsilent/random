void aiSort(int a[] /*inout*/, int N)
{int i, temp; boolean count=true;
	for ( i=0; ; i++) {
		if (i >= N-1) {
			if (count) { break; } /*no swaps*/
			count = true;   i = 0; /*start over*/
		} /*if*/
		if (a[i]  > a[i+1]) {
			temp = a[i];  a[i] = a[i+1]; a[i+1] = temp;
			count = false;
		} /*if*/
	} /*for*/
}
