#include<stdio.h>
#include<stdlib.h>
int binary_search(int [],int ,int ,int );
int main(){
    int num;int t;scanf("%d %d",&num,&t);
    int arr[num];for(int i =0;i<num;++i)scanf("%d",arr+i);
    for(int i =0;i<t;++i){
        int temp1 ; scanf("%d",&temp1);
        int ans = binary_search(arr,temp1,0,num-1);
        printf("%d\n",ans);

    }
}
int binary_search(int arr[],int num,int first,int last){
    int temp = (first+last)/2;
    if(arr[temp]==num)return temp;
    if(arr[temp]>num)return binary_search(arr,num,first,temp-1);
    else ;return binary_search(arr,num,temp+1,last);
}