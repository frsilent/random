#include<stdio.h>
#include<stdio.h>
#include<string.h>
typedef char STRING[20];
typedef struct _record {
  STRING name;
  int count;
} Record;

void sort(Record x[],int n, int ascending) {
  int i,j;
  for(i=0;i<n-1;i++) {
    for(j=0;j<n-i-1;j++) {
      if(!ascending) {
        if (strcmp(x[j].name,x[j+1].name)<0) {
          memcpy(&x[n+1],&x[j],sizeof(Record));
          memcpy(&x[j],&x[j+1],sizeof(Record));
          memcpy(&x[j+1],&x[n+1],sizeof(Record));
        }
      } else {
        if (strcmp(x[j].name,x[j+1].name)>0) {
          memcpy(&x[n+1],&x[j],sizeof(Record));
          memcpy(&x[j],&x[j+1],sizeof(Record));
          memcpy(&x[j+1],&x[n+1],sizeof(Record));
        }
      }
    }
  }
}

Record unique[1000]={"bug",1,"aug",2,"dug",3,"cug",4,"mug",5};
int main() {
  int i;
  sort(unique,5,1);
  for(i=0;i<5;i++) printf("%s %d\n",unique[i].name,unique[i].count);
  sort(unique,5,0);
  for(i=0;i<5;i++) printf("%s %d\n",unique[i].name,unique[i].count);
  return 0;
}
