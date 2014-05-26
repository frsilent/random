/*Recode Program #7 as a C++ class definition with a
constructor/destructor in a .h file.  Code the implementation
in a separate .cpp file.  Code the test program to a separate
.cpp file.  E-mail the three files and a screenshot of execution
to the Instructor. */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void init(int x, node *temp) {
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

void sort(node *p) {
  node *index,*i,*j;
  i=p;
  int temp;
  while(i->next!=NULL) {
    j=i->next;
    index=i;
    while(j!=NULL) {
//      if(!ascending) {index=((index->value)<(j->value))?index:j;}
        /*else*/ {index=((index->value)>(j->value))?index:j;}
      j=j->next;
    }
    temp=i->value; i->value=index->value;index->value=temp;
    i=i->next;
  }
}

void print(node *p) {
  if(p->next!=NULL) {
    printf("%d-->",p->value);
    print(p->next);
  }
}

int main(int argc, char *argv[]) {
  node *myList;
  myList = (node*)malloc(sizeof(node));
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
