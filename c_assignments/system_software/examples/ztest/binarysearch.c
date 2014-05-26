static int aisearch(int target, int values[] /*in*/, int start, int stop) {
	int midpoint;
	if (start > stop) {
		return -1;
	}
	midpoint = (stop+start)/2;
	//printf("%d %d %d\n",start,stop,midpoint);
	if (values[midpoint] == target) {
		return midpoint;
	} /*if*/
	if (values[midpoint] > target) {
		return aisearch(target, values, start, midpoint-1);
	}
	return aisearch(target, values, midpoint+1, stop);
}
int aiSearch(int target, int values[] /*in*/, int N) {
	return aisearch(target, values, 0, N-1);
}