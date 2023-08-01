#include<stdio.h>
void find(int now,int target,int pivot,int used[],int use,int arrsize,int arr[]);
int flag = 0;
int main(){
    int t ;scanf("%d",&t);
    for(int i =0;i<t;i++){
        int target;scanf("%d",&target);
        int arr[30]={0};
        int arrsize = -1;
        do{
            arrsize++;
            scanf("%d",&arr[arrsize]);
        }while(arr[arrsize]!=0);//we have arrize valid number
        int used[101];
        flag =0;
        find(0,target,0,used,0,arrsize-1,arr);
        if(flag)printf("finish\n");
        else printf("no solution\n");
    }
}
void find(int now,int target,int pivot,int used[],int use,int arrsize,int arr[]){
    if(pivot>arrsize)return;
    if(now>target)return;
    if(now==target){
        for(int i =0;i<use;i++){
            printf("%d ",arr[used[i]]);
        }
        printf("\n");
        flag = 1;
        return;
    }    
    else{
        used[use] =pivot;
        find(now+arr[pivot],target,pivot,used,use+1,arrsize,arr);
        find(now,target,pivot+1,used,use,arrsize,arr);
        return;
    }
}