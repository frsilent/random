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

int main(void) {
	pList p;
	p = list_open();
list_close(p);
}