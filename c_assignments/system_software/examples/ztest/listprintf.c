#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct _List {
	struct _List *flink;
	int x;
} List;
typedef List *pList;
pList list_open() {
	pList p;
	p = (pList)malloc(sizeof(List));
	assert(p!=NULL);
	p->flink = NULL;
	p->x = 0x12345678; /*marker*/
	return p;
}
void list_close(pList p) {
	pList q;
	assert(p!=NULL&&p->x==0x12345678);
	do {
		q = p->flink;
		free(p);
		p = q;
	} while (p!=NULL);
}

char *list_sprintf(pList p, char format[], char s[] /*out*/, int maxChars) {
	char x[40];
	assert(p!=NULL&&p->x==0x12345678);
	s[0]=0;
	p = p->flink;
	while (p!=NULL) { //empty?
		sprintf(x,format,p->x);
		assert(strlen(x)+strlen(s)<maxChars);
		strcat(s,x);
		p = p->flink;
	}
	return s;
}
int list_scanf(pList p, char format[]) {
	int i, n, x;
	pList new;
	assert(p!=NULL&&p->x==0x12345678);
	n = 0;
	for ( ;; ) { //insert at front
		i=scanf(format,&x);
		if (i<=0) { break; }
		new = malloc(sizeof(List));
		assert(new!=NULL);
		assert(x!=0x12345678);
		new->x = x;
		new->flink = p->flink;
		p->flink = new;
		n++;
	}
	return n;
}
int main(void) {
	pList p;
	char s[200];
	p = list_open();
	list_scanf(p, "%d");
	printf("%s\n", list_sprintf(p,"%d ",s,200));
	list_close(p);
}