#include<stdio.h>
int isLeap(int n );
int isLeap(int n){
    if(n%4==0){
        if(n%400==0)return 1;
        if(n%100==0)return 0;
        return 1;
    }
    return 0;
}
int main(){
    int a,b,c;scanf("%d %d %d",&a,&b,&c);
    int temp =3;//2020/1/1 wednesday
    if(a>2020){ // a/1/1¬P´Á´X
        for(int i = 2020;i<a;++i){
            if(isLeap(i))temp +=2;
            else temp +=1;
        }
    }
    else if(a<2020){
        for(int i =2019;i>=a;--i){
            if(isLeap(i))temp+=5;
            else temp+=6;
        }
    }
    temp %=7;
    for(int i =1;i<b;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
        temp +=3;
        else if(i ==2){
            if(isLeap(a))++temp;
        }
        else temp+=2;
    }
    temp +=(c-1);
    temp%=7;
    printf("%d",temp); 
}