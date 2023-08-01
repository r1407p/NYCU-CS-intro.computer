#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    int arr[t];for(int i =0;i<t;++i)arr[i]=i+1;
    secret(arr,0,t-1);
    for(int i = 0;i<t;++i)printf("%d ",arr[i]);
}
void swap(int *a,int *b){
    int temp =*a;
    *a = *b;
    *b = temp;
}
void secret(int arr[],int b,int c){
    if(c==b)return;
    int length = (c-b+1)/2;
    for(int i =b;i<b+length;++i)swap(arr+(i),arr+(i+length));
    secret(arr,b,b+length-1);
    if((c-b)%2 ==0)secret(arr,b+length,c-1);
    else secret(arr,b+length,c);
}