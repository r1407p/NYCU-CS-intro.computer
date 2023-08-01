#include<stdio.h>
int main(){
    int arr[10000];
    int i =0;
    int sum =0;
    int max = 0;
    while(scanf("%d",arr+i)!=EOF){
        sum +=arr[i];
        if (arr[i]>max)max = arr[i];
        i++;
    }
    printf("%d %d %d",i,sum,max);
}