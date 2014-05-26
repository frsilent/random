typedef struct _List {
	struct _List *flink;
	struct _List *blink;
	int x;
} List;
typedef List *pList;

pList list_open() {
	pList p;
	p = (pList)malloc(sizeof(List));
	assert(p!=NULL);
	p->flink = NULL;
	p->blink = NULL;
	p->x = 0x12345678;
	return p;
}

void list_close(pList p) {
	//no change
	char *list_sprintf(pList p, char format[], char s[] /*out*/, int maxChars) {
		//no change
		int list_scanf(pList p, char format[]) {
			int i, n, x;
			pList new;
			assert(p!=NULL&&p->x==0x12345678);
			n = 0;
			for ( ;; ) {
				i=scanf(format,&x);
				if (i<=0) { break; }
				new = malloc(sizeof(List));
				assert(new!=NULL);
				new->x = x;
				new->flink = p->flink;
				new->blink = p;
				if (p->flink!=NULL) {
					p->flink->blink = new;
				}
				p->flink = new;
				n++;
			}
			return n;
		}
		
		pList list_find(pList p, int value) {
			assert(p!=NULL&&p->x==0x12345678);
			while (p->flink!=NULL&&p->flink->x!=value) {
				p = p->flink;
			}
			return p->flink;
		}
		
		int list_delete(pList p, int value) {
			p = list_find(p, value);
			if (p==NULL) {return 0;}
			p->flink->blink = p->blink;
			p->blink->flink = p->flink;
  free(p);
  return 1;
}
