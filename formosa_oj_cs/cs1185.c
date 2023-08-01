#include<stdio.h>
int main(){
    int sum = 100;
    int temp;
    int i =0;
    while(scanf("%d",&temp)!=EOF){
        sum -=temp;
        if(sum<0)break;
        i++;
    }
    printf("%d",i);
}
