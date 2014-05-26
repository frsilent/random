typedef struct _List {
	. . . . .
	struct _List *cursor;
} List;

pList list_open() {
	. . . . .
	p->cursor = NULL;
	
	void list_close(pList p) {
		. . . . .
		assert(p!=NULL&&p->x==0x12345678&&p->cursor==NULL);
		
		int list_iterator_open(pList p) {
			assert(p!=NULL&&p->x==0x12345678&&p->cursor==NULL);
			if (p->flink==NULL) { return 0;}
			p->cursor = p;
			return 1;
		}
		void list_iterator_close(pList p) {
			assert(p!=NULL&&p->x==0x12345678);
			p->cursor = NULL;
		}
		int list_iterator_next(pList p) {
			assert(p!=NULL&&p->x==0x12345678);
			if (p->cursor==NULL) { return 0;}
			p->cursor = p->cursor->flink;
			if (p->cursor==NULL) { return 0;}
			return 1;
		}
		int list_iterator_get(pList p) {
			assert(p!=NULL&&p->x==0x12345678&&p->cursor!=NULL);
			return p->cursor->x;
		}
		void list_iterator_put(pList p, int value) {
			assert(p!=NULL&&p->x==0x12345678&&p->cursor!=NULL);
			p->cursor->x = value;
		}
		int main(void) {
			. . . . .
			int sum;
			. . . . .
			sum = 0;
			assert(list_iterator_open(p));
			while(list_iterator_next(p)) {
				sum += list_iterator_get(p);
			}
			list_iterator_close(p);
printf("sum=%d\n",sum);