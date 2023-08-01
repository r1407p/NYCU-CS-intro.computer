#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int is_valid(char string[]);
int sixteen(char c);
int isvalid(char string[]);
int main (){
    int t;scanf("%d",&t);
    for(int i =0;i<t;++i){
        int temp;
        char string[51];
        scanf("%d %s",&temp,string);
        if(temp ==4){
            if(is_valid(string))printf("Valid IP\n");
            else printf("QAQ\n");
        }
        if(temp ==6){
            if(isvalid(string))printf("Valid IP\n");
            else printf("QAQ\n");
        }
    }
}
int is_valid(char string[]){
    int length =  strlen(string);
    if(string[0]=='.')return 0 ;
    if(string[length-1]=='.')return 0;
    for(int i =0;i<length;i++){
        if(string[i]=='.')continue;
        if(string[i]<'0')return 0 ;
        if(string[i]>'9')return 0 ;
    }
    int temp=0;
    int ispoint=0;
    int flag=1;
    int base=1;
    for(int i = length-1;i>=0;i--){
        if(string[i]!='.'){
            ispoint=0;
            if(flag){
                temp+=(string[i]-'0')*base;
                flag=0;
            }else{
                if(string[i]=='0')return 0;
                temp+=(string[i]-'0')*base;
            }
            base*=10;
        }
        else{
            if(ispoint)return 0;
            ispoint=1;
            if(temp>255)return 0;
            flag =1,temp =0,base =1;
        }
    }
    return 1;
}
int sixteen(char c){
    if(c>='0'&&c<='9')return 1;
    if(c>='a'&&c<='f')return 1;
    if(c>='A'&&c<='F')return 1;
    return 0;
}
int isvalid(char string[]){
    int length = strlen(string);
    for(int i =0;i<length;i++){
        if(string[i]==':')continue;
        if(!sixteen(string[i]))return 0;
    }
    int count=0;
    int countnum =0;
    int flag =1;
    for(int i =0;i<length;i++){
        if(flag){
            if(string[i]==':')return 0;
            countnum++;
            if(countnum>4)return 0;
            flag =0;
        }else{
            if(string[i]==':')flag =1,count++,countnum =0;
            else{
                countnum++;
                if(countnum>4)return 0;
            }
        }
    }
    if(string[length-1]==':')return 0;
    if(count!=7)return 0;
    return 1;
}
