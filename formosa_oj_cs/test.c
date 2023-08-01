#include<stdio.h>
#include<string.h>
#define MAX 20
#define BASE 2
int main(){
    char *string = "/skjhfw/sajdhfoue/";
    char *p = strtok(string,"/");
    printf("%s\n",p);
    p = strtok(NULL,"/");
    printf("%s\n",p);
    printf("dshufoe");
}