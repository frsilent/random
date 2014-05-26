#include <stdio.h>
#include <assert.h>

int main(void) {
	double sales=5000.0, percent, commission;
	printf("enter sale amount>");
	assert(scanf("%lg", &sales)==1);
	switch ((int) (sales/5000.0) ) {
		case 1:
		case 2:
		case 3:
			percent = 2.0;
			break;
		case 4:
		case 5:
		case 6:
			percent = 3.0;
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			percent = 5.0;
			break;
		default:
			assert(0/*bad sales number*/);
	} /*switch*/
	commission = percent*0.01*sales;
	printf("Sale=$%lg Percent=%lg%% Commission=$%lg\n",sales,percent,commission);
}