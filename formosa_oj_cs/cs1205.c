#include<stdio.h>
int main(){
    int lenth,inquiry;scanf("%d %d",&lenth,&inquiry);
    int arr[lenth];for(int i =0;i<lenth;++i)scanf("%d",arr+i);
    for(int i =0;i<inquiry;++i){
        int temp ;scanf("%d",&temp);
        for(int j = 0;j<lenth;++j){
            if(temp ==arr[j]){
                printf("%d\n",j);
                break;
            }
        }
    }
}