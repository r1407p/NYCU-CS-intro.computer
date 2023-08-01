#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int flag = 0;
int main(){
    int t;scanf("%d",&t);
    getchar();
    char combination[8][8];
    for(int i =0;i<t;i++){
        flag =1;
        char string[50];
        gets(string);
        //printf("%s",string);
        int length = strlen(string);
        if(length<=3){
            printf("QAQ\n");
            continue;
        }
        if(length>12){
            printf("QAQ\n");
            continue;
        }
        recur(string,0,0,length,combination);
        if(flag)printf("QAQ\n");
        else printf("\n");
    }
}
void recur(char string[],int n,int now,int length,char combination[8][8]){
    if(n==4){
        if(now!=length)return;
        int fag =0;
        for(int i =0;i<4;i++){
            if(fag)printf(".");
            printf("%s",combination[i]);
            fag = 1;
        }
        printf(" ");
        flag =0;
        return;
    }
    char temp[50];
    for(int i =1;i<4;i++){
        strncpy(temp,string,i);
        temp[i]='\0';
        if(i>1){
            if(temp[0]=='0')return;
        }
        int num = atoi(temp);
        if(num>255||num<0)return;
        if(now+i<=length){
            strcpy(combination[n],temp);
            recur(string+i,n+1,now+i,length,combination); 
        }
    }
}