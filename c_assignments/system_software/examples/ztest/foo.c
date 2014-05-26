#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct _List {
  struct _List *flink;
  struct _List *blink;
  struct _List *cursor;
  int x;
} List;
typedef List *pList;
pList list_open() {
  pList p;
  p = (pList)malloc(sizeof(List));
  assert(p!=NULL);
  p->flink = NULL;
  p->blink = NULL;
  p->cursor = NULL;
  p->x = 0x12345678;
  return p;
}
void list_close(pList p) {
  pList q;
  assert(p!=NULL&&p->x==0x12345678&&p->cursor==NULL);
  do {
    q = p->flink;
    free(p);
    p = q;
  } while (p!=NULL);
}
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
char *list_sprintf(pList p, char format[], char s[] /*out*/, int maxChars) {
  char x[40];
  assert(p!=NULL&&p->x==0x12345678);
  s[0]=0;
  p = p->flink;
  while (p!=NULL) {
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
typedef enum {RED, COLOR=5, GREEN} Color;
int main(void) {
Color c;
pList p;
char s[200];
int sum;
c=GREEN;
printf("c=%d\n",c);
p = list_open();
printf("enter list with a 3 and 5>");
list_scanf(p, "%d");
printf("%s\n", list_sprintf(p,"%d ",s,200));
if (!list_delete(p, 5)) {
  printf("no 5 in list\n");
}
if (!list_delete(p, 3)) {
  printf("no 3 in list\n");
}
printf("%s\n", list_sprintf(p,"%d ",s,200));
sum = 0;
assert(list_iterator_open(p));
while(list_iterator_next(p)) {
  sum += list_iterator_get(p);
}
list_iterator_close(p);
printf("sum=%d\n",sum);
list_close(p);
}
