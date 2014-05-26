/* @Heintze, Darrell R.
6544 GSU
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <time.h>

void print(node *p) {
  if(p->next!=NULL) {
    printf("%d-->",p->value);
    print(p->next);
  }
}
