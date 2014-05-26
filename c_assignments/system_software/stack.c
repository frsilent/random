/* @Heintze, Darrell R.
6544 GSU
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 50
int stack[MAX],top=0;
void init();
void toString(char output[],int n); //top,stack[0].....stack[top-1]
int parse(char input[],int n);

push(int x) {
  if(!(top>MAX)) { stack[++top] = x;}
}

int pop() {return stack[top--];}

void toString(char output[],int n) {
	int i=0;
	char buffer[15]; buffer[0]=0;
  for(i=n;i>=0;i--) {
    sprintf(buffer,"%d, ",stack[i]);
    strcat(output,buffer);
  }
  output[strlen(output)-2]=0;
}

void init() {
  srand((unsigned int)time(NULL));
  int i=0;
    for(i=1;i<MAX/4;i++) {
      push(rand() % 50);
    }
}

int main(int argc,char *argv[]) {
//  init();
  push(1);push(6);push(5);push(4);push(4);
  printf("popped %d off the stack\n",pop());
  char s[20];
  toString(s,top);
  printf("%s\n",s);
}
