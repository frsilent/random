int aiSearch(int target, int values[] /*in*/, int N) {
	//sentinel-controlled loop
	//eliminates one compare
	int i, temp;
	temp = values[N-1];
	values[N-1] = target;
	for (i=0;  ; i++) {
		if (values[i] == target) {
			break;
		} /*if*/
	} /*for*/
	values[N-1] = temp;
	if (i != N-1) {
		return i;
	} /*if*/
	if (target == temp) {
		return N-1;
	}
	return -1;
}