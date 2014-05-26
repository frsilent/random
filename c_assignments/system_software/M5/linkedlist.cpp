#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <time>

void init(int x, Node *temp) {
  srand((unsigned int)time(NULL));
  int i=0;
  Node *element, *prev;
  prev=temp;
  temp->value=rand()%50;
  temp->prev=NULL;
  printf("initialized head & tail\n");
    for(i=1;i<x;i++) {
      element = (Node*)malloc(sizeof(Node));
      element->value = rand() % 50;
      prev->next=element; //forward link
      element->prev=prev; //backward link
      element->next=NULL;
      prev=element;
    }
}

void sort(Node *p) {
  Node *index,*i,*j;
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

void print(Node *p) {
  if(p->next!=NULL) {
    printf("%d-->",p->value);
    print(p->next);
  }
}

int main(int argc, char *argv[]) {
  Node *myList;
  myList = (Node*)malloc(sizeof(Node));
  printf("list created\n");
  init(10,myList);
  printf("list initialized\n");
  print(myList);
  sort(myList);
  printf("\nlist sorted\n");
  print(myList);
  printf("\n");
  return 0;
}
