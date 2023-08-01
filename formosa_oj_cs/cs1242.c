#include<stdio.h>
#include<stdlib.h>
int rom_to_int(char arr[]){
    int i =0;
    int sum = 0;
    while(arr[i]=='M'){
        sum +=1000;
        i++;
    }
    if(arr[i]=='C'&&arr[i+1]=='M'){
        sum +=900;
        i +=2;
    }
    if(arr[i]=='D'){
        sum +=500;
        i++;
    }
    if(arr[i]=='C'&&arr[i+1]=='D'){
        sum +=400;
        i +=2;
    }
    while(arr[i]=='C'){
        sum +=100;
        i++;
    }
    if(arr[i]=='X'&&arr[i+1]=='C'){
        sum +=90;
        i +=2;
    }
    if(arr[i]=='L'){
        sum +=50;
        i++;
    }
    if(arr[i]=='X'&&arr[i+1]=='L'){
        sum +=40;
        i +=2;
    }
    while(arr[i]=='X'){
        sum +=10;
        i++;
    }
    if(arr[i]=='I'&&arr[i+1]=='X'){
        sum +=9;
        i +=2;
    }
    if(arr[i]=='V'){
        sum +=5;
        i++;
    }
    if(arr[i]=='I'&&arr[i+1]=='V'){
        sum +=4;
        i +=2;
    }
    while(arr[i]=='I'){
        sum +=1;
        i++;
    }
    return sum;
}
int main(){
    char arr[100];
    int t;scanf("%d",&t);
    for(int i =0;i<t;++i){
        scanf("%s",arr);
        int sum =rom_to_int(arr);
        printf("%d\n",sum);
    }
    

}