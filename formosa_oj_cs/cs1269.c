#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char combination[4][4];
int flag = 1;
int main(){
    int t;scanf("%d\n",&t);
    for(int i =0;i<t;i++){
        flag =0;
        char *string;
        gets(string);
        printf("%s",string);
        int length = strlen(string);
        if(length<=3){
            printf("QAQ\n");
            continue;
        }
        if(length>12){
            printf("QAQ\n");
            continue;
        }
        recur(string,0,0,length);
    }
}
void recur(char *string,int n,int now,int length){
    //if(n==0)printf("\n");
    char temp[4];
    if(n==4){
        int fag = 0;
        for(int i =0;i<4;i++){
            if(fag)printf(".");
            printf("%s",combination[i]);
            fag = 1;
        }
        printf("\n");
        return;
    }
    if(n==3){
        strcpy(temp,string);
        //printf("%s\n",temp);
        int len = strlen(string);
        if(len<1||len>3) return;
        else{
            if(len!=1){
                if(temp[0]=='0')return;
            }else{
                if(atoi(temp)>255)return;
                strcpy(combination[n],temp);
                recur(string+len,n+1,now+len,length);
            }
        }
    }else{
        for(int i =1;i<4;i++){
            strncpy(temp,string,i);
            temp[i]='\0';
            //printf("%s ",temp);
            if(i==1){
                strcpy(combination[n],temp);
                if(now+1<length) recur(string+i,n+1,now+i,length);
            }else if(i==2){
                if(temp[0]=='0')return;
                strcpy(combination[n],temp);
                if(now+2<length) recur(string+i,n+1,now+i,length);
            }else{
                if(temp[0]=='0')return;
                if(atoi(temp)>255)return;
                //printf("%d ,%d ",atoi(temp),n);
                strcpy(combination[n],temp);
                if(now+3<length) recur(string+i,n+1,now+i,length);
            }
        }
    }
}