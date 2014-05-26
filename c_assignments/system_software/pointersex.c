#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char STRING[20];
typedef struct _record {
  STRING buffer[1000];
  int count[1000];
  } Record;
void test(Record p) {
  p.count[2]=7;
}
void test1(Record *p) {
  (*p).count[2]=7;
}
void test2(Record *p) {
  p->count[2]=8;
}
typedef struct _record2 {
  STRING name;
  int count;
} Record2;
Record2 unique[1000]={"bog",3,"hog",6};
int main()
{
  struct _record r;
  Record *s;
  Record2 *x, *y;
  int i=1;
  s=malloc(sizeof(Record));
  x=malloc(sizeof(Record2));
  printf("pointer addr=%lx\n",x);
  y=malloc(sizeof(Record2));
  printf("pointer addr=%lx\n",y);
  printf("addr y - addr x:%lx\n",y-x);
  memcpy(&unique[3],&unique[5],sizeof(Record2));
  printf("%s %d\n",unique[i].name,unique[i].count);
  r.count[0]=5;
  (*s).count[2]=6;

  printf("%d %d\n",r.count[0],s->count[2]);
  test(*s);
  printf("%d %d\n",r.count[0],s->count[2]);
  test1(s);
  printf("%d %d\n",r.count[0],s->count[2]);
  test2(s);
  printf("%d %d\n",r.count[0],s->count[2]);
  free(s);
  return 0;
}
