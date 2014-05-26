#include <stdio.h>

int ack(int m, int n) {
  int i;
  if (m==0) { return n+1; }
  if (n==0) { return ack(m-1,1); }
  i = ack(m, n-1);
  return ack(m-1, i);
}

int main(int argc, char *argv[]) {
  int i,m,n;
  if (argc==3) {
   m=atoi(argv[1]);
   n=atoi(argv[2]);
   i=ack(m,n);
  }
  printf("m=%d n=%d f=%d\n",m,n,i);
  return 0;
}
