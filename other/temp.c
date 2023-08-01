#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char string[5][5] ={"ff","bb","dd","cc","ee"};
    qsort(string,5,sizeof(string[1]),strcmp);
    for(int i =0;i<5;i++){
        puts(string[i]);
    }
}