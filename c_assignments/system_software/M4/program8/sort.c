/* @Heintze, Darrell R.
6544 GSU
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <time.h>

void sort(node *p) {
  node *index,*i,*j;
  i=p;
  int temp;
  while(i->next!=NULL) {
    j=i->next;
    index=i;
    while(j->next!=NULL) {
      index=((index->value)<(j->value))?index:j;
      j=j->next;
    }
    temp=i->value; i->value=index->value;index->value=temp;
    i=i->next;
  }
}
