#include <stdio.h>
#include <string.h>
char searchingfor[] = " hello ";
int main(int argc, char *argv[]) {
        FILE *fp=fopen(argv[1],"r");
        char  tmp[256]={0x0};
        while(fp!=NULL && fgets(tmp, sizeof(tmp),fp)!=NULL)
        {
        if (strstr(tmp, argv[2]))
        printf("%s", tmp);
        }
        if(fp!=NULL) fclose(fp);
        return 0;
}
