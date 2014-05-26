/* @Heintze, Darrell R.
6544 GSU
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <time.h>

void init(int x, node *temp) {
  srand((unsigned int)time(NULL));
  int i=0;
  node *element, *prev;
  prev=temp;
  temp->value=rand()%50;
  temp->prev=NULL;
  printf("initialized head & tail\n");
    for(i=1;i<x;i++) {
      element = (node*)malloc(sizeof(node));
      element->value = rand() % 50;
      prev->next=element; //forward link
      element->prev=prev; //backward link
      element->next=NULL;
      prev=element;
    }
}
