#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {

printf(" %d \n", -56); //int
printf(" %d \n", 056); //octal int
printf(" %d \n", 0xCAB); //hex int
printf(" %ld \n", 123456789L); //long
printf(" %lld \n", 123456789123456789LL); //long long
printf(" %g \n", 5.6f); //float
printf(" %lg \n", 5.6E+56); //double
printf(" %c \n", 'X'); //char
printf(" %s \n", "Hello World!!"); //string or char[]
printf("Hello World!! \n");
int A,B,C,D;
scanf("%d%d%d%d",&A,&B,&C,&D);
printf("%d%d%d%d\n",A,B,C,D);
}

