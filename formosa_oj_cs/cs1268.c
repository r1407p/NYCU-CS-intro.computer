#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int t ;scanf("%d\n",&t);
    for(int i =0;i<t;i++){
        char string1[1000];
        char string2[1000];
        gets(string1);
        gets(string2);
        int length1 = strlen(string1);
        int length2 = strlen(string2);
        if(length1!=length2){
            printf("Fail\n");
            continue;
        }
        for(int j =0;j<length1;j++){
            if(islower(string1[j])){
                string1[j]-=32;
            }
        }
        for(int j =0;j<length2;j++){
            if(islower(string2[j])){
                string2[j]-=32;
            }
        }
        if(strcmp(string1,string2)==0){
            printf("Pass\n");
        }else printf("Fail\n");
    }
}