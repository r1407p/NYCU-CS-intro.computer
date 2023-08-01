#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++){
        int move;
        scanf("%d",&move);
        char string[105];
        scanf("%s",string);
        int len = strlen(string);
        for(int k=0;k<len;k++){
            int temp = string[k]-move;
            if(temp<'a'){
                temp +=26;
            }
            printf("%c",temp);
        }
        printf("\n");
    }
}